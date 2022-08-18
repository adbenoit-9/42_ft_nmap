pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;

package x86_64_linux_gnu_bits_waitflags_h is

   WNOHANG : constant := 1;  --  /usr/include/x86_64-linux-gnu/bits/waitflags.h:25
   WUNTRACED : constant := 2;  --  /usr/include/x86_64-linux-gnu/bits/waitflags.h:26

   WSTOPPED : constant := 2;  --  /usr/include/x86_64-linux-gnu/bits/waitflags.h:30
   WEXITED : constant := 4;  --  /usr/include/x86_64-linux-gnu/bits/waitflags.h:31
   WCONTINUED : constant := 8;  --  /usr/include/x86_64-linux-gnu/bits/waitflags.h:32
   WNOWAIT : constant := 16#01000000#;  --  /usr/include/x86_64-linux-gnu/bits/waitflags.h:33

   type idtype_t is 
     (P_ALL,
      P_PID,
      P_PGID)
   with Convention => C;  -- /usr/include/x86_64-linux-gnu/bits/waitflags.h:57

end x86_64_linux_gnu_bits_waitflags_h;
