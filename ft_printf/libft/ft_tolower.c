/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:34:33 by pvong             #+#    #+#             */
/*   Updated: 2022/10/11 15:00:32 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	a;

	if (argc < 3 && argv[1][1] == '\0')
	{
		a = argv[1][0];
		printf("Before ft: %c\n", a);
		a = ft_tolower(a);
		printf("After ft: %c\n", a);
	}
	return (0);
}
*/
