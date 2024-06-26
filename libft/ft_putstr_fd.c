/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pustr_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:58:13 by pvong             #+#    #+#             */
/*   Updated: 2022/10/19 15:10:53 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t ret;

	while (*s)
	{
		ret = write(fd, s++, 1);
		if (ret == -1) {
			ssize_t err_ret;
			err_ret = write(2, "write error\n", 12);
			(void) err_ret;
		}

	}
}
