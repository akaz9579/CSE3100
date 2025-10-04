//Do not modify starter code
//You may add helper functions if needed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Insert at end
void insertEnd(Node **head, int data) {
  Node *newNode = createNode(data);
  if (!*head) {
    *head = newNode;
    return;
  }
  Node *temp = *head;
  while (temp->next)
    temp = temp->next;
  temp->next = newNode;
}

// Print list
void printList(Node *head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void zipList(Node **headRef) {


  if (*headRef == NULL || (*headRef)->next == NULL) return;

  Node *check1 = *headRef, *check2 = *headRef;
  while (check2->next && check2->next->next) {
    check1 = check1->next;
    check2 = check2->next->next;
  }

  Node *second = check1->next;
  check1->next = NULL;

  Node *prev = NULL; 
  Node *curr = second;
  Node*next = NULL;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  second = prev;

  Node *first = *headRef;
  while (first && second) {
    Node *tmp1 = first->next;
    Node *tmp2 = second->next;
    first->next = second;
    if (tmp1 == NULL) break;
    second->next = tmp1;
    first = tmp1;
    second = tmp2;
  }
}

int main(int argc, char *argv[]) {
  Node *head = NULL;

  if (argc < 2) {
    printf("Usage: %s <list of integers>\n", argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    int val = atoi(argv[i]);
    insertEnd(&head, val);
  }

  printf("Original list:\n");
  printList(head);

  zipList(&head);

  printf("Zipped list:\n");
  printList(head);
 
  //f????/ipjj bruh waht i do here

  Node *temp;
  while (head) {
    temp = head;
    head = head->next;
    free(temp);
  }


  return 0;
}
