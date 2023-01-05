/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:04:26 by pvong             #+#    #+#             */
/*   Updated: 2022/11/09 12:57:01 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/* nbr */

int	ft_get_unbr_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	int		len;
	char	*nbr;

	i = 0;
	len = ft_get_unbr_len(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (n > 0)
	{
		nbr[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (nbr);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_printstr(str);
	free(str);
	return (len);
}

unsigned int	ft_printunbr(unsigned int n)
{
	int		len;
	char	*str;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		str = ft_uitoa(n);
		len += ft_printstr(str);
		free(str);
	}
	return (len);
}
