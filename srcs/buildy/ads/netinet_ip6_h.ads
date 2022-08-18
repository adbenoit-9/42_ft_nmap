pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;
with netinet_in_h;

package netinet_ip6_h is

   --  unsupported macro: ip6_vfc ip6_ctlun.ip6_un2_vfc
   --  unsupported macro: ip6_flow ip6_ctlun.ip6_un1.ip6_un1_flow
   --  unsupported macro: ip6_plen ip6_ctlun.ip6_un1.ip6_un1_plen
   --  unsupported macro: ip6_nxt ip6_ctlun.ip6_un1.ip6_un1_nxt
   --  unsupported macro: ip6_hlim ip6_ctlun.ip6_un1.ip6_un1_hlim
   --  unsupported macro: ip6_hops ip6_ctlun.ip6_un1.ip6_un1_hlim
   IP6F_OFF_MASK : constant := 16#f8ff#;  --  /usr/include/netinet/ip6.h:109
   IP6F_RESERVED_MASK : constant := 16#0600#;  --  /usr/include/netinet/ip6.h:110
   IP6F_MORE_FRAG : constant := 16#0100#;  --  /usr/include/netinet/ip6.h:111
   --  arg-macro: function IP6OPT_TYPE (o)
   --    return (o) and 16#c0#;

   IP6OPT_TYPE_SKIP : constant := 16#00#;  --  /usr/include/netinet/ip6.h:126
   IP6OPT_TYPE_DISCARD : constant := 16#40#;  --  /usr/include/netinet/ip6.h:127
   IP6OPT_TYPE_FORCEICMP : constant := 16#80#;  --  /usr/include/netinet/ip6.h:128
   IP6OPT_TYPE_ICMP : constant := 16#c0#;  --  /usr/include/netinet/ip6.h:129
   IP6OPT_TYPE_MUTABLE : constant := 16#20#;  --  /usr/include/netinet/ip6.h:130

   IP6OPT_PAD1 : constant := 0;  --  /usr/include/netinet/ip6.h:133
   IP6OPT_PADN : constant := 1;  --  /usr/include/netinet/ip6.h:134

   IP6OPT_JUMBO : constant := 16#c2#;  --  /usr/include/netinet/ip6.h:136
   IP6OPT_NSAP_ADDR : constant := 16#c3#;  --  /usr/include/netinet/ip6.h:137
   IP6OPT_TUNNEL_LIMIT : constant := 16#04#;  --  /usr/include/netinet/ip6.h:138
   IP6OPT_ROUTER_ALERT : constant := 16#05#;  --  /usr/include/netinet/ip6.h:139

   IP6OPT_JUMBO_LEN : constant := 6;  --  /usr/include/netinet/ip6.h:148

   IP6_ALERT_MLD : constant := 16#0000#;  --  /usr/include/netinet/ip6.h:183
   IP6_ALERT_RSVP : constant := 16#0100#;  --  /usr/include/netinet/ip6.h:184
   IP6_ALERT_AN : constant := 16#0200#;  --  /usr/include/netinet/ip6.h:185

   type ip6_hdrctl is record
      ip6_un1_flow : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/ip6.h:30
      ip6_un1_plen : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/ip6.h:32
      ip6_un1_nxt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:33
      ip6_un1_hlim : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:34
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:28

   type anon1179_ip6_ctlun_union (discr : unsigned := 0) is record
      case discr is
         when 0 =>
            ip6_un1 : aliased ip6_hdrctl;  -- /usr/include/netinet/ip6.h:35
         when others =>
            ip6_un2_vfc : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:36
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;
   type ip6_hdr is record
      ip6_ctlun : aliased anon1179_ip6_ctlun_union;  -- /usr/include/netinet/ip6.h:37
      ip6_src : aliased netinet_in_h.in6_addr;  -- /usr/include/netinet/ip6.h:38
      ip6_dst : aliased netinet_in_h.in6_addr;  -- /usr/include/netinet/ip6.h:39
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:24

   type ip6_ext is record
      ip6e_nxt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:52
      ip6e_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:53
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:50

   type ip6_hbh is record
      ip6h_nxt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:59
      ip6h_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:60
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:57

   type ip6_dest is record
      ip6d_nxt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:67
      ip6d_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:68
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:65

   type ip6_rthdr is record
      ip6r_nxt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:75
      ip6r_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:76
      ip6r_type : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:77
      ip6r_segleft : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:78
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:73

   type anon1186_ip6r0_slmap_array is array (0 .. 2) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type anon1186_ip6r0_addr_array is array (0 .. 0) of aliased netinet_in_h.in6_addr;
   type ip6_rthdr0 is record
      ip6r0_nxt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:85
      ip6r0_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:86
      ip6r0_type : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:87
      ip6r0_segleft : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:88
      ip6r0_reserved : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:89
      ip6r0_slmap : aliased anon1186_ip6r0_slmap_array;  -- /usr/include/netinet/ip6.h:90
      ip6r0_addr : aliased anon1186_ip6r0_addr_array;  -- /usr/include/netinet/ip6.h:92
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:83

   type ip6_frag is record
      ip6f_nxt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:98
      ip6f_reserved : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:99
      ip6f_offlg : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/ip6.h:100
      ip6f_ident : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/ip6.h:101
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:96

   type ip6_opt is record
      ip6o_type : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:117
      ip6o_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:118
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:115

   type anon1194_ip6oj_jumbo_len_array is array (0 .. 3) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type ip6_opt_jumbo is record
      ip6oj_type : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:144
      ip6oj_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:145
      ip6oj_jumbo_len : aliased anon1194_ip6oj_jumbo_len_array;  -- /usr/include/netinet/ip6.h:146
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:142

   type ip6_opt_nsap is record
      ip6on_type : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:153
      ip6on_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:154
      ip6on_src_nsap_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:155
      ip6on_dst_nsap_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:156
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:151

   type ip6_opt_tunnel is record
      ip6ot_type : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:164
      ip6ot_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:165
      ip6ot_encap_limit : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:166
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:162

   type anon1199_ip6or_value_array is array (0 .. 1) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type ip6_opt_router is record
      ip6or_type : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:172
      ip6or_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip6.h:173
      ip6or_value : aliased anon1199_ip6or_value_array;  -- /usr/include/netinet/ip6.h:174
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/ip6.h:170

end netinet_ip6_h;
