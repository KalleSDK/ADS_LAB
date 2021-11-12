#include <stdio.h>
#include <stdlib.h>
 

struct node {
    int data;
    struct node* next;
};
 
struct node* XOR(struct node *a, struct node *b) {
     return (struct node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}
 
void insert(struct node **head, int data) {
    
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = XOR(*head, NULL);
 
    if (*head != NULL) {
        struct node* next = XOR((*head)->next, NULL);
        (*head)->next = XOR(new_node, next);
    }
    *head = new_node;
}

 

void print(struct node *head) {
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
 
    printf("List: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        next = XOR(prev, curr->next);
        prev = curr;
        curr = next;
    }
    printf("\n");
}
 

struct node* deleteEnd(struct node** head)
{
    
    if (*head == NULL)
        printf("List is empty");
    else {

        struct node* curr = *head;        
        struct node* prev = NULL;
        struct node* next;
  
        
        while (XOR(curr->next, prev) != NULL) { 
            next = XOR(prev, curr->next);
            prev = curr;
            curr = next;
        }
        
        if (prev != NULL)
            prev->next = XOR(XOR(prev->next, curr), NULL);
        else
            *head = NULL;

        free(curr);
    }
  
    
    return *head;
}


void main() {
    struct node *head = NULL;
    int x,n,i=0, flag = 1;
    while(flag==1) {
        printf("\n1. Insert\n2. Delete\n3. Print\n4. Exit\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter a number to insert: ");
            scanf("%d", &x);
            insert(&head,x);
            break;
        case 2:
            deleteEnd(&head);
            printf("deleted node\n");
            break;
        case 3:
            print(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
 
    
    
}