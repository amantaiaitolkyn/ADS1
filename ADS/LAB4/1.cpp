#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this-> val = val;
        left = right = NULL;
    }
};
class BST{
private:
    Node* root;

    Node* push(Node* cur,int val){
        if(cur == NULL){
            return new Node(val);
        }
        if(val > cur -> val) cur -> right = push(cur -> right,val);
        if(val < cur -> val) cur -> left = push(cur -> left,val);
        return cur;
    }

    int height(Node* cur){
        if(cur == NULL) return 0;
        return max(height(cur->left),height(cur->right))+ 1;
    }
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root,val);
    }

    int height(){
        return height(root);
    }

};
int main(){
    BST tree;
    int x;
    while(cin >> x && x != 0){
        tree.push(x);
    }
    cout <<  tree.height();
    return 0;
}