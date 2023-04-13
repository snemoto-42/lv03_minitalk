/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:45:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/13 19:14:43 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	cl_exit_success(void)
{
	exit(EXIT_SUCCESS);
}

static void	cl_exit_failure(void)
{
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
}

static void	cl_to_bit(pid_t pid, unsigned int ch)
{
	unsigned int	n;
	unsigned int	mask;

	n = MAX_BIT - 1;
	while (1)
	{
		mask = (unsigned int)1 << n;
		if ((ch & mask) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (n == 0)
			break ;
		usleep(1000 * 0.1);
		n--;
	}
}

int	main(int argc, char **argv)
{
	size_t	idx;

	if (argc != 3)
		cl_exit_failure();
	idx = 0;
	while (argv[2][idx])
	{
		cl_to_bit((pid_t)ft_atoi(argv[1]), argv[2][idx]);
		usleep(1000 * 0.1);
		idx++;
	}
	cl_exit_success();
}
