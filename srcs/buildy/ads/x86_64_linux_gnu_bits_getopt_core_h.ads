pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Strings;
with System;

package x86_64_linux_gnu_bits_getopt_core_h is

   optarg : Interfaces.C.Strings.chars_ptr  -- /usr/include/x86_64-linux-gnu/bits/getopt_core.h:36
   with Import => True, 
        Convention => C, 
        External_Name => "optarg";

   optind : aliased int  -- /usr/include/x86_64-linux-gnu/bits/getopt_core.h:50
   with Import => True, 
        Convention => C, 
        External_Name => "optind";

   opterr : aliased int  -- /usr/include/x86_64-linux-gnu/bits/getopt_core.h:55
   with Import => True, 
        Convention => C, 
        External_Name => "opterr";

   optopt : aliased int  -- /usr/include/x86_64-linux-gnu/bits/getopt_core.h:59
   with Import => True, 
        Convention => C, 
        External_Name => "optopt";

   function getopt
     (uuu_argc : int;
      uuu_argv : System.Address;
      uu_shortopts : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/x86_64-linux-gnu/bits/getopt_core.h:91
   with Import => True, 
        Convention => C, 
        External_Name => "getopt";

end x86_64_linux_gnu_bits_getopt_core_h;
