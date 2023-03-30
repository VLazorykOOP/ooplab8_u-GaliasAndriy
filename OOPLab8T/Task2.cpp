#include <iostream>
#include <vector>
#include <algorithm>

namespace task2_arrays {
    using namespace std;

    template <typename T>
    void unionArrays(vector<T>& arr1, vector<T>& arr2) {
        if (arr1.empty() && arr2.empty()) {
            return;
        }
                                                                                                                        
        vector<double> v(arr1);
        v.insert(v.end(), arr2.begin(), arr2.end());
        auto end = v.end();
        for (auto it = v.begin(); it != end; ++it) {
            end = std::remove(it + 1, end, *it);
        }
        v.erase(end, v.end());

        for (const auto& elem : v) {
            cout << elem << " ";
        }
    }

    template<>
    void unionArrays<char*>(vector<char*>& arr1, vector<char*>& arr2) {
        if (arr1.empty() && arr2.empty()) {
            return;
        }
        vector<const char*> merged(arr1.size() + arr2.size());
        auto it = set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), merged.begin());
        merged.resize(it - merged.begin());
        for (const auto& elem : merged) {
            cout << elem << " ";
        }
    }

    int main() {
        cout << "\n\n Task 2" << endl;
        int n1, n2;

        do {
            cout << " Enter size for of first array (1 <= n <= 20): ";
            cin >> n1;
            if (cin.fail() || n1 < 0 || n1 > 20) {
                cin.clear();
                cout << " Invalid input." << endl;
            }
        } while (cin.fail() || n1 < 0 || n1 > 20);
        vector<double> arr1(n1);  // Fill arr1
        for (int i = 0; i < n1; i++) {
            cout << " Enter [" << i << "] element: ";
            cin >> arr1[i];
        }

        do {
            cout << " Enter size for of first array (1 <= n <= 20): ";
            cin >> n2;
            if (cin.fail() || n2 < 0 || n2 > 20) {
                cin.clear();
                cout << " Invalid input." << endl;
            }
        } while (cin.fail() || n2 < 0 || n2 > 20);
        vector<double> arr2(n2);  // Fill arr
        for (int i = 0; i < n2; i++) {
            cout << " Enter [" << i << "] element: ";
            cin >> arr2[i];
        }

        cout << "\n Array 1: " << endl;
        for (const auto& elem : arr1) {
            cout << elem << " ";
        }   
        cout << "\n Array 2: " << endl;
        for (const auto& elem : arr2) {
            cout << elem << " ";
        }
        cout << "\n Union of two arrays: " << endl;
        unionArrays(arr1, arr2);

        vector<const char*> a = { "hello", "world", "foo", "bar" };
        vector<const char*> b = { "world", "baz", "qux" };

        unionArrays(a, b);
        return 0;
    }
}

void task2()
{
    task2_arrays::main();
}