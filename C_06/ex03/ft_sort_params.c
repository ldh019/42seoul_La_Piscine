/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:34:52 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/20 14:40:26 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_compare(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] < b[i])
			return (0);
		else if (a[i] > b[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_sort(int argc, char **argv)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (++i < argc - 1)
	{
		j = 0;
		while (++j < argc - i)
		{
			if (ft_compare(argv[j], argv[j + 1]))
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	ft_sort(argc, argv);
	i = 0;
	while (++i < argc)
	{
		len = 0;
		while (argv[i][len] != '\0')
			len++;
		write(1, argv[i], len);
		write(1, "\n", 1);
	}
	return (0);
}
