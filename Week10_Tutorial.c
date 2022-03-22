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

Node* insert(Node* root, int n) {
    Node* new = newNode(n);
    if (root == NULL) {
        return new;
    }
    new->next = root;
    return new;
}

int getFactorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * getFactorial(n-1);
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int getLargest(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return max(root->val, getLargest(root->next));
}

int isPalendrome(char* s, int l) {
    if (l <= 1) {
        return 1;
    } else if (*s == *(s+l-1)) {
        return isPalendrome(s+1, l-2);
    } else {
        return 0;
    }
}

int main() {
    printf("7 factorial: %d\n",getFactorial(7));
    Node* head = insert(NULL, 1);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 23);
    head = insert(head, 14);
    printf("Max of list is : %d\n", getLargest(head));

    printf("%d\n", isPalendrome("racecar", 7));
    printf("%d\n", isPalendrome("obama", 5));
    
    return 0;
}