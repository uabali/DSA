#include <iostream>
using namespace std;

// Düğüm yapısı
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Binary Tree sınıfı
class BinaryTree {
private:
    Node* root;
    
    // Private yardımcı fonksiyonlar
    void printInorderHelper(Node* node) {
        if (node == NULL) return;
        
        printInorderHelper(node->left);
        cout << node->data << " ";
        printInorderHelper(node->right);
    }
    
    void printPreorderHelper(Node* node) {
        if (node == NULL) return;
        
        cout << node->data << " ";
        printPreorderHelper(node->left);
        printPreorderHelper(node->right);
    }
    
    void printPostorderHelper(Node* node) {
        if (node == NULL) return;
        
        printPostorderHelper(node->left);
        printPostorderHelper(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() {
        root = NULL;
    }
    
    // Kök düğümü oluştur
    void createRoot(int value) {
        root = new Node(value);
    }
    
    // Sol çocuk ekle
    void addLeft(Node* parent, int value) {
        parent->left = new Node(value);
    }
    
    // Sağ çocuk ekle
    void addRight(Node* parent, int value) {
        parent->right = new Node(value);
    }
    
    // Root'a erişim
    Node* getRoot() {
        return root;
    }
    
    // Traversal fonksiyonları
    void printInorder() {
        cout << "Inorder traversal: ";
        printInorderHelper(root);
        cout << endl;
    }
    
    void printPreorder() {
        cout << "Preorder traversal: ";
        printPreorderHelper(root);
        cout << endl;
    }
    
    void printPostorder() {
        cout << "Postorder traversal: ";
        printPostorderHelper(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    
    // Ağaç oluşturma
    tree.createRoot(1);
    Node* root = tree.getRoot();
    
    tree.addLeft(root, 2);
    tree.addRight(root, 3);
    
    tree.addLeft(root->left, 4);
    tree.addRight(root->left, 5);
    
    tree.addRight(root->right, 6);
    
    /*
        Oluşturulan ağaç:
              1
             / \
            2   3
           / \   \
          4   5   6
    */
    
    // Ağacı farklı şekillerde yazdırma
    tree.printInorder();    // Expected: 4 2 5 1 3 6
    tree.printPreorder();   // Expected: 1 2 4 5 3 6
    tree.printPostorder();  // Expected: 4 5 2 6 3 1
    
    return 0;
}