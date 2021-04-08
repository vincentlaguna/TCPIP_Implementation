#ifndef __LL_API__
#define __LL_API__

#define GET_HEAD_SINGLY_LL(linked_list) (linked_list->head)
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
int linked_list_add_node(linked_list_t *linked_list, linked_list_node_t *node);
int linked_list_add_node_by_val(linked_list_t *linked_list, void *data);
