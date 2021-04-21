#ifndef 	__GRAPH_H__
#define 	__GRAPH_H__

#include 	"gluethread_lib/glthread.h"
// Define Constants
#define 	NODE_NAME_SIZE    16
#define 	IF_NAME_SIZE		  16
#define		MAX_INTF_PER_NODE	10
// Forward Declarations (to avoid recursive dependencies between Data Structures)
typedef struct 	node_ node_t;
typedef struct 	link_ link_t;

typedef struct 	interface_
{
  char		      if_name[IF_NAME_SIZE];
  struct node_ 	*att_node;
  struct link_ 	*link;
} interface_t;

struct link_
{
  interface_t	  intf1;
  interface_t	  intf2;
  unsigned int	cost;
};

struct 		      node_
{
  char		      node_name[NODE_NAME_SIZE];
  interface_t	  *intf[MAX_INTF_PER_NODE];
  glthread_t 	  graph_glue;
};

GLTHREAD_TO_STRUCT(graph_glue_to_node, node_t, graph_glue);

typedef struct 	graph_
{
  char 		      topology_name[32];
  glthread_t 	  node_list;
} graph_t;

node_t          *create_graph_node(graph_t *graph, char *node_name);
graph_t         *create_new_graph(char *topology_name);

void  insert_link_between_two_nodes(node_t       *node1,
                                    node_t       *node2,
                                    char         *from_if_name,
                                    char         *to_if_name,
                                    unsigned int cost);
// Helper Functions
static inline   node_t *get_nbr_node(interface_t *interface)
{
  link_t *pLink = interface->link;
  
  if (&pLink->intf1 == interface)
    return pLink->intf2.att_node;
  else
    return pLink->intf1.att_node;
}
// For first assignment: get the available slot for the interface node
// This still needs testing of some sort...
static inline int   get_node_intf_available_slot(node_t *node)
{
  int i;
  
  for (i = 0; i < MAX_INTF_PER_NODE; i++)
  {
    if (node->intf[i])
      continue;
    return i;
  }
  return -1;
}
// Assignment 3 - Function that returns a pointer to the local interface of
// the node, if searched by interface name
static inline interface_t * get_node_intf_by_name(node_t *node, char *if_name)
// Display Routines
void  dump_graph(graph_t *graph);

void  dump_node(node_t *node);

void  dump_interface(interface_t *interface);

#endif // __GRAPH_H__
