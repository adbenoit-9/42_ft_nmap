pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with stddef_h;
with System;

package get_next_line_h is

   BUFFER_SIZE : constant := 4096;  --  ../libft/inc/get_next_line.h:23

   type s_gnl is record
      fd : aliased int;  -- ../libft/inc/get_next_line.h:27
      len : aliased stddef_h.size_t;  -- ../libft/inc/get_next_line.h:28
   end record
   with Convention => C_Pass_By_Copy;  -- ../libft/inc/get_next_line.h:25

   subtype t_gnl is s_gnl;  -- ../libft/inc/get_next_line.h:29

   function get_next_line (fd : int; line : System.Address) return int  -- ../libft/inc/get_next_line.h:31
   with Import => True, 
        Convention => C, 
        External_Name => "get_next_line";

end get_next_line_h;
