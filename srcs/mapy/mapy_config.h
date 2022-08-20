#ifndef MAPY_CONFIG_H
# define MAPY_CONFIG_H

#define THREAD_NB	 					250

#define BLCK_NB							THREAD_NB

#define MAP_BLCK_SIZE					256

// First 4 bytes are used to identify block owner

#define MAX_CONFIG_SIZE					4096

#define SIZE							((MAP_BLCK_SIZE + BLCK_NB) + MAX_CONFIG_SIZE)


// Application config structure binding 
#define ST_MAX							16
#define ND_MAX							1024
#define RD_MAX							6

#include "test_structs.h"

#define T_CLIENT_RD						t_nmap_scan
#define T_CLIENT_ND						t_nmap_app
#define T_CLIENT_ST						t_nmap_link
#define T_CLIENT_ROOT					t_nmap_setting

// Execution control
#define EXEC_LST_SIZE					10
#define EXEC_TODO_MSK					0x80
#define EXEC_MAX_LIST 					8
#define EXEC_MAX_CMD					8
#define EXEC_MAX_HOOK					8

#define SETY_EXEC_MAX_CMD					8
#define SETY_EXEC_MAX_HOOK					8


// Throw a warning 
//#define BUILD_BUG_ON(sizeof()) ((void)sizeof(char[1 - 2*!!(condition)]))

#endif
