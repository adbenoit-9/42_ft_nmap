pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Strings;
limited with x86_64_linux_gnu_bits_stat_h;
with x86_64_linux_gnu_bits_types_h;
limited with x86_64_linux_gnu_bits_types_struct_timespec_h;

package x86_64_linux_gnu_sys_stat_h is

   --  arg-macro: procedure S_ISDIR (mode)
   --    __S_ISTYPE((mode), __S_IFDIR)
   --  arg-macro: procedure S_ISCHR (mode)
   --    __S_ISTYPE((mode), __S_IFCHR)
   --  arg-macro: procedure S_ISBLK (mode)
   --    __S_ISTYPE((mode), __S_IFBLK)
   --  arg-macro: procedure S_ISREG (mode)
   --    __S_ISTYPE((mode), __S_IFREG)
   --  arg-macro: procedure S_ISFIFO (mode)
   --    __S_ISTYPE((mode), __S_IFIFO)
   --  arg-macro: procedure S_ISLNK (mode)
   --    __S_ISTYPE((mode), __S_IFLNK)
   --  arg-macro: procedure S_ISSOCK (mode)
   --    __S_ISTYPE((mode), __S_IFSOCK)
   --  arg-macro: procedure S_TYPEISMQ (buf)
   --    __S_TYPEISMQ(buf)
   --  arg-macro: procedure S_TYPEISSEM (buf)
   --    __S_TYPEISSEM(buf)
   --  arg-macro: procedure S_TYPEISSHM (buf)
   --    __S_TYPEISSHM(buf)
   --  unsupported macro: S_IREAD S_IRUSR
   --  unsupported macro: S_IWRITE S_IWUSR
   --  unsupported macro: S_IEXEC S_IXUSR
   --  unsupported macro: ACCESSPERMS (S_IRWXU|S_IRWXG|S_IRWXO)
   --  unsupported macro: ALLPERMS (S_ISUID|S_ISGID|S_ISVTX|S_IRWXU|S_IRWXG|S_IRWXO)
   --  unsupported macro: DEFFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
   S_BLKSIZE : constant := 512;  --  /usr/include/x86_64-linux-gnu/sys/stat.h:199

   function stat (uu_file : Interfaces.C.Strings.chars_ptr; uu_buf : access x86_64_linux_gnu_bits_stat_h.stat) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:205
   with Import => True, 
        Convention => C, 
        External_Name => "stat";

   function fstat (uu_fd : int; uu_buf : access x86_64_linux_gnu_bits_stat_h.stat) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:210
   with Import => True, 
        Convention => C, 
        External_Name => "fstat";

   function fstatat
     (uu_fd : int;
      uu_file : Interfaces.C.Strings.chars_ptr;
      uu_buf : access x86_64_linux_gnu_bits_stat_h.stat;
      uu_flag : int) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:234
   with Import => True, 
        Convention => C, 
        External_Name => "fstatat";

   function lstat (uu_file : Interfaces.C.Strings.chars_ptr; uu_buf : access x86_64_linux_gnu_bits_stat_h.stat) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:259
   with Import => True, 
        Convention => C, 
        External_Name => "lstat";

   function chmod (uu_file : Interfaces.C.Strings.chars_ptr; uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:280
   with Import => True, 
        Convention => C, 
        External_Name => "chmod";

   function lchmod (uu_file : Interfaces.C.Strings.chars_ptr; uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:287
   with Import => True, 
        Convention => C, 
        External_Name => "lchmod";

   function fchmod (uu_fd : int; uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:293
   with Import => True, 
        Convention => C, 
        External_Name => "fchmod";

   function fchmodat
     (uu_fd : int;
      uu_file : Interfaces.C.Strings.chars_ptr;
      uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t;
      uu_flag : int) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:299
   with Import => True, 
        Convention => C, 
        External_Name => "fchmodat";

   function umask (uu_mask : x86_64_linux_gnu_bits_types_h.uu_mode_t) return x86_64_linux_gnu_bits_types_h.uu_mode_t  -- /usr/include/x86_64-linux-gnu/sys/stat.h:308
   with Import => True, 
        Convention => C, 
        External_Name => "umask";

   function mkdir (uu_path : Interfaces.C.Strings.chars_ptr; uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:317
   with Import => True, 
        Convention => C, 
        External_Name => "mkdir";

   function mkdirat
     (uu_fd : int;
      uu_path : Interfaces.C.Strings.chars_ptr;
      uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:324
   with Import => True, 
        Convention => C, 
        External_Name => "mkdirat";

   function mknod
     (uu_path : Interfaces.C.Strings.chars_ptr;
      uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t;
      uu_dev : x86_64_linux_gnu_bits_types_h.uu_dev_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:332
   with Import => True, 
        Convention => C, 
        External_Name => "mknod";

   function mknodat
     (uu_fd : int;
      uu_path : Interfaces.C.Strings.chars_ptr;
      uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t;
      uu_dev : x86_64_linux_gnu_bits_types_h.uu_dev_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:339
   with Import => True, 
        Convention => C, 
        External_Name => "mknodat";

   function mkfifo (uu_path : Interfaces.C.Strings.chars_ptr; uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:346
   with Import => True, 
        Convention => C, 
        External_Name => "mkfifo";

   function mkfifoat
     (uu_fd : int;
      uu_path : Interfaces.C.Strings.chars_ptr;
      uu_mode : x86_64_linux_gnu_bits_types_h.uu_mode_t) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:353
   with Import => True, 
        Convention => C, 
        External_Name => "mkfifoat";

   function utimensat
     (uu_fd : int;
      uu_path : Interfaces.C.Strings.chars_ptr;
      uu_times : access constant x86_64_linux_gnu_bits_types_struct_timespec_h.timespec;
      uu_flags : int) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:360
   with Import => True, 
        Convention => C, 
        External_Name => "utimensat";

   function futimens (uu_fd : int; uu_times : access constant x86_64_linux_gnu_bits_types_struct_timespec_h.timespec) return int  -- /usr/include/x86_64-linux-gnu/sys/stat.h:368
   with Import => True, 
        Convention => C, 
        External_Name => "futimens";

   --  skipped func __fxstat

   --  skipped func __xstat

   --  skipped func __lxstat

   --  skipped func __fxstatat

   --  skipped func __xmknod

   --  skipped func __xmknodat

end x86_64_linux_gnu_sys_stat_h;
