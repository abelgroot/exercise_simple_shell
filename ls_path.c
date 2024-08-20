#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure for a linked list node */
typedef struct path_node
{
	char *dir;
	struct path_node *next;
} path_node;

/* Function to create a new node */
path_node *create_node(const char *dir)
{
	path_node *new_node = malloc(sizeof(path_node));
	if (new_node == NULL)
	{
		perror("malloc");
		return NULL;
	}

	new_node->dir = strdup(dir);
	if (new_node->dir == NULL)
	{
		perror("strdup");
		free(new_node);
	return NULL;
	}

	new_node->next = NULL;
	return new_node;
}

/* Function to build the linked list */
path_node *build_path_list(void)
{
	char *path_env = getenv("PATH");
	char *dir;
	path_node *head = NULL, *tail = NULL;

	if (path_env == NULL)
	{
		perror("getenv");
		return NULL;
	}

	char *path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup");
		return NULL;
	}

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		path_node *new_node = create_node(dir);
		if (new_node == NULL)
		{
		/* Handle error, e.g., free list and exit */
		break;
		}

		if (head == NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return head;
}

/* Function to free the linked list */
void free_path_list(path_node *head)
{
	path_node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->dir);
		free(temp);
	}
}
