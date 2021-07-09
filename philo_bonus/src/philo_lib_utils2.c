/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lib_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcelia <aarcelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:25:12 by aarcelia          #+#    #+#             */
/*   Updated: 2021/07/09 14:27:08 by aarcelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_trim_execname(char *argv_0)
{
	return (ft_strrchr(argv_0, '/') + 1);
}

static uint	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*ret;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = '\0';
	return (ret);
}

static int	ft_numlen(int n)
{
	int	nret;

	nret = 0;
	while (n)
	{
		n /= 10;
		nret++;
	}
	return (nret);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*ret;
	int				mod;
	int				i;
	int				numlen;

	i = 0;
	mod = n <= 0;
	num = ft_abs(n);
	numlen = ft_numlen(n);
	ret = (char *)ft_calloc((numlen + mod + 1), sizeof(char));
	if (!ret)
		return (NULL);
	if (mod && n < 0)
		ret[i++] = '-';
	else if (mod && !n)
		ret[i++] = '0';
	while (num && numlen)
	{
		ret[--numlen + mod] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	return (ret);
}
