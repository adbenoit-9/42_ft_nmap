pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;

package netinet_udp_h is

   UDP_CORK : constant := 1;  --  /usr/include/netinet/udp.h:77
   UDP_ENCAP : constant := 100;  --  /usr/include/netinet/udp.h:78

   UDP_NO_CHECK6_TX : constant := 101;  --  /usr/include/netinet/udp.h:80

   UDP_NO_CHECK6_RX : constant := 102;  --  /usr/include/netinet/udp.h:82

   UDP_SEGMENT : constant := 103;  --  /usr/include/netinet/udp.h:84
   UDP_GRO : constant := 104;  --  /usr/include/netinet/udp.h:85

   UDP_ENCAP_ESPINUDP_NON_IKE : constant := 1;  --  /usr/include/netinet/udp.h:88
   UDP_ENCAP_ESPINUDP : constant := 2;  --  /usr/include/netinet/udp.h:89
   UDP_ENCAP_L2TPINUDP : constant := 3;  --  /usr/include/netinet/udp.h:90
   UDP_ENCAP_GTP0 : constant := 4;  --  /usr/include/netinet/udp.h:91
   UDP_ENCAP_GTP1U : constant := 5;  --  /usr/include/netinet/udp.h:92

   SOL_UDP : constant := 17;  --  /usr/include/netinet/udp.h:94

   type anon1228_anon1230_struct is record
      uh_sport : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/udp.h:61
      uh_dport : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/udp.h:62
      uh_ulen : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/udp.h:63
      uh_sum : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/udp.h:64
   end record
   with Convention => C_Pass_By_Copy;
   type anon1228_anon1231_struct is record
      source : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/udp.h:68
      dest : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/udp.h:69
      len : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/udp.h:70
      check : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;  -- /usr/include/netinet/udp.h:71
   end record
   with Convention => C_Pass_By_Copy;
   type anon1228_anon1229_union (discr : unsigned := 0) is record
      case discr is
            anon2766 : aliased anon1228_anon1230_struct;  -- /usr/include/netinet/udp.h:65
            anon2772 : aliased anon1228_anon1231_struct;  -- /usr/include/netinet/udp.h:72
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;
   type udphdr is record
      anon2773 : aliased anon1228_anon1229_union;  -- /usr/include/netinet/udp.h:73
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/netinet/udp.h:55

end netinet_udp_h;
