#include <iostream>
#include <vector>
using namespace std;
struct Node{
    string val;
    Node* next;
    int cnt;

    Node(string val){
        this -> val = val;
        next = NULL;
        cnt = 1;
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

    void push(string val){
        Node* newNode = new Node(val);
        if(head == NULL){
            tail = head = newNode;
            size++;
        }else{
            if(tail-> val == val){
                tail -> cnt++;
            }else{
                tail -> next = newNode;
                tail = newNode; 
                size++;
            }
        }
    }

    void reverse(){
        Node* cur = head;
        vector<string> rev; 
        while(cur != NULL){
            rev.push_back(cur->val);
            cur = cur -> next;
        }
        int x = rev.size() - 1;
        cur = head;
        while(cur != NULL){
            cur -> val = rev[x];
            cur = cur -> next;
            x--;
        }
    }

    void print(){
        Node* cur = head;
        cout << "All in all: " << size << endl;
        cout << "Students: " << endl;
        while(cur != NULL){
            cout << cur -> val <<endl;
            cur = cur -> next;
        }
    }
};
int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i= 0;i < n;i++){
        string s;
        while(cin >> s){
            list.push(s);
        }
    }
    list.reverse();
    list.print();
    return 0;
}