/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:01:03 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 17:24:33 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_TEST_H
# define EXPORT_TEST_H

//#include "../mapy_config.h"


//typedef int (*t_func_mapy)(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);
//int 				test_test1(uint8_t *, T_CLIENT_ST *, T_CLIENT_ND *, T_CLIENT_RD *);

int 				test_sety_rd(test_root *root, test_st *st, test_nd *nd, test_rd *rd);
int 				test_sety_rd(test_root *root, test_st *st, test_nd *nd, test_rd *rd);
int 				test_sety_nd(test_root *root, test_st *st, test_nd *nd);
int 				test_sety_st(test_root *root, test_st *st);

int 				test_mapy(uint8_t *buf, test_st *st, test_nd *nd, test_rd *rd);
int 				test_mapy_print(uint8_t *buf, test_st *st, test_nd *nd, test_rd *rd);

t_func_mapy _exec_test[EXEC_MAX_HOOK] = {
	test_mapy,
};

t_func_mapy _exec_test_print[EXEC_MAX_HOOK] = {
	test_mapy_print,
};

// TODO a wrapper exey
t_func_mapy *_exec[EXEC_MAX_CMD] = {
	_exec_test,
	_exec_test_print,
};

#define SELECT_HOOK_TEST(sockaddr, nd, hook) do { \
if (((struct sockaddr_storage *)sockaddr).ss_family == AF_INET) { \
	if (nd == NMAP_UDP) { \
		hook = 1; \
}	else { \
		hook = 0; \
}else { \
	if { \
		hook = 3; \
}	else { \
		hook = 2; \
	} \
} \
} while (0)

#endif
