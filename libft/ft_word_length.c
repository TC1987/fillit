/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 04:10:29 by tcho              #+#    #+#             */
/*   Updated: 2018/11/04 04:11:49 by tcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_word_length(char const *str, char del, int i)
{
	int j;

	j = i;
	while (str[j] && (str[j] != del))
		j++;
	return (j - i);
}
