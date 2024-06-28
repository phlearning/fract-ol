/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:54:05 by pvong             #+#    #+#             */
/*   Updated: 2022/10/19 14:57:49 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	ssize_t ret;

	ret = write(fd, &c, 1);
	if (ret == -1)
	{
		ssize_t err_ret;
		err_ret = write(2, "write error\n", 12);
		(void) err_ret;
	}
}
