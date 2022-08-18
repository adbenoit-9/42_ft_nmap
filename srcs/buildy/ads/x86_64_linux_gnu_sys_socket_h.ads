pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_socket_h;
with System;
with stddef_h;
with x86_64_linux_gnu_sys_types_h;

package x86_64_linux_gnu_sys_socket_h is

   --  unsupported macro: SHUT_RD SHUT_RD
   --  unsupported macro: SHUT_WR SHUT_WR
   --  unsupported macro: SHUT_RDWR SHUT_RDWR
   function socket
     (uu_domain : int;
      uu_type : int;
      uu_protocol : int) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:102
   with Import => True, 
        Convention => C, 
        External_Name => "socket";

   function socketpair
     (uu_domain : int;
      uu_type : int;
      uu_protocol : int;
      uu_fds : access int) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:108
   with Import => True, 
        Convention => C, 
        External_Name => "socketpair";

   function bind
     (uu_fd : int;
      uu_addr : access constant x86_64_linux_gnu_bits_socket_h.sockaddr;
      uu_len : x86_64_linux_gnu_bits_socket_h.socklen_t) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:112
   with Import => True, 
        Convention => C, 
        External_Name => "bind";

   function getsockname
     (uu_fd : int;
      uu_addr : access x86_64_linux_gnu_bits_socket_h.sockaddr;
      uu_len : access x86_64_linux_gnu_bits_socket_h.socklen_t) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:116
   with Import => True, 
        Convention => C, 
        External_Name => "getsockname";

   function connect
     (uu_fd : int;
      uu_addr : access constant x86_64_linux_gnu_bits_socket_h.sockaddr;
      uu_len : x86_64_linux_gnu_bits_socket_h.socklen_t) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:126
   with Import => True, 
        Convention => C, 
        External_Name => "connect";

   function getpeername
     (uu_fd : int;
      uu_addr : access x86_64_linux_gnu_bits_socket_h.sockaddr;
      uu_len : access x86_64_linux_gnu_bits_socket_h.socklen_t) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:130
   with Import => True, 
        Convention => C, 
        External_Name => "getpeername";

   function send
     (uu_fd : int;
      uu_buf : System.Address;
      uu_n : stddef_h.size_t;
      uu_flags : int) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/x86_64-linux-gnu/sys/socket.h:138
   with Import => True, 
        Convention => C, 
        External_Name => "send";

   function recv
     (uu_fd : int;
      uu_buf : System.Address;
      uu_n : stddef_h.size_t;
      uu_flags : int) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/x86_64-linux-gnu/sys/socket.h:145
   with Import => True, 
        Convention => C, 
        External_Name => "recv";

   function sendto
     (uu_fd : int;
      uu_buf : System.Address;
      uu_n : stddef_h.size_t;
      uu_flags : int;
      uu_addr : access constant x86_64_linux_gnu_bits_socket_h.sockaddr;
      uu_addr_len : x86_64_linux_gnu_bits_socket_h.socklen_t) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/x86_64-linux-gnu/sys/socket.h:152
   with Import => True, 
        Convention => C, 
        External_Name => "sendto";

   function recvfrom
     (uu_fd : int;
      uu_buf : System.Address;
      uu_n : stddef_h.size_t;
      uu_flags : int;
      uu_addr : access x86_64_linux_gnu_bits_socket_h.sockaddr;
      uu_addr_len : access x86_64_linux_gnu_bits_socket_h.socklen_t) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/x86_64-linux-gnu/sys/socket.h:163
   with Import => True, 
        Convention => C, 
        External_Name => "recvfrom";

   function sendmsg
     (uu_fd : int;
      uu_message : access constant x86_64_linux_gnu_bits_socket_h.msghdr;
      uu_flags : int) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/x86_64-linux-gnu/sys/socket.h:173
   with Import => True, 
        Convention => C, 
        External_Name => "sendmsg";

   function recvmsg
     (uu_fd : int;
      uu_message : access x86_64_linux_gnu_bits_socket_h.msghdr;
      uu_flags : int) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/x86_64-linux-gnu/sys/socket.h:191
   with Import => True, 
        Convention => C, 
        External_Name => "recvmsg";

   function getsockopt
     (uu_fd : int;
      uu_level : int;
      uu_optname : int;
      uu_optval : System.Address;
      uu_optlen : access x86_64_linux_gnu_bits_socket_h.socklen_t) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:208
   with Import => True, 
        Convention => C, 
        External_Name => "getsockopt";

   function setsockopt
     (uu_fd : int;
      uu_level : int;
      uu_optname : int;
      uu_optval : System.Address;
      uu_optlen : x86_64_linux_gnu_bits_socket_h.socklen_t) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:215
   with Import => True, 
        Convention => C, 
        External_Name => "setsockopt";

   function listen (uu_fd : int; uu_n : int) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:222
   with Import => True, 
        Convention => C, 
        External_Name => "listen";

   function c_accept
     (uu_fd : int;
      uu_addr : access x86_64_linux_gnu_bits_socket_h.sockaddr;
      uu_addr_len : access x86_64_linux_gnu_bits_socket_h.socklen_t) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:232
   with Import => True, 
        Convention => C, 
        External_Name => "accept";

   function shutdown (uu_fd : int; uu_how : int) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:250
   with Import => True, 
        Convention => C, 
        External_Name => "shutdown";

   function sockatmark (uu_fd : int) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:255
   with Import => True, 
        Convention => C, 
        External_Name => "sockatmark";

   function isfdtype (uu_fd : int; uu_fdtype : int) return int  -- /usr/include/x86_64-linux-gnu/sys/socket.h:263
   with Import => True, 
        Convention => C, 
        External_Name => "isfdtype";

end x86_64_linux_gnu_sys_socket_h;
