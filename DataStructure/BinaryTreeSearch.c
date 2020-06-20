#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


TreeNode* createNode(element data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

TreeNode* insertNode(TreeNode* node, element data) {
    if (node == NULL) {
        return createNode(data);
    }
    else if (data < node->data) {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    return node;
}

TreeNode* search(TreeNode* node, element data) {
    if (node == NULL) {
        return NULL;
    }
    else if (data == node->data) {
        return node;
    }
    else if (data < node->data) {
        return search(node->left, data);
    }
    else {
        return search(node->right, data);
    }
}

int main(void) {
    element elements[6] = { 5, 3, 1, 4, 8, 11 };

    TreeNode* root = NULL;
    for (int i = 0; i < 6; i++) {
        root = insertNode(root, elements[i]);
    }

    element searchVal;
    printf("검색할 값을 입력하세요: ");
    scanf("%d: ", &searchVal);

    TreeNode* result = search(root, searchVal);

    if (result) {
        printf("검색됨 : %d", result->data);
    }
    else {
        printf("%d가 트리에 존재하지 않습니다.", searchVal);
    }
    
    return 0;
}
