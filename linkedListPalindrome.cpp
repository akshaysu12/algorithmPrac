#include <iostream>

struct Node {
  int val;
  Node *next;
  //constructor
  Node(int val1, Node *next1 = nullptr) {
    val = val1;
    next = next1;
  }

};

bool recursePal(Node **head, Node *curr) {
  if (curr == nullptr) {
    return true;
  }

  bool res = recursePal(head, curr->next);
  if (res == false) {
    return false;
  }

  else if ((*head)->val == curr->val) {
    *head = (*head)->next;
    return true;
  }

  else {
    return false;
  }
}


int main() {
  struct Node *head = new Node(1);
  head->next = new Node(2);

  struct Node *temp = head->next;

  temp->next = new Node(3);
  temp = temp->next;
  temp->next = new Node(2);
  temp = temp->next;
  temp->next = new Node(7);
  temp = head;

  struct Node *newHead = head;


  std::cout << recursePal(&head, head) << std::endl;

}
