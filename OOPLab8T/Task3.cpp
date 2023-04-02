#include <iostream>
#include <string>

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

        int count() {
            int count = 0;
            Node* tmp = head;
            while (tmp != nullptr) {
                count++;
                tmp = tmp->next;
            }
            return count;
        }

        double average() {
            if (head == nullptr) {
                return 0;
            } 
            else {
                return sum() / count();
            }
        }

        bool search(int value) {
            Node* tmp = head;
            while (tmp != nullptr)
            {
                if (tmp->Inf == value)
                    return true;
                tmp = tmp->next;
            }
            return false;
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
        cout << "\n Task 3" << endl;
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
        cout << " Average = " << list.average() << endl;
        cout << endl;

        cout << " Create your own list: " << endl;
        LinkedList<double> userList;
        string input;
        double value;
        
        if (userList.count() == 0) {
            cout << " Enter a number or exit typing 'e': ";
            cin.ignore();
            getline(cin, input);

            while (input != "e") {
                try {
                    value = stod(input);
                    userList.insert(value);
                }
                catch (const invalid_argument& e) {
                    cout << "Invalid input, try again." << endl;
                }
                cout << " Enter a number or exit typing 'e': ";
                getline(cin, input);
            }

            cout << "\n Created list: " << endl;
            userList.print();
            cout << "\n Options:" << endl;
            cout << " 1. Remove an element" << endl;
            cout << " 2. Search for an element" << endl;
            cout << " 3. Exit" << endl;
           
            char option;
            double item;
            do {
                cout << " Your choice: ";
                cin >> option;

                if (option == '1') {
                    cout << " Enter the item you want to remove: ";
                    cin >> item;
                    userList.remove(item);
                    cout << " After removing: " << endl;
                    userList.print();
                }
                else if (option == '2') {
                    cout << "Enter the item you want to search for: ";
                    cin >> item;
                    if (userList.search(item) == true) {
                        cout << " true " << endl;
                    }
                    else {
                        cout << " false" << endl;
                    }
                }
                else if (option == '3') {
                    cout << "\n Sum of the list = " << userList.sum() << endl;
                    cout << " Average = " << userList.average() << endl;
                    break;
                }
                else {
                    cout << "\n Invalid option";
                }
            } while (option != '3');
        }
        return 0;
    }
}

void task3() 
{
    task3_singly_linked_list::main();
}

