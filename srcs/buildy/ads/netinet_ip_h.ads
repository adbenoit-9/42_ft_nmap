pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;
with Interfaces.C.Extensions;
with netinet_in_h;

package netinet_ip_h is

   IP_RF : constant := 16#8000#;  --  /usr/include/netinet/ip.h:121
   IP_DF : constant := 16#4000#;  --  /usr/include/netinet/ip.h:122
   IP_MF : constant := 16#2000#;  --  /usr/include/netinet/ip.h:123
   IP_OFFMASK : constant := 16#1fff#;  --  /usr/include/netinet/ip.h:124

   IPVERSION : constant := 4;  --  /usr/include/netinet/ip.h:151
   IP_MAXPACKET : constant := 65535;  --  /usr/include/netinet/ip.h:152

   IPTOS_ECN_MASK : constant := 16#03#;  --  /usr/include/netinet/ip.h:160
   --  arg-macro: function IPTOS_ECN (x)
   --    return (x) and IPTOS_ECN_MASK;

   IPTOS_ECN_NOT_ECT : constant := 16#00#;  --  /usr/include/netinet/ip.h:162
   IPTOS_ECN_ECT1 : constant := 16#01#;  --  /usr/include/netinet/ip.h:163
   IPTOS_ECN_ECT0 : constant := 16#02#;  --  /usr/include/netinet/ip.h:164
   IPTOS_ECN_CE : constant := 16#03#;  --  /usr/include/netinet/ip.h:165

   IPTOS_DSCP_MASK : constant := 16#fc#;  --  /usr/include/netinet/ip.h:173
   --  arg-macro: function IPTOS_DSCP (x)
   --    return (x) and IPTOS_DSCP_MASK;

   IPTOS_DSCP_AF11 : constant := 16#28#;  --  /usr/include/netinet/ip.h:175
   IPTOS_DSCP_AF12 : constant := 16#30#;  --  /usr/include/netinet/ip.h:176
   IPTOS_DSCP_AF13 : constant := 16#38#;  --  /usr/include/netinet/ip.h:177
   IPTOS_DSCP_AF21 : constant := 16#48#;  --  /usr/include/netinet/ip.h:178
   IPTOS_DSCP_AF22 : constant := 16#50#;  --  /usr/include/netinet/ip.h:179
   IPTOS_DSCP_AF23 : constant := 16#58#;  --  /usr/include/netinet/ip.h:180
   IPTOS_DSCP_AF31 : constant := 16#68#;  --  /usr/include/netinet/ip.h:181
   IPTOS_DSCP_AF32 : constant := 16#70#;  --  /usr/include/netinet/ip.h:182
   IPTOS_DSCP_AF33 : constant := 16#78#;  --  /usr/include/netinet/ip.h:183
   IPTOS_DSCP_AF41 : constant := 16#88#;  --  /usr/include/netinet/ip.h:184
   IPTOS_DSCP_AF42 : constant := 16#90#;  --  /usr/include/netinet/ip.h:185
   IPTOS_DSCP_AF43 : constant := 16#98#;  --  /usr/include/netinet/ip.h:186
   IPTOS_DSCP_EF : constant := 16#b8#;  --  /usr/include/netinet/ip.h:187

   IPTOS_CLASS_MASK : constant := 16#e0#;  --  /usr/include/netinet/ip.h:194
   --  arg-macro: function IPTOS_CLASS (class)
   --    return (class) and IPTOS_CLASS_MASK;

   IPTOS_CLASS_CS0 : constant := 16#00#;  --  /usr/include/netinet/ip.h:196
   IPTOS_CLASS_CS1 : constant := 16#20#;  --  /usr/include/netinet/ip.h:197
   IPTOS_CLASS_CS2 : constant := 16#40#;  --  /usr/include/netinet/ip.h:198
   IPTOS_CLASS_CS3 : constant := 16#60#;  --  /usr/include/netinet/ip.h:199
   IPTOS_CLASS_CS4 : constant := 16#80#;  --  /usr/include/netinet/ip.h:200
   IPTOS_CLASS_CS5 : constant := 16#a0#;  --  /usr/include/netinet/ip.h:201
   IPTOS_CLASS_CS6 : constant := 16#c0#;  --  /usr/include/netinet/ip.h:202
   IPTOS_CLASS_CS7 : constant := 16#e0#;  --  /usr/include/netinet/ip.h:203
   --  unsupported macro: IPTOS_CLASS_DEFAULT IPTOS_CLASS_CS0

   IPTOS_TOS_MASK : constant := 16#1E#;  --  /usr/include/netinet/ip.h:211
   --  arg-macro: function IPTOS_TOS (tos)
   --    return (tos) and IPTOS_TOS_MASK;

   IPTOS_LOWDELAY : constant := 16#10#;  --  /usr/include/netinet/ip.h:213
   IPTOS_THROUGHPUT : constant := 16#08#;  --  /usr/include/netinet/ip.h:214
   IPTOS_RELIABILITY : constant := 16#04#;  --  /usr/include/netinet/ip.h:215
   IPTOS_LOWCOST : constant := 16#02#;  --  /usr/include/netinet/ip.h:216
   --  unsupported macro: IPTOS_MINCOST IPTOS_LOWCOST
   --  unsupported macro: IPTOS_PREC_MASK IPTOS_CLASS_MASK
   --  arg-macro: procedure IPTOS_PREC (tos)
   --    IPTOS_CLASS(tos)
   --  unsupported macro: IPTOS_PREC_NETCONTROL IPTOS_CLASS_CS7
   --  unsupported macro: IPTOS_PREC_INTERNETCONTROL IPTOS_CLASS_CS6
   --  unsupported macro: IPTOS_PREC_CRITIC_ECP IPTOS_CLASS_CS5
   --  unsupported macro: IPTOS_PREC_FLASHOVERRIDE IPTOS_CLASS_CS4
   --  unsupported macro: IPTOS_PREC_FLASH IPTOS_CLASS_CS3
   --  unsupported macro: IPTOS_PREC_IMMEDIATE IPTOS_CLASS_CS2
   --  unsupported macro: IPTOS_PREC_PRIORITY IPTOS_CLASS_CS1
   --  unsupported macro: IPTOS_PREC_ROUTINE IPTOS_CLASS_CS0

   IPOPT_COPY : constant := 16#80#;  --  /usr/include/netinet/ip.h:236
   IPOPT_CLASS_MASK : constant := 16#60#;  --  /usr/include/netinet/ip.h:237
   IPOPT_NUMBER_MASK : constant := 16#1f#;  --  /usr/include/netinet/ip.h:238
   --  arg-macro: function IPOPT_COPIED (o)
   --    return (o) and IPOPT_COPY;
   --  arg-macro: function IPOPT_CLASS (o)
   --    return (o) and IPOPT_CLASS_MASK;
   --  arg-macro: function IPOPT_NUMBER (o)
   --    return (o) and IPOPT_NUMBER_MASK;

   IPOPT_CONTROL : constant := 16#00#;  --  /usr/include/netinet/ip.h:244
   IPOPT_RESERVED1 : constant := 16#20#;  --  /usr/include/netinet/ip.h:245
   IPOPT_DEBMEAS : constant := 16#40#;  --  /usr/include/netinet/ip.h:246
   --  unsupported macro: IPOPT_MEASUREMENT IPOPT_DEBMEAS

   IPOPT_RESERVED2 : constant := 16#60#;  --  /usr/include/netinet/ip.h:248

   IPOPT_EOL : constant := 0;  --  /usr/include/netinet/ip.h:250
   --  unsupported macro: IPOPT_END IPOPT_EOL

   IPOPT_NOP : constant := 1;  --  /usr/include/netinet/ip.h:252
   --  unsupported macro: IPOPT_NOOP IPOPT_NOP

   IPOPT_RR : constant := 7;  --  /usr/include/netinet/ip.h:255
   IPOPT_TS : constant := 68;  --  /usr/include/netinet/ip.h:256
   --  unsupported macro: IPOPT_TIMESTAMP IPOPT_TS

   IPOPT_SECURITY : constant := 130;  --  /usr/include/netinet/ip.h:258
   --  unsupported macro: IPOPT_SEC IPOPT_SECURITY

   IPOPT_LSRR : constant := 131;  --  /usr/include/netinet/ip.h:260
   IPOPT_SATID : constant := 136;  --  /usr/include/netinet/ip.h:261
   --  unsupported macro: IPOPT_SID IPOPT_SATID

   IPOPT_SSRR : constant := 137;  --  /usr/include/netinet/ip.h:263
   IPOPT_RA : constant := 148;  --  /usr/include/netinet/ip.h:264

   IPOPT_OPTVAL : constant := 0;  --  /usr/include/netinet/ip.h:269
   IPOPT_OLEN : constant := 1;  --  /usr/include/netinet/ip.h:270
   IPOPT_OFFSET : constant := 2;  --  /usr/include/netinet/ip.h:271
   IPOPT_MINOFF : constant := 4;  --  /usr/include/netinet/ip.h:272

   MAX_IPOPTLEN : constant := 40;  --  /usr/include/netinet/ip.h:274

   IPOPT_TS_TSONLY : constant := 0;  --  /usr/include/netinet/ip.h:277
   IPOPT_TS_TSANDADDR : constant := 1;  --  /usr/include/netinet/ip.h:278
   IPOPT_TS_PRESPEC : constant := 3;  --  /usr/include/netinet/ip.h:279

   IPOPT_SECUR_UNCLASS : constant := 16#0000#;  --  /usr/include/netinet/ip.h:282
   IPOPT_SECUR_CONFID : constant := 16#f135#;  --  /usr/include/netinet/ip.h:283
   IPOPT_SECUR_EFTO : constant := 16#789a#;  --  /usr/include/netinet/ip.h:284
   IPOPT_SECUR_MMMM : constant := 16#bc4d#;  --  /usr/include/netinet/ip.h:285
   IPOPT_SECUR_RESTR : constant := 16#af13#;  --  /usr/include/netinet/ip.h:286
   IPOPT_SECUR_SECRET : constant := 16#d788#;  --  /usr/include/netinet/ip.h:287
   IPOPT_SECUR_TOPSECRET : constant := 16#6bc5#;  --  /usr/include/netinet/ip.h:288

   MAXTTL : constant := 255;  --  /usr/include/netinet/ip.h:293
   IPDEFTTL : constant := 64;  --  /usr/include/netinet/ip.h:294
   IPFRAGTTL : constant := 60;  --  /usr/include/netinet/ip.h:295
   IPTTLDEC : constant := 1;  --  /usr/include/netinet/ip.h:296

   IP_MSS : constant := 576;  --  /usr/include/netinet/ip.h:298

   type anon1123_data_array is array (0 .. 8) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;
   type timestamp is record
      len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:30
      ptr : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:31
      flags : Extensions.Unsigned_4;  -- /usr/include/netinet/ip.h:33
      overflow : Extensions.Unsigned_4;  -- /usr/include/netinet/ip.h:34
      data : aliased anon1123_data_array;  -- /usr/include/netinet/ip.h:41
   end record
   with Convention => C_Pass_By_Copy,
        Pack => True;  -- /usr/include/netinet/ip.h:28

   type iphdr is record
      ihl : Extensions.Unsigned_4;  -- /usr/include/netinet/ip.h:47
      version : Extensions.Unsigned_4;  -- /usr/include/netinet/ip.h:48
      tos : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:55
      tot_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/ip.h:56
      id : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/ip.h:57
      frag_off : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/ip.h:58
      ttl : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:59
      protocol : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:60
      check : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/ip.h:61
      saddr : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/ip.h:62
      daddr : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/ip.h:63
   end record
   with Convention => C_Pass_By_Copy,
        Pack => True;  -- /usr/include/netinet/ip.h:44

   type ip is record
      ip_hl : Extensions.Unsigned_4;  -- /usr/include/netinet/ip.h:110
      ip_v : Extensions.Unsigned_4;  -- /usr/include/netinet/ip.h:111
      ip_tos : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:117
      ip_len : aliased unsigned_short;  -- /usr/include/netinet/ip.h:118
      ip_id : aliased unsigned_short;  -- /usr/include/netinet/ip.h:119
      ip_off : aliased unsigned_short;  -- /usr/include/netinet/ip.h:120
      ip_ttl : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:125
      ip_p : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:126
      ip_sum : aliased unsigned_short;  -- /usr/include/netinet/ip.h:127
      ip_src : aliased netinet_in_h.in_addr;  -- /usr/include/netinet/ip.h:128
      ip_dst : aliased netinet_in_h.in_addr;  -- /usr/include/netinet/ip.h:128
   end record
   with Convention => C_Pass_By_Copy,
        Pack => True;  -- /usr/include/netinet/ip.h:107

   type anon1130_data_array is array (0 .. 8) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;
   type ip_timestamp is record
      ipt_code : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:136
      ipt_len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:137
      ipt_ptr : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/ip.h:138
      ipt_flg : Extensions.Unsigned_4;  -- /usr/include/netinet/ip.h:140
      ipt_oflw : Extensions.Unsigned_4;  -- /usr/include/netinet/ip.h:141
      data : aliased anon1130_data_array;  -- /usr/include/netinet/ip.h:147
   end record
   with Convention => C_Pass_By_Copy,
        Pack => True;  -- /usr/include/netinet/ip.h:134

end netinet_ip_h;
