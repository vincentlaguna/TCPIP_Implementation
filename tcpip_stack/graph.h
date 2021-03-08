#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph_
{
  char topology_name[32];
  glthread_t node_list;
};

#endif // GRAPH_H
