/* Description:
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LLNode {
    struct LLNode* next;
    int value;
} node;

void print_ll(node* head) {
    while(head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

node* push_front(node* head, int val) {
    node* new = (node*)(calloc(1, sizeof(node)));
    new->value = val;
    new->next = head;
    return new;
}


node* reverseLinkedList(node* head) {
    node* curr = head;
    node* tempnext;
    node* tempcurr;

    while(curr != NULL) {
        tempnext = curr->next;
        curr->next = head;
        
        head = head->next;
        curr = tempnext;
    }

    return curr;
}

int main() {
    node* head = (node*)(calloc(1, sizeof(node)));

    //Insert
    for (int i = 1; i < 10; i++) {
        head = push_front(head, i);
    }

    print_ll(head);

    head = reverseLinkedList(head);

    print_ll(head);

    return 0;
}