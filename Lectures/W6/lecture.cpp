#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

struct product {
  int id;
  string name;
  int price;
  int quantity;
  product *next;
};

int main() {
  Node *head = NULL;
  Node *second = NULL;
  Node *third = NULL;

  head = new Node();
  second = new Node();
  third = new Node();

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  product *headProduct = NULL;
  return 0;
}