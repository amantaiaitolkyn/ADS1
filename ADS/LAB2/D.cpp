#include <iostream>
using namespace std;

struct Node{
    int val;
    int cnt;
    Node * next;

    Node(int val){
        this -> val = val;
        next = NULL;
        cnt = 1;
    }

};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = NULL;
    }

    void push(int val){ 
        Node* newNode = new Node(val); 
        if(head == NULL){
            head = newNode;
        }else{
            Node * cur = head;
            while(cur != NULL){
                if(cur -> val == val){
                    cur -> cnt++;
                    break;
                }
                if(cur -> next == NULL){
                    cur -> next = newNode;
                    break;
                }
                cur = cur -> next;
            }

        }
    }

    void sort(){
        Node * first = head;
        Node * second = NULL;
        if(head == NULL){
            return;
        }
        while(first -> next != NULL){
            second = first -> next;
            while(second != NULL){
                if(first -> cnt != second -> cnt){
                    if(first -> cnt < second -> cnt ){
                        swap(first -> cnt,second -> cnt );
                        swap(first -> val,second -> val );
                    }
                }else{
                    if((first -> cnt < second -> cnt) or (first -> val < second -> val)){
                        swap(first -> cnt,second -> cnt );
                        swap(first -> val,second -> val );
                    }
                }
                second = second -> next;
            }
            first = first -> next;
        }
    

    }

    void print(){
        Node * first = head;
        Node * second = NULL;
       if(head == NULL){
            return;
        }
        second = first -> next;
        if(second == NULL){
            cout << first -> val;
        }else if(first -> cnt != second -> cnt){
            cout << first -> val;
        }else{
            cout << first -> val;
            while(second != NULL){
                cout << " ";
                if(first -> cnt == second -> cnt){
                    cout << second -> val;
                }
                second = second -> next;
            }
        }
        
    }

};
int main(){
    int n; cin >> n;
    LinkedList list;

    for(int i = 0;i < n;i++){
        int x; cin >> x;
        list.push(x);
    }
    list.sort();
    list.print();
    return 0;
}