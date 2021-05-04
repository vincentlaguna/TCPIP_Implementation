#include  <stdio.h>
#include  <memory.h>
#include  "graph.h"
#include  "utils.h"
// Heuristics; Assign a unique MAC address to interface
void  interface_assign_mac_address(interface_t *interface)
{
  memset(IF_MAC(interface), 0, 48);
  strcpy(IF_MAC(interface), interface->att_node->node_name);
  strcat(IF_MAC(interface), interface->if_name);
}

bool_t  node_set_device_type(node_t *node, unsigned int F)
{
  SET_BIT(node->node_nw_prop.flags, F);
  return TRUE;
}

bool_t  node_set_loopback_address(node_t *node, char ip_addr)
{
  assert(ip_addr);
  node->node_nw_prop.is_lb_addr_config = TRUE;
  strncpy(NODE_LO_ADDR(node), ip_addr, 16);
  NODE_LO_ADDR(node)[15] = '\0';
  
  return TRUE;
}

bool_t  node_set_intf_ip_address(node_t *node, char *local_if,
                                char ip_addr, char mask)
{
  
}void   dump_node_nw_props(node_t *node)
{
  
}

void    dump_intf_props(interface_t *interface)
{
  
}

void  dump_nw_graph(graph_t *graph)
{
  
}