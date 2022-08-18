pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with System;

package stdarg_h is

   subtype uu_gnuc_va_list is System.Address;  -- /usr/lib/gcc/x86_64-linux-gnu/9/include/stdarg.h:40

end stdarg_h;
