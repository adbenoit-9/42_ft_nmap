pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with System;
with stddef_h;
with Interfaces.C.Strings;
with x86_64_linux_gnu_bits_types_locale_t_h;

package string_h is

   function memcpy
     (arg1 : System.Address;
      arg2 : System.Address;
      arg3 : stddef_h.size_t) return System.Address  -- /usr/include/string.h:43
   with Import => True, 
        Convention => C, 
        External_Name => "memcpy";

   function memmove
     (arg1 : System.Address;
      arg2 : System.Address;
      arg3 : stddef_h.size_t) return System.Address  -- /usr/include/string.h:47
   with Import => True, 
        Convention => C, 
        External_Name => "memmove";

   function memccpy
     (arg1 : System.Address;
      arg2 : System.Address;
      arg3 : int;
      arg4 : stddef_h.size_t) return System.Address  -- /usr/include/string.h:54
   with Import => True, 
        Convention => C, 
        External_Name => "memccpy";

   function memset
     (arg1 : System.Address;
      arg2 : int;
      arg3 : stddef_h.size_t) return System.Address  -- /usr/include/string.h:61
   with Import => True, 
        Convention => C, 
        External_Name => "memset";

   function memcmp
     (uu_s1 : System.Address;
      uu_s2 : System.Address;
      uu_n : stddef_h.size_t) return int  -- /usr/include/string.h:64
   with Import => True, 
        Convention => C, 
        External_Name => "memcmp";

   function memchr
     (arg1 : System.Address;
      arg2 : int;
      arg3 : stddef_h.size_t) return System.Address  -- /usr/include/string.h:91
   with Import => True, 
        Convention => C, 
        External_Name => "memchr";

   function strcpy (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:122
   with Import => True, 
        Convention => C, 
        External_Name => "strcpy";

   function strncpy
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:125
   with Import => True, 
        Convention => C, 
        External_Name => "strncpy";

   function strcat (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:130
   with Import => True, 
        Convention => C, 
        External_Name => "strcat";

   function strncat
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:133
   with Import => True, 
        Convention => C, 
        External_Name => "strncat";

   function strcmp (uu_s1 : Interfaces.C.Strings.chars_ptr; uu_s2 : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/string.h:137
   with Import => True, 
        Convention => C, 
        External_Name => "strcmp";

   function strncmp
     (uu_s1 : Interfaces.C.Strings.chars_ptr;
      uu_s2 : Interfaces.C.Strings.chars_ptr;
      uu_n : stddef_h.size_t) return int  -- /usr/include/string.h:140
   with Import => True, 
        Convention => C, 
        External_Name => "strncmp";

   function strcoll (uu_s1 : Interfaces.C.Strings.chars_ptr; uu_s2 : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/string.h:144
   with Import => True, 
        Convention => C, 
        External_Name => "strcoll";

   function strxfrm
     (uu_dest : Interfaces.C.Strings.chars_ptr;
      uu_src : Interfaces.C.Strings.chars_ptr;
      uu_n : stddef_h.size_t) return stddef_h.size_t  -- /usr/include/string.h:147
   with Import => True, 
        Convention => C, 
        External_Name => "strxfrm";

   function strcoll_l
     (uu_s1 : Interfaces.C.Strings.chars_ptr;
      uu_s2 : Interfaces.C.Strings.chars_ptr;
      uu_l : x86_64_linux_gnu_bits_types_locale_t_h.locale_t) return int  -- /usr/include/string.h:156
   with Import => True, 
        Convention => C, 
        External_Name => "strcoll_l";

   function strxfrm_l
     (uu_dest : Interfaces.C.Strings.chars_ptr;
      uu_src : Interfaces.C.Strings.chars_ptr;
      uu_n : stddef_h.size_t;
      uu_l : x86_64_linux_gnu_bits_types_locale_t_h.locale_t) return stddef_h.size_t  -- /usr/include/string.h:160
   with Import => True, 
        Convention => C, 
        External_Name => "strxfrm_l";

   function strdup (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:167
   with Import => True, 
        Convention => C, 
        External_Name => "strdup";

   function strndup (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:175
   with Import => True, 
        Convention => C, 
        External_Name => "strndup";

   function strchr (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:226
   with Import => True, 
        Convention => C, 
        External_Name => "strchr";

   function strrchr (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:253
   with Import => True, 
        Convention => C, 
        External_Name => "strrchr";

   function strcspn (uu_s : Interfaces.C.Strings.chars_ptr; uu_reject : Interfaces.C.Strings.chars_ptr) return stddef_h.size_t  -- /usr/include/string.h:273
   with Import => True, 
        Convention => C, 
        External_Name => "strcspn";

   function strspn (uu_s : Interfaces.C.Strings.chars_ptr; uu_accept : Interfaces.C.Strings.chars_ptr) return stddef_h.size_t  -- /usr/include/string.h:277
   with Import => True, 
        Convention => C, 
        External_Name => "strspn";

   function strpbrk (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:303
   with Import => True, 
        Convention => C, 
        External_Name => "strpbrk";

   function strstr (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:330
   with Import => True, 
        Convention => C, 
        External_Name => "strstr";

   function strtok (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:336
   with Import => True, 
        Convention => C, 
        External_Name => "strtok";

   --  skipped func __strtok_r

   function strtok_r
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : System.Address) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:346
   with Import => True, 
        Convention => C, 
        External_Name => "strtok_r";

   function strlen (uu_s : Interfaces.C.Strings.chars_ptr) return stddef_h.size_t  -- /usr/include/string.h:385
   with Import => True, 
        Convention => C, 
        External_Name => "strlen";

   function strnlen (uu_string : Interfaces.C.Strings.chars_ptr; uu_maxlen : stddef_h.size_t) return stddef_h.size_t  -- /usr/include/string.h:391
   with Import => True, 
        Convention => C, 
        External_Name => "strnlen";

   function strerror (arg1 : int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:397
   with Import => True, 
        Convention => C, 
        External_Name => "strerror";

   function strerror_r
     (uu_errnum : int;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_buflen : stddef_h.size_t) return int  -- /usr/include/string.h:410
   with Import => True, 
        Convention => C, 
        External_Name => "__xpg_strerror_r";

   function strerror_l (arg1 : int; arg2 : x86_64_linux_gnu_bits_types_locale_t_h.locale_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:428
   with Import => True, 
        Convention => C, 
        External_Name => "strerror_l";

   procedure explicit_bzero (uu_s : System.Address; uu_n : stddef_h.size_t)  -- /usr/include/string.h:436
   with Import => True, 
        Convention => C, 
        External_Name => "explicit_bzero";

   function strsep (arg1 : System.Address; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:440
   with Import => True, 
        Convention => C, 
        External_Name => "strsep";

   function strsignal (arg1 : int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:447
   with Import => True, 
        Convention => C, 
        External_Name => "strsignal";

   --  skipped func __stpcpy

   function stpcpy (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:452
   with Import => True, 
        Convention => C, 
        External_Name => "stpcpy";

   --  skipped func __stpncpy

   function stpncpy
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/string.h:460
   with Import => True, 
        Convention => C, 
        External_Name => "stpncpy";

end string_h;
