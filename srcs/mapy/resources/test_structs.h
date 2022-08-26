/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <lmariott@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:33:37 by leon              #+#    #+#             */
/*   Updated: 2022/08/21 01:39:40 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_STRUCTS_H
# define TEST_STRUCTS_H

#include <sys/types.h>
#include <sys/socket.h>

#define PORT_LIMIT			1024
#define SCAN_LIMIT			6
#define IP_LIMIT			16

typedef struct		test_root {
	uint8_t				buf[128];
	uint8_t				flag;
}					test_root;


typedef struct		test_st {
	uint8_t				buf[128];
	uint8_t				flag;
}					test_st;

typedef struct		test_nd {
	uint8_t				buf[128];
	uint8_t				flag;
}					test_nd;

typedef struct		test_rd {
	uint8_t				buf[32];
	uint8_t				flag;
}					test_rd;


#endif