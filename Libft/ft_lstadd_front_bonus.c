/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:48:10 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/01 12:48:55 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node != NULL)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	return (new_node);
}

int main(void)
{
    t_list *first_node = ft_lstnew("First Node");
    t_list *second_node = ft_lstnew("Second Node");

    ft_lstadd_front(&first_node, second_node);

    while (first_node != NULL)
    {
        printf("%s\n", (char *)first_node->content);
        first_node = first_node->next;
    }

    return 0;
}
*/
