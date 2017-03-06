/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:19:40 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/03 18:03:33 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new_elem)
{
	if (*alst)
	{
		new_elem->next = *alst;
		*alst = new_elem;
	}
	if (!(*alst))
		*alst = new_elem;
}
