#include <iostream>
#include <vector>
using namespace std;

struct Node{
    char val;
    Node* next;

    Node(int val){
        this -> val = val;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
    Node* tail;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }


    void push(char val){
        Node* newNode = new Node(val); 
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void print(vector<int> vec){
        while(head != NULL and vec[head -> val -'a'] > 1){
            head = head -> next;
        }
        if(head == NULL){
            cout << -1 << " ";
        }else{
            cout << head -> val << " ";
        }
    }
};
int main(){
    int n; cin >> n;
    for(int i = 0;i < n;i++){
       LinkedList list;
       vector<int> vec(30,0);
       int m; cin >> m;
       for(int j = 0;j < m;j++){
            char x; cin >> x;
            vec[x - 'a']++;
            list.push(x);
            list.print(vec);
       }
       cout << endl;
    }
    return 0;
}