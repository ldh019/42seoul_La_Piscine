/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:08:56 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/12 19:14:25 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *arr);

int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				dlen;
	int				slen;

	i = 0;
	dlen = ft_len(dest);
	slen = ft_len(src);
	dest += dlen;
	while (*src != '\0' && i < size - 1)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	if (size < dlen)
		return (slen + (int)size);
	return (dlen + slen);
}

int	ft_len(char *arr)
{
	int	len;

	len = 0;
	while (arr[len] != '\0')
	{
		len++;
	}
	return (len);
}
