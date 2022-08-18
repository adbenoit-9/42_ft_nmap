pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with Interfaces.C.Strings;
with System;
with Interfaces.C.Extensions;
with stddef_h;
with x86_64_linux_gnu_bits_stdint_intn_h;

package stdlib_h is

   --  arg-macro: procedure WEXITSTATUS (status)
   --    __WEXITSTATUS (status)
   --  arg-macro: procedure WTERMSIG (status)
   --    __WTERMSIG (status)
   --  arg-macro: procedure WSTOPSIG (status)
   --    __WSTOPSIG (status)
   --  arg-macro: procedure WIFEXITED (status)
   --    __WIFEXITED (status)
   --  arg-macro: procedure WIFSIGNALED (status)
   --    __WIFSIGNALED (status)
   --  arg-macro: procedure WIFSTOPPED (status)
   --    __WIFSTOPPED (status)
   --  arg-macro: procedure WIFCONTINUED (status)
   --    __WIFCONTINUED (status)
   RAND_MAX : constant := 2147483647;  --  /usr/include/stdlib.h:86

   EXIT_FAILURE : constant := 1;  --  /usr/include/stdlib.h:91
   EXIT_SUCCESS : constant := 0;  --  /usr/include/stdlib.h:92
   --  unsupported macro: MB_CUR_MAX (__ctype_get_mb_cur_max ())

   type div_t is record
      quot : aliased int;  -- /usr/include/stdlib.h:60
      c_rem : aliased int;  -- /usr/include/stdlib.h:61
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/stdlib.h:62

   type ldiv_t is record
      quot : aliased long;  -- /usr/include/stdlib.h:68
      c_rem : aliased long;  -- /usr/include/stdlib.h:69
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/stdlib.h:70

   type lldiv_t is record
      quot : aliased Long_Long_Integer;  -- /usr/include/stdlib.h:78
      c_rem : aliased Long_Long_Integer;  -- /usr/include/stdlib.h:79
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/stdlib.h:80

   --  skipped func __ctype_get_mb_cur_max

   function atof (uu_nptr : Interfaces.C.Strings.chars_ptr) return double  -- /usr/include/stdlib.h:101
   with Import => True, 
        Convention => C, 
        External_Name => "atof";

   function atoi (uu_nptr : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdlib.h:104
   with Import => True, 
        Convention => C, 
        External_Name => "atoi";

   function atol (uu_nptr : Interfaces.C.Strings.chars_ptr) return long  -- /usr/include/stdlib.h:107
   with Import => True, 
        Convention => C, 
        External_Name => "atol";

   function atoll (uu_nptr : Interfaces.C.Strings.chars_ptr) return Long_Long_Integer  -- /usr/include/stdlib.h:112
   with Import => True, 
        Convention => C, 
        External_Name => "atoll";

   function strtod (uu_nptr : Interfaces.C.Strings.chars_ptr; uu_endptr : System.Address) return double  -- /usr/include/stdlib.h:117
   with Import => True, 
        Convention => C, 
        External_Name => "strtod";

   function strtof (uu_nptr : Interfaces.C.Strings.chars_ptr; uu_endptr : System.Address) return float  -- /usr/include/stdlib.h:123
   with Import => True, 
        Convention => C, 
        External_Name => "strtof";

   function strtold (uu_nptr : Interfaces.C.Strings.chars_ptr; uu_endptr : System.Address) return long_double  -- /usr/include/stdlib.h:126
   with Import => True, 
        Convention => C, 
        External_Name => "strtold";

   function strtol
     (uu_nptr : Interfaces.C.Strings.chars_ptr;
      uu_endptr : System.Address;
      uu_base : int) return long  -- /usr/include/stdlib.h:176
   with Import => True, 
        Convention => C, 
        External_Name => "strtol";

   function strtoul
     (uu_nptr : Interfaces.C.Strings.chars_ptr;
      uu_endptr : System.Address;
      uu_base : int) return unsigned_long  -- /usr/include/stdlib.h:180
   with Import => True, 
        Convention => C, 
        External_Name => "strtoul";

   function strtoq
     (uu_nptr : Interfaces.C.Strings.chars_ptr;
      uu_endptr : System.Address;
      uu_base : int) return Long_Long_Integer  -- /usr/include/stdlib.h:187
   with Import => True, 
        Convention => C, 
        External_Name => "strtoq";

   function strtouq
     (uu_nptr : Interfaces.C.Strings.chars_ptr;
      uu_endptr : System.Address;
      uu_base : int) return Extensions.unsigned_long_long  -- /usr/include/stdlib.h:192
   with Import => True, 
        Convention => C, 
        External_Name => "strtouq";

   function strtoll
     (uu_nptr : Interfaces.C.Strings.chars_ptr;
      uu_endptr : System.Address;
      uu_base : int) return Long_Long_Integer  -- /usr/include/stdlib.h:200
   with Import => True, 
        Convention => C, 
        External_Name => "strtoll";

   function strtoull
     (uu_nptr : Interfaces.C.Strings.chars_ptr;
      uu_endptr : System.Address;
      uu_base : int) return Extensions.unsigned_long_long  -- /usr/include/stdlib.h:205
   with Import => True, 
        Convention => C, 
        External_Name => "strtoull";

   function l64a (arg1 : long) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:385
   with Import => True, 
        Convention => C, 
        External_Name => "l64a";

   function a64l (uu_s : Interfaces.C.Strings.chars_ptr) return long  -- /usr/include/stdlib.h:388
   with Import => True, 
        Convention => C, 
        External_Name => "a64l";

   function random return long  -- /usr/include/stdlib.h:401
   with Import => True, 
        Convention => C, 
        External_Name => "random";

   procedure srandom (uu_seed : unsigned)  -- /usr/include/stdlib.h:404
   with Import => True, 
        Convention => C, 
        External_Name => "srandom";

   function initstate
     (arg1 : unsigned;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : stddef_h.size_t) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:410
   with Import => True, 
        Convention => C, 
        External_Name => "initstate";

   function setstate (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:415
   with Import => True, 
        Convention => C, 
        External_Name => "setstate";

   type random_data is record
      fptr : access x86_64_linux_gnu_bits_stdint_intn_h.int32_t;  -- /usr/include/stdlib.h:425
      rptr : access x86_64_linux_gnu_bits_stdint_intn_h.int32_t;  -- /usr/include/stdlib.h:426
      state : access x86_64_linux_gnu_bits_stdint_intn_h.int32_t;  -- /usr/include/stdlib.h:427
      rand_type : aliased int;  -- /usr/include/stdlib.h:428
      rand_deg : aliased int;  -- /usr/include/stdlib.h:429
      rand_sep : aliased int;  -- /usr/include/stdlib.h:430
      end_ptr : access x86_64_linux_gnu_bits_stdint_intn_h.int32_t;  -- /usr/include/stdlib.h:431
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/stdlib.h:423

   function random_r (uu_buf : access random_data; uu_result : access x86_64_linux_gnu_bits_stdint_intn_h.int32_t) return int  -- /usr/include/stdlib.h:434
   with Import => True, 
        Convention => C, 
        External_Name => "random_r";

   function srandom_r (uu_seed : unsigned; uu_buf : access random_data) return int  -- /usr/include/stdlib.h:437
   with Import => True, 
        Convention => C, 
        External_Name => "srandom_r";

   function initstate_r
     (uu_seed : unsigned;
      uu_statebuf : Interfaces.C.Strings.chars_ptr;
      uu_statelen : stddef_h.size_t;
      uu_buf : access random_data) return int  -- /usr/include/stdlib.h:440
   with Import => True, 
        Convention => C, 
        External_Name => "initstate_r";

   function setstate_r (uu_statebuf : Interfaces.C.Strings.chars_ptr; uu_buf : access random_data) return int  -- /usr/include/stdlib.h:445
   with Import => True, 
        Convention => C, 
        External_Name => "setstate_r";

   function rand return int  -- /usr/include/stdlib.h:453
   with Import => True, 
        Convention => C, 
        External_Name => "rand";

   procedure srand (uu_seed : unsigned)  -- /usr/include/stdlib.h:455
   with Import => True, 
        Convention => C, 
        External_Name => "srand";

   function rand_r (uu_seed : access unsigned) return int  -- /usr/include/stdlib.h:459
   with Import => True, 
        Convention => C, 
        External_Name => "rand_r";

   function drand48 return double  -- /usr/include/stdlib.h:467
   with Import => True, 
        Convention => C, 
        External_Name => "drand48";

   function erand48 (uu_xsubi : access unsigned_short) return double  -- /usr/include/stdlib.h:468
   with Import => True, 
        Convention => C, 
        External_Name => "erand48";

   function lrand48 return long  -- /usr/include/stdlib.h:471
   with Import => True, 
        Convention => C, 
        External_Name => "lrand48";

   function nrand48 (uu_xsubi : access unsigned_short) return long  -- /usr/include/stdlib.h:472
   with Import => True, 
        Convention => C, 
        External_Name => "nrand48";

   function mrand48 return long  -- /usr/include/stdlib.h:476
   with Import => True, 
        Convention => C, 
        External_Name => "mrand48";

   function jrand48 (uu_xsubi : access unsigned_short) return long  -- /usr/include/stdlib.h:477
   with Import => True, 
        Convention => C, 
        External_Name => "jrand48";

   procedure srand48 (uu_seedval : long)  -- /usr/include/stdlib.h:481
   with Import => True, 
        Convention => C, 
        External_Name => "srand48";

   function seed48 (arg1 : access unsigned_short) return access unsigned_short  -- /usr/include/stdlib.h:482
   with Import => True, 
        Convention => C, 
        External_Name => "seed48";

   procedure lcong48 (uu_param : access unsigned_short)  -- /usr/include/stdlib.h:484
   with Import => True, 
        Convention => C, 
        External_Name => "lcong48";

   type anon1499_uu_x_array is array (0 .. 2) of aliased unsigned_short;
   type anon1499_uu_old_x_array is array (0 .. 2) of aliased unsigned_short;
   type drand48_data is record
      uu_x : aliased anon1499_uu_x_array;  -- /usr/include/stdlib.h:492
      uu_old_x : aliased anon1499_uu_old_x_array;  -- /usr/include/stdlib.h:493
      uu_c : aliased unsigned_short;  -- /usr/include/stdlib.h:494
      uu_init : aliased unsigned_short;  -- /usr/include/stdlib.h:495
      uu_a : aliased Extensions.unsigned_long_long;  -- /usr/include/stdlib.h:496
   end record
   with Convention => C_Pass_By_Copy;  -- /usr/include/stdlib.h:490

   function drand48_r (uu_buffer : access drand48_data; uu_result : access double) return int  -- /usr/include/stdlib.h:501
   with Import => True, 
        Convention => C, 
        External_Name => "drand48_r";

   function erand48_r
     (uu_xsubi : access unsigned_short;
      uu_buffer : access drand48_data;
      uu_result : access double) return int  -- /usr/include/stdlib.h:503
   with Import => True, 
        Convention => C, 
        External_Name => "erand48_r";

   function lrand48_r (uu_buffer : access drand48_data; uu_result : access long) return int  -- /usr/include/stdlib.h:508
   with Import => True, 
        Convention => C, 
        External_Name => "lrand48_r";

   function nrand48_r
     (uu_xsubi : access unsigned_short;
      uu_buffer : access drand48_data;
      uu_result : access long) return int  -- /usr/include/stdlib.h:511
   with Import => True, 
        Convention => C, 
        External_Name => "nrand48_r";

   function mrand48_r (uu_buffer : access drand48_data; uu_result : access long) return int  -- /usr/include/stdlib.h:517
   with Import => True, 
        Convention => C, 
        External_Name => "mrand48_r";

   function jrand48_r
     (uu_xsubi : access unsigned_short;
      uu_buffer : access drand48_data;
      uu_result : access long) return int  -- /usr/include/stdlib.h:520
   with Import => True, 
        Convention => C, 
        External_Name => "jrand48_r";

   function srand48_r (uu_seedval : long; uu_buffer : access drand48_data) return int  -- /usr/include/stdlib.h:526
   with Import => True, 
        Convention => C, 
        External_Name => "srand48_r";

   function seed48_r (uu_seed16v : access unsigned_short; uu_buffer : access drand48_data) return int  -- /usr/include/stdlib.h:529
   with Import => True, 
        Convention => C, 
        External_Name => "seed48_r";

   function lcong48_r (uu_param : access unsigned_short; uu_buffer : access drand48_data) return int  -- /usr/include/stdlib.h:532
   with Import => True, 
        Convention => C, 
        External_Name => "lcong48_r";

   function malloc (arg1 : stddef_h.size_t) return System.Address  -- /usr/include/stdlib.h:539
   with Import => True, 
        Convention => C, 
        External_Name => "malloc";

   function calloc (arg1 : stddef_h.size_t; arg2 : stddef_h.size_t) return System.Address  -- /usr/include/stdlib.h:542
   with Import => True, 
        Convention => C, 
        External_Name => "calloc";

   function realloc (arg1 : System.Address; arg2 : stddef_h.size_t) return System.Address  -- /usr/include/stdlib.h:550
   with Import => True, 
        Convention => C, 
        External_Name => "realloc";

   function reallocarray
     (arg1 : System.Address;
      arg2 : stddef_h.size_t;
      arg3 : stddef_h.size_t) return System.Address  -- /usr/include/stdlib.h:559
   with Import => True, 
        Convention => C, 
        External_Name => "reallocarray";

   procedure free (uu_ptr : System.Address)  -- /usr/include/stdlib.h:565
   with Import => True, 
        Convention => C, 
        External_Name => "free";

   function valloc (arg1 : stddef_h.size_t) return System.Address  -- /usr/include/stdlib.h:574
   with Import => True, 
        Convention => C, 
        External_Name => "valloc";

   function posix_memalign
     (uu_memptr : System.Address;
      uu_alignment : stddef_h.size_t;
      uu_size : stddef_h.size_t) return int  -- /usr/include/stdlib.h:580
   with Import => True, 
        Convention => C, 
        External_Name => "posix_memalign";

   function aligned_alloc (arg1 : stddef_h.size_t; arg2 : stddef_h.size_t) return System.Address  -- /usr/include/stdlib.h:586
   with Import => True, 
        Convention => C, 
        External_Name => "aligned_alloc";

   procedure c_abort  -- /usr/include/stdlib.h:591
   with Import => True, 
        Convention => C, 
        External_Name => "abort";

   function atexit (uu_func : access procedure) return int  -- /usr/include/stdlib.h:595
   with Import => True, 
        Convention => C, 
        External_Name => "atexit";

   function at_quick_exit (uu_func : access procedure) return int  -- /usr/include/stdlib.h:603
   with Import => True, 
        Convention => C, 
        External_Name => "at_quick_exit";

   function on_exit (uu_func : access procedure (arg1 : int; arg2 : System.Address); uu_arg : System.Address) return int  -- /usr/include/stdlib.h:610
   with Import => True, 
        Convention => C, 
        External_Name => "on_exit";

   procedure c_exit (uu_status : int)  -- /usr/include/stdlib.h:617
   with Import => True, 
        Convention => C, 
        External_Name => "exit";

   procedure quick_exit (uu_status : int)  -- /usr/include/stdlib.h:623
   with Import => True, 
        Convention => C, 
        External_Name => "quick_exit";

   --  skipped func _Exit

   function getenv (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:634
   with Import => True, 
        Convention => C, 
        External_Name => "getenv";

   function putenv (uu_string : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdlib.h:647
   with Import => True, 
        Convention => C, 
        External_Name => "putenv";

   function setenv
     (uu_name : Interfaces.C.Strings.chars_ptr;
      uu_value : Interfaces.C.Strings.chars_ptr;
      uu_replace : int) return int  -- /usr/include/stdlib.h:653
   with Import => True, 
        Convention => C, 
        External_Name => "setenv";

   function unsetenv (uu_name : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdlib.h:657
   with Import => True, 
        Convention => C, 
        External_Name => "unsetenv";

   function clearenv return int  -- /usr/include/stdlib.h:664
   with Import => True, 
        Convention => C, 
        External_Name => "clearenv";

   function mktemp (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:675
   with Import => True, 
        Convention => C, 
        External_Name => "mktemp";

   function mkstemp (uu_template : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdlib.h:688
   with Import => True, 
        Convention => C, 
        External_Name => "mkstemp";

   function mkstemps (uu_template : Interfaces.C.Strings.chars_ptr; uu_suffixlen : int) return int  -- /usr/include/stdlib.h:710
   with Import => True, 
        Convention => C, 
        External_Name => "mkstemps";

   function mkdtemp (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:731
   with Import => True, 
        Convention => C, 
        External_Name => "mkdtemp";

   function c_system (uu_command : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdlib.h:784
   with Import => True, 
        Convention => C, 
        External_Name => "system";

   function realpath (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:800
   with Import => True, 
        Convention => C, 
        External_Name => "realpath";

   type uu_compar_fn_t is access function (arg1 : System.Address; arg2 : System.Address) return int
   with Convention => C;  -- /usr/include/stdlib.h:808

   function bsearch
     (arg1 : System.Address;
      arg2 : System.Address;
      arg3 : stddef_h.size_t;
      arg4 : stddef_h.size_t;
      arg5 : uu_compar_fn_t) return System.Address  -- /usr/include/stdlib.h:820
   with Import => True, 
        Convention => C, 
        External_Name => "bsearch";

   procedure qsort
     (uu_base : System.Address;
      uu_nmemb : stddef_h.size_t;
      uu_size : stddef_h.size_t;
      uu_compar : uu_compar_fn_t)  -- /usr/include/stdlib.h:830
   with Import => True, 
        Convention => C, 
        External_Name => "qsort";

   function c_abs (uu_x : int) return int  -- /usr/include/stdlib.h:840
   with Import => True, 
        Convention => C, 
        External_Name => "abs";

   function labs (uu_x : long) return long  -- /usr/include/stdlib.h:841
   with Import => True, 
        Convention => C, 
        External_Name => "labs";

   function llabs (uu_x : Long_Long_Integer) return Long_Long_Integer  -- /usr/include/stdlib.h:844
   with Import => True, 
        Convention => C, 
        External_Name => "llabs";

   function div (uu_numer : int; uu_denom : int) return div_t  -- /usr/include/stdlib.h:852
   with Import => True, 
        Convention => C, 
        External_Name => "div";

   function ldiv (uu_numer : long; uu_denom : long) return ldiv_t  -- /usr/include/stdlib.h:854
   with Import => True, 
        Convention => C, 
        External_Name => "ldiv";

   function lldiv (uu_numer : Long_Long_Integer; uu_denom : Long_Long_Integer) return lldiv_t  -- /usr/include/stdlib.h:858
   with Import => True, 
        Convention => C, 
        External_Name => "lldiv";

   function ecvt
     (arg1 : double;
      arg2 : int;
      arg3 : access int;
      arg4 : access int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:872
   with Import => True, 
        Convention => C, 
        External_Name => "ecvt";

   function fcvt
     (arg1 : double;
      arg2 : int;
      arg3 : access int;
      arg4 : access int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:878
   with Import => True, 
        Convention => C, 
        External_Name => "fcvt";

   function gcvt
     (arg1 : double;
      arg2 : int;
      arg3 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:884
   with Import => True, 
        Convention => C, 
        External_Name => "gcvt";

   function qecvt
     (arg1 : long_double;
      arg2 : int;
      arg3 : access int;
      arg4 : access int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:890
   with Import => True, 
        Convention => C, 
        External_Name => "qecvt";

   function qfcvt
     (arg1 : long_double;
      arg2 : int;
      arg3 : access int;
      arg4 : access int) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:893
   with Import => True, 
        Convention => C, 
        External_Name => "qfcvt";

   function qgcvt
     (arg1 : long_double;
      arg2 : int;
      arg3 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdlib.h:896
   with Import => True, 
        Convention => C, 
        External_Name => "qgcvt";

   function ecvt_r
     (uu_value : double;
      uu_ndigit : int;
      uu_decpt : access int;
      uu_sign : access int;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_len : stddef_h.size_t) return int  -- /usr/include/stdlib.h:902
   with Import => True, 
        Convention => C, 
        External_Name => "ecvt_r";

   function fcvt_r
     (uu_value : double;
      uu_ndigit : int;
      uu_decpt : access int;
      uu_sign : access int;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_len : stddef_h.size_t) return int  -- /usr/include/stdlib.h:905
   with Import => True, 
        Convention => C, 
        External_Name => "fcvt_r";

   function qecvt_r
     (uu_value : long_double;
      uu_ndigit : int;
      uu_decpt : access int;
      uu_sign : access int;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_len : stddef_h.size_t) return int  -- /usr/include/stdlib.h:909
   with Import => True, 
        Convention => C, 
        External_Name => "qecvt_r";

   function qfcvt_r
     (uu_value : long_double;
      uu_ndigit : int;
      uu_decpt : access int;
      uu_sign : access int;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_len : stddef_h.size_t) return int  -- /usr/include/stdlib.h:913
   with Import => True, 
        Convention => C, 
        External_Name => "qfcvt_r";

   function mblen (uu_s : Interfaces.C.Strings.chars_ptr; uu_n : stddef_h.size_t) return int  -- /usr/include/stdlib.h:922
   with Import => True, 
        Convention => C, 
        External_Name => "mblen";

   function mbtowc
     (uu_pwc : access stddef_h.wchar_t;
      uu_s : Interfaces.C.Strings.chars_ptr;
      uu_n : stddef_h.size_t) return int  -- /usr/include/stdlib.h:925
   with Import => True, 
        Convention => C, 
        External_Name => "mbtowc";

   function wctomb (uu_s : Interfaces.C.Strings.chars_ptr; uu_wchar : stddef_h.wchar_t) return int  -- /usr/include/stdlib.h:929
   with Import => True, 
        Convention => C, 
        External_Name => "wctomb";

   function mbstowcs
     (uu_pwcs : access stddef_h.wchar_t;
      uu_s : Interfaces.C.Strings.chars_ptr;
      uu_n : stddef_h.size_t) return stddef_h.size_t  -- /usr/include/stdlib.h:933
   with Import => True, 
        Convention => C, 
        External_Name => "mbstowcs";

   function wcstombs
     (uu_s : Interfaces.C.Strings.chars_ptr;
      uu_pwcs : access stddef_h.wchar_t;
      uu_n : stddef_h.size_t) return stddef_h.size_t  -- /usr/include/stdlib.h:936
   with Import => True, 
        Convention => C, 
        External_Name => "wcstombs";

   function rpmatch (uu_response : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdlib.h:946
   with Import => True, 
        Convention => C, 
        External_Name => "rpmatch";

   function getsubopt
     (uu_optionp : System.Address;
      uu_tokens : System.Address;
      uu_valuep : System.Address) return int  -- /usr/include/stdlib.h:957
   with Import => True, 
        Convention => C, 
        External_Name => "getsubopt";

   function getloadavg (uu_loadavg : access double; uu_nelem : int) return int  -- /usr/include/stdlib.h:1003
   with Import => True, 
        Convention => C, 
        External_Name => "getloadavg";

end stdlib_h;
