/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:58:19 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/20 13:48:08 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	len;

	len = 0;
	while (argv[0][len] != '\0')
		len++;
	if (argc > 0)
	{
		write(1, argv[0], len);
		write(1, "\n", 1);
	}
	return (0);
}
