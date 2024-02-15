#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int count = 0;
    node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

//  parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    int stringLength = length(head);
    // Allocate memory for the C-style string
    char* result = (char*)malloc((stringLength + 1) * sizeof(char)); // +1 for the null terminator

    if (result == NULL) 
    {
        // Handle memory allocation failure
        printf("Memory allocation error with result.");
    }

    int i = 0;
    node* current = head;

    // Traverse the linked list and copy characters to the result string array.
    while (current != NULL) {
        result[i] = current->letter;
        i++;
        current = current->next;
    }

    result[stringLength] = '\0'; // Add null terminator

    return result;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|

void insertChar(node** pHead, char c)
{
    // Allocate memory for the new node
    node* newEndNode = malloc(sizeof(struct node));

    if(newEndNode == NULL)
    {
        // Handle memory allocation failure
        printf("Memory allocation error with newEndNode.");
    }
    
    newEndNode->letter = c;
    newEndNode->next = NULL;

    if(*pHead == NULL)
    {
        // If the list is empty, set the new node as the head.
        *pHead = newEndNode;
    }
    else
    {
        // Traverse the list to find the end and add the new node 
        node* traverseNode;
        traverseNode = *pHead;

        while(traverseNode->next != NULL)
        {
            traverseNode = traverseNode-> next;
            
        }

        traverseNode->next = newEndNode;     
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* current = *pHead;
    node* nextNode;

    // Traverse the list, free memory, and update pointers.
    while (current != NULL) 
    {
        nextNode = current->next; 
        free(current); 
        current = nextNode; 
    }
    
    *pHead = NULL; // Set the head to NULL after deleting all nodes
}


int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}