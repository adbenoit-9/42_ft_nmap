pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Strings;
with netinet_in_h;
with System;
with x86_64_linux_gnu_bits_socket_h;
with stddef_h;

package arpa_inet_h is

   function inet_addr (uu_cp : Interfaces.C.Strings.chars_ptr) return netinet_in_h.in_addr_t  -- /usr/include/arpa/inet.h:34
   with Import => True, 
        Convention => C, 
        External_Name => "inet_addr";

   function inet_lnaof (uu_in : netinet_in_h.in_addr) return netinet_in_h.in_addr_t  -- /usr/include/arpa/inet.h:37
   with Import => True, 
        Convention => C, 
        External_Name => "inet_lnaof";

   function inet_makeaddr (uu_net : netinet_in_h.in_addr_t; uu_host : netinet_in_h.in_addr_t) return netinet_in_h.in_addr  -- /usr/include/arpa/inet.h:41
   with Import => True, 
        Convention => C, 
        External_Name => "inet_makeaddr";

   function inet_netof (uu_in : netinet_in_h.in_addr) return netinet_in_h.in_addr_t  -- /usr/include/arpa/inet.h:45
   with Import => True, 
        Convention => C, 
        External_Name => "inet_netof";

   function inet_network (uu_cp : Interfaces.C.Strings.chars_ptr) return netinet_in_h.in_addr_t  -- /usr/include/arpa/inet.h:49
   with Import => True, 
        Convention => C, 
        External_Name => "inet_network";

   function inet_ntoa (arg1 : netinet_in_h.in_addr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/arpa/inet.h:53
   with Import => True, 
        Convention => C, 
        External_Name => "inet_ntoa";

   function inet_pton
     (uu_af : int;
      uu_cp : Interfaces.C.Strings.chars_ptr;
      uu_buf : System.Address) return int  -- /usr/include/arpa/inet.h:58
   with Import => True, 
        Convention => C, 
        External_Name => "inet_pton";

   function inet_ntop
     (arg1 : int;
      arg2 : System.Address;
      arg3 : Interfaces.C.Strings.chars_ptr;
      arg4 : x86_64_linux_gnu_bits_socket_h.socklen_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/arpa/inet.h:64
   with Import => True, 
        Convention => C, 
        External_Name => "inet_ntop";

   function inet_aton (uu_cp : Interfaces.C.Strings.chars_ptr; uu_inp : access netinet_in_h.in_addr) return int  -- /usr/include/arpa/inet.h:73
   with Import => True, 
        Convention => C, 
        External_Name => "inet_aton";

   function inet_neta
     (arg1 : netinet_in_h.in_addr_t;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/arpa/inet.h:77
   with Import => True, 
        Convention => C, 
        External_Name => "inet_neta";

   function inet_net_ntop
     (arg1 : int;
      arg2 : System.Address;
      arg3 : int;
      arg4 : Interfaces.C.Strings.chars_ptr;
      arg5 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/arpa/inet.h:82
   with Import => True, 
        Convention => C, 
        External_Name => "inet_net_ntop";

   function inet_net_pton
     (uu_af : int;
      uu_cp : Interfaces.C.Strings.chars_ptr;
      uu_buf : System.Address;
      uu_len : stddef_h.size_t) return int  -- /usr/include/arpa/inet.h:88
   with Import => True, 
        Convention => C, 
        External_Name => "inet_net_pton";

   function inet_nsap_addr
     (uu_cp : Interfaces.C.Strings.chars_ptr;
      uu_buf : access unsigned_char;
      uu_len : int) return unsigned  -- /usr/include/arpa/inet.h:94
   with Import => True, 
        Convention => C, 
        External_Name => "inet_nsap_addr";

   function inet_nsap_ntoa
     (arg1 : int;
      arg2 : access unsigned_char;
      arg3 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/arpa/inet.h:99
   with Import => True, 
        Convention => C, 
        External_Name => "inet_nsap_ntoa";

end arpa_inet_h;
