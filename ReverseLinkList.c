// ReverseLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char *name;
	int age;
	struct node *next;
}node;

size_t	ft_strlen(const char* s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

size_t	ft_strlcpy(char* dst, const char* src, size_t dssize)
{
	size_t	i;
	int		src_len;

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

void printList(node* n)
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
	scanf_s("%s", buffer);
	nameLength = ft_strlen(buffer) + 1;
	name = (char*)malloc(nameLength);
	ft_strlcpy(name, buffer, nameLength);
	//printf("Your name is %s\n", name);
	return name;
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



int main()
{
	node	*headNode = NULL;
	node	*temp = NULL;
	int		length;

	printf("Type the amount of list\n");
	scanf_s("%d", &length);

	for (int i = 0; i < length; i++)
	{
		node* currentNode = (node*)malloc(sizeof(node));
		currentNode->name = createName();
		currentNode->age = 15;
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

	printLinkList(temp);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
