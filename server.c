/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/13 23:44:06 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	sr_to_ch(int sig)
{
	static unsigned int	n = MAX_BIT;
	static unsigned int	ch = 0;
	unsigned int		mask;
	unsigned int		bit;

	bit = 0;
	if (sig == SIGUSR2)
		bit = 1;
	n--;
	mask = (unsigned int)1 << n;
	if (bit == 1)
		ch |= mask;
	if (n == 0)
	{
		ft_printf("%c", ch);
		n = MAX_BIT;
		ch = 0;
	}
}

int	main(void)
{
	ft_printf("%u\n", (int)getpid());
	signal(SIGUSR1, sr_to_ch);
	signal(SIGUSR2, sr_to_ch);
	while (1)
		pause();
}
