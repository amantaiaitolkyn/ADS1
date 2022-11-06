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
            head = tail = newNode;
            size++;
        }else{
            tail-> next = newNode;
            tail = newNode;
            size++;
        }

    }

    void check(int num){
        Node * first = head;
        Node * second = NULL;
        while(first != NULL && first -> val < num){
            second = first -> next;
            while(second -> val < num && second != NULL){
                if(first->val+second-> val == num){
                    cout << first -> val << " " << second -> val;
                    break;
                }
                second = second -> next;
            }
            first = first -> next;
        }
    }
};
int main(){
    LinkedList list;
    int num; cin >>num;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        list.push(x);
    }
    list.check(num);
    return 0;
}