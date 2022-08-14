#ifndef               __NET_H__
#define               __NET_H__

#include <memory.h>
#include "utils.h"
// Device ID's
#define L3_ROUTER     (1 << 0)
#define L2_SWITCH     (1 << 1)
#define HUB           (1 << 2)

typedef struct        graph_      graph_t;
typedef struct        interface_  interface_t;
typedef struct        node_       node_t;

typedef struct        ip_add_
{
  char                ip_addr[16];
} ip_add_t;

typedef struct        mac_add_
{
  char                mac[6];
} mac_add_t;

typedef struct        node_nw_prop_
{
  // Used to find various device type capabilities
  // of the node and other features
  unsigned int        flags;
  //L3 Properties
  bool_t              is_lb_addr_config; // If False == no need to 
  //access the lb value below unless true
  ip_add_t            lb_addr; // Loop-back address of node
} node_nw_prop_t;

static inline void  init_node_nw_prop(node_nw_prop_t *node_nw_prop)
{
  node_nw_prop->flags = 0;
  node_nw_prop->is_lb_addr_config = FALSE;
  memset(node_nw_prop->lb_addr.ip_addr, 0, 16);
}

typedef struct        intf_nw_props_
{
  // L2 Properties
  mac_add_t           mac_add; // MAC's are hard-coded into the interface NIC
  // L3 Properties
  // Set to TRUE if ip address is configures, intf operates in L3 mode if ip address is configured on it
  bool_t              is_ipadd_config;
  ip_add_t            ip_add;
  char                mask;
} intf_nw_props_t;

static inline void  init_intf_nw_prop(intf_nw_props_t *intf_nw_props)
{
  memset(intf_nw_props->mac_add.mac, 0, 48);
  intf_nw_props->is_ipadd_config = FALSE;
  memset(intf_nw_props->ip_add.ip_addr, 0, 16);
  intf_nw_props->mask = 0;
}

void interface_assign_mac_address(interface_t *interface);
// Get shorthand Macros
#define  IF_MAC(intf_ptr)       ((intf_ptr)->intf_nw_props.mac_add.mac)
#define  IF_IP(intf_ptr)        ((intf_ptr)->intf_nw_props.ip_add.ip_addr)
#define  NODE_LO_ADDR(node_ptr) (node_ptr->node_nw_prop.lb_addr.ip_addr)
// API's to set Network Node Properties
bool_t  node_set_device_type(node_t *node, unsigned int F);
bool_t  node_set_loopback_address(node_t *node, char *ip_addr);
bool_t  node_set_intf_ip_address(node_t *node, 
                                 char *local_if,
                                 char *ip_addr, 
                                 char mask);
bool_t  node_unset_intf_ip_address(node_t *node, char *local_if);
// Dump Functions to dump network information on nodes and interfaces
void  dump_nw_graph(graph_t *graph);
void  dump_node_nw_props(node_t *node);
void  dump_intf_props(interface_t *interface);
// Assignment 5 prototypes:
interface_t  *node_get_matching_subnet_interface(node_t *node, char *ip_addr);
unsigned int  convert_ip_from_str_to_int(char *ip_addr);
void          convert_ip_from_int_to_str(unsigned int ip_addr, char *output_buffer);

#endif //__NET_H__