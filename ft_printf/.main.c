/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:26:19 by pvong             #+#    #+#             */
/*   Updated: 2022/11/09 11:30:46 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_printf.h"

int	main(void)
{
	char	c;
	char	*str;
	char	*ptr;
	char	*ptr2;

	ptr = &c;
	ptr2 = 0;
	c = 'a';
	str = malloc(sizeof(char) * 100);
	if (!str)
		return (0);
	str = "Hello world";
	ft_printf("c: %c\n", c);
	printf("c: %c\n", c);
	ft_printf("s: %s\n", str);
	printf("s: %s\n", str);
	ft_printf("d: %d\n", 10);
	printf("d: %d\n", 10);
	ft_printf("x: %x\n", 30);
	printf("x: %x\n", 30);
	ft_printf("u: %u\n", 4294967295);
	printf("u: %lu\n", 4294967295);
	ft_printf("ptr: %p\n", ptr);
	printf("ptr: %p\n", ptr);
	ft_printf("ptr: %p\n", ptr2);
	printf("ptr: %p\n", ptr2);
	return (0);
}
