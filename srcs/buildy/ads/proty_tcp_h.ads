pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;

package proty_tcp_h is

   --  arg-macro: procedure SET_TCP_SPORT (tcp, value)
   --    do {((struct tcphdr*)tcp).th_sport := (uint16_t)value;} while (0)
   --  arg-macro: procedure SET_TCP_DPORT (tcp, value)
   --    do {((struct tcphdr*)tcp).th_dport := (uint16_t)value;} while (0)
   --  arg-macro: procedure SET_TCP_SEQ (tcp, value)
   --    do {((struct tcphdr*)tcp).th_seq := (uint32_t)value;} while (0)
   --  arg-macro: procedure GET_TCP_SEQ (tcp, value)
   --    do {value := ((struct tcphdr*)tcp).th_seq;} while (0)
   --  arg-macro: procedure SET_TCP_ACK (tcp, value)
   --    do {((struct tcphdr*)tcp).th_ack := (uint32_t)value;} while (0)
   --  arg-macro: procedure GET_TCP_ACK (tcp, value)
   --    do {value := ((struct tcphdr*)tcp).th_ack;} while (0)
   --  arg-macro: procedure SET_TCP_OFF (tcp, value)
   --    do {((struct tcphdr*)tcp).th_off := (uint8_t)value and (uint8_t)16#0F#;} while (0)
   --  arg-macro: procedure SET_TCP_FLAGS (tcp, value)
   --    do {((struct tcphdr*)tcp).th_flags := (uint8_t)value;} while (0)
   --  arg-macro: procedure GET_TCP_FLAGS (tcp, value)
   --    do {value := ((struct tcphdr*)tcp).th_flags;} while (0)
   --  arg-macro: procedure SET_TCP_WIN (tcp, value)
   --    do {((struct tcphdr*)tcp).th_win := (uint16_t)value;} while (0)
   --  arg-macro: procedure SET_TCP_SUM (tcp, value)
   --    do {((struct tcphdr*)tcp).th_sum := (uint16_t)value;} while (0)
   --  arg-macro: procedure SET_TCP_URP (tcp, value)
   --    do {((struct tcphdr*)tcp).th_urp := (uint16_t)value;} while (0)
   --  arg-macro: procedure SET_TCP_DATA (tcp, value, length)
   --    do {if (value /= 0) {memcpy(and((uint8_t*)tcp)(sizeof(struct tcphdr)), value, length);}} while (0)
   --  unsupported macro: FLAG_S_SYN TH_SYN
   FLAG_S_NULL : constant := 16#00#;  --  ../proty/proty_tcp.h:50
   --  unsupported macro: FLAG_S_ACK TH_ACK
   --  unsupported macro: FLAG_S_FIN TH_RST | TH_ACK
   --  unsupported macro: FLAG_S_XMAS TH_FIN | TH_SYN | TH_RST | TH_ACK

   syn_mss : aliased array (0 .. 3) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t  -- ../proty/proty_tcp.h:47
   with Import => True, 
        Convention => C, 
        External_Name => "syn_mss";

end proty_tcp_h;
