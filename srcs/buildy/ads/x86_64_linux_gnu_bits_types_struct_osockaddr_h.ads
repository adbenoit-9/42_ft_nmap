pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;

package x86_64_linux_gnu_bits_types_struct_osockaddr_h is

   type anon1052_sa_data_array is array (0 .. 13) of aliased unsigned_char;
   type osockaddr is record
      sa_family : aliased unsigned_short;  -- /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h:8
      sa_data : aliased anon1052_sa_data_array;  -- /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h:9
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/x86_64-linux-gnu/bits/types/struct_osockaddr.h:6

end x86_64_linux_gnu_bits_types_struct_osockaddr_h;
