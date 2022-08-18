pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with netinet_in_h;

package x86_64_linux_gnu_bits_in_h is

   IP_OPTIONS : constant := 4;  --  /usr/include/x86_64-linux-gnu/bits/in.h:47
   IP_HDRINCL : constant := 3;  --  /usr/include/x86_64-linux-gnu/bits/in.h:48
   IP_TOS : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/in.h:49
   IP_TTL : constant := 2;  --  /usr/include/x86_64-linux-gnu/bits/in.h:50
   IP_RECVOPTS : constant := 6;  --  /usr/include/x86_64-linux-gnu/bits/in.h:51
   --  unsupported macro: IP_RECVRETOPTS IP_RETOPTS

   IP_RETOPTS : constant := 7;  --  /usr/include/x86_64-linux-gnu/bits/in.h:54

   MCAST_JOIN_GROUP : constant := 42;  --  /usr/include/x86_64-linux-gnu/bits/in.h:66
   MCAST_BLOCK_SOURCE : constant := 43;  --  /usr/include/x86_64-linux-gnu/bits/in.h:67
   MCAST_UNBLOCK_SOURCE : constant := 44;  --  /usr/include/x86_64-linux-gnu/bits/in.h:68
   MCAST_LEAVE_GROUP : constant := 45;  --  /usr/include/x86_64-linux-gnu/bits/in.h:69
   MCAST_JOIN_SOURCE_GROUP : constant := 46;  --  /usr/include/x86_64-linux-gnu/bits/in.h:70
   MCAST_LEAVE_SOURCE_GROUP : constant := 47;  --  /usr/include/x86_64-linux-gnu/bits/in.h:71
   MCAST_MSFILTER : constant := 48;  --  /usr/include/x86_64-linux-gnu/bits/in.h:72

   MCAST_EXCLUDE : constant := 0;  --  /usr/include/x86_64-linux-gnu/bits/in.h:76
   MCAST_INCLUDE : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/in.h:77

   IP_ROUTER_ALERT : constant := 5;  --  /usr/include/x86_64-linux-gnu/bits/in.h:80
   IP_PKTINFO : constant := 8;  --  /usr/include/x86_64-linux-gnu/bits/in.h:81
   IP_PKTOPTIONS : constant := 9;  --  /usr/include/x86_64-linux-gnu/bits/in.h:82
   IP_PMTUDISC : constant := 10;  --  /usr/include/x86_64-linux-gnu/bits/in.h:83
   IP_MTU_DISCOVER : constant := 10;  --  /usr/include/x86_64-linux-gnu/bits/in.h:84
   IP_RECVERR : constant := 11;  --  /usr/include/x86_64-linux-gnu/bits/in.h:85
   IP_RECVTTL : constant := 12;  --  /usr/include/x86_64-linux-gnu/bits/in.h:86
   IP_RECVTOS : constant := 13;  --  /usr/include/x86_64-linux-gnu/bits/in.h:87
   IP_MTU : constant := 14;  --  /usr/include/x86_64-linux-gnu/bits/in.h:88
   IP_FREEBIND : constant := 15;  --  /usr/include/x86_64-linux-gnu/bits/in.h:89
   IP_IPSEC_POLICY : constant := 16;  --  /usr/include/x86_64-linux-gnu/bits/in.h:90
   IP_XFRM_POLICY : constant := 17;  --  /usr/include/x86_64-linux-gnu/bits/in.h:91
   IP_PASSSEC : constant := 18;  --  /usr/include/x86_64-linux-gnu/bits/in.h:92
   IP_TRANSPARENT : constant := 19;  --  /usr/include/x86_64-linux-gnu/bits/in.h:93

   IP_ORIGDSTADDR : constant := 20;  --  /usr/include/x86_64-linux-gnu/bits/in.h:97
   --  unsupported macro: IP_RECVORIGDSTADDR IP_ORIGDSTADDR

   IP_MINTTL : constant := 21;  --  /usr/include/x86_64-linux-gnu/bits/in.h:100
   IP_NODEFRAG : constant := 22;  --  /usr/include/x86_64-linux-gnu/bits/in.h:101
   IP_CHECKSUM : constant := 23;  --  /usr/include/x86_64-linux-gnu/bits/in.h:102
   IP_BIND_ADDRESS_NO_PORT : constant := 24;  --  /usr/include/x86_64-linux-gnu/bits/in.h:103
   IP_RECVFRAGSIZE : constant := 25;  --  /usr/include/x86_64-linux-gnu/bits/in.h:104

   IP_PMTUDISC_DONT : constant := 0;  --  /usr/include/x86_64-linux-gnu/bits/in.h:107
   IP_PMTUDISC_WANT : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/in.h:108
   IP_PMTUDISC_DO : constant := 2;  --  /usr/include/x86_64-linux-gnu/bits/in.h:109
   IP_PMTUDISC_PROBE : constant := 3;  --  /usr/include/x86_64-linux-gnu/bits/in.h:110

   IP_PMTUDISC_INTERFACE : constant := 4;  --  /usr/include/x86_64-linux-gnu/bits/in.h:114

   IP_PMTUDISC_OMIT : constant := 5;  --  /usr/include/x86_64-linux-gnu/bits/in.h:116

   IP_MULTICAST_IF : constant := 32;  --  /usr/include/x86_64-linux-gnu/bits/in.h:118
   IP_MULTICAST_TTL : constant := 33;  --  /usr/include/x86_64-linux-gnu/bits/in.h:119
   IP_MULTICAST_LOOP : constant := 34;  --  /usr/include/x86_64-linux-gnu/bits/in.h:120
   IP_ADD_MEMBERSHIP : constant := 35;  --  /usr/include/x86_64-linux-gnu/bits/in.h:121
   IP_DROP_MEMBERSHIP : constant := 36;  --  /usr/include/x86_64-linux-gnu/bits/in.h:122
   IP_UNBLOCK_SOURCE : constant := 37;  --  /usr/include/x86_64-linux-gnu/bits/in.h:123
   IP_BLOCK_SOURCE : constant := 38;  --  /usr/include/x86_64-linux-gnu/bits/in.h:124
   IP_ADD_SOURCE_MEMBERSHIP : constant := 39;  --  /usr/include/x86_64-linux-gnu/bits/in.h:125
   IP_DROP_SOURCE_MEMBERSHIP : constant := 40;  --  /usr/include/x86_64-linux-gnu/bits/in.h:126
   IP_MSFILTER : constant := 41;  --  /usr/include/x86_64-linux-gnu/bits/in.h:127
   IP_MULTICAST_ALL : constant := 49;  --  /usr/include/x86_64-linux-gnu/bits/in.h:128
   IP_UNICAST_IF : constant := 50;  --  /usr/include/x86_64-linux-gnu/bits/in.h:129

   SOL_IP : constant := 0;  --  /usr/include/x86_64-linux-gnu/bits/in.h:132

   IP_DEFAULT_MULTICAST_TTL : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/in.h:134
   IP_DEFAULT_MULTICAST_LOOP : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/in.h:135
   IP_MAX_MEMBERSHIPS : constant := 20;  --  /usr/include/x86_64-linux-gnu/bits/in.h:136

   IPV6_ADDRFORM : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/in.h:168
   IPV6_2292PKTINFO : constant := 2;  --  /usr/include/x86_64-linux-gnu/bits/in.h:169
   IPV6_2292HOPOPTS : constant := 3;  --  /usr/include/x86_64-linux-gnu/bits/in.h:170
   IPV6_2292DSTOPTS : constant := 4;  --  /usr/include/x86_64-linux-gnu/bits/in.h:171
   IPV6_2292RTHDR : constant := 5;  --  /usr/include/x86_64-linux-gnu/bits/in.h:172
   IPV6_2292PKTOPTIONS : constant := 6;  --  /usr/include/x86_64-linux-gnu/bits/in.h:173
   IPV6_CHECKSUM : constant := 7;  --  /usr/include/x86_64-linux-gnu/bits/in.h:174
   IPV6_2292HOPLIMIT : constant := 8;  --  /usr/include/x86_64-linux-gnu/bits/in.h:175
   --  unsupported macro: SCM_SRCRT IPV6_RXSRCRT

   IPV6_NEXTHOP : constant := 9;  --  /usr/include/x86_64-linux-gnu/bits/in.h:179
   IPV6_AUTHHDR : constant := 10;  --  /usr/include/x86_64-linux-gnu/bits/in.h:180
   IPV6_UNICAST_HOPS : constant := 16;  --  /usr/include/x86_64-linux-gnu/bits/in.h:181
   IPV6_MULTICAST_IF : constant := 17;  --  /usr/include/x86_64-linux-gnu/bits/in.h:182
   IPV6_MULTICAST_HOPS : constant := 18;  --  /usr/include/x86_64-linux-gnu/bits/in.h:183
   IPV6_MULTICAST_LOOP : constant := 19;  --  /usr/include/x86_64-linux-gnu/bits/in.h:184
   IPV6_JOIN_GROUP : constant := 20;  --  /usr/include/x86_64-linux-gnu/bits/in.h:185
   IPV6_LEAVE_GROUP : constant := 21;  --  /usr/include/x86_64-linux-gnu/bits/in.h:186
   IPV6_ROUTER_ALERT : constant := 22;  --  /usr/include/x86_64-linux-gnu/bits/in.h:187
   IPV6_MTU_DISCOVER : constant := 23;  --  /usr/include/x86_64-linux-gnu/bits/in.h:188
   IPV6_MTU : constant := 24;  --  /usr/include/x86_64-linux-gnu/bits/in.h:189
   IPV6_RECVERR : constant := 25;  --  /usr/include/x86_64-linux-gnu/bits/in.h:190
   IPV6_V6ONLY : constant := 26;  --  /usr/include/x86_64-linux-gnu/bits/in.h:191
   IPV6_JOIN_ANYCAST : constant := 27;  --  /usr/include/x86_64-linux-gnu/bits/in.h:192
   IPV6_LEAVE_ANYCAST : constant := 28;  --  /usr/include/x86_64-linux-gnu/bits/in.h:193
   IPV6_MULTICAST_ALL : constant := 29;  --  /usr/include/x86_64-linux-gnu/bits/in.h:194
   IPV6_ROUTER_ALERT_ISOLATE : constant := 30;  --  /usr/include/x86_64-linux-gnu/bits/in.h:195
   IPV6_IPSEC_POLICY : constant := 34;  --  /usr/include/x86_64-linux-gnu/bits/in.h:196
   IPV6_XFRM_POLICY : constant := 35;  --  /usr/include/x86_64-linux-gnu/bits/in.h:197
   IPV6_HDRINCL : constant := 36;  --  /usr/include/x86_64-linux-gnu/bits/in.h:198

   IPV6_RECVPKTINFO : constant := 49;  --  /usr/include/x86_64-linux-gnu/bits/in.h:201
   IPV6_PKTINFO : constant := 50;  --  /usr/include/x86_64-linux-gnu/bits/in.h:202
   IPV6_RECVHOPLIMIT : constant := 51;  --  /usr/include/x86_64-linux-gnu/bits/in.h:203
   IPV6_HOPLIMIT : constant := 52;  --  /usr/include/x86_64-linux-gnu/bits/in.h:204
   IPV6_RECVHOPOPTS : constant := 53;  --  /usr/include/x86_64-linux-gnu/bits/in.h:205
   IPV6_HOPOPTS : constant := 54;  --  /usr/include/x86_64-linux-gnu/bits/in.h:206
   IPV6_RTHDRDSTOPTS : constant := 55;  --  /usr/include/x86_64-linux-gnu/bits/in.h:207
   IPV6_RECVRTHDR : constant := 56;  --  /usr/include/x86_64-linux-gnu/bits/in.h:208
   IPV6_RTHDR : constant := 57;  --  /usr/include/x86_64-linux-gnu/bits/in.h:209
   IPV6_RECVDSTOPTS : constant := 58;  --  /usr/include/x86_64-linux-gnu/bits/in.h:210
   IPV6_DSTOPTS : constant := 59;  --  /usr/include/x86_64-linux-gnu/bits/in.h:211
   IPV6_RECVPATHMTU : constant := 60;  --  /usr/include/x86_64-linux-gnu/bits/in.h:212
   IPV6_PATHMTU : constant := 61;  --  /usr/include/x86_64-linux-gnu/bits/in.h:213
   IPV6_DONTFRAG : constant := 62;  --  /usr/include/x86_64-linux-gnu/bits/in.h:214

   IPV6_RECVTCLASS : constant := 66;  --  /usr/include/x86_64-linux-gnu/bits/in.h:217
   IPV6_TCLASS : constant := 67;  --  /usr/include/x86_64-linux-gnu/bits/in.h:218

   IPV6_AUTOFLOWLABEL : constant := 70;  --  /usr/include/x86_64-linux-gnu/bits/in.h:220

   IPV6_ADDR_PREFERENCES : constant := 72;  --  /usr/include/x86_64-linux-gnu/bits/in.h:223

   IPV6_MINHOPCOUNT : constant := 73;  --  /usr/include/x86_64-linux-gnu/bits/in.h:226

   IPV6_ORIGDSTADDR : constant := 74;  --  /usr/include/x86_64-linux-gnu/bits/in.h:228
   --  unsupported macro: IPV6_RECVORIGDSTADDR IPV6_ORIGDSTADDR

   IPV6_TRANSPARENT : constant := 75;  --  /usr/include/x86_64-linux-gnu/bits/in.h:230
   IPV6_UNICAST_IF : constant := 76;  --  /usr/include/x86_64-linux-gnu/bits/in.h:231
   IPV6_RECVFRAGSIZE : constant := 77;  --  /usr/include/x86_64-linux-gnu/bits/in.h:232
   IPV6_FREEBIND : constant := 78;  --  /usr/include/x86_64-linux-gnu/bits/in.h:233
   --  unsupported macro: IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
   --  unsupported macro: IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
   --  unsupported macro: IPV6_RXHOPOPTS IPV6_HOPOPTS
   --  unsupported macro: IPV6_RXDSTOPTS IPV6_DSTOPTS

   IPV6_PMTUDISC_DONT : constant := 0;  --  /usr/include/x86_64-linux-gnu/bits/in.h:244
   IPV6_PMTUDISC_WANT : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/in.h:245
   IPV6_PMTUDISC_DO : constant := 2;  --  /usr/include/x86_64-linux-gnu/bits/in.h:246
   IPV6_PMTUDISC_PROBE : constant := 3;  --  /usr/include/x86_64-linux-gnu/bits/in.h:247
   IPV6_PMTUDISC_INTERFACE : constant := 4;  --  /usr/include/x86_64-linux-gnu/bits/in.h:248
   IPV6_PMTUDISC_OMIT : constant := 5;  --  /usr/include/x86_64-linux-gnu/bits/in.h:249

   SOL_IPV6 : constant := 41;  --  /usr/include/x86_64-linux-gnu/bits/in.h:252
   SOL_ICMPV6 : constant := 58;  --  /usr/include/x86_64-linux-gnu/bits/in.h:253

   IPV6_RTHDR_LOOSE : constant := 0;  --  /usr/include/x86_64-linux-gnu/bits/in.h:256
   IPV6_RTHDR_STRICT : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/in.h:257

   IPV6_RTHDR_TYPE_0 : constant := 0;  --  /usr/include/x86_64-linux-gnu/bits/in.h:259

   subtype anon1089_ip_opts_array is Interfaces.C.char_array (0 .. 39);
   type ip_opts is record
      ip_dst : aliased netinet_in_h.in_addr;  -- /usr/include/x86_64-linux-gnu/bits/in.h:144
      ip_opts : aliased anon1089_ip_opts_array;  -- /usr/include/x86_64-linux-gnu/bits/in.h:145
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/x86_64-linux-gnu/bits/in.h:142

   type ip_mreqn is record
      imr_multiaddr : aliased netinet_in_h.in_addr;  -- /usr/include/x86_64-linux-gnu/bits/in.h:151
      imr_address : aliased netinet_in_h.in_addr;  -- /usr/include/x86_64-linux-gnu/bits/in.h:152
      imr_ifindex : aliased int;  -- /usr/include/x86_64-linux-gnu/bits/in.h:153
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/x86_64-linux-gnu/bits/in.h:149

   type in_pktinfo is record
      ipi_ifindex : aliased int;  -- /usr/include/x86_64-linux-gnu/bits/in.h:159
      ipi_spec_dst : aliased netinet_in_h.in_addr;  -- /usr/include/x86_64-linux-gnu/bits/in.h:160
      ipi_addr : aliased netinet_in_h.in_addr;  -- /usr/include/x86_64-linux-gnu/bits/in.h:161
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/x86_64-linux-gnu/bits/in.h:157

end x86_64_linux_gnu_bits_in_h;
