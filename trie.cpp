#include <iostream>
#include <map>
using namespace std;


struct TrieNode{
    map<char, struct TrieNode*> children;
    bool eof;
};

struct TrieNode* getNode(void){
    struct TrieNode* pNode = new TrieNode;
    pNode-> eof = false;
    map<char, struct TrieNode*> nmap;
    pNode->children = nmap;
    return pNode;
}

void insert(struct TrieNode* root, string key){
    struct TrieNode* pCrawl = root;
    for(int i=0;i<key.length();i++){
        if(!pCrawl->children[key[i]]){
            pCrawl->children[key[i]] = getNode();
        }

        pCrawl = pCrawl->children[key[i]];
    }

    pCrawl->eof = true;
}

bool search(struct TrieNode* root, string key){
    struct TrieNode* pCrawl = root;
    for(int i=0;i<key.length();i++){
        if(!pCrawl->children[key[i]]) return false;
        pCrawl = pCrawl->children[key[i]];
    }

    return (pCrawl!=NULL && pCrawl->eof);
}


bool isEmpty(struct TrieNode* root){
    return root->children.empty();
}



struct TrieNode* remove(struct TrieNode* root, string key, int depth=0){
    if(!root){
        return NULL;
    }

    if(depth == key.length()){
        //if the trie has that exact word
        if(root->eof){
            root->eof = false;
        }
        
        //if the key is not prefix to any other string
        if(isEmpty(root)){
            delete root;
            root = NULL;
        }

        return root;
    }

    root->children[key[depth]] = remove(root->children[key[depth]], key, depth+1);
    if(isEmpty(root) && !root->eof) {
        delete root;
        root = NULL;
    }

    return root;
}



int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = { "the", "a", "there", 
                      "answer", "any", "by", 
                      "bye", "their", "hero", "heroplane" }; 
    int n = sizeof(keys) / sizeof(keys[0]); 
  
    struct TrieNode* root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these") ? cout << "Yes\n" : cout << "No\n"; 
  
    remove(root, "heroplane"); 
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n"; 
    return 0; 
} 