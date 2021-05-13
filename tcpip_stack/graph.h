#ifndef 	        __GRAPH_H__
#define 	        __GRAPH_H__

#include          <assert.h>
#include 	        "gluethread_lib/glthread.h"
#include          "net.h"
// Define Constants
#define 	        NODE_NAME_SIZE    16
#define 	        IF_NAME_SIZE		  16
#define		        MAX_INTF_PER_NODE	10
// Forward Declarations (to avoid recursive dependencies between Data Structures)
typedef struct 	  node_ node_t;
typedef struct 	  link_ link_t;

typedef struct 	  interface_
{
  char		        if_name[IF_NAME_SIZE];
  struct node_ 	  *att_node;
  struct link_ 	  *link;
  intf_nw_props_t intf_nw_props;
} interface_t;

struct            link_
{
  interface_t	    intf1;
  interface_t	    intf2;
  unsigned int	  cost;
};

struct 		        node_
{
  char		        node_name[NODE_NAME_SIZE];
  interface_t	    *intf[MAX_INTF_PER_NODE];
  glthread_t 	    graph_glue;
  node_nw_prop_t  node_nw_prop;
};

GLTHREAD_TO_STRUCT(graph_glue_to_node, node_t, graph_glue);

typedef struct 	  graph_
{
  char 		        topology_name[32];
  glthread_t	    node_list;
} graph_t;

node_t            *create_graph_node(graph_t *graph, char *node_name);
graph_t           *create_new_graph(char *topology_name);

void  insert_link_between_two_nodes(node_t       *node1,
                                    node_t       *node2,
                                    char         *from_if_name,
                                    char         *to_if_name,
                                    unsigned int cost);
// Helper Functions
static inline node_t  *get_nbr_node(interface_t *interface)
{
  assert(interface->att_node);
  assert(interface->link);
  
  link_t *link = interface->link;
  
  if (&link->intf1 == interface)
    return link->intf2.att_node;
  else
    return link->intf1.att_node;
}
// For first assignment: get the available slot for the interface node

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
// Assignment 3.1 - Function that returns a pointer to the local interface of
// the node, if searched by interface name
// My Answer:
static inline interface_t  *get_node_intf_by_name(node_t *node, char *if_name)
{
  int i;
  interface_t *interface;
  
  for (i = 0; i < MAX_INTF_PER_NODE; i++)
  {
    // if (!interface) // <- MINE
    //   return NULL;
    // if (strncmp(node->intf[i]->if_name, if_name, IF_NAME_SIZE) == 0)
    // {
    //   node->intf[i] = interface;
      interface = node->intf[i];
      if(!interface) return NULL;
      if(strncmp(interface->if_name, if_name, IF_NAME_SIZE) == 0)
      {
      return interface;
      }
  }
  return NULL;
}
// Instructor Example:
// static inline interface_t  *get_node_intf_by_name(node_t *node, char *if_name)
// {
//   interface_t *interface = NULL;
//   int i;
  
//   for (i = 0; i < MAX_INTF_PER_NODE; i++)
//   {
//     if (strncmp(node->intf[i].if_name) == if_name)
//     {
//       node->intf[i] = interface;
//       return interface;
//     }
//     break;
//   }
//   return -1;
// }
// Assignment 3.2 - Function that returns a pointer to a node,
// if searched by node name
// My Answer:
static inline node_t  *get_node_by_node_name(graph_t *topology, char *node_name)
{
  glthread_t *current;
  node_t     *node;
  
  ITERATE_GLTHREAD_BEGIN(&topology->node_list, current)
  {
    node = graph_glue_to_node(current);
    if (strncmp(node->node_name, node_name, NODE_NAME_SIZE) == 0)
      return node;
    return NULL;
  }
  ITERATE_GLTHREAD_END(&topology->node_list, current);
}
// Instructor Example:
// static inline node_t  *get_node_by_node_name(graph_t *topology, char *node_name)
// {
//   glthread_t      *current;
//   node_t          *node;
  
//   ITERATE_GLTHREAD_BEGIN(&topology->node_list, current)
//   {
//     if(strncmp(node->node_name, node_name) == 0)
//       return node;
//     return -1;
//   }
//   ITERATE_GLTHREAD_END(&topology->node_list, current);
// }
// Display Routines
void  dump_graph(graph_t *graph);

void  dump_node(node_t *node);

void  dump_interface(interface_t *interface);

#endif // __GRAPH_H__
