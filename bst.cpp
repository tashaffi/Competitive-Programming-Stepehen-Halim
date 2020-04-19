#include <iostream>
using namespace std;

class BST{
public:
    int key;
    BST *left,*right;

    BST(int key){
        this->key = key;
        left = NULL;
        right = NULL;
    }
    
    BST* insert(BST* root, int key){
        if(!root) return new BST(key);
        if(key < root->key) root->left = insert(root->left, key);
        else if(key > root->key ) root-> right = insert(root->right, key);
        return root;
    }

    void inorder(BST* root){
        if(root){
            inorder(root->left);
            cout << root->key << " -> " ;
            inorder(root->right);
        }
    }

    BST* search(BST* root, int key){
        if(key==root->key) return root;
        if(key<root->key) return search(root->left, key);
        return search(root->right, key);
    }

    BST* successor(BST* root){
        BST* rightTree = root->right;
        while(rightTree->left){
            rightTree = rightTree->left;
        }

        return rightTree;

    }

    BST* remove(BST* root, int key){
        if(!root) return NULL;
        if(key < root->key) {
            root->left = remove(root->left, key);
        }else if(key > root->key){
            root->right = remove(root->right, key);
        }else{
            if(!root->left){
                BST* temp = root->right;
                delete(root);
                return temp;
            }else if(!root->right){
                BST* temp = root->left;
                delete(root);
                return temp;
            }else {
                BST* suc = successor(root);
                root->key = suc->key;
                root->right = remove(root->right, suc->key);
                return root;

            }
        }

        return root;
        
    }
};

int main(){
    BST *root = new BST(50); 
    root = root->insert(root, 30); 
    root = root->insert(root, 20); 
    root = root->insert(root, 40); 
    root = root->insert(root, 70); 
    root = root->insert(root, 60); 
    root = root->insert(root, 80); 
  
    cout << "Inorder traversal of the given tree \n"; 
    root->inorder(root); 
  
    cout<<"\nDelete 20\n"; 
    root = root->remove(root, 20); 
    cout<<"Inorder traversal of the modified tree \n"; 
    root->inorder(root); 
  
    cout<<"\nDelete 30\n"; 
    root = root->remove(root, 30); 
    cout<<"Inorder traversal of the modified tree \n"; 
    root->inorder(root); 
  
    cout<<"\nDelete 50\n"; 
    root = root->remove(root, 50); 
    cout<<"Inorder traversal of the modified tree \n"; 
    root->inorder(root); 
  
    return 0; 
}