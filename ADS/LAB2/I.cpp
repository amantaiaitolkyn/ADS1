#include <iostream>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt = 0;

void add_back(string s){
    Node * newNode = new Node(s);
    Node* tail = head;
    Node* cur = head;
    while(cur){
		tail = cur;
		cur = cur -> next;
	}
    if(head == NULL){
        head = tail = newNode;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
    cnt++;
}

void add_front(string s){
    Node* newNode = new Node(s);
    Node* cur = head;
    newNode -> next = head;
    head = newNode;
    cnt++;
}

bool empty(){
   if(cnt == 0){
    return true;
   }else{
    return false;
   }
}

void erase_front(){
    if(cnt > 0){
        head = head -> next;
    }else{
        head = NULL;
    }
    cnt--;
}

void erase_back(){
    Node* cur = head;
	Node* prev = NULL;
    if(cnt > 1){
        while(cur != NULL){
            if(cur -> next == NULL){
                prev -> next = cur -> next;

            }
            prev = cur;
            cur = cur -> next;
	    }
    }else{
        head = NULL;
    }
    cnt--;
}

string front(){
    Node* cur = head;
    return cur -> val;
}

string back(){
    Node* cur = head;
	Node* tail = head;
	while(cur){
		tail = cur;
		cur = cur -> next;
	}
    return tail -> val;
}

void clear(){
    Node* cur = head;
    delete cur;
    head = NULL;
    cnt = 0;
}

int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   	}
    return 0;
}