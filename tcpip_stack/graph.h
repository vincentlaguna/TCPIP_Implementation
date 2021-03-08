#ifndef GRAPH_H
#define GRAPH_H

typedef struct interface_
{
  char		if_name[IF_NAME_SIZE];
  struct node_ 	*att_node;
  struct link_ 	*link;
} interface_t;

struct link_
{
  interface_t	intf1;
  interface_t	intf2;
  unsigned int	cost;
};

typedef struct graph_
{
  char topology_name[32];
  glthread_t node_list;
};

#endif // GRAPH_H
