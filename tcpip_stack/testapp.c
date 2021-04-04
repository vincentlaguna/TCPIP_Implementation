#include          "graph.h"

extern graph_t *build_first_topo();

int main(void)
{
  graph_t *topo   =  build_first_topo();
  dump_graph(topo);
  return(0);
}