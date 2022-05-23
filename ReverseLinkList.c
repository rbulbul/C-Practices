#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *name;
	int age;
	struct node *next;
} node;

size_t ft_strlen(const char *s)
{
	size_t counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dssize)
{
	size_t i;
	int src_len;

	src_len = ft_strlen(src);
	if (!dssize || !src)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < dssize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

void printList(node *n)
{
	while (n != NULL)
	{
		printf("%s is %d years old", n->name, n->age);
		n = n->next;
	}
}

char *createName(void)
{
	char buffer[101];
	char *name;
	int nameLength;

	printf("Please type a name up to 30 char\n");
	scanf("%s", buffer);
	nameLength = ft_strlen(buffer) + 1;
	name = (char *)malloc(nameLength);
	ft_strlcpy(name, buffer, nameLength);
	return name;
}

int askAgeToUser(void)
{
	int personAge;

	printf("Please type the age of person:\n");
	scanf("%d", &personAge);
	return personAge;
}

void printLinkList(node *list)
{
	printf("Iterating through the elements of the linked list : \n");
	while (list != NULL)
	{
		printf("Hello, my name is %s and I'm %d years old\n", list->name, list->age);
		list = list->next;
	}
}
void printReverseLinkList(node *list)
{
	node *prev = NULL;
	node *current = list;
	node *next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list = prev;
	printLinkList(list);
}

int main(void)
{
	node *headNode = NULL;
	node *temp = NULL;
	int length;

	printf("Type the amount of list\n");
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
	{
		node *currentNode = (node *)malloc(sizeof(node));
		currentNode->name = createName();
		currentNode->age = askAgeToUser();
		if (i == 0)
		{
			headNode = temp = currentNode;
		}
		else
		{
			temp->next = currentNode;
			temp = currentNode;
		}
	}
	temp->next = NULL;
	temp = headNode;

	printf("******** Printing created link list.. ********");
	printLinkList(temp);
	printf("******** Printing reverse version of created link list.. ********");
	printReverseLinkList(temp);
	return 0;
}
