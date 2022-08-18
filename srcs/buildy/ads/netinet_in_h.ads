pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;
with x86_64_linux_gnu_bits_sockaddr_h;
with x86_64_linux_gnu_bits_socket_h;

package netinet_in_h is

   --  unsupported macro: IPPROTO_IP IPPROTO_IP
   --  unsupported macro: IPPROTO_ICMP IPPROTO_ICMP
   --  unsupported macro: IPPROTO_IGMP IPPROTO_IGMP
   --  unsupported macro: IPPROTO_IPIP IPPROTO_IPIP
   --  unsupported macro: IPPROTO_TCP IPPROTO_TCP
   --  unsupported macro: IPPROTO_EGP IPPROTO_EGP
   --  unsupported macro: IPPROTO_PUP IPPROTO_PUP
   --  unsupported macro: IPPROTO_UDP IPPROTO_UDP
   --  unsupported macro: IPPROTO_IDP IPPROTO_IDP
   --  unsupported macro: IPPROTO_TP IPPROTO_TP
   --  unsupported macro: IPPROTO_DCCP IPPROTO_DCCP
   --  unsupported macro: IPPROTO_IPV6 IPPROTO_IPV6
   --  unsupported macro: IPPROTO_RSVP IPPROTO_RSVP
   --  unsupported macro: IPPROTO_GRE IPPROTO_GRE
   --  unsupported macro: IPPROTO_ESP IPPROTO_ESP
   --  unsupported macro: IPPROTO_AH IPPROTO_AH
   --  unsupported macro: IPPROTO_MTP IPPROTO_MTP
   --  unsupported macro: IPPROTO_BEETPH IPPROTO_BEETPH
   --  unsupported macro: IPPROTO_ENCAP IPPROTO_ENCAP
   --  unsupported macro: IPPROTO_PIM IPPROTO_PIM
   --  unsupported macro: IPPROTO_COMP IPPROTO_COMP
   --  unsupported macro: IPPROTO_SCTP IPPROTO_SCTP
   --  unsupported macro: IPPROTO_UDPLITE IPPROTO_UDPLITE
   --  unsupported macro: IPPROTO_MPLS IPPROTO_MPLS
   --  unsupported macro: IPPROTO_RAW IPPROTO_RAW
   --  unsupported macro: IPPROTO_HOPOPTS IPPROTO_HOPOPTS
   --  unsupported macro: IPPROTO_ROUTING IPPROTO_ROUTING
   --  unsupported macro: IPPROTO_FRAGMENT IPPROTO_FRAGMENT
   --  unsupported macro: IPPROTO_ICMPV6 IPPROTO_ICMPV6
   --  unsupported macro: IPPROTO_NONE IPPROTO_NONE
   --  unsupported macro: IPPROTO_DSTOPTS IPPROTO_DSTOPTS
   --  unsupported macro: IPPROTO_MH IPPROTO_MH
   --  arg-macro: function IN_CLASSA (a)
   --    return (((in_addr_t)(a)) and 16#80000000#) = 0;
   IN_CLASSA_NET : constant := 16#ff000000#;  --  /usr/include/netinet/in.h:167
   IN_CLASSA_NSHIFT : constant := 24;  --  /usr/include/netinet/in.h:168
   --  unsupported macro: IN_CLASSA_HOST (0xffffffff & ~IN_CLASSA_NET)

   IN_CLASSA_MAX : constant := 128;  --  /usr/include/netinet/in.h:170
   --  arg-macro: function IN_CLASSB (a)
   --    return (((in_addr_t)(a)) and 16#c0000000#) = 16#80000000#;

   IN_CLASSB_NET : constant := 16#ffff0000#;  --  /usr/include/netinet/in.h:173
   IN_CLASSB_NSHIFT : constant := 16;  --  /usr/include/netinet/in.h:174
   --  unsupported macro: IN_CLASSB_HOST (0xffffffff & ~IN_CLASSB_NET)

   IN_CLASSB_MAX : constant := 65536;  --  /usr/include/netinet/in.h:176
   --  arg-macro: function IN_CLASSC (a)
   --    return (((in_addr_t)(a)) and 16#e0000000#) = 16#c0000000#;

   IN_CLASSC_NET : constant := 16#ffffff00#;  --  /usr/include/netinet/in.h:179
   IN_CLASSC_NSHIFT : constant := 8;  --  /usr/include/netinet/in.h:180
   --  unsupported macro: IN_CLASSC_HOST (0xffffffff & ~IN_CLASSC_NET)
   --  arg-macro: function IN_CLASSD (a)
   --    return (((in_addr_t)(a)) and 16#f0000000#) = 16#e0000000#;
   --  arg-macro: procedure IN_MULTICAST (a)
   --    IN_CLASSD(a)
   --  arg-macro: function IN_EXPERIMENTAL (a)
   --    return (((in_addr_t)(a)) and 16#e0000000#) = 16#e0000000#;
   --  arg-macro: function IN_BADCLASS (a)
   --    return (((in_addr_t)(a)) and 16#f0000000#) = 16#f0000000#;
   --  unsupported macro: INADDR_ANY ((in_addr_t) 0x00000000)
   --  unsupported macro: INADDR_BROADCAST ((in_addr_t) 0xffffffff)
   --  unsupported macro: INADDR_NONE ((in_addr_t) 0xffffffff)

   IN_LOOPBACKNET : constant := 127;  --  /usr/include/netinet/in.h:197
   --  unsupported macro: INADDR_LOOPBACK ((in_addr_t) 0x7f000001)
   --  unsupported macro: INADDR_UNSPEC_GROUP ((in_addr_t) 0xe0000000)
   --  unsupported macro: INADDR_ALLHOSTS_GROUP ((in_addr_t) 0xe0000001)
   --  unsupported macro: INADDR_ALLRTRS_GROUP ((in_addr_t) 0xe0000002)
   --  unsupported macro: INADDR_ALLSNOOPERS_GROUP ((in_addr_t) 0xe000006a)
   --  unsupported macro: INADDR_MAX_LOCAL_GROUP ((in_addr_t) 0xe00000ff)
   --  unsupported macro: s6_addr __in6_u.__u6_addr8
   --  unsupported macro: s6_addr16 __in6_u.__u6_addr16
   --  unsupported macro: s6_addr32 __in6_u.__u6_addr32
   --  unsupported macro: IN6ADDR_ANY_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } } }
   --  unsupported macro: IN6ADDR_LOOPBACK_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } } }

   INET_ADDRSTRLEN : constant := 16;  --  /usr/include/netinet/in.h:233
   INET6_ADDRSTRLEN : constant := 46;  --  /usr/include/netinet/in.h:234
   --  arg-macro: function IP_MSFILTER_SIZE (numsrc)
   --    return sizeof (struct ip_msfilter) - sizeof (struct in_addr) + (numsrc) * sizeof (struct in_addr);
   --  arg-macro: function GROUP_FILTER_SIZE (numsrc)
   --    return sizeof (struct group_filter) - sizeof (struct sockaddr_storage) + ((numsrc) * sizeof (struct sockaddr_storage));
   --  arg-macro: function IN6_IS_ADDR_UNSPECIFIED (a)
   --    return __extension__ ({ const struct in6_addr *__a := (const struct in6_addr *) (a); __a.__in6_u.__u6_addr32(0) = 0  and then  __a.__in6_u.__u6_addr32(1) = 0  and then  __a.__in6_u.__u6_addr32(2) = 0  and then  __a.__in6_u.__u6_addr32(3) = 0; });
   --  arg-macro: function IN6_IS_ADDR_LOOPBACK (a)
   --    return __extension__ ({ const struct in6_addr *__a := (const struct in6_addr *) (a); __a.__in6_u.__u6_addr32(0) = 0  and then  __a.__in6_u.__u6_addr32(1) = 0  and then  __a.__in6_u.__u6_addr32(2) = 0  and then  __a.__in6_u.__u6_addr32(3) = htonl (1); });
   --  arg-macro: function IN6_IS_ADDR_LINKLOCAL (a)
   --    return __extension__ ({ const struct in6_addr *__a := (const struct in6_addr *) (a); (__a.__in6_u.__u6_addr32(0) and htonl (16#ffc00000#)) = htonl (16#fe800000#); });
   --  arg-macro: function IN6_IS_ADDR_SITELOCAL (a)
   --    return __extension__ ({ const struct in6_addr *__a := (const struct in6_addr *) (a); (__a.__in6_u.__u6_addr32(0) and htonl (16#ffc00000#)) = htonl (16#fec00000#); });
   --  arg-macro: function IN6_IS_ADDR_V4MAPPED (a)
   --    return __extension__ ({ const struct in6_addr *__a := (const struct in6_addr *) (a); __a.__in6_u.__u6_addr32(0) = 0  and then  __a.__in6_u.__u6_addr32(1) = 0  and then  __a.__in6_u.__u6_addr32(2) = htonl (16#ffff#); });
   --  arg-macro: function IN6_IS_ADDR_V4COMPAT (a)
   --    return __extension__ ({ const struct in6_addr *__a := (const struct in6_addr *) (a); __a.__in6_u.__u6_addr32(0) = 0  and then  __a.__in6_u.__u6_addr32(1) = 0  and then  __a.__in6_u.__u6_addr32(2) = 0  and then  ntohl (__a.__in6_u.__u6_addr32(3)) > 1; });
   --  arg-macro: function IN6_ARE_ADDR_EQUAL (a, b)
   --    return __extension__ ({ const struct in6_addr *__a := (const struct in6_addr *) (a); const struct in6_addr *__b := (const struct in6_addr *) (b); __a.__in6_u.__u6_addr32(0) = __b.__in6_u.__u6_addr32(0)  and then  __a.__in6_u.__u6_addr32(1) = __b.__in6_u.__u6_addr32(1)  and then  __a.__in6_u.__u6_addr32(2) = __b.__in6_u.__u6_addr32(2)  and then  __a.__in6_u.__u6_addr32(3) = __b.__in6_u.__u6_addr32(3); });
   --  arg-macro: function IN6_IS_ADDR_MULTICAST (a)
   --    return ((const uint8_t *) (a))(0) = 16#ff#;
   --  arg-macro: function IN6_IS_ADDR_MC_NODELOCAL (a)
   --    return IN6_IS_ADDR_MULTICAST(a)  and then  ((((const uint8_t *) (a))(1) and 16#f#) = 16#1#);
   --  arg-macro: function IN6_IS_ADDR_MC_LINKLOCAL (a)
   --    return IN6_IS_ADDR_MULTICAST(a)  and then  ((((const uint8_t *) (a))(1) and 16#f#) = 16#2#);
   --  arg-macro: function IN6_IS_ADDR_MC_SITELOCAL (a)
   --    return IN6_IS_ADDR_MULTICAST(a)  and then  ((((const uint8_t *) (a))(1) and 16#f#) = 16#5#);
   --  arg-macro: function IN6_IS_ADDR_MC_ORGLOCAL (a)
   --    return IN6_IS_ADDR_MULTICAST(a)  and then  ((((const uint8_t *) (a))(1) and 16#f#) = 16#8#);
   --  arg-macro: function IN6_IS_ADDR_MC_GLOBAL (a)
   --    return IN6_IS_ADDR_MULTICAST(a)  and then  ((((const uint8_t *) (a))(1) and 16#f#) = 16#e#);

   subtype in_addr_t is x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:30

   type in_addr is record
      s_addr : aliased in_addr_t;  -- /usr/include/netinet/in.h:33
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:31

   subtype in_port_t is x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/in.h:119

   type anon1096_uu_u6_addr8_array is array (0 .. 15) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type anon1096_uu_u6_addr16_array is array (0 .. 7) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;
   type anon1096_uu_u6_addr32_array is array (0 .. 3) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;
   type anon1096_uu_in6_u_union (discr : unsigned := 0) is record
      case discr is
         when 0 =>
            uu_u6_addr8 : aliased anon1096_uu_u6_addr8_array;  -- /usr/include/netinet/in.h:216
         when 1 =>
            uu_u6_addr16 : aliased anon1096_uu_u6_addr16_array;  -- /usr/include/netinet/in.h:217
         when others =>
            uu_u6_addr32 : aliased anon1096_uu_u6_addr32_array;  -- /usr/include/netinet/in.h:218
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;
   type in6_addr is record
      uu_in6_u : aliased anon1096_uu_in6_u_union;  -- /usr/include/netinet/in.h:219
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:212

   in6addr_any : aliased constant in6_addr  -- /usr/include/netinet/in.h:228
   with Import => True, 
        Convention => C, 
        External_Name => "in6addr_any";

   in6addr_loopback : aliased constant in6_addr  -- /usr/include/netinet/in.h:229
   with Import => True, 
        Convention => C, 
        External_Name => "in6addr_loopback";

   type anon1105_sin_zero_array is array (0 .. 7) of aliased unsigned_char;
   type sockaddr_in is record
      sin_family : aliased x86_64_linux_gnu_bits_sockaddr_h.sa_family_t;  -- /usr/include/netinet/in.h:240
      sin_port : aliased in_port_t;  -- /usr/include/netinet/in.h:241
      sin_addr : aliased in_addr;  -- /usr/include/netinet/in.h:242
      sin_zero : aliased anon1105_sin_zero_array;  -- /usr/include/netinet/in.h:245
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:238

   type sockaddr_in6 is record
      sin6_family : aliased x86_64_linux_gnu_bits_sockaddr_h.sa_family_t;  -- /usr/include/netinet/in.h:255
      sin6_port : aliased in_port_t;  -- /usr/include/netinet/in.h:256
      sin6_flowinfo : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:257
      sin6_addr : aliased in6_addr;  -- /usr/include/netinet/in.h:258
      sin6_scope_id : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:259
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:253

   type ip_mreq is record
      imr_multiaddr : aliased in_addr;  -- /usr/include/netinet/in.h:268
      imr_interface : aliased in_addr;  -- /usr/include/netinet/in.h:271
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:265

   type ip_mreq_source is record
      imr_multiaddr : aliased in_addr;  -- /usr/include/netinet/in.h:277
      imr_interface : aliased in_addr;  -- /usr/include/netinet/in.h:280
      imr_sourceaddr : aliased in_addr;  -- /usr/include/netinet/in.h:283
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:274

   type ipv6_mreq is record
      ipv6mr_multiaddr : aliased in6_addr;  -- /usr/include/netinet/in.h:292
      ipv6mr_interface : aliased unsigned;  -- /usr/include/netinet/in.h:295
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:289

   type group_req is record
      gr_interface : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:304
      gr_group : aliased x86_64_linux_gnu_bits_socket_h.sockaddr_storage;  -- /usr/include/netinet/in.h:307
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:301

   type group_source_req is record
      gsr_interface : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:313
      gsr_group : aliased x86_64_linux_gnu_bits_socket_h.sockaddr_storage;  -- /usr/include/netinet/in.h:316
      gsr_source : aliased x86_64_linux_gnu_bits_socket_h.sockaddr_storage;  -- /usr/include/netinet/in.h:319
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:310

   type anon1113_imsf_slist_array is array (0 .. 0) of aliased in_addr;
   type ip_msfilter is record
      imsf_multiaddr : aliased in_addr;  -- /usr/include/netinet/in.h:327
      imsf_interface : aliased in_addr;  -- /usr/include/netinet/in.h:330
      imsf_fmode : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:333
      imsf_numsrc : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:336
      imsf_slist : aliased anon1113_imsf_slist_array;  -- /usr/include/netinet/in.h:338
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:324

   type anon1115_gf_slist_array is array (0 .. 0) of aliased x86_64_linux_gnu_bits_socket_h.sockaddr_storage;
   type group_filter is record
      gf_interface : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:348
      gf_group : aliased x86_64_linux_gnu_bits_socket_h.sockaddr_storage;  -- /usr/include/netinet/in.h:351
      gf_fmode : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:354
      gf_numsrc : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/in.h:357
      gf_slist : aliased anon1115_gf_slist_array;  -- /usr/include/netinet/in.h:359
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/in.h:345

   function ntohl (uu_netlong : x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t) return x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t  -- /usr/include/netinet/in.h:375
   with Import => True, 
        Convention => C, 
        External_Name => "ntohl";

   function ntohs (uu_netshort : x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t) return x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t  -- /usr/include/netinet/in.h:376
   with Import => True, 
        Convention => C, 
        External_Name => "ntohs";

   function htonl (uu_hostlong : x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t) return x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t  -- /usr/include/netinet/in.h:378
   with Import => True, 
        Convention => C, 
        External_Name => "htonl";

   function htons (uu_hostshort : x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t) return x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t  -- /usr/include/netinet/in.h:380
   with Import => True, 
        Convention => C, 
        External_Name => "htons";

   function bindresvport (uu_sockfd : int; uu_sock_in : access sockaddr_in) return int  -- /usr/include/netinet/in.h:503
   with Import => True, 
        Convention => C, 
        External_Name => "bindresvport";

   function bindresvport6 (uu_sockfd : int; uu_sock_in : access sockaddr_in6) return int  -- /usr/include/netinet/in.h:506
   with Import => True, 
        Convention => C, 
        External_Name => "bindresvport6";

end netinet_in_h;
