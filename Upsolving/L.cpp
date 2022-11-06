#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this-> val = val;
        left = right =NULL;
    }
};
int cnt =0;
class BST{
private:
    Node* root;

    Node* push(Node * cur,int val){
        if(cur == NULL){
            return new Node(val);
        }
        if(val > cur-> val) cur -> right = push(cur -> right,val);
        if(val < cur -> val) cur -> left = push(cur -> left,val);
        return cur;
    }
    void printleaves(Node* cur){
        if(cur != NULL){
            printleaves(cur->left);
            if(cur -> left == NULL && cur -> right == NULL){
                cnt++;
            }
            printleaves(cur->right);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root,val);
    }
    void printleaves(){
        printleaves(root);
    }
};
int main(){
    BST tree;
    int x;  cin >> x;
    for(int i = 0;i < x;i++){
        int num; cin >> num;
        tree.push(num);
    }
    tree.printleaves();
    cout << cnt;
    return 0;
}