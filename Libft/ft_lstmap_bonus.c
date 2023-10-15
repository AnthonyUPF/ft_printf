/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthtorr <anthtorr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:36:26 by anthtorr          #+#    #+#             */
/*   Updated: 2023/10/01 16:06:57 by anthtorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_st_lstnew(void *content)
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

static t_list	*ft_st_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

static void	ft_st_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_st_lstlast(*lst);
	last_node->next = new;
}

static void	ft_st_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	while (lst != NULL)
	{
		new_node = ft_st_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_st_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_st_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	*modify_content(void *content)
{
    char *new_content = strdup(content);

    if (new_content != NULL)
	{
		size_t i = 0;
		while (new_content[i])
		{
			new_content[i] = toupper(new_content[i]);
			i++;
		}
	}
    return (void *)new_content;
}

void delete_content(void *content)
{
	free(content);
}

int main(void)
{
	t_list *node1 = ft_st_lstnew("Hello");
	t_list *node2 = ft_st_lstnew("World");
	t_list *node3 = ft_st_lstnew("!");

	node1->next = node2;
	node2->next = node3;

	printf("Contenido de la lista antes de mapear:\n");
	t_list *current = node1;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	t_list *new_list = ft_lstmap(node1, modify_content, delete_content);

	printf("\nContenido de la lista después de mapear:\n");
	current = new_list;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	ft_st_lstclear(&new_list, delete_content);

	return (0);
}
*/
