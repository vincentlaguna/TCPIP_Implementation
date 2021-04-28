#ifndef  __NET_H__
#define  __NET_H__

typedef struct  ip_add_
{
  char          ip_addr[16];
} ip_add_t;

typedef struct  mac_add_
{
  char          mac[48];
} mac_add_t;

typedef struct  node_nw_prop_
{
  //L3 Properties
  bool_t        is_lb_addr_config;
  ip_add_t      lb_addr; // Loop-back address of node
} node_nw_prop_t;

static inline void  init_node_nw_prop(node_nw_prop_t *node_nw_prop)
{
  node_nw_prop->flags = 0;
  node_nw_prop->is_lb_addr_config = FALSE;
  memset(node_nw_prop->lb_addr.ip_addr, 0, 16);
}



#endif //__NET_H__