/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:48:45 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/13 18:35:06 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int		m;
	long	ans;

	m = 1;
	while (*str == ' ' || *str == '+' || *str == '-')
	{
		if (*str == '-')
			m *= -1;
		str++;
	}
	ans = 0;
	while (*str >= '0' && *str <= '9')
	{
		ans *= 10;
		ans += *str - 48;
		str++;
	}
	ans *= m;
	m = (int)ans;
	return (m);
}
