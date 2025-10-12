#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void AddAtStart(int val) {
        Node* NewNode = new Node(val);
        NewNode->next = head;
        head = NewNode;
    }

    void DeleteAtStart() {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.AddAtStart(10);
    list.AddAtStart(20);
    list.AddAtStart(30);

    cout << "List after adding nodes at the start: ";
    list.display();

    list.DeleteAtStart();
    cout << "List after deleting a node at the start: ";
    list.display();

    list.DeleteAtStart();
    cout << "List after deleting another node at the start: ";
    list.display();

    return 0;
}
