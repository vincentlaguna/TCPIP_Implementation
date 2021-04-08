#ifndef __LL_API__
#define __LL_API__

#define GET_HEAD_SINGLY_LL(linked_list) (linked_list->head)
#define INC_NODE_COUNT_SINGLY_LL(linked_list) (linked_list->node_count++)
#define DEC_NODE_COUNT_SINGLY_LL(linked_list) (linked_list->node_count--)
#define GET_NODE_COUNT_SINGLY_LL(linked_list) (linked_list->node_count)
#define GET_NEXT_NODE_SINGLY_LL(node) (node->next)

typedef enum
{
  LL_FALSE,
  LL_TRUE
} bool_t;

typedef struct linked_list_node
{
  void    *data;
  struct  linked_list_node *next;
} single_linked_list_node_t;

