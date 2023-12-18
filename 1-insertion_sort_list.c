#include "sort.h"

void swap(listint_t *, listint_t *);

/**
 * insertion_sort_list - insertion sort for doubly linked list
 * @list: double pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *new, *prev;

	head = new = prev = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	head = *list;
	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			new = head->next;
			swap(head, head->next);
			if (new->prev == NULL)
				*list = new;
			print_list((const listint_t *) *list);
			while (new->prev != NULL)
			{
				if (new->n >= new->prev->n)
					break;
				prev = new->prev;
				swap(prev, new);
				if (new->prev == NULL)
					*list = new;
				print_list((const listint_t *) *list);
			}
		}
		else
			head = head->next;
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
