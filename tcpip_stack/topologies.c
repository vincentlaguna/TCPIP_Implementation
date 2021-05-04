#include             "graph.h"

graph_t   *build_first_topo(void)
{
  graph_t *topo   =  create_new_graph("Initial Generic Graph");
  node_t  *R0_re  =  create_graph_node(topo, "R0_re");
  node_t  *R1_re  =  create_graph_node(topo, "R1_re");
  node_t  *R2_re  =  create_graph_node(topo, "R2_re");

  insert_link_between_two_nodes(R0_re, R1_re, "eth0/0", "eth0/1", 1);
  insert_link_between_two_nodes(R1_re, R2_re, "eth0/2", "eth0/3", 1);
  insert_link_between_two_nodes(R0_re, R2_re, "eth0/4", "eth0/5", 1);
  
  // continue implementation, and add the cli lib

  return topo;
}
