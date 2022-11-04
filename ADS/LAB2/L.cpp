# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};

int findMaxSum(int n, Node *head) {
	Node* cur = head;
  int max = -999999;
  n = 0;
  while(cur != NULL){
    n += cur->val;
    if(cur -> val > n){
      n = cur -> val;
    }
    cur = cur -> next;
    if(n > max){
      max = n;
    }
  }
  return max;
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}