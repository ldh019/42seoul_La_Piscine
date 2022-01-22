/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:46:27 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/20 15:16:57 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ret_vlu(char *base, char find)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == find)
			return (i);
		i++;
	}
	return (-1);
}

void	reset(int *len, int *chk, long *ans, char *base)
{
	*len = 0;
	while (base[*len] != '\0')
		(*len)++;
	*chk = 1;
	*ans = 0;
}

long	ft_atoi(char *str, char *base)
{
	long	ans;
	int		tmp;
	int		len;
	int		chk;

	reset(&len, &chk, &ans, base);
	while (ret_vlu(base, *str) == -1)
	{
		if (*str == '-')
			chk *= -1;
		str++;
	}
	while (1)
	{
		tmp = ret_vlu(base, *str++);
		if (tmp == -1)
			break ;
		ans *= len;
		ans += tmp;
	}
	ans *= chk;
	return (ans);
}

int	base_check(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 32 || base[i] == 127)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}
