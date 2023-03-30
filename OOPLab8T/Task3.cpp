#include <iostream>
#include <vector>
#include <algorithm>

namespace task3_singly_linked_list {
    using namespace std;

    template <typename T>
    class LinkedList {
    private:
        struct Node {
            T data;
            Node* next;
            
            // Default constructor without parameters
            Node(int value = 0) : data(value), next(nullptr) {}
            // Common constructor with parameters
            Node(int value, Node *tmp) : data(value), next(tmp) {}
        };
        Node* head;
    public:
        LinkedList() : head(nullptr) {}

        /*~LinkedList() {
            Node* tmp;
            while (head) {
                tmp = head->next;
                delete head;
                head = tmp;
            }
        }*/

        void insert(int value) {
            Node* add = new Node(value);
            if (head == nullptr) {
                head = add;
            }
            else {
                add->next = head;
                head = add;
            }
        }
        void print() {
            Node* tmp = head;
            while (tmp != nullptr) {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << "\n ";
        }
    };
  
    int main() {
        cout << "\n\n Task 3" << endl;
        LinkedList<double> list;
        list.insert(5.5);
        list.insert(1);
        list.insert(0);
        list.insert(-5);
        cout << "\n Singly linked list:\n  ";
        list.print(); 
        
        return 0;
    }
}

void task3()
{
    task3_singly_linked_list::main();
}