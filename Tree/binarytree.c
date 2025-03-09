#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Yeni düğüm oluşturma fonksiyonu
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Traversal fonksiyonları
void printInorder(struct Node* node) {
    if (node == NULL) return;
    
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPreorder(struct Node* node) {
    if (node == NULL) return;
    
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Kök düğümü oluştur
    struct Node* root = createNode(1);
    
    // Sol ve sağ çocukları oluştur
    root->left = createNode(2);
    root->right = createNode(3);
    
    // İkinci seviye düğümleri oluştur
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    
    /*
        Oluşturulan ağaç:
              1
             / \
            2   3
           / \   \
          4   5   6
    */
    
    // Ağacı farklı şekillerde yazdır
    printf("Inorder traversal: ");
    printInorder(root);
    printf("\n");
    
    printf("Preorder traversal: ");
    printPreorder(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    printPostorder(root);
    printf("\n");
    
    freeTree(root);
    
    return 0;
}