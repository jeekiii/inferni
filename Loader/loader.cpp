#include "loader.hpp"

using namespace std;

/*static functions prototypes*/

static node_t *get_node(node_t *node, string name);
static int load_textures(void);
static int **read_csv(char *path, int width, int height);
static void free_array(int **array, int width, int height);
static void free_array(int **array, int width, int height);

/*static variables, use close_level() to clean them*/

static document_t *document = 0;
static vector<SDL_Texture *> *textures = 0;
static vector<int> *textures_id = 0;

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
            SDL_DestroyTexture(textures->at(i));

    delete textures_id;
    delete textures;
}

/*the following functions are used to load the map and know it's dimensions*/

Tile **get_tiles()
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
    node_t *map    = list->head;
    free_node_list(list);

    return atoi(get_node(map, "height")->value);
}

/*this function is used to recover a texture based on it's id*/

SDL_Texture *get_tile_texture(int id)
{
    for (size_t i = 0; i < textures->size(); i++)
        if (textures_id->at(i) == id)
            return textures->at(i);
    return 0;
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

    textures = new vector<SDL_Texture *>();
    textures_id = new vector<int>();

    node_list_t *list;
    list = extract_nodes_by_name(document->content, (char *)"grounds");
    node_list_t *l = list->head->children;

    while (l) {
        node_t *child = l->head;

        node_t *id = get_node(child, "id");
        textures_id->push_back(atoi(id->value));

        node_t *src = get_node(child, "src");
        textures->push_back(ImageFunc::loadSprites(src->value, true, 255, 0, 0));

        l = l->tail;
    }

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
