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
  //Loop-Back Properties
  bool_t        is_lb_addr_config;
  ip_add_t      lb_addr; // Loop-back address of node
}

#endif //__NET_H__