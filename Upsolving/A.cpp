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

int a[100005];
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

    void triangles(Node* cur){
        if(cur == NULL) return;
        int l = left(cur->left);
        int r = right(cur->right);
        int num = min(l,r);
        for(int i = 1;i <= num;i++){
            a[i]++;
        }
        triangles(cur->left);
        triangles(cur->right);
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
    void triangles(){
        triangles(root);
    }
};
int main(){
    BST tree;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        tree.push(x);
    }
    tree.triangles();
    for(int i = 1;i < n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
