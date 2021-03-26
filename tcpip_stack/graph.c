#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  "graph.h"

graph_t   *create_new_graph(char *topology_name)
{
  graph_t *graph = calloc(1, sizeof(graph_t));
  strncpy(graph->topology_name, topology_name, 32);
  graph->topology_name[31] = '\0';
  
  init_glthread(&graph->node_list);
  return graph;
}

node_t  *create_graph_node(graph_t *graph, char *node_name)
{
  node_t *node = calloc(1, sizeof(node_t));
  strncpy(node->node_name, node_name, NODE_NAME_SIZE);
  node->node_name[NODE_NAME_SIZE] = '\0';
  
  init_glthread(&graph->node_list, &node->graph_glue);
  return node;
}

void insert_link_between_two_nodes(node_t *node1,
                                   node_t *node2,
                                   char *from_if_name,
                                   char *to_if_name,
                                   unsigned int cost)
{
  link_t *link = calloc(1, sizeof(link_t));
  // Set interface properties
  strncpy(link->intf1.if_name, from_if_name, IF_NAME_SIZE);
  link->intf1.if_name[IF_NAME_SIZE] = '\0';
  strncpy(link->intf2.if_name, to_if_name, IF_NAME_SIZE);
  link->intf2.if_name[IF_NAME_SIZE] = '\0';
  
  link->intf1.att_node = node1;
  link->intf2.att_node = node2;
  link->cost = cost;
  
  int empty_intf_slot;
  // Plugin interface ends into Node*
  empty_intf_slot = get_node_intf_available_slot(node1);
  node1->intf1[empty_intf_slot] = &link->intf1;
  
  empty_intf_slot = get_node_intf_available_slot(node2);
  node2->intf2[empty_intf_slot] = &link->intf2;
}