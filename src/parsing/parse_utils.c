/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 22:31:49 by anasinda          #+#    #+#             */
/*   Updated: 2026/08/30 03:37:58 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


long long ft_atol(char *str)
{
	long long i;
	long long sign;
	long long result;

	i = 0;
	sign = 1;
	result = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;

	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign *= -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	
	return result * sign;
}


int	is_valid_number(char *num_check)
{
	int i;
	
	i = 0;
	if (num_check[i] == '\0')
		return (0);
		
	while (num_check[i])
	{
		if ((num_check[i] == '+' || num_check[i] == '-') && i == 0 )
			i++;
		if (num_check[i] < '0' || num_check[i] > '9')
				return (0);
		i++;
	}
	
	long long valid_range;

	valid_range = ft_atol(num_check);
	if (valid_range < 0 || valid_range > 2147483647)
		return 0;
	return (1);
}