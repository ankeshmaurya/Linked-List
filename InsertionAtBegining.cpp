#include <iostream>
struct Node {
 int data;
 Node* next;
 Node(int data) : data(data), next(nullptr) {}
};
class LinkedList {
private:
 Node* head;
public:
 LinkedList() : head(nullptr) {}
void insertAtBeginning(int newData)
{
 Node* newNode = new Node(newData);
 newNode->next = head;
 head = newNode;
}
 void printList() const
{
 Node* temp = head;
 while (temp != nullptr)
 {
 std::cout << temp->data << " ";
 temp = temp->next;
 }
 std::cout << std::endl;
 }
};
int main() {
 LinkedList list;
 list.insertAtBeginning(10);
 list.insertAtBeginning(20);
 list.insertAtBeginning(30);
 std::cout << "Linked list after insertions: ";
 list.printList();
 return 0;

}
