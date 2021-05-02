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
  
}

bool_t  node_set_loopback_address(node_t *node, char ip_addr)
{
  
}

