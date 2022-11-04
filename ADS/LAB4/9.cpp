#include <iostream>
using namespace std;
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
        if(val > cur-> val) cur->right = push(cur->right,val);
        if(val < cur-> val) cur -> left = push(cur -> left,val);
        return cur;
    }
    int height(Node* cur){
        if(cur == NULL) return 0;
        return max(height(cur->left),height(cur-> right))+1;
    }

    void summ(Node* cur, int level, int sum[]){
        if(cur!= NULL){
            sum[level] += cur-> val;
            summ(cur->left,level+1,sum);
            summ(cur->right,level+1,sum);
        }
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
    void summ(int level,int sum[]){
        summ(root,level,sum);
    }
};
int main(){
    BST tree;
    int n;
    cin >> n;
    for(int i=0;i <n;i++){
        int x; cin >> x;
        tree.push(x);
    }
    int h = tree.height();
    cout << h << endl;
    int sum[h];
    for(int i = 0;i < h;i++){
        sum[i] = 0;
    }
    tree.summ(0,sum);
    for(int i =0;i < h;i++){
        cout << sum[i] << " ";
    }
    return 0;
}
