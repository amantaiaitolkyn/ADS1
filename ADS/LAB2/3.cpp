#include <iostream>
using namespace std;

struct Node{
    string s;
    Node * next;
    Node(string s){
        this-> s = s;
        next = NULL;
    }
};
class LinkedList{
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(string s){
        Node * newNode = new Node(s);
        if(head == NULL){
            head = newNode;
        }else{
            Node * cur = head;
            while(cur != NULL){
                if(cur ->next == NULL){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }
        }
        size++;
    }
    void cycle_left(int x){
        Node* cur = head;
        Node* tail = head;
        while(cur){
            tail = cur;
            cur = cur -> next;
        }
        
        for(int i = 0;i < x;i++){
            tail -> next = head;
            tail = head;
            head = head -> next;
            tail -> next = NULL;
        }
    }
    void cycle_right(int x){
        if(x == size || x == 0) {
            return;
        }else{
            int a = size - x;
            cycle_left(a);
        }
    }

    void print(){
        Node * cur = head;
        while(cur != NULL){
            cout << cur -> s << " ";
            cur = cur -> next;
        }
    }

};
int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0;i<n;i++){
        string s; cin >> s;
        list.push(s);
    }
    int x; cin >> x;
    list.cycle_left(x);
    list.print();
    return 0;
}