#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this-> val =val;
        left = right =NULL;
    }
};
int cnt = 0;
class BST{
private:
    Node* root;

    Node* push(Node* cur,int val){
        if(cur == NULL){
            return new Node(val);
        }
        if(val > cur-> val) cur -> right = push(cur -> right,val);
        if(val < cur -> val) cur -> left = push(cur-> left,val);
        return cur;
    }
    void element(Node* cur){
        if(cur != NULL){
            cnt++;
            element(cur-> left);
            element(cur-> right);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root,val);
    }
    void element(){
        element(root);
    }
};
int main(){
    BST tree;
    int x;
    while(cin >> x && x != 0){
        tree.push(x);
    }
    tree.element();
    cout << cnt;
    return 0;
}