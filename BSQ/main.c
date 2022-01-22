/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:27:09 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/22 12:34:00 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		file_count;
	char	*file_name;

	fc = 1;
	while (fc <= argc)
	{
		file_name = argv[fc];
		if (open(file_name, O_RDONLY) < 0)
		{
			write(1, "File cannot open\n", 17);
			continue ;
		}
		
	}

	return (0);
}