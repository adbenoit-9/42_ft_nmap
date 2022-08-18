pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Strings;

package x86_64_linux_gnu_bits_types_u_locale_t_h is

   type uu_locale_data is null record;   -- incomplete struct

   type anon1281_uu_locales_array is array (0 .. 12) of access uu_locale_data;
   type anon1281_uu_names_array is array (0 .. 12) of Interfaces.C.Strings.chars_ptr;
   type uu_locale_struct is record
      uu_locales : anon1281_uu_locales_array;  -- /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h:31
      uu_ctype_b : access unsigned_short;  -- /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h:34
      uu_ctype_tolower : access int;  -- /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h:35
      uu_ctype_toupper : access int;  -- /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h:36
      uu_names : anon1281_uu_names_array;  -- /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h:39
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h:28

   type uu_locale_t is access all uu_locale_struct;  -- /usr/include/x86_64-linux-gnu/bits/types/__locale_t.h:42

end x86_64_linux_gnu_bits_types_u_locale_t_h;
