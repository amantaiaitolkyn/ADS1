#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int val){
        this->val = val;
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
        if(val > cur->val) cur-> right = push(cur->right,val);
        if(val < cur->val) cur->left = push(cur->left,val);
        return cur;
    }

    int height(Node* cur){
        if(cur == NULL) return 0;
        return max(height(cur->left),height(cur->right))+1;
    }

    int left(Node* cur){
        if(cur == NULL) return 0;
        return left(cur->left)+1;
    }
    int right(Node* cur){
        if(cur == NULL) return 0;
        return right(cur->right)+1;
    }

    void check(Node* cur,int a[],int level){
        if(cur != NULL){
            a[level] += (cur-> val - level);
            check(cur->left,a,level+1);
            check(cur->right,a,level+1);
        }
    }


public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root,val);
    }
    void left(){
        left(root);
    }
    void right(){
        right(root);
    }
    int height(){
       return height(root);
    }
    void check(int a[],int level){
        check(root,a,0);
    }
};
int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        tree.push(x);
    }
    int num = tree.height();
    int a[num];
    for(int i = 0;i < num;i++){
        a[i] = 0;
    }
    tree.check(a,0);
    int sum = 0;
    for(int i = 0;i < num;i++){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}