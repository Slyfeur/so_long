/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:05:28 by tuytters          #+#    #+#             */
/*   Updated: 2021/05/07 09:12:17 by tuytters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(t_list *lst)
{
	t_list	*tmp;

	tmp = NULL;
	ft_lstnew(tmp->content);
	while (lst)
	{
		tmp = lst;
		free(lst->content);
		free(lst);
		lst = tmp->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		list = ft_lstnew(f(lst->content));
		if (!list)
		{
			if (del)
				ft_lstclear(&list, del);
			else
				ft_freeall(list);
			return (NULL);
		}
		ft_lstadd_back(&ptr, list);
		lst = lst->next;
	}
	return (ptr);
}
