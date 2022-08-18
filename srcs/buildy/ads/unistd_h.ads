pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_types_h;
with Interfaces.C.Strings;
with System;
with stddef_h;
with x86_64_linux_gnu_sys_types_h;
with stdint_h;

package unistd_h is

   STDIN_FILENO : constant := 0;  --  /usr/include/unistd.h:210
   STDOUT_FILENO : constant := 1;  --  /usr/include/unistd.h:211
   STDERR_FILENO : constant := 2;  --  /usr/include/unistd.h:212

   R_OK : constant := 4;  --  /usr/include/unistd.h:281
   W_OK : constant := 2;  --  /usr/include/unistd.h:282
   X_OK : constant := 1;  --  /usr/include/unistd.h:283
   F_OK : constant := 0;  --  /usr/include/unistd.h:284
   --  unsupported macro: L_SET SEEK_SET
   --  unsupported macro: L_INCR SEEK_CUR
   --  unsupported macro: L_XTND SEEK_END

   F_ULOCK : constant := 0;  --  /usr/include/unistd.h:1073
   F_LOCK : constant := 1;  --  /usr/include/unistd.h:1074
   F_TLOCK : constant := 2;  --  /usr/include/unistd.h:1075
   F_TEST : constant := 3;  --  /usr/include/unistd.h:1076

   subtype useconds_t is x86_64_linux_gnu_bits_types_h.uu_useconds_t;  -- /usr/include/unistd.h:255

   function c_access (uu_name : Interfaces.C.Strings.chars_ptr; uu_type : int) return int  -- /usr/include/unistd.h:287
   with Import => True, 
        Convention => C, 
        External_Name => "access";

   function faccessat
     (uu_fd : int;
      uu_file : Interfaces.C.Strings.chars_ptr;
      uu_type : int;
      uu_flag : int) return int  -- /usr/include/unistd.h:304
   with Import => True, 
        Convention => C, 
        External_Name => "faccessat";

   function lseek
     (uu_fd : int;
      uu_offset : x86_64_linux_gnu_bits_types_h.uu_off_t;
      uu_whence : int) return x86_64_linux_gnu_bits_types_h.uu_off_t  -- /usr/include/unistd.h:334
   with Import => True, 
        Convention => C, 
        External_Name => "lseek";

   function close (uu_fd : int) return int  -- /usr/include/unistd.h:353
   with Import => True, 
        Convention => C, 
        External_Name => "close";

   function read
     (uu_fd : int;
      uu_buf : System.Address;
      uu_nbytes : stddef_h.size_t) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/unistd.h:360
   with Import => True, 
        Convention => C, 
        External_Name => "read";

   function write
     (uu_fd : int;
      uu_buf : System.Address;
      uu_n : stddef_h.size_t) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/unistd.h:366
   with Import => True, 
        Convention => C, 
        External_Name => "write";

   function pread
     (uu_fd : int;
      uu_buf : System.Address;
      uu_nbytes : stddef_h.size_t;
      uu_offset : x86_64_linux_gnu_bits_types_h.uu_off_t) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/unistd.h:376
   with Import => True, 
        Convention => C, 
        External_Name => "pread";

   function pwrite
     (uu_fd : int;
      uu_buf : System.Address;
      uu_n : stddef_h.size_t;
      uu_offset : x86_64_linux_gnu_bits_types_h.uu_off_t) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/unistd.h:384
   with Import => True, 
        Convention => C, 
        External_Name => "pwrite";

   function pipe (uu_pipedes : access int) return int  -- /usr/include/unistd.h:417
   with Import => True, 
        Convention => C, 
        External_Name => "pipe";

   function alarm (uu_seconds : unsigned) return unsigned  -- /usr/include/unistd.h:432
   with Import => True, 
        Convention => C, 
        External_Name => "alarm";

   function sleep (uu_seconds : unsigned) return unsigned  -- /usr/include/unistd.h:444
   with Import => True, 
        Convention => C, 
        External_Name => "sleep";

   function ualarm (uu_value : x86_64_linux_gnu_bits_types_h.uu_useconds_t; uu_interval : x86_64_linux_gnu_bits_types_h.uu_useconds_t) return x86_64_linux_gnu_bits_types_h.uu_useconds_t  -- /usr/include/unistd.h:452
   with Import => True, 
        Convention => C, 
        External_Name => "ualarm";

   function usleep (uu_useconds : x86_64_linux_gnu_bits_types_h.uu_useconds_t) return int  -- /usr/include/unistd.h:460
   with Import => True, 
        Convention => C, 
        External_Name => "usleep";

   function pause return int  -- /usr/include/unistd.h:469
   with Import => True, 
        Convention => C, 
        External_Name => "pause";

   function chown
     (uu_file : Interfaces.C.Strings.chars_ptr;
      uu_owner : x86_64_linux_gnu_bits_types_h.uu_uid_t;
      uu_group : x86_64_linux_gnu_bits_types_h.uu_gid_t) return int  -- /usr/include/unistd.h:473
   with Import => True, 
        Convention => C, 
        External_Name => "chown";

   function fchown
     (uu_fd : int;
      uu_owner : x86_64_linux_gnu_bits_types_h.uu_uid_t;
      uu_group : x86_64_linux_gnu_bits_types_h.uu_gid_t) return int  -- /usr/include/unistd.h:478
   with Import => True, 
        Convention => C, 
        External_Name => "fchown";

   function lchown
     (uu_file : Interfaces.C.Strings.chars_ptr;
      uu_owner : x86_64_linux_gnu_bits_types_h.uu_uid_t;
      uu_group : x86_64_linux_gnu_bits_types_h.uu_gid_t) return int  -- /usr/include/unistd.h:483
   with Import => True, 
        Convention => C, 
        External_Name => "lchown";

   function fchownat
     (uu_fd : int;
      uu_file : Interfaces.C.Strings.chars_ptr;
      uu_owner : x86_64_linux_gnu_bits_types_h.uu_uid_t;
      uu_group : x86_64_linux_gnu_bits_types_h.uu_gid_t;
      uu_flag : int) return int  -- /usr/include/unistd.h:491
   with Import => True, 
        Convention => C, 
        External_Name => "fchownat";

   function chdir (uu_path : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:497
   with Import => True, 
        Convention => C, 
        External_Name => "chdir";

   function fchdir (uu_fd : int) return int  -- /usr/include/unistd.h:501
   with Import => True, 
        Convention => C, 
        External_Name => "fchdir";

   function getcwd (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/unistd.h:511
   with Import => True, 
        Convention => C, 
        External_Name => "getcwd";

   function getwd (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/unistd.h:525
   with Import => True, 
        Convention => C, 
        External_Name => "getwd";

   function dup (uu_fd : int) return int  -- /usr/include/unistd.h:531
   with Import => True, 
        Convention => C, 
        External_Name => "dup";

   function dup2 (uu_fd : int; uu_fd2 : int) return int  -- /usr/include/unistd.h:534
   with Import => True, 
        Convention => C, 
        External_Name => "dup2";

   function execve
     (uu_path : Interfaces.C.Strings.chars_ptr;
      uu_argv : System.Address;
      uu_envp : System.Address) return int  -- /usr/include/unistd.h:551
   with Import => True, 
        Convention => C, 
        External_Name => "execve";

   function fexecve
     (uu_fd : int;
      uu_argv : System.Address;
      uu_envp : System.Address) return int  -- /usr/include/unistd.h:557
   with Import => True, 
        Convention => C, 
        External_Name => "fexecve";

   function execv (uu_path : Interfaces.C.Strings.chars_ptr; uu_argv : System.Address) return int  -- /usr/include/unistd.h:563
   with Import => True, 
        Convention => C, 
        External_Name => "execv";

   function execle (uu_path : Interfaces.C.Strings.chars_ptr; uu_arg : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/unistd.h:568
   with Import => True, 
        Convention => C, 
        External_Name => "execle";

   function execl (uu_path : Interfaces.C.Strings.chars_ptr; uu_arg : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/unistd.h:573
   with Import => True, 
        Convention => C, 
        External_Name => "execl";

   function execvp (uu_file : Interfaces.C.Strings.chars_ptr; uu_argv : System.Address) return int  -- /usr/include/unistd.h:578
   with Import => True, 
        Convention => C, 
        External_Name => "execvp";

   function execlp (uu_file : Interfaces.C.Strings.chars_ptr; uu_arg : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/unistd.h:584
   with Import => True, 
        Convention => C, 
        External_Name => "execlp";

   function nice (uu_inc : int) return int  -- /usr/include/unistd.h:598
   with Import => True, 
        Convention => C, 
        External_Name => "nice";

   --  skipped func _exit

   function pathconf (uu_path : Interfaces.C.Strings.chars_ptr; uu_name : int) return long  -- /usr/include/unistd.h:612
   with Import => True, 
        Convention => C, 
        External_Name => "pathconf";

   function fpathconf (uu_fd : int; uu_name : int) return long  -- /usr/include/unistd.h:616
   with Import => True, 
        Convention => C, 
        External_Name => "fpathconf";

   function sysconf (uu_name : int) return long  -- /usr/include/unistd.h:619
   with Import => True, 
        Convention => C, 
        External_Name => "sysconf";

   function confstr
     (uu_name : int;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_len : stddef_h.size_t) return stddef_h.size_t  -- /usr/include/unistd.h:623
   with Import => True, 
        Convention => C, 
        External_Name => "confstr";

   function getpid return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:628
   with Import => True, 
        Convention => C, 
        External_Name => "getpid";

   function getppid return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:631
   with Import => True, 
        Convention => C, 
        External_Name => "getppid";

   function getpgrp return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:634
   with Import => True, 
        Convention => C, 
        External_Name => "getpgrp";

   --  skipped func __getpgid

   function getpgid (uu_pid : x86_64_linux_gnu_bits_types_h.uu_pid_t) return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:639
   with Import => True, 
        Convention => C, 
        External_Name => "getpgid";

   function setpgid (uu_pid : x86_64_linux_gnu_bits_types_h.uu_pid_t; uu_pgid : x86_64_linux_gnu_bits_types_h.uu_pid_t) return int  -- /usr/include/unistd.h:646
   with Import => True, 
        Convention => C, 
        External_Name => "setpgid";

   function setpgrp return int  -- /usr/include/unistd.h:660
   with Import => True, 
        Convention => C, 
        External_Name => "setpgrp";

   function setsid return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:667
   with Import => True, 
        Convention => C, 
        External_Name => "setsid";

   function getsid (uu_pid : x86_64_linux_gnu_bits_types_h.uu_pid_t) return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:671
   with Import => True, 
        Convention => C, 
        External_Name => "getsid";

   function getuid return x86_64_linux_gnu_bits_types_h.uu_uid_t  -- /usr/include/unistd.h:675
   with Import => True, 
        Convention => C, 
        External_Name => "getuid";

   function geteuid return x86_64_linux_gnu_bits_types_h.uu_uid_t  -- /usr/include/unistd.h:678
   with Import => True, 
        Convention => C, 
        External_Name => "geteuid";

   function getgid return x86_64_linux_gnu_bits_types_h.uu_gid_t  -- /usr/include/unistd.h:681
   with Import => True, 
        Convention => C, 
        External_Name => "getgid";

   function getegid return x86_64_linux_gnu_bits_types_h.uu_gid_t  -- /usr/include/unistd.h:684
   with Import => True, 
        Convention => C, 
        External_Name => "getegid";

   function getgroups (uu_size : int; uu_list : access x86_64_linux_gnu_bits_types_h.uu_gid_t) return int  -- /usr/include/unistd.h:689
   with Import => True, 
        Convention => C, 
        External_Name => "getgroups";

   function setuid (uu_uid : x86_64_linux_gnu_bits_types_h.uu_uid_t) return int  -- /usr/include/unistd.h:700
   with Import => True, 
        Convention => C, 
        External_Name => "setuid";

   function setreuid (uu_ruid : x86_64_linux_gnu_bits_types_h.uu_uid_t; uu_euid : x86_64_linux_gnu_bits_types_h.uu_uid_t) return int  -- /usr/include/unistd.h:705
   with Import => True, 
        Convention => C, 
        External_Name => "setreuid";

   function seteuid (uu_uid : x86_64_linux_gnu_bits_types_h.uu_uid_t) return int  -- /usr/include/unistd.h:710
   with Import => True, 
        Convention => C, 
        External_Name => "seteuid";

   function setgid (uu_gid : x86_64_linux_gnu_bits_types_h.uu_gid_t) return int  -- /usr/include/unistd.h:717
   with Import => True, 
        Convention => C, 
        External_Name => "setgid";

   function setregid (uu_rgid : x86_64_linux_gnu_bits_types_h.uu_gid_t; uu_egid : x86_64_linux_gnu_bits_types_h.uu_gid_t) return int  -- /usr/include/unistd.h:722
   with Import => True, 
        Convention => C, 
        External_Name => "setregid";

   function setegid (uu_gid : x86_64_linux_gnu_bits_types_h.uu_gid_t) return int  -- /usr/include/unistd.h:727
   with Import => True, 
        Convention => C, 
        External_Name => "setegid";

   function fork return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:756
   with Import => True, 
        Convention => C, 
        External_Name => "fork";

   function vfork return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:764
   with Import => True, 
        Convention => C, 
        External_Name => "vfork";

   function ttyname (arg1 : int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/unistd.h:770
   with Import => True, 
        Convention => C, 
        External_Name => "ttyname";

   function ttyname_r
     (uu_fd : int;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_buflen : stddef_h.size_t) return int  -- /usr/include/unistd.h:774
   with Import => True, 
        Convention => C, 
        External_Name => "ttyname_r";

   function isatty (uu_fd : int) return int  -- /usr/include/unistd.h:779
   with Import => True, 
        Convention => C, 
        External_Name => "isatty";

   function ttyslot return int  -- /usr/include/unistd.h:784
   with Import => True, 
        Convention => C, 
        External_Name => "ttyslot";

   function link (uu_from : Interfaces.C.Strings.chars_ptr; uu_to : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:789
   with Import => True, 
        Convention => C, 
        External_Name => "link";

   function linkat
     (uu_fromfd : int;
      uu_from : Interfaces.C.Strings.chars_ptr;
      uu_tofd : int;
      uu_to : Interfaces.C.Strings.chars_ptr;
      uu_flags : int) return int  -- /usr/include/unistd.h:795
   with Import => True, 
        Convention => C, 
        External_Name => "linkat";

   function symlink (uu_from : Interfaces.C.Strings.chars_ptr; uu_to : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:802
   with Import => True, 
        Convention => C, 
        External_Name => "symlink";

   function readlink
     (uu_path : Interfaces.C.Strings.chars_ptr;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_len : stddef_h.size_t) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/unistd.h:808
   with Import => True, 
        Convention => C, 
        External_Name => "readlink";

   function symlinkat
     (uu_from : Interfaces.C.Strings.chars_ptr;
      uu_tofd : int;
      uu_to : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:815
   with Import => True, 
        Convention => C, 
        External_Name => "symlinkat";

   function readlinkat
     (uu_fd : int;
      uu_path : Interfaces.C.Strings.chars_ptr;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_len : stddef_h.size_t) return x86_64_linux_gnu_sys_types_h.ssize_t  -- /usr/include/unistd.h:819
   with Import => True, 
        Convention => C, 
        External_Name => "readlinkat";

   function unlink (uu_name : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:825
   with Import => True, 
        Convention => C, 
        External_Name => "unlink";

   function unlinkat
     (uu_fd : int;
      uu_name : Interfaces.C.Strings.chars_ptr;
      uu_flag : int) return int  -- /usr/include/unistd.h:829
   with Import => True, 
        Convention => C, 
        External_Name => "unlinkat";

   function rmdir (uu_path : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:834
   with Import => True, 
        Convention => C, 
        External_Name => "rmdir";

   function tcgetpgrp (uu_fd : int) return x86_64_linux_gnu_bits_types_h.uu_pid_t  -- /usr/include/unistd.h:838
   with Import => True, 
        Convention => C, 
        External_Name => "tcgetpgrp";

   function tcsetpgrp (uu_fd : int; uu_pgrp_id : x86_64_linux_gnu_bits_types_h.uu_pid_t) return int  -- /usr/include/unistd.h:841
   with Import => True, 
        Convention => C, 
        External_Name => "tcsetpgrp";

   function getlogin return Interfaces.C.Strings.chars_ptr  -- /usr/include/unistd.h:848
   with Import => True, 
        Convention => C, 
        External_Name => "getlogin";

   function getlogin_r (uu_name : Interfaces.C.Strings.chars_ptr; uu_name_len : stddef_h.size_t) return int  -- /usr/include/unistd.h:856
   with Import => True, 
        Convention => C, 
        External_Name => "getlogin_r";

   function setlogin (uu_name : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:861
   with Import => True, 
        Convention => C, 
        External_Name => "setlogin";

   function gethostname (uu_name : Interfaces.C.Strings.chars_ptr; uu_len : stddef_h.size_t) return int  -- /usr/include/unistd.h:877
   with Import => True, 
        Convention => C, 
        External_Name => "gethostname";

   function sethostname (uu_name : Interfaces.C.Strings.chars_ptr; uu_len : stddef_h.size_t) return int  -- /usr/include/unistd.h:884
   with Import => True, 
        Convention => C, 
        External_Name => "sethostname";

   function sethostid (uu_id : long) return int  -- /usr/include/unistd.h:889
   with Import => True, 
        Convention => C, 
        External_Name => "sethostid";

   function getdomainname (uu_name : Interfaces.C.Strings.chars_ptr; uu_len : stddef_h.size_t) return int  -- /usr/include/unistd.h:895
   with Import => True, 
        Convention => C, 
        External_Name => "getdomainname";

   function setdomainname (uu_name : Interfaces.C.Strings.chars_ptr; uu_len : stddef_h.size_t) return int  -- /usr/include/unistd.h:897
   with Import => True, 
        Convention => C, 
        External_Name => "setdomainname";

   function vhangup return int  -- /usr/include/unistd.h:904
   with Import => True, 
        Convention => C, 
        External_Name => "vhangup";

   function revoke (uu_file : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:907
   with Import => True, 
        Convention => C, 
        External_Name => "revoke";

   function profil
     (uu_sample_buffer : access unsigned_short;
      uu_size : stddef_h.size_t;
      uu_offset : stddef_h.size_t;
      uu_scale : unsigned) return int  -- /usr/include/unistd.h:915
   with Import => True, 
        Convention => C, 
        External_Name => "profil";

   function acct (uu_name : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:923
   with Import => True, 
        Convention => C, 
        External_Name => "acct";

   function getusershell return Interfaces.C.Strings.chars_ptr  -- /usr/include/unistd.h:927
   with Import => True, 
        Convention => C, 
        External_Name => "getusershell";

   procedure endusershell  -- /usr/include/unistd.h:928
   with Import => True, 
        Convention => C, 
        External_Name => "endusershell";

   procedure setusershell  -- /usr/include/unistd.h:929
   with Import => True, 
        Convention => C, 
        External_Name => "setusershell";

   function daemon (uu_nochdir : int; uu_noclose : int) return int  -- /usr/include/unistd.h:935
   with Import => True, 
        Convention => C, 
        External_Name => "daemon";

   function chroot (uu_path : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/unistd.h:942
   with Import => True, 
        Convention => C, 
        External_Name => "chroot";

   function getpass (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/unistd.h:946
   with Import => True, 
        Convention => C, 
        External_Name => "getpass";

   function fsync (uu_fd : int) return int  -- /usr/include/unistd.h:954
   with Import => True, 
        Convention => C, 
        External_Name => "fsync";

   function gethostid return long  -- /usr/include/unistd.h:967
   with Import => True, 
        Convention => C, 
        External_Name => "gethostid";

   procedure sync  -- /usr/include/unistd.h:970
   with Import => True, 
        Convention => C, 
        External_Name => "sync";

   function getpagesize return int  -- /usr/include/unistd.h:976
   with Import => True, 
        Convention => C, 
        External_Name => "getpagesize";

   function getdtablesize return int  -- /usr/include/unistd.h:981
   with Import => True, 
        Convention => C, 
        External_Name => "getdtablesize";

   function truncate (uu_file : Interfaces.C.Strings.chars_ptr; uu_length : x86_64_linux_gnu_bits_types_h.uu_off_t) return int  -- /usr/include/unistd.h:991
   with Import => True, 
        Convention => C, 
        External_Name => "truncate";

   function ftruncate (uu_fd : int; uu_length : x86_64_linux_gnu_bits_types_h.uu_off_t) return int  -- /usr/include/unistd.h:1014
   with Import => True, 
        Convention => C, 
        External_Name => "ftruncate";

   function brk (uu_addr : System.Address) return int  -- /usr/include/unistd.h:1035
   with Import => True, 
        Convention => C, 
        External_Name => "brk";

   function sbrk (arg1 : stdint_h.intptr_t) return System.Address  -- /usr/include/unistd.h:1041
   with Import => True, 
        Convention => C, 
        External_Name => "sbrk";

   function syscall (uu_sysno : long  -- , ...
      ) return long  -- /usr/include/unistd.h:1056
   with Import => True, 
        Convention => C, 
        External_Name => "syscall";

   function lockf
     (uu_fd : int;
      uu_cmd : int;
      uu_len : x86_64_linux_gnu_bits_types_h.uu_off_t) return int  -- /usr/include/unistd.h:1079
   with Import => True, 
        Convention => C, 
        External_Name => "lockf";

   function fdatasync (uu_fildes : int) return int  -- /usr/include/unistd.h:1115
   with Import => True, 
        Convention => C, 
        External_Name => "fdatasync";

   function crypt (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/unistd.h:1124
   with Import => True, 
        Convention => C, 
        External_Name => "crypt";

   function getentropy (uu_buffer : System.Address; uu_length : stddef_h.size_t) return int  -- /usr/include/unistd.h:1161
   with Import => True, 
        Convention => C, 
        External_Name => "getentropy";

end unistd_h;
