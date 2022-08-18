pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;
with System;

package buildy_ipv4_tcp_c is

   function build_ipv4_tcp
     (buf : access x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
      conf_st : System.Address;
      conf_nd : System.Address;
      conf_exec : System.Address) return int  -- buildy_ipv4_tcp.c:28
   with Import => True, 
        Convention => C, 
        External_Name => "build_ipv4_tcp";

end buildy_ipv4_tcp_c;
