pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;

package stddef_h is

   --  unsupported macro: NULL ((void *)0)
   subtype size_t is unsigned_long;  -- /usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h:209

   subtype wchar_t is int;  -- /usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h:321

end stddef_h;
