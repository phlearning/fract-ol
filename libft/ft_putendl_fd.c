/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:11:50 by pvong             #+#    #+#             */
/*   Updated: 2022/10/19 15:16:22 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_write(void)
{
	ssize_t err_ret;
	err_ret = write(2, "write error\n", 12);
	(void) err_ret;
}

void	ft_putendl_fd(char *s, int fd)
{
	ssize_t ret;
	while (*s)
	{
		ret = write(fd, s++, 1);
		if (ret == -1)
			ft_error_write();
	}
	ret = write(fd, "\n", 1);
	if (ret == -1)
		ft_error_write();
}
