/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:02:14 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/13 19:26:28 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str, char *base, int len);
int	base_check(char *base, int *len);
int	ret_vlu(char *base, char find);

int	ft_atoi_base(char *str, char *base)
{
	int	len;

	if (base_check(base, &len) == 0)
		return (0);
	return (ft_atoi(str, base, len));
}

int	ft_atoi(char *str, char *base, int len)
{
	int		m;
	long	ans;
	int		tmp;

	m = 1;
	while (ret_vlu(base, *str) == -1)
	{
		if (*str == '-')
			m *= -1;
		str++;
	}
	ans = 0;
	while (1)
	{
		tmp = ret_vlu(base, *str);
		if (tmp == -1)
			break ;
		ans *= len;
		ans += tmp;
		str++;
	}
	ans *= m;
	m = (int)ans;
	return (m);
}

int	base_check(char *base, int *len)
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
	*len = i;
	return (1);
}

int	ret_vlu(char *base, char find)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == find)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
