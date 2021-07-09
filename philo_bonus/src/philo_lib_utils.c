/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lib_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:51:28 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/07 12:53:59 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	if (s)
	{
		while (s[n])
			n++;
	}
	return (n);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	char	ctmp;
	size_t	slen;

	slen = ft_strlen(s);
	ret = (char *)s + slen;
	ctmp = (char)c;
	slen++;
	while (slen--)
	{
		if (*ret == ctmp)
			return ((char *)ret);
		ret--;
	}
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

int64_t	ft_atoll(char *s)
{
	int64_t	ret;
	int		mod;
	int		i;
	int		len;

	ret = 0;
	i = 0;
	mod = 1;
	len = ft_strlen(s);
	if (len <= 19 || (s[0] == '-' && ft_strlen(&s[1]) <= 19))
	{
		if (s[0] == '-')
		{
			mod = -1;
			i = 1;
		}
		while (ft_isdigit(s[i]))
			ret = ret * 10 + s[i++] - '0';
	}
	return (ret * mod);
}
