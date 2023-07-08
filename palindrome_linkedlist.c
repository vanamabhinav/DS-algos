#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

 // Traverse the given string and append each character as a new node at the beginning.
  // Traverse the linked list and compare each character with the characters in the string.

// Linked list node
struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node
struct Node* temporary_Node(char data)
{
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if a string is palindrome
bool Palindrome(char* str)
{
    // Create an empty linked list
    struct Node* head = NULL;

    
    for (int i = 0; str[i] != '\0'; i++) {
        struct Node* node = temporary_Node(str[i]);
        node->next = head;
        head = node;
    }

    struct Node* current = head;
    int i = 0;
    while (current != NULL) {
        if (current->data != str[i])
            return false;
        current = current->next;
        i++;
    }

    return true;
}

// Main function
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (Palindrome(str))
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
