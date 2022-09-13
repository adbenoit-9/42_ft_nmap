/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proty_udp.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 20:11:55 by leon              #+#    #+#             */
/*   Updated: 2022/09/13 16:26:12 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_UDP_H
# define FT_NMAP_UDP_H

# include <netinet/udp.h>

# define SET_UDP_SPORT(udp, value) do {((struct udphdr*)udp)->uh_sport =\
						(uint16_t)value;} while (0)
# define SET_UDP_DPORT(udp, value) do {((struct udphdr*)udp)->uh_dport =\
						(uint16_t)value;} while (0)
# define SET_UDP_LEN(udp, value) do {((struct udphdr*)udp)->uh_ulen =\
       					(uint16_t)value;} while (0)
# define SET_UDP_ACK(udp, value) do {((struct udphdr*)udp)->uh_sum =\
       					(uint16_t)value;} while (0)

# define FLAG_S_UDP 0x42

#endif /* FT_NMAP_UDP */
