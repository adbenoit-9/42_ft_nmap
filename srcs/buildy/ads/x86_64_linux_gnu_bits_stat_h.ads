pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_types_h;
with x86_64_linux_gnu_bits_types_struct_timespec_h;

package x86_64_linux_gnu_bits_stat_h is

   --  unsupported macro: st_atime st_atim.tv_sec
   --  unsupported macro: st_mtime st_mtim.tv_sec
   --  unsupported macro: st_ctime st_ctim.tv_sec
   UTIME_NOW : constant := ((2 ** 30) - 1);  --  /usr/include/x86_64-linux-gnu/bits/stat.h:206
   UTIME_OMIT : constant := ((2 ** 30) - 2);  --  /usr/include/x86_64-linux-gnu/bits/stat.h:207

   type anon1734_uu_glibc_reserved_array is array (0 .. 2) of aliased x86_64_linux_gnu_bits_types_h.uu_syscall_slong_t;
   type stat is record
      st_dev : aliased x86_64_linux_gnu_bits_types_h.uu_dev_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:48
      st_ino : aliased x86_64_linux_gnu_bits_types_h.uu_ino_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:53
      st_nlink : aliased x86_64_linux_gnu_bits_types_h.uu_nlink_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:61
      st_mode : aliased x86_64_linux_gnu_bits_types_h.uu_mode_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:62
      st_uid : aliased x86_64_linux_gnu_bits_types_h.uu_uid_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:64
      st_gid : aliased x86_64_linux_gnu_bits_types_h.uu_gid_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:65
      uu_pad0 : aliased int;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:67
      st_rdev : aliased x86_64_linux_gnu_bits_types_h.uu_dev_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:69
      st_size : aliased x86_64_linux_gnu_bits_types_h.uu_off_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:74
      st_blksize : aliased x86_64_linux_gnu_bits_types_h.uu_blksize_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:78
      st_blocks : aliased x86_64_linux_gnu_bits_types_h.uu_blkcnt_t;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:80
      st_atim : aliased x86_64_linux_gnu_bits_types_struct_timespec_h.timespec;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:91
      st_mtim : aliased x86_64_linux_gnu_bits_types_struct_timespec_h.timespec;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:92
      st_ctim : aliased x86_64_linux_gnu_bits_types_struct_timespec_h.timespec;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:93
      uu_glibc_reserved : aliased anon1734_uu_glibc_reserved_array;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:106
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/x86_64-linux-gnu/bits/stat.h:46

end x86_64_linux_gnu_bits_stat_h;
