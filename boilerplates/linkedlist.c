/* Description:
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_Struct {
    int val;
    struct Node_Struct* next;
} Node;

Node* newNode(int n) {
    Node* new = (Node*)calloc(1, sizeof(Node));
    new->val = n;
    new->next = NULL;

    return new;
}

Node* insert(Node* root, Node* n) {
    if (root == NULL) {
        return n;
    }
    n->next = root;
    return n;
}

int main() {
    
    return 0;
}