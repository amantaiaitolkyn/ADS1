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
    int size;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push_back(int val){ //функция для доб элемента
        Node* newNode = new Node(val); //используя конструктор создаем Node;
        if(head == NULL){
            head = tail = newNode;
            size++;
            
        }else{
            tail -> next = newNode;
            tail = newNode;
            size++;

        }
    }

    void add(int val,int pos){
        if(pos >= size){
            return;
        }

        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }else{
            Node* cur = head;
            int i = 1;
            while(cur != NULL){
                if(i == pos){
                    newNode->next = cur -> next;
                    cur -> next = newNode;
                    break;
                }else if(pos == 0){
                    newNode->next = cur;
                    head = newNode;
                    break;
                }
                cur = cur -> next;
                i++;
            }
        }
        size++;

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
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        list.push_back(x);
    }
    int data , pos;
    cin >> data >> pos;
    list.add(data,pos);
    list.print();
    return 0;
}