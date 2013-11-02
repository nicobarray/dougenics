#include "list.h"

s_list *add_list(s_list *list, void *body)
{
	static int ids = 0;
	s_list *head = NULL;
	
	if (!(head = malloc(sizeof (struct list))))
		return NULL;

	head->body = body;
	head->next = list;
	head->id = ids;		

	ids++;
	return head;
}

s_list *get_list(int id, s_list *list)
{
	while (list)
	{
		if (list->id == id)
			return list;
	}
	return NULL;
}

s_list *remove_at_list(int id, s_list *list)
{
	if (!list)
		return NULL;
	else
	{
		if (list->id == id)
		{
			s_list *node = list->next;
			free(list);
			return node;
		}
		else
		{
			return s_remove_at(id, list->next);		
		}
	}
}
