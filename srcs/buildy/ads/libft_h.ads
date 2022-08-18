pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with System;
with stddef_h;
with Interfaces.C.Strings;

package libft_h is

   type s_list;
   type s_list is record
      content : System.Address;  -- ../libft/inc/libft.h:23
      next : access s_list;  -- ../libft/inc/libft.h:24
   end record
   with Convention => C_Pass_By_Copy;  -- ../libft/inc/libft.h:21

   subtype t_list is s_list;  -- ../libft/inc/libft.h:25

   procedure ft_bzero (s : System.Address; n : stddef_h.size_t)  -- ../libft/inc/libft.h:31
   with Import => True, 
        Convention => C, 
        External_Name => "ft_bzero";

   function ft_calloc (arg1 : stddef_h.size_t; arg2 : stddef_h.size_t) return System.Address  -- ../libft/inc/libft.h:32
   with Import => True, 
        Convention => C, 
        External_Name => "ft_calloc";

   function ft_memccpy
     (arg1 : System.Address;
      arg2 : System.Address;
      arg3 : int;
      arg4 : stddef_h.size_t) return System.Address  -- ../libft/inc/libft.h:33
   with Import => True, 
        Convention => C, 
        External_Name => "ft_memccpy";

   function ft_memchr
     (arg1 : System.Address;
      arg2 : int;
      arg3 : stddef_h.size_t) return System.Address  -- ../libft/inc/libft.h:34
   with Import => True, 
        Convention => C, 
        External_Name => "ft_memchr";

   function ft_memcmp
     (s1 : System.Address;
      s2 : System.Address;
      n : stddef_h.size_t) return int  -- ../libft/inc/libft.h:35
   with Import => True, 
        Convention => C, 
        External_Name => "ft_memcmp";

   function ft_memcpy
     (arg1 : System.Address;
      arg2 : System.Address;
      arg3 : stddef_h.size_t) return System.Address  -- ../libft/inc/libft.h:36
   with Import => True, 
        Convention => C, 
        External_Name => "ft_memcpy";

   function ft_memmove
     (arg1 : System.Address;
      arg2 : System.Address;
      arg3 : stddef_h.size_t) return System.Address  -- ../libft/inc/libft.h:37
   with Import => True, 
        Convention => C, 
        External_Name => "ft_memmove";

   function ft_memset
     (arg1 : System.Address;
      arg2 : int;
      arg3 : stddef_h.size_t) return System.Address  -- ../libft/inc/libft.h:38
   with Import => True, 
        Convention => C, 
        External_Name => "ft_memset";

   procedure ft_putendl_fd (s : Interfaces.C.Strings.chars_ptr; fd : int)  -- ../libft/inc/libft.h:44
   with Import => True, 
        Convention => C, 
        External_Name => "ft_putendl_fd";

   procedure ft_putstr_fd (s : Interfaces.C.Strings.chars_ptr; fd : int)  -- ../libft/inc/libft.h:45
   with Import => True, 
        Convention => C, 
        External_Name => "ft_putstr_fd";

   function ft_split (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : char) return System.Address  -- ../libft/inc/libft.h:46
   with Import => True, 
        Convention => C, 
        External_Name => "ft_split";

   function ft_strchr (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : int) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:47
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strchr";

   function ft_strdup (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:48
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strdup";

   function ft_strjoin (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:49
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strjoin";

   function ft_strlen (s : Interfaces.C.Strings.chars_ptr) return stddef_h.size_t  -- ../libft/inc/libft.h:50
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strlen";

   function ft_strlcat
     (dest : Interfaces.C.Strings.chars_ptr;
      src : Interfaces.C.Strings.chars_ptr;
      dstsize : stddef_h.size_t) return stddef_h.size_t  -- ../libft/inc/libft.h:51
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strlcat";

   function ft_strcat (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:52
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strcat";

   function ft_strlcpy
     (dest : Interfaces.C.Strings.chars_ptr;
      src : Interfaces.C.Strings.chars_ptr;
      dstsize : stddef_h.size_t) return stddef_h.size_t  -- ../libft/inc/libft.h:53
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strlcpy";

   function ft_strmapi (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : access function (arg1 : unsigned; arg2 : char) return char) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:54
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strmapi";

   function ft_strcmp (s1 : Interfaces.C.Strings.chars_ptr; s2 : Interfaces.C.Strings.chars_ptr) return int  -- ../libft/inc/libft.h:55
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strcmp";

   function ft_strncmp
     (s1 : Interfaces.C.Strings.chars_ptr;
      s2 : Interfaces.C.Strings.chars_ptr;
      n : stddef_h.size_t) return int  -- ../libft/inc/libft.h:56
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strncmp";

   function ft_strcpy (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:57
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strcpy";

   function ft_strncpy
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:58
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strncpy";

   function ft_strndup (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:59
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strndup";

   function ft_strrchr (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : int) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:60
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strrchr";

   function ft_strtrim (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:61
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strtrim";

   function ft_substr
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : unsigned;
      arg3 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:62
   with Import => True, 
        Convention => C, 
        External_Name => "ft_substr";

   function ft_realloc (arg1 : System.Address; arg2 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:63
   with Import => True, 
        Convention => C, 
        External_Name => "ft_realloc";

   function ft_strnstr
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:64
   with Import => True, 
        Convention => C, 
        External_Name => "ft_strnstr";

   function ft_tolower (c : int) return int  -- ../libft/inc/libft.h:71
   with Import => True, 
        Convention => C, 
        External_Name => "ft_tolower";

   function ft_toupper (c : int) return int  -- ../libft/inc/libft.h:72
   with Import => True, 
        Convention => C, 
        External_Name => "ft_toupper";

   procedure ft_putchar_fd (c : char; fd : int)  -- ../libft/inc/libft.h:73
   with Import => True, 
        Convention => C, 
        External_Name => "ft_putchar_fd";

   function ft_isalnum (c : int) return int  -- ../libft/inc/libft.h:74
   with Import => True, 
        Convention => C, 
        External_Name => "ft_isalnum";

   function ft_isalpha (c : int) return int  -- ../libft/inc/libft.h:75
   with Import => True, 
        Convention => C, 
        External_Name => "ft_isalpha";

   function ft_isascii (c : int) return int  -- ../libft/inc/libft.h:76
   with Import => True, 
        Convention => C, 
        External_Name => "ft_isascii";

   function ft_isdigit (c : int) return int  -- ../libft/inc/libft.h:77
   with Import => True, 
        Convention => C, 
        External_Name => "ft_isdigit";

   function ft_isprint (c : int) return int  -- ../libft/inc/libft.h:78
   with Import => True, 
        Convention => C, 
        External_Name => "ft_isprint";

   function ft_atoi (str : Interfaces.C.Strings.chars_ptr) return int  -- ../libft/inc/libft.h:84
   with Import => True, 
        Convention => C, 
        External_Name => "ft_atoi";

   function ft_itoa (arg1 : int) return Interfaces.C.Strings.chars_ptr  -- ../libft/inc/libft.h:85
   with Import => True, 
        Convention => C, 
        External_Name => "ft_itoa";

   procedure ft_putnbr_fd (n : int; fd : int)  -- ../libft/inc/libft.h:86
   with Import => True, 
        Convention => C, 
        External_Name => "ft_putnbr_fd";

   function ft_lstnew (arg1 : System.Address) return access t_list  -- ../libft/inc/libft.h:92
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstnew";

   procedure ft_lstadd_front (alst : System.Address; c_new : access t_list)  -- ../libft/inc/libft.h:93
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstadd_front";

   function ft_lstsize (lst : access t_list) return int  -- ../libft/inc/libft.h:94
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstsize";

   procedure ft_lstadd_back (alst : System.Address; c_new : access t_list)  -- ../libft/inc/libft.h:95
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstadd_back";

   function ft_lstlast (arg1 : access t_list) return access t_list  -- ../libft/inc/libft.h:96
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstlast";

   procedure ft_lstdelone (lst : access t_list; del : access procedure (arg1 : System.Address))  -- ../libft/inc/libft.h:97
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstdelone";

   procedure ft_lstclear (lst : System.Address; del : access procedure (arg1 : System.Address))  -- ../libft/inc/libft.h:98
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstclear";

   procedure ft_lstiter (lst : access t_list; f : access procedure (arg1 : System.Address))  -- ../libft/inc/libft.h:99
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstiter";

   function ft_lstmap
     (arg1 : access t_list;
      arg2 : access function (arg1 : System.Address) return System.Address;
      arg3 : access procedure (arg1 : System.Address)) return access t_list  -- ../libft/inc/libft.h:100
   with Import => True, 
        Convention => C, 
        External_Name => "ft_lstmap";

   function ft_freetab (arg1 : System.Address) return System.Address  -- ../libft/inc/libft.h:107
   with Import => True, 
        Convention => C, 
        External_Name => "ft_freetab";

   procedure ft_puttab_fd (tab : System.Address; fd : int)  -- ../libft/inc/libft.h:108
   with Import => True, 
        Convention => C, 
        External_Name => "ft_puttab_fd";

   function ft_realloc_tab (arg1 : System.Address; arg2 : stddef_h.size_t) return System.Address  -- ../libft/inc/libft.h:109
   with Import => True, 
        Convention => C, 
        External_Name => "ft_realloc_tab";

   function ft_tabdup (arg1 : System.Address) return System.Address  -- ../libft/inc/libft.h:110
   with Import => True, 
        Convention => C, 
        External_Name => "ft_tabdup";

   function ft_tabsize (tab : System.Address) return stddef_h.size_t  -- ../libft/inc/libft.h:111
   with Import => True, 
        Convention => C, 
        External_Name => "ft_tabsize";

end libft_h;
