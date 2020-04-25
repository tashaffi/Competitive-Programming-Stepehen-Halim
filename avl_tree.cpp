#include <iostream>
using namespace std;

class Node{
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node){
    if(!node) return 0;
    return node->height;
}


int getBalance(Node* node){
    if(!node) return 0;
    return (height(node->left)-height(node->right));
}

Node* newNode(int key){
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}


Node* leftRotate(Node* z){
    Node* y = z->right;
    Node* T2 = y->left;

    z->right = T2;
    y->left = z;

    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


Node* rightRotate(Node* z){
    Node* y = z->left;
    Node* T3 = y->right;

    z->left = T3;
    y->right = z;

    z->height = max(height(z->left), height(z->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key){
    if(node==NULL) return newNode(key);
    if(key < node->key) node->left = insert(node->left, key);
    else if(key > node->key ) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left),  
                        height(node->right));  
    int balance = getBalance(node);

    //Left-Left imbalance
    if(balance>1 && key < node->left->key){
        return rightRotate(node);
    }
    //Left-Right imbalance
    if(balance>1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //Right-Right imbalance
    if(balance<-1 && key > node->right->key){
        return leftRotate(node);
    }
    //Right-Left imbalance
    if(balance<-1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->key << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

// Driver Code 
int main()  
{  
    Node *root = NULL;  
      
    /* Constructing tree given in  
    the above figure */
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
      
    /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
      
    return 0;  
}  