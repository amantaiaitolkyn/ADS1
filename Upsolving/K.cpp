#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

struct Node{
    int val; 
    Node* next; 
    Node* prev;

    Node(int val){
        this->val = val;
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

    void push_back(int val){ 
        Node* newNode = new Node(val); 
        if(head == NULL){
            head = tail = newNode;
            size++;
            
        }else{
            tail -> next = newNode;
            tail = newNode;
            size++;

        }
    }

    void push_front(int val){
        Node* newNode = new Node(val); 
        if(head == NULL){
            head = tail = newNode;
            size++;
            
        }else{
            newNode -> next = head;
            head = newNode;

        }
    }
    void reverse(){
        stack<int> st;
        Node* cur = head;
        while (cur != NULL) {
            st.push(cur-> val);
            cur = cur->next;
        }
        cur = head;
        while (cur != NULL) {
            cur -> val = st.top();
            st.pop();
            cur = cur->next;
        }
 
    }

    void print(int v) {
        if(v % 2 != 0){
            reverse();
        }
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

};

int main(){
    LinkedList list;
    int q; cin >> q;
    int cnt = 0;
    for(int i = 0;i < q;i++){
        int num; cin >> num;
        if(num == 1){
            int x; cin >> x;
            if(cnt%2==0){
                list.push_back(x);
            }else{
                list.push_front(x);
            }
        }else if(num == 2){
            cnt++;
        }
    }
    list.print(cnt);
   
    return 0;
}