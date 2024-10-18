
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
int data;
struct Node* next;
struct Node* prev;
} Node;
Node* createNode(int data) {
Node* newNode = (Node*)malloc(sizeof(Node));
if (newNode == NULL) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = data;
newNode->next = NULL;
newNode->prev = NULL;
return newNode;
}
void insertEnd(Node** head, int data) {
Node* newNode = createNode(data);
if (*head == NULL) {
*head = newNode;
newNode->next = *head;
newNode->prev = *head;
} else {
Node* temp = *head;
while (temp->next != *head) {
temp = temp->next;
}
temp->next = newNode;
newNode->prev = temp;
newNode->next = *head;
(*head)->prev = newNode;
}
}
void display(Node* head) {
if (head == NULL) {
printf("List is empty\n");
return;
}
Node* temp = head;
do {
printf("%d <-> ", temp->data);
temp = temp->next;
} while (temp != head);
printf("(head)\n");
}
void freeList(Node* head) {
if (head == NULL) return;
Node* temp = head;
Node* nextNode;
do {
nextNode = temp->next;
free(temp);
temp = nextNode;
} while (temp != head);
}
int main() {
Node* head = NULL;
int choice, data;
while (1) {
printf("\nMenu:\n");
printf("1. Insert at End\n");
printf("2. Display List\n");
printf("3. Free List\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert: ");
scanf("%d", &data);
insertEnd(&head, data);
printf("Node inserted.\n");
break;
case 2:
printf("Circular Doubly Linked List:\n");
display(head);
break;
case 3:
freeList(head);
head = NULL;
printf("List freed.\n");
break;
case 4:
freeList(head);
printf("Exiting...\n");
return 0;
default:
printf("Invalid choice. Please enter a number between 1 and 4.\n");
break;
}
}
}

