/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:38:25 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/01 14:57:20 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/*
#include <stdio.h>
#include <string.h>

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

void delete_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *node = ft_lstnew(strdup("Hello World!")); 

    if (node)
    {
        printf("Contenido antes de borrar: %s\n", (char *)node->content);
        ft_lstdelone(node, delete_content);
        node = NULL;
    }

    printf("Contenido después de borrar: %p\n", (void *)node); 

    return 0;
}
*/
