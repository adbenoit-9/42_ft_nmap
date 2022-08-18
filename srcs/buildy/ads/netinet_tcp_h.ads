pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;
with Interfaces.C.Extensions;
with x86_64_linux_gnu_bits_socket_h;

package netinet_tcp_h is

   TCP_NODELAY : constant := 1;  --  /usr/include/netinet/tcp.h:40
   TCP_MAXSEG : constant := 2;  --  /usr/include/netinet/tcp.h:41
   TCP_CORK : constant := 3;  --  /usr/include/netinet/tcp.h:42
   TCP_KEEPIDLE : constant := 4;  --  /usr/include/netinet/tcp.h:43
   TCP_KEEPINTVL : constant := 5;  --  /usr/include/netinet/tcp.h:44
   TCP_KEEPCNT : constant := 6;  --  /usr/include/netinet/tcp.h:45
   TCP_SYNCNT : constant := 7;  --  /usr/include/netinet/tcp.h:46
   TCP_LINGER2 : constant := 8;  --  /usr/include/netinet/tcp.h:47
   TCP_DEFER_ACCEPT : constant := 9;  --  /usr/include/netinet/tcp.h:48
   TCP_WINDOW_CLAMP : constant := 10;  --  /usr/include/netinet/tcp.h:49
   TCP_INFO : constant := 11;  --  /usr/include/netinet/tcp.h:50
   TCP_QUICKACK : constant := 12;  --  /usr/include/netinet/tcp.h:51
   TCP_CONGESTION : constant := 13;  --  /usr/include/netinet/tcp.h:52
   TCP_MD5SIG : constant := 14;  --  /usr/include/netinet/tcp.h:53
   TCP_COOKIE_TRANSACTIONS : constant := 15;  --  /usr/include/netinet/tcp.h:54
   TCP_THIN_LINEAR_TIMEOUTS : constant := 16;  --  /usr/include/netinet/tcp.h:55
   TCP_THIN_DUPACK : constant := 17;  --  /usr/include/netinet/tcp.h:56
   TCP_USER_TIMEOUT : constant := 18;  --  /usr/include/netinet/tcp.h:57
   TCP_REPAIR : constant := 19;  --  /usr/include/netinet/tcp.h:58
   TCP_REPAIR_QUEUE : constant := 20;  --  /usr/include/netinet/tcp.h:59
   TCP_QUEUE_SEQ : constant := 21;  --  /usr/include/netinet/tcp.h:60
   TCP_REPAIR_OPTIONS : constant := 22;  --  /usr/include/netinet/tcp.h:61
   TCP_FASTOPEN : constant := 23;  --  /usr/include/netinet/tcp.h:62
   TCP_TIMESTAMP : constant := 24;  --  /usr/include/netinet/tcp.h:63
   TCP_NOTSENT_LOWAT : constant := 25;  --  /usr/include/netinet/tcp.h:64

   TCP_CC_INFO : constant := 26;  --  /usr/include/netinet/tcp.h:66

   TCP_SAVE_SYN : constant := 27;  --  /usr/include/netinet/tcp.h:68

   TCP_SAVED_SYN : constant := 28;  --  /usr/include/netinet/tcp.h:70

   TCP_REPAIR_WINDOW : constant := 29;  --  /usr/include/netinet/tcp.h:72
   TCP_FASTOPEN_CONNECT : constant := 30;  --  /usr/include/netinet/tcp.h:73
   TCP_ULP : constant := 31;  --  /usr/include/netinet/tcp.h:74
   TCP_MD5SIG_EXT : constant := 32;  --  /usr/include/netinet/tcp.h:75
   TCP_FASTOPEN_KEY : constant := 33;  --  /usr/include/netinet/tcp.h:76
   TCP_FASTOPEN_NO_COOKIE : constant := 34;  --  /usr/include/netinet/tcp.h:77
   TCP_ZEROCOPY_RECEIVE : constant := 35;  --  /usr/include/netinet/tcp.h:78
   TCP_INQ : constant := 36;  --  /usr/include/netinet/tcp.h:79
   --  unsupported macro: TCP_CM_INQ TCP_INQ

   TCP_TX_DELAY : constant := 37;  --  /usr/include/netinet/tcp.h:82

   TCP_REPAIR_ON : constant := 1;  --  /usr/include/netinet/tcp.h:84
   TCP_REPAIR_OFF : constant := 0;  --  /usr/include/netinet/tcp.h:85
   TCP_REPAIR_OFF_NO_WP : constant := -1;  --  /usr/include/netinet/tcp.h:86

   TH_FIN : constant := 16#01#;  --  /usr/include/netinet/tcp.h:117
   TH_SYN : constant := 16#02#;  --  /usr/include/netinet/tcp.h:118
   TH_RST : constant := 16#04#;  --  /usr/include/netinet/tcp.h:119
   TH_PUSH : constant := 16#08#;  --  /usr/include/netinet/tcp.h:120
   TH_ACK : constant := 16#10#;  --  /usr/include/netinet/tcp.h:121
   TH_URG : constant := 16#20#;  --  /usr/include/netinet/tcp.h:122

   TCPOPT_EOL : constant := 0;  --  /usr/include/netinet/tcp.h:178
   TCPOPT_NOP : constant := 1;  --  /usr/include/netinet/tcp.h:179
   TCPOPT_MAXSEG : constant := 2;  --  /usr/include/netinet/tcp.h:180
   TCPOLEN_MAXSEG : constant := 4;  --  /usr/include/netinet/tcp.h:181
   TCPOPT_WINDOW : constant := 3;  --  /usr/include/netinet/tcp.h:182
   TCPOLEN_WINDOW : constant := 3;  --  /usr/include/netinet/tcp.h:183
   TCPOPT_SACK_PERMITTED : constant := 4;  --  /usr/include/netinet/tcp.h:184
   TCPOLEN_SACK_PERMITTED : constant := 2;  --  /usr/include/netinet/tcp.h:185
   TCPOPT_SACK : constant := 5;  --  /usr/include/netinet/tcp.h:186
   TCPOPT_TIMESTAMP : constant := 8;  --  /usr/include/netinet/tcp.h:187
   TCPOLEN_TIMESTAMP : constant := 10;  --  /usr/include/netinet/tcp.h:188
   --  unsupported macro: TCPOLEN_TSTAMP_APPA (TCPOLEN_TIMESTAMP+2)
   --  unsupported macro: TCPOPT_TSTAMP_HDR (TCPOPT_NOP<<24|TCPOPT_NOP<<16|TCPOPT_TIMESTAMP<<8|TCPOLEN_TIMESTAMP)

   TCP_MSS : constant := 512;  --  /usr/include/netinet/tcp.h:200

   TCP_MAXWIN : constant := 65535;  --  /usr/include/netinet/tcp.h:202

   TCP_MAX_WINSHIFT : constant := 14;  --  /usr/include/netinet/tcp.h:204

   SOL_TCP : constant := 6;  --  /usr/include/netinet/tcp.h:206

   TCPI_OPT_TIMESTAMPS : constant := 1;  --  /usr/include/netinet/tcp.h:209
   TCPI_OPT_SACK : constant := 2;  --  /usr/include/netinet/tcp.h:210
   TCPI_OPT_WSCALE : constant := 4;  --  /usr/include/netinet/tcp.h:211
   TCPI_OPT_ECN : constant := 8;  --  /usr/include/netinet/tcp.h:212
   TCPI_OPT_ECN_SEEN : constant := 16;  --  /usr/include/netinet/tcp.h:213
   TCPI_OPT_SYN_DATA : constant := 32;  --  /usr/include/netinet/tcp.h:214

   TCP_MD5SIG_MAXKEYLEN : constant := 80;  --  /usr/include/netinet/tcp.h:271

   TCP_MD5SIG_FLAG_PREFIX : constant := 1;  --  /usr/include/netinet/tcp.h:274

   TCP_COOKIE_MIN : constant := 8;  --  /usr/include/netinet/tcp.h:303
   TCP_COOKIE_MAX : constant := 16;  --  /usr/include/netinet/tcp.h:304
   --  unsupported macro: TCP_COOKIE_PAIR_SIZE (2*TCP_COOKIE_MAX)

   TCP_COOKIE_IN_ALWAYS : constant := (2 ** 0);  --  /usr/include/netinet/tcp.h:308
   TCP_COOKIE_OUT_NEVER : constant := (2 ** 1);  --  /usr/include/netinet/tcp.h:309

   TCP_S_DATA_IN : constant := (2 ** 2);  --  /usr/include/netinet/tcp.h:313
   TCP_S_DATA_OUT : constant := (2 ** 3);  --  /usr/include/netinet/tcp.h:314

   TCP_MSS_DEFAULT : constant := 536;  --  /usr/include/netinet/tcp.h:316
   TCP_MSS_DESIRED : constant := 1220;  --  /usr/include/netinet/tcp.h:317

   subtype tcp_seq is x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:93

   type anon1203_anon1205_struct is record
      th_sport : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:104
      th_dport : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:105
      th_seq : aliased tcp_seq;  -- /usr/include/netinet/tcp.h:106
      th_ack : aliased tcp_seq;  -- /usr/include/netinet/tcp.h:107
      th_x2 : Extensions.Unsigned_4;  -- /usr/include/netinet/tcp.h:109
      th_off : Extensions.Unsigned_4;  -- /usr/include/netinet/tcp.h:110
      th_flags : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:116
      th_win : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:123
      th_sum : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:124
      th_urp : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:125
   end record
   with Convention => C_Pass_By_Copy;
   type anon1203_anon1206_struct is record
      source : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:129
      dest : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:130
      seq : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:131
      ack_seq : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:132
      res1 : Extensions.Unsigned_4;  -- /usr/include/netinet/tcp.h:134
      doff : Extensions.Unsigned_4;  -- /usr/include/netinet/tcp.h:135
      fin : Extensions.Unsigned_1;  -- /usr/include/netinet/tcp.h:136
      syn : Extensions.Unsigned_1;  -- /usr/include/netinet/tcp.h:137
      rst : Extensions.Unsigned_1;  -- /usr/include/netinet/tcp.h:138
      psh : Extensions.Unsigned_1;  -- /usr/include/netinet/tcp.h:139
      ack : Extensions.Unsigned_1;  -- /usr/include/netinet/tcp.h:140
      urg : Extensions.Unsigned_1;  -- /usr/include/netinet/tcp.h:141
      res2 : Extensions.Unsigned_2;  -- /usr/include/netinet/tcp.h:142
      window : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:156
      check : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:157
      urg_ptr : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:158
   end record
   with Convention => C_Pass_By_Copy;
   type anon1203_anon1204_union (discr : unsigned := 0) is record
      case discr is
            anon2653 : aliased anon1203_anon1205_struct;  -- /usr/include/netinet/tcp.h:126
            anon2672 : aliased anon1203_anon1206_struct;  -- /usr/include/netinet/tcp.h:159
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;
   type tcphdr is record
      anon2673 : aliased anon1203_anon1204_union;  -- /usr/include/netinet/tcp.h:160
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/tcp.h:98

   type tcp_ca_state is 
     (TCP_CA_Open,
      TCP_CA_Disorder,
      TCP_CA_CWR,
      TCP_CA_Recovery,
      TCP_CA_Loss)
   with Convention => C;  -- /usr/include/netinet/tcp.h:217

   type tcp_info is record
      tcpi_state : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:228
      tcpi_ca_state : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:229
      tcpi_retransmits : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:230
      tcpi_probes : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:231
      tcpi_backoff : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:232
      tcpi_options : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:233
      tcpi_snd_wscale : Extensions.Unsigned_4;  -- /usr/include/netinet/tcp.h:234
      tcpi_rcv_wscale : Extensions.Unsigned_4;  -- /usr/include/netinet/tcp.h:234
      tcpi_rto : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:236
      tcpi_ato : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:237
      tcpi_snd_mss : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:238
      tcpi_rcv_mss : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:239
      tcpi_unacked : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:241
      tcpi_sacked : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:242
      tcpi_lost : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:243
      tcpi_retrans : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:244
      tcpi_fackets : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:245
      tcpi_last_data_sent : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:248
      tcpi_last_ack_sent : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:249
      tcpi_last_data_recv : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:250
      tcpi_last_ack_recv : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:251
      tcpi_pmtu : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:254
      tcpi_rcv_ssthresh : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:255
      tcpi_rtt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:256
      tcpi_rttvar : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:257
      tcpi_snd_ssthresh : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:258
      tcpi_snd_cwnd : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:259
      tcpi_advmss : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:260
      tcpi_reordering : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:261
      tcpi_rcv_rtt : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:263
      tcpi_rcv_space : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:264
      tcpi_total_retrans : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:266
   end record
   with Convention => C_Pass_By_Copy,
        Pack => True;  -- /usr/include/netinet/tcp.h:226

   type anon1212_tcpm_key_array is array (0 .. 79) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type tcp_md5sig is record
      tcpm_addr : aliased x86_64_linux_gnu_bits_socket_h.sockaddr_storage;  -- /usr/include/netinet/tcp.h:278
      tcpm_flags : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:279
      tcpm_prefixlen : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:280
      tcpm_keylen : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:281
      uu_tcpm_pad : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:282
      tcpm_key : aliased anon1212_tcpm_key_array;  -- /usr/include/netinet/tcp.h:283
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/tcp.h:276

   type tcp_repair_opt is record
      opt_code : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:289
      opt_val : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:290
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/tcp.h:287

   type anon1218_tcpct_value_array is array (0 .. 535) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type tcp_cookie_transactions is record
      tcpct_flags : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:321
      uu_tcpct_pad1 : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:322
      tcpct_cookie_desired : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- /usr/include/netinet/tcp.h:323
      tcpct_s_data_desired : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:324
      tcpct_used : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/tcp.h:325
      tcpct_value : aliased anon1218_tcpct_value_array;  -- /usr/include/netinet/tcp.h:326
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/tcp.h:319

   type tcp_repair_window is record
      snd_wl1 : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:332
      snd_wnd : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:333
      max_window : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:334
      rcv_wnd : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:335
      rcv_wup : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:336
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/tcp.h:330

   type tcp_zerocopy_receive is record
      address : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint64_t;  -- /usr/include/netinet/tcp.h:342
      length : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:343
      recv_skip_hint : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- /usr/include/netinet/tcp.h:344
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/tcp.h:340

end netinet_tcp_h;
