pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with System;
with stddef_h;

package x86_64_linux_gnu_bits_types_struct_iovec_h is

   type iovec is record
      iov_base : System.Address;  -- /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h:28
      iov_len : aliased stddef_h.size_t;  -- /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h:29
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/x86_64-linux-gnu/bits/types/struct_iovec.h:26

end x86_64_linux_gnu_bits_types_struct_iovec_h;
