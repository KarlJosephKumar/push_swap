/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:46:53 by kakumar           #+#    #+#             */
/*   Updated: 2023/02/28 15:35:47 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	positive_num(const char *str)
{
	int			result;
	long long	rslt;

	if (*str == '+')
		return (shutdown("No weird stuff"));
	rslt = 0;
	result = 0;
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result += *str - 48;
		rslt *= 10;
		rslt += *str -48;
		str++;
		if (rslt > 2147483647)
			return (shutdown("Number is  too big"));
	}
	if (*str && (*str != ' ' || *str != '\t' || *str != '\n' || *str != '\v'
			|| *str != '\f' || *str != '\r' || *str != '\0'))
		return (shutdown ("Error with number"));
	return (result);
}

int	negative_num(const char *str)
{
	int			result;
	long long	rslt;

	if (*str == '-')
		return (shutdown("No double minus"));
	rslt = 0;
	result = 0;
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result -= *str - 48;
		rslt *= 10;
		rslt -= *str -48;
		str++;
		if (rslt < -2147483648)
			return (shutdown("Number is  too small"));
	}
	if (*str && (*str != ' ' || *str != '\t' || *str != '\n' || *str != '\v'
			|| *str != '\f' || *str != '\r' || *str != '\0'))
		return (shutdown ("Error with number"));
	return (result);
}

int	ft_atoi_pswap(const char *str)
	{
	int	i;

	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		str++;
		if (*str < 48 || *str > 57)
			shutdown("horse");
		return (negative_num((char *)str));
	}
	else if (*str == '+')
	{
		str++;
		if (*str < 48 || *str > 57)
			shutdown("horse");
		return (positive_num((char *)str));
	}
	else
	{
		return (positive_num((char *)str));
	}
}
