#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/*
 * HOW TO :
 *
 * 1. Read the targeted document with the function read_XML_file(char *path).
 * 2. Build the parsed document with the function parse_XML_file(char *file).
 * 3. Use the function extract_nodes_by_name(node_t node, char *name) to
 *    recover all the nodes of the document with the targeted name.
 * 4. Recover the values of the nodes (look at the content of the node_list and
 *    node structures).
 * 5. Free the memory allocated to your node_list with the function
 *    free_node_list(node_list_t *list).
 * 6. Free the memory allocated to the document by using the function
 *    free_document(document_t *document).
 */

/*structures*/

typedef struct document
{
	char *type;
	struct node *content;
} document_t;

typedef struct node
{
	char *name;
	char *value;
	struct node_list *children;
} node_t;

typedef struct node_list
{
	node_t *head;
	struct node_list *tail;
} node_list_t;


/*build*/

node_t *build_node(char *name, char *value, node_list_t *children);
node_list_t *build_node_list(node_t *head, node_list_t *tail);

void push_node_list(node_list_t **list, node_t *value);

char *read_XML_file(char *path);

/*destroy*/

void free_document(document_t *document);
void free_node(node_t *node);
void free_node_list(node_list_t *list);
void full_free_node_list(node_list_t *list);

/*use*/

node_list_t *extract_nodes_by_name(node_t *node, char *name);
void print_node(node_t *node);
void print_document(document_t *document);
void print_node_list(node_list_t *list);
void node_cpy(node_t *dest, node_t *source);
void node_list_cpy(node_list_t *dest, node_list_t *source);

/*parse*/

document_t *parse_XML_file(char *file);
node_t *parse_node(char *node);

char *find_next_substring(char *string, char *sub_string);
char *extract_next_substring(char *string, char *open, char *close);

char *extract_next_node(char *file);
char *extract_next_attribute_node(char *file);
char *extract_next_tag_node(char *file);
char *extract_next_double_tag_node(char *file);
char *extract_next_single_tag_node(char *file);

char *extract_node_name(char *node);
char *extract_attribute_node_name(char *node);
char *extract_tag_node_name(char *node);

char *extract_node_value(char *node);
char *extract_attribute_node_value(char *node);
char *extract_tag_node_value(char *node);
