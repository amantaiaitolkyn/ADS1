#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this -> val = val;
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
        if(val > cur-> val) cur-> right = push(cur-> right,val);
        if(val < cur->val) cur-> left = push(cur->left,val);
        return cur;
    }

    void find(Node* cur,int val){
        if(cur != NULL){
            if(cur -> val == val){
            print(cur);
            }
            find(cur-> left,val);
            find(cur-> right,val);
        }
    }

    void print(Node* cur){
        if(cur!= NULL){
            cout << cur-> val << " ";
            print(cur ->left);
            print(cur ->right);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root,val);
    }
    void find(int val){
        find(root,val);
    }
    void print(){
        print(root);
    }

};
int main(){
    BST tree;
    int n; cin >>n;
    for(int i=0;i < n;i++){
        int x; cin >> x;
        tree.push(x);
    }
    int val;
    cin >> val;
    tree.find(val);
    return 0;
}