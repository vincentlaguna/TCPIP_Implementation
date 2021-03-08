#ifndef GRAPH_H
#define GRAPH_H

typedef struct interface_
{
  char if_name[IF_NAME_SIZE];
  struct node_ * att_node;
} interface_t;

typedef struct graph_
{
  char topology_name[32];
  glthread_t node_list;
};

#endif // GRAPH_H
