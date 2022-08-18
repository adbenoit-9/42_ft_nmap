pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with stdarg_h;
with x86_64_linux_gnu_bits_types_u_fpos_t_h;
limited with x86_64_linux_gnu_bits_types_FILE_h;
with Interfaces.C.Strings;
with System;
with stddef_h;
with x86_64_linux_gnu_bits_types_h;

package stdio_h is

   BUFSIZ : constant := 8192;  --  /usr/include/stdio.h:99

   EOF : constant := (-1);  --  /usr/include/stdio.h:104

   P_tmpdir : aliased constant String := "/tmp" & ASCII.NUL;  --  /usr/include/stdio.h:120
   --  unsupported macro: stdin stdin
   --  unsupported macro: stdout stdout
   --  unsupported macro: stderr stderr

   subtype va_list is stdarg_h.uu_gnuc_va_list;  -- /usr/include/stdio.h:52

   subtype fpos_t is x86_64_linux_gnu_bits_types_u_fpos_t_h.uu_fpos_t;  -- /usr/include/stdio.h:84

   stdin : access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:137
   with Import => True, 
        Convention => C, 
        External_Name => "stdin";

   stdout : access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:138
   with Import => True, 
        Convention => C, 
        External_Name => "stdout";

   stderr : access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:139
   with Import => True, 
        Convention => C, 
        External_Name => "stderr";

   function remove (uu_filename : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdio.h:146
   with Import => True, 
        Convention => C, 
        External_Name => "remove";

   function rename (uu_old : Interfaces.C.Strings.chars_ptr; uu_new : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdio.h:148
   with Import => True, 
        Convention => C, 
        External_Name => "rename";

   function renameat
     (uu_oldfd : int;
      uu_old : Interfaces.C.Strings.chars_ptr;
      uu_newfd : int;
      uu_new : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdio.h:152
   with Import => True, 
        Convention => C, 
        External_Name => "renameat";

   function tmpfile return access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:173
   with Import => True, 
        Convention => C, 
        External_Name => "tmpfile";

   function tmpnam (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdio.h:187
   with Import => True, 
        Convention => C, 
        External_Name => "tmpnam";

   function tmpnam_r (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdio.h:192
   with Import => True, 
        Convention => C, 
        External_Name => "tmpnam_r";

   function tempnam (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdio.h:204
   with Import => True, 
        Convention => C, 
        External_Name => "tempnam";

   function fclose (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:213
   with Import => True, 
        Convention => C, 
        External_Name => "fclose";

   function fflush (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:218
   with Import => True, 
        Convention => C, 
        External_Name => "fflush";

   function fflush_unlocked (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:227
   with Import => True, 
        Convention => C, 
        External_Name => "fflush_unlocked";

   function fopen (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:246
   with Import => True, 
        Convention => C, 
        External_Name => "fopen";

   function freopen
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : Interfaces.C.Strings.chars_ptr;
      arg3 : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:252
   with Import => True, 
        Convention => C, 
        External_Name => "freopen";

   function fdopen (arg1 : int; arg2 : Interfaces.C.Strings.chars_ptr) return access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:279
   with Import => True, 
        Convention => C, 
        External_Name => "fdopen";

   function fmemopen
     (arg1 : System.Address;
      arg2 : stddef_h.size_t;
      arg3 : Interfaces.C.Strings.chars_ptr) return access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:292
   with Import => True, 
        Convention => C, 
        External_Name => "fmemopen";

   function open_memstream (arg1 : System.Address; arg2 : access stddef_h.size_t) return access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:298
   with Import => True, 
        Convention => C, 
        External_Name => "open_memstream";

   procedure setbuf (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE; uu_buf : Interfaces.C.Strings.chars_ptr)  -- /usr/include/stdio.h:304
   with Import => True, 
        Convention => C, 
        External_Name => "setbuf";

   function setvbuf
     (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_modes : int;
      uu_n : stddef_h.size_t) return int  -- /usr/include/stdio.h:308
   with Import => True, 
        Convention => C, 
        External_Name => "setvbuf";

   procedure setbuffer
     (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE;
      uu_buf : Interfaces.C.Strings.chars_ptr;
      uu_size : stddef_h.size_t)  -- /usr/include/stdio.h:314
   with Import => True, 
        Convention => C, 
        External_Name => "setbuffer";

   procedure setlinebuf (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE)  -- /usr/include/stdio.h:318
   with Import => True, 
        Convention => C, 
        External_Name => "setlinebuf";

   function fprintf (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE; uu_format : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/stdio.h:326
   with Import => True, 
        Convention => C, 
        External_Name => "fprintf";

   function printf (uu_format : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/stdio.h:332
   with Import => True, 
        Convention => C, 
        External_Name => "printf";

   function sprintf (uu_s : Interfaces.C.Strings.chars_ptr; uu_format : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/stdio.h:334
   with Import => True, 
        Convention => C, 
        External_Name => "sprintf";

   function vfprintf
     (uu_s : access x86_64_linux_gnu_bits_types_FILE_h.FILE;
      uu_format : Interfaces.C.Strings.chars_ptr;
      uu_arg : access System.Address) return int  -- /usr/include/stdio.h:341
   with Import => True, 
        Convention => C, 
        External_Name => "vfprintf";

   function vprintf (uu_format : Interfaces.C.Strings.chars_ptr; uu_arg : access System.Address) return int  -- /usr/include/stdio.h:347
   with Import => True, 
        Convention => C, 
        External_Name => "vprintf";

   function vsprintf
     (uu_s : Interfaces.C.Strings.chars_ptr;
      uu_format : Interfaces.C.Strings.chars_ptr;
      uu_arg : access System.Address) return int  -- /usr/include/stdio.h:349
   with Import => True, 
        Convention => C, 
        External_Name => "vsprintf";

   function snprintf
     (uu_s : Interfaces.C.Strings.chars_ptr;
      uu_maxlen : stddef_h.size_t;
      uu_format : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/stdio.h:354
   with Import => True, 
        Convention => C, 
        External_Name => "snprintf";

   function vsnprintf
     (uu_s : Interfaces.C.Strings.chars_ptr;
      uu_maxlen : stddef_h.size_t;
      uu_format : Interfaces.C.Strings.chars_ptr;
      uu_arg : access System.Address) return int  -- /usr/include/stdio.h:358
   with Import => True, 
        Convention => C, 
        External_Name => "vsnprintf";

   function vdprintf
     (uu_fd : int;
      uu_fmt : Interfaces.C.Strings.chars_ptr;
      uu_arg : access System.Address) return int  -- /usr/include/stdio.h:379
   with Import => True, 
        Convention => C, 
        External_Name => "vdprintf";

   function dprintf (uu_fd : int; uu_fmt : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/stdio.h:382
   with Import => True, 
        Convention => C, 
        External_Name => "dprintf";

   function fscanf (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE; uu_format : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/stdio.h:407
   with Import => True, 
        Convention => C, 
        External_Name => "__isoc99_fscanf";

   function scanf (uu_format : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/stdio.h:410
   with Import => True, 
        Convention => C, 
        External_Name => "__isoc99_scanf";

   function sscanf (uu_s : Interfaces.C.Strings.chars_ptr; uu_format : Interfaces.C.Strings.chars_ptr  -- , ...
      ) return int  -- /usr/include/stdio.h:412
   with Import => True, 
        Convention => C, 
        External_Name => "__isoc99_sscanf";

   function vfscanf
     (uu_s : access x86_64_linux_gnu_bits_types_FILE_h.FILE;
      uu_format : Interfaces.C.Strings.chars_ptr;
      uu_arg : access System.Address) return int  -- /usr/include/stdio.h:451
   with Import => True, 
        Convention => C, 
        External_Name => "__isoc99_vfscanf";

   function vscanf (uu_format : Interfaces.C.Strings.chars_ptr; uu_arg : access System.Address) return int  -- /usr/include/stdio.h:456
   with Import => True, 
        Convention => C, 
        External_Name => "__isoc99_vscanf";

   function vsscanf
     (uu_s : Interfaces.C.Strings.chars_ptr;
      uu_format : Interfaces.C.Strings.chars_ptr;
      uu_arg : access System.Address) return int  -- /usr/include/stdio.h:459
   with Import => True, 
        Convention => C, 
        External_Name => "__isoc99_vsscanf";

   function fgetc (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:485
   with Import => True, 
        Convention => C, 
        External_Name => "fgetc";

   function getc (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:486
   with Import => True, 
        Convention => C, 
        External_Name => "getc";

   function getchar return int  -- /usr/include/stdio.h:492
   with Import => True, 
        Convention => C, 
        External_Name => "getchar";

   function getc_unlocked (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:499
   with Import => True, 
        Convention => C, 
        External_Name => "getc_unlocked";

   function getchar_unlocked return int  -- /usr/include/stdio.h:500
   with Import => True, 
        Convention => C, 
        External_Name => "getchar_unlocked";

   function fgetc_unlocked (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:510
   with Import => True, 
        Convention => C, 
        External_Name => "fgetc_unlocked";

   function fputc (uu_c : int; uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:521
   with Import => True, 
        Convention => C, 
        External_Name => "fputc";

   function putc (uu_c : int; uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:522
   with Import => True, 
        Convention => C, 
        External_Name => "putc";

   function putchar (uu_c : int) return int  -- /usr/include/stdio.h:528
   with Import => True, 
        Convention => C, 
        External_Name => "putchar";

   function fputc_unlocked (uu_c : int; uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:537
   with Import => True, 
        Convention => C, 
        External_Name => "fputc_unlocked";

   function putc_unlocked (uu_c : int; uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:545
   with Import => True, 
        Convention => C, 
        External_Name => "putc_unlocked";

   function putchar_unlocked (uu_c : int) return int  -- /usr/include/stdio.h:546
   with Import => True, 
        Convention => C, 
        External_Name => "putchar_unlocked";

   function getw (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:553
   with Import => True, 
        Convention => C, 
        External_Name => "getw";

   function putw (uu_w : int; uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:556
   with Import => True, 
        Convention => C, 
        External_Name => "putw";

   function fgets
     (arg1 : Interfaces.C.Strings.chars_ptr;
      arg2 : int;
      arg3 : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdio.h:564
   with Import => True, 
        Convention => C, 
        External_Name => "fgets";

   --  skipped func __getdelim

   function getdelim
     (uu_lineptr : System.Address;
      uu_n : access stddef_h.size_t;
      uu_delimiter : int;
      uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return x86_64_linux_gnu_bits_types_h.uu_ssize_t  -- /usr/include/stdio.h:606
   with Import => True, 
        Convention => C, 
        External_Name => "getdelim";

   function getline
     (uu_lineptr : System.Address;
      uu_n : access stddef_h.size_t;
      uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return x86_64_linux_gnu_bits_types_h.uu_ssize_t  -- /usr/include/stdio.h:616
   with Import => True, 
        Convention => C, 
        External_Name => "getline";

   function fputs (uu_s : Interfaces.C.Strings.chars_ptr; uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:626
   with Import => True, 
        Convention => C, 
        External_Name => "fputs";

   function puts (uu_s : Interfaces.C.Strings.chars_ptr) return int  -- /usr/include/stdio.h:632
   with Import => True, 
        Convention => C, 
        External_Name => "puts";

   function ungetc (uu_c : int; uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:639
   with Import => True, 
        Convention => C, 
        External_Name => "ungetc";

   function fread
     (uu_ptr : System.Address;
      uu_size : stddef_h.size_t;
      uu_n : stddef_h.size_t;
      uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return stddef_h.size_t  -- /usr/include/stdio.h:646
   with Import => True, 
        Convention => C, 
        External_Name => "fread";

   function fwrite
     (uu_ptr : System.Address;
      uu_size : stddef_h.size_t;
      uu_n : stddef_h.size_t;
      uu_s : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return stddef_h.size_t  -- /usr/include/stdio.h:652
   with Import => True, 
        Convention => C, 
        External_Name => "fwrite";

   function fread_unlocked
     (uu_ptr : System.Address;
      uu_size : stddef_h.size_t;
      uu_n : stddef_h.size_t;
      uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return stddef_h.size_t  -- /usr/include/stdio.h:673
   with Import => True, 
        Convention => C, 
        External_Name => "fread_unlocked";

   function fwrite_unlocked
     (uu_ptr : System.Address;
      uu_size : stddef_h.size_t;
      uu_n : stddef_h.size_t;
      uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return stddef_h.size_t  -- /usr/include/stdio.h:675
   with Import => True, 
        Convention => C, 
        External_Name => "fwrite_unlocked";

   function fseek
     (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE;
      uu_off : long;
      uu_whence : int) return int  -- /usr/include/stdio.h:684
   with Import => True, 
        Convention => C, 
        External_Name => "fseek";

   function ftell (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return long  -- /usr/include/stdio.h:689
   with Import => True, 
        Convention => C, 
        External_Name => "ftell";

   procedure rewind (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE)  -- /usr/include/stdio.h:694
   with Import => True, 
        Convention => C, 
        External_Name => "rewind";

   function fseeko
     (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE;
      uu_off : x86_64_linux_gnu_bits_types_h.uu_off_t;
      uu_whence : int) return int  -- /usr/include/stdio.h:707
   with Import => True, 
        Convention => C, 
        External_Name => "fseeko";

   function ftello (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return x86_64_linux_gnu_bits_types_h.uu_off_t  -- /usr/include/stdio.h:712
   with Import => True, 
        Convention => C, 
        External_Name => "ftello";

   function fgetpos (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE; uu_pos : access fpos_t) return int  -- /usr/include/stdio.h:731
   with Import => True, 
        Convention => C, 
        External_Name => "fgetpos";

   function fsetpos (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE; uu_pos : access constant fpos_t) return int  -- /usr/include/stdio.h:736
   with Import => True, 
        Convention => C, 
        External_Name => "fsetpos";

   procedure clearerr (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE)  -- /usr/include/stdio.h:757
   with Import => True, 
        Convention => C, 
        External_Name => "clearerr";

   function feof (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:759
   with Import => True, 
        Convention => C, 
        External_Name => "feof";

   function ferror (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:761
   with Import => True, 
        Convention => C, 
        External_Name => "ferror";

   procedure clearerr_unlocked (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE)  -- /usr/include/stdio.h:765
   with Import => True, 
        Convention => C, 
        External_Name => "clearerr_unlocked";

   function feof_unlocked (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:766
   with Import => True, 
        Convention => C, 
        External_Name => "feof_unlocked";

   function ferror_unlocked (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:767
   with Import => True, 
        Convention => C, 
        External_Name => "ferror_unlocked";

   procedure perror (uu_s : Interfaces.C.Strings.chars_ptr)  -- /usr/include/stdio.h:775
   with Import => True, 
        Convention => C, 
        External_Name => "perror";

   function fileno (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:786
   with Import => True, 
        Convention => C, 
        External_Name => "fileno";

   function fileno_unlocked (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:791
   with Import => True, 
        Convention => C, 
        External_Name => "fileno_unlocked";

   function popen (arg1 : Interfaces.C.Strings.chars_ptr; arg2 : Interfaces.C.Strings.chars_ptr) return access x86_64_linux_gnu_bits_types_FILE_h.FILE  -- /usr/include/stdio.h:800
   with Import => True, 
        Convention => C, 
        External_Name => "popen";

   function pclose (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:806
   with Import => True, 
        Convention => C, 
        External_Name => "pclose";

   function ctermid (arg1 : Interfaces.C.Strings.chars_ptr) return Interfaces.C.Strings.chars_ptr  -- /usr/include/stdio.h:812
   with Import => True, 
        Convention => C, 
        External_Name => "ctermid";

   procedure flockfile (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE)  -- /usr/include/stdio.h:840
   with Import => True, 
        Convention => C, 
        External_Name => "flockfile";

   function ftrylockfile (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE) return int  -- /usr/include/stdio.h:844
   with Import => True, 
        Convention => C, 
        External_Name => "ftrylockfile";

   procedure funlockfile (uu_stream : access x86_64_linux_gnu_bits_types_FILE_h.FILE)  -- /usr/include/stdio.h:847
   with Import => True, 
        Convention => C, 
        External_Name => "funlockfile";

   --  skipped func __uflow

   --  skipped func __overflow

end stdio_h;
