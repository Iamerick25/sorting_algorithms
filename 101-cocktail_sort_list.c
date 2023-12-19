#include "sort.h"

void swap(listint_t *, listint_t *);

/**
 * cocktail_sort_list - Cocktail sort algorithm
 * @list: double pointer to head of a linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *display, *start, *finish;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	start = *list;
	finish = NULL;
	while (start->next != finish) /* start and finish are sorted */
	{
		display = start;
		while (display->next != finish)
		{
			if (display->n > display->next->n)
			{
				if (display == *list)
					*list = start = display->next;
				swap(display, display->next);
				print_list(*list);
			}
			else
				display = display->next;
		}
		finish = display; /* display is sorted */
		display = display->prev;
		while (display != start)
		{
			if (display->prev != NULL && display->n < display->prev->n)
			{
				if (display->prev == *list)
					*list = start = display;
				swap(display->prev, display);
				print_list(*list);
			}
			else
				display = display->prev;
		}
		start = display; /* display is sorted */
	}
}

/**
 * swap - function to swap two nodes in a doubly linked list
 * @left: left node to swap
 * @right: right node to swap
 */
void swap(listint_t *left, listint_t *right)
{
	if (left->prev != NULL)
		left->prev->next = right;
	if (right->next != NULL)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}
