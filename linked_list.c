#include <stdio.h>
#include <stdlib.h>  // Include for memory allocation

typedef struct node {
    struct node *next;  // Pointer to the next node
    int data;
} list;

list *head = NULL;  // Global head pointer

// Function to insert a node at the first position
void insertf(int d) {
    list *new_node = (list *)malloc(sizeof(list));  // Allocate memory for new node
    new_node->data = d;
    new_node->next = head;  // Link new node to existing head
    head = new_node;       // Update head to point to the new node
}

// Function to insert a node at the last position
void insertl(int d) {
    list *new_node = (list *)malloc(sizeof(list));  // Allocate memory for new node
    new_node->data = d;
    new_node->next = NULL;  // Mark as the last node

    if (head == NULL) {  // If list is empty, make new node the head
        head = new_node;
        return;
    }

    list *temp = head;
    while (temp->next != NULL) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = new_node;  // Append new node to the end
}

// Function to delete the first node
void deletef() {
    if (head == NULL) {  // Handle empty list case
        printf("List is empty.\n");
        return;
    }

    list *temp = head;
    head = head->next;  // Update head to point to the next node
    free(temp);         // Free the deleted node
}

// Function to delete the last node
void deletel() {
    if (head == NULL) {  // Handle empty list case
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {  // If only one node, delete head
        free(head);
        head = NULL;
        return;
    }

    list *temp = head;
    while (temp->next->next != NULL) {  // Traverse to second last node
        temp = temp->next;
    }
    free(temp->next);  // Free the last node
    temp->next = NULL;  // Mark the second last node as the new last node
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    list *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void menu(){
    int c1,c2,d;
    printf("[1] Insert\n[2] Delete\n[3] Display\n[4] Exit\n");
    scanf("%d",&c1);
    switch(c1){
        case 1:
        printf("[1] Insert at First\n[2] Insert at last\n");
        scanf("%d",&c2);
        switch(c2){
            case 1:
            printf("Enter data: \n");
            scanf("%d",&d);
            insertf(d);
            menu();
            break;
            case 2:
            printf("Enter Data: \n");
            scanf("%d",&d);
            insertl(d);
            menu();
            break;
            default: printf("[1] Enter valid Choice");
            break;
        }
        break;
        case 2:
        printf("[1] Delete at first\n[2] Delete at last\n");
        scanf("%d",&c2);
        switch(c2){
            case 1:
            deletef();
            menu();
            break;
            case 2:
            deletel();
            menu();
            break;
            default: printf("[!] Enter valid Choice\n");
            break;
        }
        break;
        case 3:
        display();
        menu();
        break;
        case 4:
        break;
        default: printf("[!] Please enter valid choice\n");
        menu();
    }
}
int main(){
    menu();
}