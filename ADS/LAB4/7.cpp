#include <iostream>
using namespace std;


struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this -> val = val;
        left = right = nullptr;
    }
};
int cnt =0;

class BST{
private:
    Node * root;
    Node * insert(Node * cur, int val){
        if(cur == nullptr){
            return new Node(val);
        }
        if(val > cur -> val) cur -> right = insert(cur -> right , val);
        if(val < cur -> val) cur -> left = insert(cur -> left, val);
        return cur;
    }
    
    void inOrder(Node * cur){
        if (cur != nullptr){
            inOrder(cur -> left);
            inOrder(cur -> right);
        }
    }
    int height(Node * cur){
        if(cur == NULL) return 0;
        int left =  height(cur-> left) + 1;
        int right = height(cur-> right) + 1;
        return left - right;
    }

    void isBalanced(Node * cur){
        if(cur != NULL){
            if((height(cur)<= 1)){
                cnt++;
            }
            isBalanced(cur -> left);
            isBalanced(cur -> right);
        }
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int val){
        root = insert(root, val);
    }
    void inOrder(){
        inOrder(root);
    }
    int  height(){
        return height(root);
    }
    void isBalanced(){
        isBalanced(root);
    }
    
};
int main(){
    BST tree;
    int x;
    int c= 0;
    while(cin >> x && x != 0){
        c++;
        tree.insert(x);
    }
    tree.isBalanced();
    if(c == cnt){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}