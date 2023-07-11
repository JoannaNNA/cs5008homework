#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* newNode(int data) {
    node* Node = (node*) malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}

node* insertNode(node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

double findClosestValue(node* root, double target, double closest) {
    if (root == NULL) {
        return closest;
    }

    if (fabs(target - closest) >= fabs(root->data - target)) {
        closest = root->data;
    }

    if (target < root->data) {
        return findClosestValue(root->left, target, closest);
    } else {
        return findClosestValue(root->right, target, closest);
    }
}

int main() {
    node *root = NULL;
    int size;
    double target;

    printf("Input array size: ");
    scanf("%d", &size);

    printf("Input elements of the array:\n");
    for(int i = 0; i < size; i++) {
        int data;
        scanf("%d", &data);
        if(i == 0) {
            root = newNode(data);
        } else {
            insertNode(root, data);
        }
    }

    printf("Input target: ");
    scanf("%lf", &target);

    double result = findClosestValue(root, target, root->data);

    printf("Closest number = %.0lf\n", result);

    return 0;
}
