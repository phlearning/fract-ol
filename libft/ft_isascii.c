/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:04:01 by pvong             #+#    #+#             */
/*   Updated: 2022/10/10 17:12:12 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(int argc, char** argv)
{
	char	a;

	a = argv[1][0];
	printf("Is \"%c\" ascii ?: %d\n", a, ft_isascii(a));
	return (0);
}
*/
