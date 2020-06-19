#include <stdio.h>

typedef int element;
typedef struct TreeNode {
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("[%d] ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    printf("[%d] ", root->data);
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("[%d] ", root->data);
}

int main(void) {
    printf("Binary Tree Traversal\n\n");
    
    printf("Pre-Order -> ");
    preorder(root);
    printf("\n");

    printf("In-Order -> ");
    inorder(root);
    printf("\n");

    printf("Post-Order -> ");
    postorder(root);
    printf("\n");

    return 0;
}
