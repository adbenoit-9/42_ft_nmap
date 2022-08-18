pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with stddef_h;
with System;

package alloca_h is

   --  arg-macro: procedure alloca (size)
   --    __builtin_alloca (size)
   function alloca (arg1 : stddef_h.size_t) return System.Address  -- /usr/include/alloca.h:32
   with Import => True, 
        Convention => C, 
        External_Name => "alloca";

end alloca_h;
