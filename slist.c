#include <stdio.h>
#include <stdlib.h>

#include "slist.h"

void
sllist_init(SLList * list)
{
	list->head = NULL;
}

// Add int value to the end of list. The values may be repeated.
void
sllist_add_end( SLList *list, int value )
{
	SLEntry * e;
	if (list->head == NULL)
	{
		SLEntry * newE = (SLEntry*)malloc(sizeof(SLEntry));
		list->head = newE;
		newE->value = value;
		newE->next = NULL;
		return;
	}
	e = list->head;
	while (e->next != NULL)
	{
		e = e->next;
	}
	SLEntry * newE = (SLEntry*)malloc(sizeof(SLEntry));
	e->next = newE;
	newE->value = value;
	newE->next = NULL;
}


// Remove first occurrence of value in the list. It returns 1 if value is found or 0 otherwise.
int sllist_remove(SLList *list, int value)
{
	SLEntry * e;
	if (list->head == NULL)
	{
		return 0;
	}
	e = list->head;
	if (e->value == value)
	{
		list->head = e->next;
		return 1;
	}
	while (e->next != NULL)
	{
		if (e->next->value == value)
		{
			e->next = e->next->next;
			return 1;
		}
		e = e->next;
	}
	
	return 0;
}


// Removes from the list and frees the nodes of all the items that are min <= value <= max
void sllist_remove_interval(SLList *list, int min, int max)
{
	SLEntry * e;
	if (list->head == NULL)
	{
		return;
	}
	e = list->head;
	while (e->value <= max && e->value >= min)
	{
		list->head = e->next;
		SLEntry * freeThis = e;
		e = e->next;
		free(freeThis);
	}
	while (e->next != NULL)
	{
		if (e->next->value <= max && e->next->value >= min)
		{
			SLEntry * freeThis = e->next;
			e->next = e->next->next;
			free(freeThis);
		}
		else
		{
			e = e->next;
		}
	}
}


// It allocates and returns a new list with the intersection of the two lists, that is the 
// list of all the items that are common to the two lists. The items in the intersection are
// unique. 
SLList *
sllist_intersection(SLList *a, SLList *b)
{
	SLEntry * e;
	SLEntry * f;
	if (a->head == NULL || b->head == NULL)
	{
		return;
	}
	e = a->head;
	f = b->head;
	SLList * inter = (SLList*)malloc(sizeof(SLList));
	inter->head = NULL;
	while (f->next != NULL)
	{
		e = a->head;
		while (e->next != NULL)
		{
			if (f->value == e->value)
			{
				sllist_add_end(inter, e->value);
				break;
			}
			e = e->next;
		}
		f = f->next;
	}
	e = a->head;
	while(e->next != NULL)
	{
		if (f->value == e->value)
		{
			sllist_add_end(inter, e->value);
			break;
		}
		e = e->next;
	}
	return inter;
}

void
sllist_print(SLList *list)
{
	// Move to the end
	SLEntry * e = list->head;

	printf("--- List ---\n");
	while (e!= NULL) {
		printf("val=%d\n", e->value);
		e = e->next;
	}
}

