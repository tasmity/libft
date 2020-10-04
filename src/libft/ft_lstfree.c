/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasmity <tasmity@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 00:17:25 by tasmity           #+#    #+#             */
/*   Updated: 2019/09/24 00:17:25 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void				ft_lstfree(t_list *lst)
{
	if (lst->next)
		ft_lstfree((lst->next));
	free(lst->content);
	free(lst);
	lst = NULL;
}
