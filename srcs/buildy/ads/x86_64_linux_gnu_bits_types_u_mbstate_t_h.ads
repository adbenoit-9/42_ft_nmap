pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;

package x86_64_linux_gnu_bits_types_u_mbstate_t_h is

   subtype uu_mbstate_t_uu_wchb_array is Interfaces.C.char_array (0 .. 3);
   type uu_mbstate_t_uu_value_union (discr : unsigned := 0) is record
      case discr is
         when 0 =>
            uu_wch : aliased unsigned;  -- /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h:18
         when others =>
            uu_wchb : aliased uu_mbstate_t_uu_wchb_array;  -- /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h:19
      end case;
   end record
   with Convention => C_Pass_By_Copy,
        Unchecked_Union => True;
   type uu_mbstate_t is record
      uu_count : aliased int;  -- /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h:15
      uu_value : aliased uu_mbstate_t_uu_value_union;  -- /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h:20
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/x86_64-linux-gnu/bits/types/__mbstate_t.h:21

end x86_64_linux_gnu_bits_types_u_mbstate_t_h;
