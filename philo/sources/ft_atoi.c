/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:51 by jgasparo          #+#    #+#             */
/*   Updated: 2024/02/07 12:42:10 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(const char *str)
{
	long long int	result;
	int				i;
	int				sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (str[i] == '+')
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if ((result * sign) >= 2147483648 || (result * sign) <= -2147483649)
		printf("error atoi"); // gerer l'erreur
	return (result * sign);
}
