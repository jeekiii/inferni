#include "parser.h"

/*build*/

node_t *build_node(char *name, char *value, node_list_t *children)
{
    node_t *result = malloc(sizeof(node_t));

    if (!result)
        return NULL;

    *result = (node_t) {
        .name = name,
        .value = value,
        .children = children,
    };

    return result;
}

node_list_t *build_node_list(node_t *head, node_list_t *tail)
{
    node_list_t *result = malloc(sizeof(node_list_t));

    if (!result)
        return NULL;

    *result = (node_list_t) {
        .head = head,
        .tail = tail,
    };

    return result;
}

void push_node_list(node_list_t **list, node_t *value)
{
    *list = build_node_list(value, *list);
}

char *read_XML_file(char *path)
{
    int file = open(path, O_RDONLY);
    char *result = malloc(1024 * 1024);

    if (file <= 0 || !result) {
        free(result);
        return NULL;
    }

    *result = '\0';
    char buffer[1024];

    int n = read(file, buffer, 1024);

    while (n > 0) {
        strncat(result, buffer, n);
        n = read(file, buffer, 1024);
    }

    if (n < 0) {
        free(result);
        return NULL;
    }

    return result;
}

/*destroy*/

void free_document(document_t *document)
{
    if (!document)
        return;

    free(document->type);
    free_node(document->content);

    free(document);
}

void free_node(node_t *node)
{
    if (!node)
        return;

    free(node->name);
    free(node->value);
    full_free_node_list(node->children);

    free(node);
}

void full_free_node_list(node_list_t *list)
{
    if (!list)
        return;

    free_node(list->head);
    full_free_node_list(list->tail);

    free(list);
}

void free_node_list(node_list_t *list)
{
    if (!list)
        return;

    free_node_list(list->tail);

    free(list);
}

/*use*/

node_list_t *extract_nodes_by_name(node_t *node, char *name)
{
    if (!node || !node->name)
        return NULL;

    node_list_t *result = NULL;

    if (!strcmp(node->name, name))
        push_node_list(&result, node);

    node_list_t *children = node->children;

    while (children) {
        node_list_t *list = extract_nodes_by_name(children->head, name);

        if (list) {
            if (!result)
                result = list;
            else {
                node_list_t *l = result;

                while (l->tail)
                    l = l->tail;

                l->tail = list;
            }
        }

        children = children->tail;
    }

    return result;
}

void print_node(node_t *node)
{
    if (!node)
        return;

    printf("node : '%s', '%s'\n", node->name, node->value);
    print_node_list(node->children);
}

void print_document(document_t *document)
{
	if (!document)
		return;

	printf("document type : %s\n", document->type);
	print_node(document->content);
}

void print_node_list(node_list_t *list)
{
	if (!list)
		return;

	print_node(list->head);
	print_node_list(list->tail);
}

/*parse*/

char *find_next_substring(char *string, char *substring)
{
    if (!string || !substring)
        return NULL;

    //looking for the position of the substring's  first character

    char *n = strchr(string, *substring);

    //while there's such a position, if the substring isn't complete at the
    //current position, we look for the next occurence of this first character,
    //else we return the position of the substring.

    while (n) {
        if (!strncmp(n, substring, strlen(substring)))
            return n;

        n = strchr(++n, *substring);
    }

    return NULL;
}

char *extract_next_substring(char *string, char *open, char *close)
{
    //we're looking for the position of next occurrence of the opening character
    //sequence

    char *start = find_next_substring(string, open);

    if (!start)
        return NULL;

    //if there's a position for the opening character sequence, we're looking
    //for the next occurrence of the ending character sequence

    char *end = find_next_substring(start + strlen(open), close);

    if (!end)
        return NULL;

    //the length of the substring is computed

    int length = (int)(end - start) + strlen(close);

    if (length < 0)
        return NULL;

    //memory is allocated for the substring and the substring is written in
    //the allocated memory

    char *result = malloc(length + 1);

    if (!result)
        return NULL;

    strncpy(result, start, length);
    result[length] = '\0';

    return result;
}

char *extract_attribute_node_name(char *node)
{
    char s[2] = {*node, '\0'};
    char *result = extract_next_substring(node, s, "=");

    if (!result)
        return NULL;

    result[strlen(result) - 1] = '\0';

    return result;
}

char *extract_tag_node_name(char *node)
{
    //if there are attributes inside the node ...

    char *result = extract_next_substring(node, "<", " ");

    //if there aren't ...

    if (!result)
        result = extract_next_substring(node, "<", ">");

    if (!result)
        return NULL;

    //if second_result is shorter than result, result becomes second_result ...

    char *second_result = extract_next_substring(node, "<", ">");

    if (second_result && strlen(second_result) < strlen(result)) {
        free(result);
        result = second_result;
    }
    else
        free(second_result);

    char * raw_result = result;
    result = malloc(strlen(result));

    if (!result) {
        free(raw_result);
        return NULL;
    }

    strncpy(result, raw_result + 1, strlen(raw_result) - 2);
    result[strlen(raw_result) - 2] = '\0';
    free(raw_result);

    return result;
}

char *extract_node_name(char *node)
{
    //if the node is a tag node ...

    char *result = extract_tag_node_name(node);

    //if it's an attribute node ...

    if (!result)
        return extract_attribute_node_name(node);

    return result;
}

char *extract_attribute_node_value(char *node)
{
    char *result = extract_next_substring(node, "=\"", "\"");

    if (!result)
        return NULL;

    char * raw_result = result;
    result = malloc(strlen(result));

    if (!result) {
        free(raw_result);
        return NULL;
    }

    strncpy(result, raw_result + 2, strlen(raw_result) - 3);
    result[strlen(raw_result) - 3] = '\0';
    free(raw_result);

    return result;
}

char *extract_tag_node_value(char *node)
{
    //if the node is a double tag node ...

    char *result = extract_next_substring(node, ">", "<");

    //if it's a single tag node, it doesn't have a value and "null" is returned
    //else it wasnt a tag node at all and NULL is returned

    if (!result) {
        if (*node == '<')
            return extract_next_substring("null", "nu", "ll");
        else
            return NULL;
        }

    char * raw_result = result;
    result = malloc(strlen(result));

    if (!result) {
        free(raw_result);
        return NULL;
    }

    strncpy(result, raw_result + 1, strlen(raw_result) - 2);
    result[strlen(raw_result) - 2] = '\0';
    free(raw_result);

    char *s = result;

    //if the value isn't only blank characters, it's returned, otherwise "null"
    //is returned

    while (*s != '\0') {
        if (*s != ' ' && *s != '\t' && *s != '\n')
            return result;
        s++;
    }

    free(result);
    result = malloc(5);

    strncpy(result, "null", 5);

    return result;
}

char *extract_node_value(char *node)
{
    //if the node is a tag node ...

    char *result = extract_tag_node_value(node);

    //if the node is an attribute node ...

    if (!result)
        return extract_attribute_node_value(node);

    return result;
}

char *extract_next_attribute_node(char *file)
{
    //trying to recover the next attribute node ...

    char *result = extract_next_substring(file, " ", "\" ");

    //checking if it contains a '=', if it doesn't, trying again ...

    while (result && !find_next_substring(result, "=")) {
        free(result);
        result = extract_next_substring(file, " ", " ");
    }

    //if the attribute node is the last element in a tag node ...

    if (!result)
        result = extract_next_substring(file, " ", ">");

    if (!result)
        return NULL;

    //trying to confirm that we've got the closest result ...

    char *second_result = extract_next_substring(file, " ", "\">");

    if (second_result) {
        char *value = extract_node_value(second_result);

        if (value && strlen(second_result) < strlen(result)) {
            free(result);
            result = second_result;
        }
        else
            free(second_result);

        free(value);
    }

    strncpy(result, result + 1, strlen(result) - 2);
    result[strlen(result) - 2] = '\0';

    return result;
}

char *extract_next_double_tag_node(char *file)
{
    //finding the next '<' sign ...

    char *start = find_next_substring(file, "<");

    if (!start)
        return NULL;

    //if there's such a sign, we're extracting the name of the tag node the
    //sign is opening

    char * name = extract_tag_node_name(start);

    if (!name)
        return NULL;

    //building the end tag of the node

    char end_tag[strlen(name) + 4];
    sprintf(end_tag, "</%s>", name);

    char *end = find_next_substring(start, end_tag);
    free(name);

    //if there's no end tag, then our next node wasn't a double tag one, we
    //return NULL

    if (!end)
        return NULL;

    //otherwise, the length of the node is computed and it's character sequence
    //is extracted

    int length = end - start + strlen(end_tag);
    char *result = malloc(length + 1);

    if (!result)
        return NULL;

    strncpy(result, start, length);
    result[length] = '\0';

    return result;
}

char *extract_next_single_tag_node(char *file)
{
    //finding the next '<' sign ...

    char *start = find_next_substring(file, "<");

    if (!start)
        return NULL;

    //finding the next '>' sing ...

    char *end = find_next_substring(start, ">");

    if (!end)
        return NULL;

    //the length of the node is computed and it's character sequence
    //is extracted

    int length = end - start + 1;
    char *result = malloc(length + 1);

    if (!result)
        return NULL;

    strncpy(result, start, length);
    result[length] = '\0';

    char *name = extract_tag_node_name(result);

    //ignoring comments ...

    if (!strcmp(name, "!--") || *name == '/') {
        free(result);
        free(name);

        return extract_next_node(end);
    }

    free(name);

    return result;
}

char *extract_next_tag_node(char *file)
{
    char *result = extract_next_double_tag_node(file);

    if (!result)
        return extract_next_single_tag_node(file);

    return result;
}

char *extract_next_node(char *file)
{
    //finding the next '=' and '<' signs

    char *next_equals  = find_next_substring(file, "=");
    char *next_bracket = find_next_substring(file, "<");

    if (!next_equals && !next_bracket)
        return NULL;

    //if the position of '=' precedes the one of the '<' sign, then the next
    //node should be an attribute node, otherwise we're expecting a tag node

    if (next_equals && (next_equals < next_bracket || !next_bracket))
        return extract_next_attribute_node(file);
    else
        return extract_next_tag_node(file);
}

node_t *parse_node(char *node)
{
    //extracting the name and the value of the node

    char *name =  extract_node_name(node);
    char *value = extract_node_value(node);

    if (!name || !value) {
        free(name);
        free(value);

        return NULL;
    }

    if (!strlen(value)) {
        free(value);
        value = NULL;
    }

    //extracting the children nodes of our node

    node_list_t *children = NULL;
    char *child = extract_next_node(++node);

    //ignoring javascript

    while (strcmp("script", name) && child) {
        node_t *n = parse_node(child);

        if (n)
            push_node_list(&children, n);

        node = find_next_substring(node, child);

        if (node)
            node += strlen(child);

        free(child);
        child = NULL;

        if (node)
            child = extract_next_node(node);
    }

    free(child);

    //building our node ...

    node_t *result = build_node(name, value, children);

    if (!result) {
        free(name);
        free(value);

        return NULL;
    }

    return result;
}

document_t *parse_XML_file(char *file)
{
    //extracting the type of the file ...

    char *type = extract_next_node(file);
    node_t *content = NULL;

    if (!type)
        return NULL;

    //if there's content, extracting nodes from it, otherwise we're returning
    //NULL

    if (strlen(file) > strlen(type)) {
        char * node = extract_next_node(file + strlen(type));
        content = parse_node(node);
        free(node);
    }
    else {
        free(type);
        return NULL;
    }

    //building the document

    document_t *result = malloc(sizeof(document_t));

    *result = (document_t) {
        .type = type,
        .content = content,
    };

    return result;
}
