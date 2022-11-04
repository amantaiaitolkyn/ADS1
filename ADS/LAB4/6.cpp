#include <iostream>
using namespace std;

int m1 = 0;
int m2 = 0;
struct Node{
    int val;
    Node* left;
    Node* right;
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
        if(val > cur->val) cur -> right = push(cur->right,val);
        if(val < cur-> val) cur -> left = push(cur-> left,val);
        return cur;
    }
    void inOrder(Node* cur){
        if(cur != NULL){
            inOrder(cur->left);
            if(cur -> val > m1){
                m2 = m1;
                m1 = cur -> val;
            }
            // if(cur -> val > m2 && cur-> val < m1) m2 = cur-> val;
            inOrder(cur->right);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root,val);
    }
    void inOrder(){
        inOrder(root);
    }
};
int main(){
    BST tree;
    int x; 
    while(cin >> x && x != 0){
        tree.push(x);
    }
    tree.inOrder();
    cout << m2;
    return 0;
}