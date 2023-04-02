#include <iostream>
#include <string>

namespace task4_singly_linear_list {
    using namespace std;

    template <typename T>
    class LinearList {
    private:
        struct Node {
            T inf;
            Node* next;
            // Default constructor without parameters
            Node(T value = T()) : inf(value), next(nullptr) {}
            // Common constructor with parameters
            Node(T value, Node* tmp) : inf(value), next(tmp) {}

            // getters and setters
            T get_inf() const {
                return inf;
            }
            void set_inf(T value) {
                inf = value;
            }
            Node* get_next() const {
                return next;
            }
            void set_next(Node* ptr) {
                next = ptr;
            }
        };
        Node* head;
    public:
        LinearList() : head(nullptr) {}
        ~LinearList() {
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
                Node* cnt = head;
                while (cnt->next != nullptr) {
                    cnt = cnt->next;
                }
                cnt->next = add;
            }
        }

        class Iterator {
        private:
            Node* cnt;
        public:
            Iterator(Node* node) : cnt(node) {}
            Iterator& operator++() {
                cnt = cnt->next;
                return *this;
            }
            T& operator*() const {
                return cnt->inf;
            }
            bool operator!=(const Iterator& other) const {
                return cnt != other.cnt;
            }
            friend class LinearList<T>;
        };

        // begin() and end() methods implemented inside LinearList class
        Iterator begin() {
            return Iterator(head);
        }
        Iterator end() {
            return Iterator(nullptr);
        }
    };

    void main() {
        LinearList<double> list;
        list.insert(55);
        list.insert(-5);
        list.insert(28);
        list.insert(55);
        list.insert(-55);
        list.insert(-55);

        for (LinearList<double>::Iterator iter = list.begin(); iter != list.end(); ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }
}

void task4()
{
    task4_singly_linear_list::main();
}