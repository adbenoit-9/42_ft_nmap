pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;

package x86_64_linux_gnu_bits_socket_type_h is

   --  unsupported macro: SOCK_STREAM SOCK_STREAM
   --  unsupported macro: SOCK_DGRAM SOCK_DGRAM
   --  unsupported macro: SOCK_RAW SOCK_RAW
   --  unsupported macro: SOCK_RDM SOCK_RDM
   --  unsupported macro: SOCK_SEQPACKET SOCK_SEQPACKET
   --  unsupported macro: SOCK_DCCP SOCK_DCCP
   --  unsupported macro: SOCK_PACKET SOCK_PACKET
   --  unsupported macro: SOCK_CLOEXEC SOCK_CLOEXEC
   --  unsupported macro: SOCK_NONBLOCK SOCK_NONBLOCK
   subtype uu_socket_type is unsigned;
   SOCK_STREAM : constant unsigned := 1;
   SOCK_DGRAM : constant unsigned := 2;
   SOCK_RAW : constant unsigned := 3;
   SOCK_RDM : constant unsigned := 4;
   SOCK_SEQPACKET : constant unsigned := 5;
   SOCK_DCCP : constant unsigned := 6;
   SOCK_PACKET : constant unsigned := 10;
   SOCK_CLOEXEC : constant unsigned := 524288;
   SOCK_NONBLOCK : constant unsigned := 2048;  -- /usr/include/x86_64-linux-gnu/bits/socket_type.h:24

end x86_64_linux_gnu_bits_socket_type_h;
