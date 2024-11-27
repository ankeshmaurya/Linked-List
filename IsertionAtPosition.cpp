#include <iostream>
struct Node {
 int data;
 Node* next;
};
Node* createNode(int data) {
 Node* newNode = new Node();
 newNode->data = data;
 newNode->next = nullptr;
 return newNode;
}
void insertAtPosition(Node*& head, int data, int position) {
 Node* newNode = createNode(data);
 if (position < 0) {
 std::cerr << "Error: Position must be non-negative." << std::endl;
 delete newNode;
 return;
 }
 if (position == 0) {
 newNode->next = head;
 head = newNode;
 return;
 }
 Node* current = head;
 for (int i = 0; i < position - 1; ++i) {
 if (current == nullptr) {
 std::cerr << "Error: Position out of bounds." << std::endl;
 delete newNode;
 return;
 }
 current = current->next;
 }
 newNode->next = current->next;
 current->next = newNode;
}
void printList(Node* head) {
 Node* current = head;
 std::cout << "Linked list: ";
 while (current != nullptr) {
 std::cout << current->data << " ";
 current = current->next;
 }
 std::cout << std::endl;
}
void deleteList(Node*& head) {
 Node* current = head;
 while (current != nullptr) {
 Node* nextNode = current->next;
 delete current;
 current = nextNode;
 }
 head = nullptr;
}
int main() {
 Node* head = nullptr;
 insertAtPosition(head, 1, 0);
 insertAtPosition(head, 2, 1);
 insertAtPosition(head, 3, 2);
 std::cout << "Before insertion: ";
 printList(head);
 insertAtPosition(head, 99, 1);
 std::cout << "After insertion: ";
 printList(head);
 deleteList(head);
 return 0;
}
