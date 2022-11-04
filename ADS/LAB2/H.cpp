#include <iostream>
#include <vector>
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr){}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
int sizee;
 
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if(head == NULL){
        head = node;
    }else{
        Node* cur = head;
        int i = 1;
        if(p == 0){
            node -> next = cur;
            head = node;
        }else{
            while(cur != NULL){
                if(i == p){
                    node -> next = cur-> next;
                    cur -> next = node;
                    break;
                }
                i++;
                cur = cur -> next;
            }
        }
    }
    sizee++;
    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    if(head == NULL){
        return 0;
    }
    Node* cur = head;
    Node* prev = NULL;
    int i = 0;
    if(p == 0){
        head = head -> next;
    }else{
        while(cur != NULL){
            if(i == p){
                prev -> next = cur -> next;
                delete cur;
            }
            prev = cur;
            cur = cur-> next;
            i++;
        }
    }
    sizee--;
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    Node* cur = head;
    int i = 0;
    Node* myval = new Node();
    while(cur != NULL){
        if(i == p1){
            myval -> val = cur -> val;
            break;
        }
        cur = cur -> next;
        i++;
    }
    head = remove(head,p1);
    head = insert(head,myval,p2);
    return head;
}
 
Node* reverse(Node* head){
    /* write your code here */
    Node* prev =NULL;
    Node* next = NULL;
    Node* cur = head;
    while(cur != NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}
 
void print(Node* head){
    /* write your code here */
    Node* cur = head;
    if(sizee == 0){
        cout << -1 << endl;
    }else{
        while(cur != NULL){
            cout << cur -> val << " ";
            cur = cur -> next;
        }
        cout << endl;
    }
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    if(sizee == x || x == 0) return head;
    Node* cur = head;
	Node* tail = head;
    for(int i = 0;i < x;i++){
        while(cur){
            tail = cur;
            cur = cur -> next;
	    }
        tail -> next = head;
        tail = head;
        head = head -> next;
        tail -> next = NULL;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    if(sizee == x || x == 0) return head;
    int a = sizee - x;
    head = cyclic_left(head, a);
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}