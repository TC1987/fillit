/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 04:08:25 by tcho              #+#    #+#             */
/*   Updated: 2018/11/04 04:10:23 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_word_count(char const *str, char del)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != del)
		{
			count++;
			while (str[i] != del)
				i++;
		}
		i++;
	}
	return (count);
}