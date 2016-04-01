#include "loader.hpp"

using namespace std;

/*static functions prototypes*/

static node_t *get_node(node_t *node, string name);
static int load_textures(void);
static int get_type_as_int(char *type);
static vector<Objective *> *get_objectives(node_list_t * list);
static int **read_csv(char *path, int width, int height);
static void free_array(int **array, int width, int height);
static void free_array(int **array, int width, int height);

/*static variables, use close_level() to clean them*/

static document_t *document = 0;
static vector<texture_t *> *textures;

texture_t *build_texture(int type, int id, SDL_Texture *texture)
{
    texture_t *result = (texture_t *)malloc(sizeof(texture_t));

    if (!result)
        return NULL;

    *result = (texture_t)
    {
        .texture = texture,
        .type = type,
        .id = id,
    };

    return result;
}

void free_texture(texture_t *texture)
{
    if (!texture)
        return;

    SDL_DestroyTexture(texture->texture);
    free(texture);
}

/*the following functions are loading and freeing textures and level's file*/

int open_level(string path)
{
    close_level();

    //reading and parsing document
    char *real_path = (char *)path.c_str();
    char *file = read_XML_file(real_path);

    if (!file)
        return 1;

    document = parse_XML_file(file);
    free(file);

    return load_textures();
}

void close_level(void)
{
    //freeing previously loaded document
    free_document(document);

    if (textures)
        for (size_t i = 0; i < textures->size(); i++)
            free_texture(textures->at(i));

    delete textures;
}

/*the following functions are used to load the quests*/

Quest *get_quest(Player *player, vector<Object *> *objects, int id)
{
    node_list_t *list = extract_nodes_by_name(document->content, (char *)"quest");
    node_list_t *l    = list;

    while (l)
    {
        node_t *n = l->head;
        node_t *id_node = get_node(n, "id");

        if (atoi(id_node->value) == id)
            return new Quest(atoi(id_node->value), player, objects, get_objectives(extract_nodes_by_name(n, (char *)"objective")), 0);

        l = l->tail;
    }

    free_node_list(list);
    return NULL;
}

static vector<Objective *> *get_objectives(node_list_t * list)
{
    vector<Objective*> *objectives = new vector<Objective *>();

    while (list)
    {
        node_t *n = list->head;
        node_t *type = get_node(n, "type");
        node_t *target_id = get_node(n, "target_id");

        objectives->push_back(new Objective(get_type_as_int(type->value), atoi(target_id->value)));

        list = list->tail;
    }

    return objectives;
}

static int get_type_as_int(char *type)
{
    if (!strcmp("kill", type))
        return KILL;
    if (!strcmp("reach", type))
        return REACH;
    if (!strcmp("possess", type))
        return POSSESS;

    return 0;
}

/*the following functions are used to load the map and know it's dimensions*/

Tile **get_tiles(void)
{
    node_list_t *list = extract_nodes_by_name(document->content, (char *)"map");
    node_t *map    = list->head;
    free_node_list(list);

    node_t *path = get_node(map, "src");

    int width  = atoi(get_node(map, "width")->value);
    int height = atoi(get_node(map, "height")->value);

    int **tiles = read_csv(path->value, width, height);

    Tile **result = (Tile **)malloc(width * sizeof(Tile *));

    if (!result)
        return 0;

    for (int i = 0; i < width; i++)
        result[i] = (Tile *)malloc(height * sizeof(Tile));

    for (int i = 0; i < width; i++)
        if (!result[i]) {
            for (int j = 0; j <= i; j++)
                free(result[j]);
            free(result);

            return 0;
        }

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            result[x][y] = *(new Tile(tiles[x][y]));

    free_array(tiles, width, height);

    return result;
}


int get_map_width(void)
{
    node_list_t *list = extract_nodes_by_name(document->content, (char *)"map");
    node_t *map    = list->head;
    free_node_list(list);

    return atoi(get_node(map, "width")->value);
}

int get_map_height(void)
{
    node_list_t *list = extract_nodes_by_name(document->content, (char *)"map");
    node_t *map = list->head;
    free_node_list(list);

    return atoi(get_node(map, "height")->value);
}

SDL_Texture *get_texture(int type, int id)
{
    for (size_t i = 0; i < textures->size(); i++)
        if (textures->at(i)->type == type && textures->at(i)->id == id)
            return textures->at(i)->texture;
    return NULL;
}

int get_id_from_class(char *class_name)
{
    node_list_t *list;
    list = extract_nodes_by_name(get_node(document->content, "classes"), (char *)"type");
    node_list_t *l = list;

    while (l)
    {
        node_t *child = l->head;

        node_t *id   = get_node(child, "id");
        node_t *name = get_node(child, "name");

        if (!strcmp(name->value, class_name))
        {
            free_node_list(list);
            printf("%s %s\n", id->value, class_name);
            return atoi(id->value);
        }
        else
        {
            printf("%s %s : %s\n", id->value, name->value, class_name);
        }

        l = l->tail;
    }

    free_node_list(list);
    printf("%s\n", class_name);

    return 0;
}

SDL_Texture *get_texture(int type, char *object_class)
{
    return get_texture(type, get_id_from_class(object_class));
}

/*the following functions are used to load the map's content*/

vector<Object *> *get_content(void)
{
    vector<Object *> *result = new vector<Object *>();

    node_list_t *list;
    list = extract_nodes_by_name(document->content, (char *)"content");
    node_list_t *l = list->head->children;

    while (l) {
        node_t *child = l->head;

        //node_t *id = get_node(child, "id");
        node_t *x = get_node(child, "x");
        node_t *y = get_node(child, "y");
        node_t *o_class = get_node(child, "class");
        node_t *id = get_node(child, "id");

        if (!strcmp(o_class->value, "player"))
        {
            Player *p = new Player(atoi(x->value) * 50, atoi(y->value) * 50);
            p->setTexture(get_object_texture(get_id_from_class(o_class->value)));
            result->push_back(p);
        }

        if (!strcmp(o_class->value, "creature"))
        {
            Creature *c = new Creature(atoi(id->value), atoi(x->value) * 50, atoi(y->value) * 50);
            c->setTexture(get_object_texture(get_id_from_class(o_class->value)));
            result->push_back(c);
        }

        l = l->tail;
    }

    free_node_list(list);

    return result;
}

/*kind of private, don't mind that*/

SDL_Texture *get_object_texture(int id)
{
    return get_texture(OBJECT, id);
}

SDL_Texture *get_tile_texture(int id)
{
    return get_texture(GROUND, id);
}

/*the following functions are static, looking into them serves no purpose*/

static node_t *get_node(node_t *node, string name)
{
    node_list_t *list = extract_nodes_by_name(node, (char *)name.c_str());
    node_t *result = list->head;
    free_node_list(list);

    return result;
}

static int load_textures(void)
{
    if (!document)
        return 1;

    textures = new vector<texture_t *>();

    node_list_t *list;
    list = extract_nodes_by_name(document->content, (char *)"grounds");
    node_list_t *l = list->head->children;

    while (l) {
        node_t *child = l->head;

        node_t *id = get_node(child, "id");
        node_t *src = get_node(child, "src");
        texture_t *texture = build_texture(GROUND, atoi(id->value), ImageFunc::loadSprites(src->value, true, 255, 0, 0));
        textures->push_back(texture);

        l = l->tail;
    }

    free_node_list(list);

    list = extract_nodes_by_name(document->content, (char *)"classes");
    l = list->head->children;

    while (l) {
        node_t *child = l->head;

        node_t *id = get_node(child, "id");
        node_t *src = get_node(child, "src");
        texture_t *texture = build_texture(OBJECT, atoi(id->value), ImageFunc::loadSprites(src->value, true, 255, 0, 0));
        textures->push_back(texture);

        l = l->tail;
    }

    free_node_list(list);

    return 0;
}

static int **read_csv(char *path, int width, int height)
{
    int **result = (int **)malloc(width * sizeof(int *));

    if (!result)
        return 0;

    for (int i = 0; i < width; i++)
        result[i] = (int *)malloc(height * sizeof(int));

    for (int i = 0; i < width; i++)
        if (!result[i]) {
            for (int j = 0; j <= i; j++)
                free(result[j]);
            free(result);

            return 0;
        }

    ifstream in;
    in.open(path);

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            in >> result[x][y];
            in.get();
        }

    in.close();

    return result;
}

static void free_array(int **array, int width, int height)
{
    for (int i = 0; i < width; i++)
        free(array[i]);
    free(array);
}
