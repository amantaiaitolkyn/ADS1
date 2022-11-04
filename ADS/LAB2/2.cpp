#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
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
        tail =  NULL;
        size = 0;
    }

    void push(int val){
        Node * newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            size++;
        }else{
            Node * cur = head;
            while(cur != NULL){
                if(cur -> next == NULL){
                    cur -> next = newNode;
                    size++;
                    break;
                }
                cur = cur-> next;
            }
        }

    }

    void insert(int pos,int val){
        Node* newNode = new Node(val);
        int i = 0;
        Node* cur = head;
        Node* prev = NULL;
        if(pos == 0){
            newNode -> next = head;
            head = newNode;
            size++;
        }
        if(pos > size){
            return;
        }
        while(cur != NULL){
            if(i == pos){
                newNode -> next = cur;
                prev -> next = newNode;
                size++;
            }
            i++;
            prev = cur;
            cur = cur -> next;
        }
    }

    void reverse(){
        int a[size];
        int i = 0;
        Node* cur = head;
        while(cur != NULL){
            a[i] = cur -> val;
            i++;
            cur = cur->next;
        }
        i = 0;
        cur = head;
        while(cur!= NULL){
            cur-> val = a[size - i - 1];
            i++;
            cur = cur -> next;
        }
    }

    void sort(){
        Node * first = head;
        Node * second = NULL;
        while(first != NULL){
            second = first -> next;
            while(second != NULL){
                if(first->val < second->val){
                    swap(first->val,second->val);
                }
                second = second -> next;
            }
            first = first -> next;
        }
    }

    void print(){
        Node * cur = head;
        while(cur != NULL){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
    }
};
int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        list.push(x);
    }
    // list.reverse();
    list.insert(3,10);
    list.sort();
    list.print();
    return 0;
}
