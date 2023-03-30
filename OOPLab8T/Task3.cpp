#include <iostream>
#include <vector>
#include <algorithm>

namespace task3_singly_linked_list {
    using namespace std;

    template <typename T>
    class LinkedList {
    private:
        struct Node {
            T Inf;
            Node* next;
            
            // Default constructor without parameters
            Node(int value = 0) : Inf(value), next(nullptr) {}
            // Common constructor with parameters
            Node(int value, Node *tmp) : Inf(value), next(tmp) {}
        };
        Node* head;
    public:
        LinkedList() : head(nullptr) {}

        ~LinkedList() {
            Node* tmp;
            while (head) {
                tmp = head->next;
                delete head;
                head = tmp;
            }
            cout << "\n Destructor " << endl;
        }

        void insert(T value) {
            Node* add = new Node(value);
            if (head == nullptr) {
                head = add;
            }
            else {
                add->next = head;
                head = add;
            }
        }

        void remove(T value) {
            Node* tmp = head;
            if (tmp != nullptr && tmp->Inf == value) {
                head = tmp->next;
                delete tmp;
                return;
            }
            else {
                Node* Cnt = head;
                while (tmp != nullptr && tmp->Inf != value) {
                    Cnt = tmp;
                    tmp = tmp->next;
                }
                if (!tmp) {
                    cout << " Value not found" << endl;
                    return;
                }
                Cnt->next = tmp->next;
                delete tmp;
            }
        }

        T sum() {
            T result = 0;
            Node* tmp = head;
            while (tmp != nullptr) {
                result += tmp->Inf;
                tmp = tmp->next;
            }
            return result;
        }

        double average() {
            if (head == nullptr) {
                return 0.0;
            }
            int count = 0;
            double sum = 0;
            Node* cnt = head;
            while (cnt != nullptr) {
                count++;
                sum += cnt->Inf;
                cnt = cnt->next;
            }
            return sum / count;
        }

        void print() {
            Node* tmp = head;
            while (tmp != nullptr) {
                cout << tmp->Inf << " ";
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
        list.remove(0);
        cout << "\n Remove first (0) from list:\n  ";
        list.print();
        cout << "\n Sum of the list = " << list.sum() << endl;
        cout << "\n Average = " << list.average() << endl;
        cout << endl;
        
        return 0;
    }
}

void task3()
{
    task3_singly_linked_list::main();
}