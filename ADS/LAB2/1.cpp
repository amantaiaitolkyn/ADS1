#include <iostream>
#include <cmath>
using namespace std;

struct Node{
    int val; 
    Node* next; // указатель на располож  след.элемента , то есть на Ноду

    Node(int val){
        this->val = val;
        next = NULL;
    }
};

class LinkedList{
    Node* head; // указатель на первый элемент(head)
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
    void print() {
        Node* cur = head;
        int i = 0;
        while (cur != NULL) {
            if(i >= size /2){
                cout << cur->val << " ";
            }
            i++;
            cur = cur->next;
        }
        cout << endl;
    }

};

int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        list.push_back(x);
    }
    list.print();
   
    return 0;
}