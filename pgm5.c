#include <stdio.h>
#include <stdlib.h>
struct node {
int val;
struct node *next;
};
struct node *top = NULL;
void push() {
int val;
struct node *ptr = (struct node *)malloc(sizeof(struct node));
if (!ptr) {
printf("Memory allocation failed\n");
return;
}
printf("Enter the value: ");
scanf("%d", &val);
ptr->val = val;
ptr->next = top;
top = ptr;
printf("Item pushed\n");
}
void pop() {
if (top == NULL) {
printf("Underflow\n");
return;
}
struct node *temp = top;
top = top->next;
free(temp);
printf("Item popped\n");
}
void display() {
struct node *temp = top;
if (!temp) {
printf("Stack is empty\n");
return;
}
printf("Stack: ");
while (temp) {
printf("%d -> ", temp->val);
temp = temp->next;
}
printf("NULL\n");
}
int main() {
int choice;
printf("\n*Stack operations using linked list*\n");
do {
printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: push(); break;
case 2: pop(); break;
 case 3: display(); break;
case 4: printf("Exiting...\n"); break;
 default: printf("Please enter a valid choice\n");
}
} while (choice != 4);
return 0;
}
