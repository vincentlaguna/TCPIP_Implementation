#include  <stdio.h>
#include  <memory.h>
#include  "graph.h"
#include  "utils.h"

// Random number generator
static unsigned int hash_code(void *ptr, unsigned int size)
{
  unsigned int value = 0, i = 0;
  char *str = (char *)ptr;
  
  while(i < size)
  {
    value += *str;
    value *= 97;
    str++;
    i++;
  }
  return value;
}

// Heuristics; Assign a unique MAC address to interface
void  interface_assign_mac_address(interface_t *interface)
{
  node_t *node = interface->att_node;
  int if_size  = sizeof(interface_t);
  
  if(!node)
    return;
  
  unsigned int hash_code_value = 0;
  hash_code_value   =   hash_code(node->node_name, NODE_NAME_SIZE);
  hash_code_value  *=   hash_code(interface->if_name, IF_NAME_SIZE);
  memset(IF_MAC(interface), 0, sizeof(IF_MAC(interface)));
  memcpy(IF_MAC(interface), (char *)&hash_code_value, sizeof(unsigned int));
  memset(IF_MAC(interface), 0, if_size); // <- Questionable... 081322
  // Need to review the following - Don't know when or why I put this here?... 081322
  strcpy(IF_MAC(interface), interface->att_node->node_name);
  strcat(IF_MAC(interface), interface->if_name);
}

bool_t  node_set_device_type(node_t *node, unsigned int F)
{
  SET_BIT(node->node_nw_prop.flags, F);
  return TRUE;
}

bool_t  node_set_loopback_address(node_t *node, char *ip_addr)
{
  assert(ip_addr);
  
  if(IS_BIT_SET(node->node_nw_prop.flags, HUB))
    assert(0); // Wrong cfg: No IP addreses on HUB
  
  if(!IS_BIT_SET(node->node_nw_prop.flags, L3_ROUTER))
    assert(0); // Must enable L3 routing first
  
  node->node_nw_prop.is_lb_addr_config = TRUE;
  strncpy(NODE_LO_ADDR(node), ip_addr, 16);
  NODE_LO_ADDR(node)[15] = '\0';
  
  return TRUE;
}

bool_t  node_set_intf_ip_address(node_t *node, char *local_if,
                                char *ip_addr, char mask)
{
  interface_t *interface = get_node_intf_by_name(node, local_if);
  
  if(!interface) 
    assert(0);
    
  strncpy(IF_IP(interface), ip_addr, 16);
  IF_IP(interface)[15] = '\0';
  interface->intf_nw_props.mask = mask;
  interface->intf_nw_props.is_ipadd_config = TRUE;
  
  return TRUE;
}

bool_t  node_unset_intf_ip_address(node_t *node, char *local_if)
{
  return TRUE;
}

void  dump_node_nw_props(node_t *node)
{
  printf("\nNode Name = %s\n", node->node_name);
  printf("\t node flags : %u", node->node_nw_prop.flags);
  
  if(node->node_nw_prop.is_lb_addr_config)
    printf("\t lo addr : %s/32\n", NODE_LO_ADDR(node));
}

void  dump_intf_props(interface_t *interface)
{
  dump_interface(interface);
  
  if(interface->intf_nw_props.is_ipadd_config)
  {
    printf("\t IP Addr = %s/%u", IF_IP(interface), interface->intf_nw_props.mask);
    
    // printf("\t MAC : %u:%u:%u:%u:%u:%u\n",
    //     IF_MAC(interface)[0], IF_MAC(interface)[1],
    //     IF_MAC(interface)[2], IF_MAC(interface)[3],
    //     IF_MAC(interface)[4], IF_MAC(interface)[5]);
  }
  else
  {
    printf("\t IP Addr = %s/%u", "NULL", 0);
  }
  printf("\t MAC : %u:%u:%u:%u:%u:%u\n",
         IF_MAC(interface)[0], IF_MAC(interface)[1],
         IF_MAC(interface)[2], IF_MAC(interface)[3],
         IF_MAC(interface)[4], IF_MAC(interface)[5]);
}
// Assignment 5.5
// Write a below API in net.c/net.h which shall print the 
// networking properties of all nodes and interfaces in a topology.
// It should also print the name of nbr node on an interface of local node.
// My example:
void  dump_nw_graph(graph_t *graph)
{
  node_t        *node;
  glthread_t    *current;
  interface_t   *interface;
  unsigned int  i;
  
  printf("Topology Name = %s\n", graph->topology_name);
  
  ITERATE_GLTHREAD_BEGIN(&graph->node_list, current)
  {
    node = graph_glue_to_node(current);
    dump_node_nw_props(node);
    
    for(i = 0; i < MAX_INTF_PER_NODE; i++)
    {
      interface = node->intf[i];
      
      if(!interface)
        break;
      dump_intf_props(interface);
    }
  } ITERATE_GLTHREAD_END(&graph->node_list, current);
}
// Assignment 5.4
// Write a below API in net.h/net.c which returns the pointer
// to local interface of a node such that this local interface
// shares the same subnet as that of ip_addr passed as 2nd argument.
// 
// For example :
// For node R0 containing two local interfaces with ip/mask configured 
// as : 40.1.1.1/24 on eth0/4 and 20.1.1.1/24 on eth0/0,  
// this API must return :
// pointer to eth0/4 if ip_addr passed is 40.1.1.x, for all x [0-255]
// pointer to eth0/0 if ip_addr passed is 20.1.1.x, for all x [0-255]
// NULL otherwise.
// My Example:
interface_t  *node_get_matching_subnet_interface(node_t *node, char *ip_addr)
{
  
}
// Assignment 5.6
// Write a function in net.h/net.c which converts an ip address in 
// string form (A.B.C.D format) into its equivalent 32-bit integer form.
// My Example: 
unsigned int  convert_ip_from_str_to_int(char *ip_addr)
{
  
}
// Assignment 5.7
// Write a function in net.h/net.c which converts an ip address in 
// integer form into its equivalent dot decimal form (A.B.C.D format)
// Output should be stored in the array output_buffer of size 16 bytes
// passed as second argument.
// My example:
void  convert_ip_from_int_to_str(unsigned int ip_addr, char *output_buffer)
{
  
}

