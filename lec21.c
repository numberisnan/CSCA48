/* Description:
*
* This program was written by Faraz Malik. Copy idk its nothing special
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_Struct {
    coord val;
    struct Node_Struct* next;
} Node;

Node* newNode(coord n) {
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

int adj[100][100];
int vis[100][100];

typedef struct coord_s {
    int x, y;
} coord;

Node* DFS(coord curr, coord dest, int adj[100][100]) {
    if (curr.x == dest.x && curr.y == curr.y) {
        return newNode(curr);
    } else {
        vis[curr.x][curr.y] = 1;
        Node* head;
        int diffs[4][2] = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            
        }
    }
}