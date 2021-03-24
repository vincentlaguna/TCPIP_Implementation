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
}