pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;
with Interfaces.C.Strings;
with x86_64_linux_gnu_bits_socket_h;
with mappy_h;
with x86_64_linux_gnu_bits_stdint_intn_h;
limited with libft_h;

package ft_nmap_structs_h is

   PORTS_SCAN_LIMIT : constant := 1024;  --  ../nmap/ft_nmap_structs.h:21

   type anon1895_ports_array is array (0 .. 1023) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;
   type anon1895_scans_array is array (0 .. 5) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type anon1895_ips_array is array (0 .. 127) of Interfaces.C.Strings.chars_ptr;
   type anon1895_socks_array is array (0 .. 127) of aliased x86_64_linux_gnu_bits_socket_h.sockaddr_storage;
   type s_nmap_setting is record
      cross : aliased mappy_h.t_proto_root;  -- ../nmap/ft_nmap_structs.h:24
      nmap_flag : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../nmap/ft_nmap_structs.h:25
      ports : aliased anon1895_ports_array;  -- ../nmap/ft_nmap_structs.h:26
      scans : aliased anon1895_scans_array;  -- ../nmap/ft_nmap_structs.h:27
      speedup : aliased x86_64_linux_gnu_bits_stdint_intn_h.int8_t;  -- ../nmap/ft_nmap_structs.h:28
      ipfile : aliased char;  -- ../nmap/ft_nmap_structs.h:29
      ip_lst : access libft_h.t_list;  -- ../nmap/ft_nmap_structs.h:30
      ips : anon1895_ips_array;  -- ../nmap/ft_nmap_structs.h:31
      socks : aliased anon1895_socks_array;  -- ../nmap/ft_nmap_structs.h:32
   end record
   with Convention => C_Pass_By_Copy;  -- ../nmap/ft_nmap_structs.h:23

   subtype t_nmap_setting is s_nmap_setting;  -- ../nmap/ft_nmap_structs.h:34

   type s_nmap_link is record
      cross : aliased mappy_h.t_proto_tree;  -- ../nmap/ft_nmap_structs.h:38
      sock : aliased x86_64_linux_gnu_bits_socket_h.sockaddr_storage;  -- ../nmap/ft_nmap_structs.h:39
      st_flag : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- ../nmap/ft_nmap_structs.h:40
   end record
   with Convention => C_Pass_By_Copy;  -- ../nmap/ft_nmap_structs.h:37

   subtype t_nmap_link is s_nmap_link;  -- ../nmap/ft_nmap_structs.h:41

   type anon1908_ports_array is array (0 .. 1023) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint16_t;
   type s_nmap_app is record
      cross : aliased mappy_h.t_proto_tree;  -- ../nmap/ft_nmap_structs.h:44
      ports : aliased anon1908_ports_array;  -- ../nmap/ft_nmap_structs.h:45
      sock : aliased int;  -- ../nmap/ft_nmap_structs.h:46
      nd_flag : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- ../nmap/ft_nmap_structs.h:47
      port : aliased int;  -- ../nmap/ft_nmap_structs.h:48
   end record
   with Convention => C_Pass_By_Copy;  -- ../nmap/ft_nmap_structs.h:43

   subtype t_nmap_app is s_nmap_app;  -- ../nmap/ft_nmap_structs.h:49

   type s_nmap_scan is record
      cross : aliased mappy_h.t_proto_elem;  -- ../nmap/ft_nmap_structs.h:52
      exec_flag : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- ../nmap/ft_nmap_structs.h:53
      scans : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- ../nmap/ft_nmap_structs.h:54
      packet_length : aliased int;  -- ../nmap/ft_nmap_structs.h:55
      socket : aliased int;  -- ../nmap/ft_nmap_structs.h:56
      tcpflag : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- ../nmap/ft_nmap_structs.h:57
      scan_result : aliased int;  -- ../nmap/ft_nmap_structs.h:58
   end record
   with Convention => C_Pass_By_Copy;  -- ../nmap/ft_nmap_structs.h:51

   subtype t_nmap_scan is s_nmap_scan;  -- ../nmap/ft_nmap_structs.h:59

end ft_nmap_structs_h;
