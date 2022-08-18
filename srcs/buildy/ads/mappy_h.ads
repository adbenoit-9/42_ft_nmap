pragma Ada_2012;
pragma Style_Checks (Off);

with Interfaces.C; use Interfaces.C;
with x86_64_linux_gnu_bits_stdint_uintn_h;
with System;

package mappy_h is

   MAPPY_MAX_ST : constant := 128;  --  ../mappy/mappy.h:32
   MAPPY_MAX_ND : constant := 1024;  --  ../mappy/mappy.h:33
   MAPPY_MAX_RD : constant := 6;  --  ../mappy/mappy.h:34
   MAPPY_MAX_BUFFER_SIZE : constant := 64;  --  ../mappy/mappy.h:35
   --  unsupported macro: MAPPY_SIZE (MAPPY_MAX_ST * MAPPY_ST_SIZE)
   --  unsupported macro: MAPPY_ST_SIZE (MAPPY_MAX_ND * MAPPY_ND_SIZE)
   --  unsupported macro: MAPPY_ND_SIZE (MAPPY_MAX_RD * MAPPY_MAX_BUFFER_SIZE)

   SETY_MAX_ST : constant := 16;  --  ../mappy/mappy.h:40
   SETY_ST_CONFIG_SIZE : constant := 64;  --  ../mappy/mappy.h:41
   SETY_MAX_ND : constant := 1048;  --  ../mappy/mappy.h:42
   SETY_ND_CONFIG_SIZE : constant := 64;  --  ../mappy/mappy.h:43
   SETY_MAX_RD : constant := 6;  --  ../mappy/mappy.h:44
   SETY_RD_CONFIG_SIZE : constant := 64;  --  ../mappy/mappy.h:45

   SETY_MAX_BUFFER_SIZE : constant := 64;  --  ../mappy/mappy.h:47
   --  unsupported macro: SETY_SIZE (SETY_MAX_ST * SETY_ST_SIZE)
   --  unsupported macro: SETY_ST_SIZE (SETY_MAX_ND * SETY_ND_SIZE)
   --  unsupported macro: SETY_ND_SIZE (SETY_MAX_RD * SETY_MAX_BUFFER_SIZE)

   SETY_MAX_EXECUTION_LIST : constant := 10;  --  ../mappy/mappy.h:52
   SETY_TASK_EXECUTION_TODO_MSK : constant := 16#80#;  --  ../mappy/mappy.h:53
   SETY_MAX_EXECUTION_CMD : constant := 4;  --  ../mappy/mappy.h:54
   SETY_MAX_EXECUTION_HOOK : constant := 4;  --  ../mappy/mappy.h:55

   MAPPY_MAX_EXECUTION_LIST : constant := 8;  --  ../mappy/mappy.h:57
   MAPPY_MAX_EXECUTION_CMD : constant := 8;  --  ../mappy/mappy.h:58
   MAPPY_MAX_EXECUTION_HOOK : constant := 8;  --  ../mappy/mappy.h:59

   MAPPY_NO_MORE : constant := 1;  --  ../mappy/mappy.h:90
   MAPPY_OK : constant := 0;  --  ../mappy/mappy.h:91
   MAPPY_ERROR : constant := -1;  --  ../mappy/mappy.h:92

   SETY_NO_MORE : constant := 1;  --  ../mappy/mappy.h:94

   SETY_OK : constant := 0;  --  ../mappy/mappy.h:96
   SETY_ERROR : constant := -1;  --  ../mappy/mappy.h:97

   TASK_EXECUTION_TODO_MSK : constant := 16#80#;  --  ../mappy/mappy.h:110
   MAX_EXECUTION_LIST : constant := 10;  --  ../mappy/mappy.h:111

   type anon1839_execution_target_array is array (0 .. 9) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type anon1839_execution_task_list_array is array (0 .. 9) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type s_proto_tree is record
      map_index : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../mappy/mappy.h:63
      conf_index : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../mappy/mappy.h:64
      nb_elements : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../mappy/mappy.h:65
      execution_target : aliased anon1839_execution_target_array;  -- ../mappy/mappy.h:68
      execution_task_list : aliased anon1839_execution_task_list_array;  -- ../mappy/mappy.h:69
      status : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../mappy/mappy.h:70
   end record
   with Convention => C_Pass_By_Copy;  -- ../mappy/mappy.h:62

   subtype t_proto_tree is s_proto_tree;  -- ../mappy/mappy.h:71

   type anon1844_execution_target_array is array (0 .. 7) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type anon1844_execution_task_list_array is array (0 .. 7) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type s_proto_elem is record
      map_index : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../mappy/mappy.h:74
      config_index : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../mappy/mappy.h:75
      execution_target : aliased anon1844_execution_target_array;  -- ../mappy/mappy.h:76
      execution_task_list : aliased anon1844_execution_task_list_array;  -- ../mappy/mappy.h:77
      status : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../mappy/mappy.h:78
   end record
   with Convention => C_Pass_By_Copy;  -- ../mappy/mappy.h:73

   subtype t_proto_elem is s_proto_elem;  -- ../mappy/mappy.h:79

   type anon1847_execution_target_array is array (0 .. 7) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type anon1847_execution_task_list_array is array (0 .. 7) of aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
   type t_proto_root is record
      config : access x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- ../mappy/mappy.h:82
      map : access x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- ../mappy/mappy.h:83
      execution_target : aliased anon1847_execution_target_array;  -- ../mappy/mappy.h:84
      execution_task_list : aliased anon1847_execution_task_list_array;  -- ../mappy/mappy.h:85
      main_flag : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;  -- ../mappy/mappy.h:86
      nb_elements : aliased x86_64_linux_gnu_bits_stdint_uintn_h.uint32_t;  -- ../mappy/mappy.h:87
   end record
   with Convention => C_Pass_By_Copy;  -- ../mappy/mappy.h:81

   function mappy (root : access t_proto_root) return int  -- ../mappy/mappy.h:100
   with Import => True, 
        Convention => C, 
        External_Name => "mappy";

   function sety_root (root : access t_proto_root) return int  -- ../mappy/mappy.h:101
   with Import => True, 
        Convention => C, 
        External_Name => "sety_root";

   function sety_st (root : access t_proto_root; st : access t_proto_tree) return int  -- ../mappy/mappy.h:102
   with Import => True, 
        Convention => C, 
        External_Name => "sety_st";

   function sety_nd
     (root : access t_proto_root;
      st : access t_proto_tree;
      nd : access t_proto_tree) return int  -- ../mappy/mappy.h:103
   with Import => True, 
        Convention => C, 
        External_Name => "sety_nd";

   type t_func_mappy is access function
        (arg1 : access x86_64_linux_gnu_bits_stdint_uintn_h.uint8_t;
         arg2 : System.Address;
         arg3 : System.Address;
         arg4 : System.Address) return int
   with Convention => C;  -- ../mappy/mappy.h:105

   type t_func_sety_nd is access function
        (arg1 : access t_proto_root;
         arg2 : access t_proto_tree;
         arg3 : access t_proto_tree;
         arg4 : System.Address) return int
   with Convention => C;  -- ../mappy/mappy.h:106

   type t_func_sety_st is access function
        (arg1 : access t_proto_root;
         arg2 : access t_proto_tree;
         arg3 : access t_proto_tree) return int
   with Convention => C;  -- ../mappy/mappy.h:107

   type t_func_sety_root is access function (arg1 : access t_proto_root; arg2 : access t_proto_tree) return int
   with Convention => C;  -- ../mappy/mappy.h:108

end mappy_h;
