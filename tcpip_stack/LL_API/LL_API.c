#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#include "LL_API.h"

linked_list_t *init_single_linked_list(void)
{
  return calloc(1, sizeof(linked_list_t));
}

linked_list_node_t *linked_list_init_node(void *data)
{
  linked_list_node_t *node = calloc(1, sizeof(linked_list_node_t));
  node->data = data;
  return node;
}

int  linked_list_add_node(linked_list_t *linked_list, linked_list_node_t *node)
{
  if (!linked_list)
    return -1;
  if (!node)
    return -1;
  if (!GET_HEAD_LL(linked_list))
  {
    GET_HEAD_LL(linked_list) = node;
    INC_NODE_COUNT_LL(linked_list);
    return 0;
  }
  
  node->next = GET_HEAD_LL(linked_list);
  GET_HEAD_LL(linked_list) = node;
  INC_NODE_COUNT_LL(linked_list);
  return 0;
}

int  linked_list_add_node_by_val(linked_list_t *linked_list, void *data)
{
  linked_list_node_t *node = linked_list_init_node(data);
  return linked_list_add_node(linked_list, node);
}

int  linked_list_remove_node(linked_list_t *linked_list, linked_list_node_t *node)
{
  if (!linked_list || !GET_HEAD_LL(linked_list))
    return 0;
  if (!node)
  {
    printf("%s (%d) : Error = node is NULL\n", __FUNCTION__, __LINE__);
    return -1;
  }
  int i = 0;
  linked_list_node_t *head = GET_HEAD_LL(linked_list), *prev = NULL;
  
  if (head == node)
  {
    GET_HEAD_LL(linked_list) = GET_NEXT_NODE_LL(head);
    DEC_NODE_COUNT_LL(linked_list);
    node->next = NULL;
    return 0;
  }
  prev = head;
  head = GET_NEXT_NODE_LL(linked_list);
  for (i = 1; i < GET_NODE_COUNT_LL(linked_list); i++)
  {
    if (head != node)
    {
      prev = head;
      head = GET_NEXT_NODE_LL(head);
      continue;
    }
    GET_NEXT_NODE_LL(prev) = GET_NEXT_NODE_LL(head);
    GET_NEXT_NODE_LL(head) = NULL;
    DEC_NODE_COUNT_LL(linked_list);
    node->next = NULL;
    return 0;
  }
  printf("%s (%d) : Error = node not found\n", __FUNCTION__, __LINE__);
  return -1;
}

unsigned int  linked_list_delete_node_by_val(linked_list_t *linked_list, void *data, int size)
{
  if (!linked_list || !GET_HEAD_LL(linked_list))
    return 0;
  unsigned int current_node_count = GET_NODE_COUNT_LL(linked_list);
  linked_list_node_t *traversal = GET_HEAD_LL(linked_list);
  
  while (traversal != NULL)
  {
    if (memcmp(traversal->data, data, size) == 0)
    {
      linked_list_delete_node(linked_list, traversal);
      return current_node_count - GET_NODE_COUNT_LL(linked_list);
    }
    traversal = traversal->next;
  }
  return current_node_count - GET_NODE_COUNT_LL(linked_list);
}
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
