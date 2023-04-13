/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:50:49 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/13 23:44:32 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define MAX_BIT 32
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

typedef void	(*t_sighandler)(int);

t_sighandler	signal(int sig, t_sighandler handler);

int				ft_printf(const char *format, ...);

#endif
