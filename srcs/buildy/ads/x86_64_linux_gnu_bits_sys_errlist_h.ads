pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Strings;

package x86_64_linux_gnu_bits_sys_errlist_h is

   sys_nerr : aliased int  -- /usr/include/x86_64-linux-gnu/bits/sys_errlist.h:26
   with Import => True, 
        Convention => C, 
        External_Name => "sys_nerr";

   sys_errlist : array (size_t) of Interfaces.C.Strings.chars_ptr  -- /usr/include/x86_64-linux-gnu/bits/sys_errlist.h:27
   with Import => True, 
        Convention => C, 
        External_Name => "sys_errlist";

end x86_64_linux_gnu_bits_sys_errlist_h;
