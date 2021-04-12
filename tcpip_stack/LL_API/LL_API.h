#ifndef __LL_API__
#define __LL_API__

#define GET_HEAD_LL(linked_list) (linked_list->head)
#define INC_NODE_COUNT_LL(linked_list) (linked_list->node_count++)
#define DEC_NODE_COUNT_LL(linked_list) (linked_list->node_count--)
#define GET_NODE_COUNT_LL(linked_list) (linked_list->node_count)
#define GET_NEXT_NODE_LL(node) (node->next)

typedef enum
{
  LL_FALSE,
  LL_TRUE
} bool_t;

typedef struct linked_list_node
{
  void                      *data;
  struct  linked_list_node  *next;
} linked_list_node_t;

typedef struct linked_list
{
  unsigned int              node_count;
  linked_list_node_t        *head;
  int (*comparison_fn)(void *, void *);
} linked_list_t;

linked_list_t *init_single_linked_list(void);
linked_list_node_t *linked_list_init_node(void *data);
int  linked_list_add_node(linked_list_t *linked_list, linked_list_node_t *node);
int  linked_list_add_node_by_val(linked_list_t *linked_list, void *data);
unsigned int  linked_list_remove_node(linked_list_t *linked_list, linked_list_node_t *node);
int  linked_list_delete_node_by_val(linked_list_t *linked_list, void *data, int size);
bool_t is_linked_list_empty(linked_list_t *linked_list);
void print_linked_list(linked_list_t *linked_list);
void reverse_linked_list(linked_list_t *linked_list);
void delete_linked_list(linked_list_t *linked_list);
int  linked_list_delete_node(linked_list_t *linked_list, linked_list_node_t *node);
unsigned int  linked_list_delete_node_by_val(linked_list_t *linked_list, void *data, int size);
linked_list_node_t *linked_list_get_node_by_data_ptr(linked_list_t *linked_list, void *data);
unsigned int  linked_list_remove_node_by_data_ptr(linked_list_t *linked_list, void *data);
void linked_list_set_comparison_fn(linked_list_t *linked_list, int (*comparison_fn)(void *, void*));
void *linked_list_search_by_key(linked_list_t *linked_list, void *key);

#define ITERATE_LIST(list_ptr, node_ptr)                                        \
        node_ptr = GET_HEAD_LL(list_ptr);                                       \
        for(; node_ptr != NULL; node_ptr = GET_NEXT_NODE_LL(node_ptr))          
#endif