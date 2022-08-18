pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;

package buildy_h is

   BUILDY_OK : constant := 0;  --  buildy.h:42
   BUILDY_ERROR : constant := -1;  --  buildy.h:43

   function get_urandom (buf : access x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t; length : int) return int  -- buildy.h:36
   with Import => True, 
        Convention => C, 
        External_Name => "get_urandom";

   function ipv4_checksum (addr : access x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t; len : int) return x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t  -- buildy.h:37
   with Import => True, 
        Convention => C, 
        External_Name => "ipv4_checksum";

   function tcp_ipv4_checksum (ip : access x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t; tcplen : x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t) return x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t  -- buildy.h:38
   with Import => True, 
        Convention => C, 
        External_Name => "tcp_ipv4_checksum";

end buildy_h;
