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