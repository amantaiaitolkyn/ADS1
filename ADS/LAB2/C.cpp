#include <iostream>
using namespace std;
struct Node{
        int val;
        Node* next;

        Node(int val){
            this -> val = val;
            next = NULL;

        }
    };

class LinkedList{
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void print(){
        Node* cur = head;
        while(cur != NULL){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }

};
int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 1;i <= n;i++){
        int x; cin >> x;
        if(i % 2 != 0){
            list.push(x);
        }else{
            continue;
        }
    }
    list.print();
    return 0;
}