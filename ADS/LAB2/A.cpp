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
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void push_back(int val){ //функция для доб элемента
        Node* newNode = new Node(val); //используя конструктор создаем Node;
        if(head == NULL){
            head = tail = newNode;
            
        }else{
            tail -> next = newNode;
            tail = newNode;

        }
    }
    
    void offSet(int k){
        Node* cur = head;
        int min = +2147483647;
        int ind = 0;
        int i;
        while(cur != NULL){
            int num = abs(k - cur-> val);
            if(num < min){
                min = num;
                i = ind;
            }
            cur = cur -> next;
            ind++;
        }
        cout << i;
    }

};

int main(){
    LinkedList list;
    int n; cin >> n;
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        list.push_back(x);
    }
    int k; cin >> k;
    list.offSet(k);
    return 0;
}
