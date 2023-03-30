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

        std::vector<double> v(arr1);
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


    }

    int main() {
        cout << "\n\n Task 2" << endl;
        vector<double> arr1 = { 5, 2, 3, 2, 0 };
        vector<double> arr2 = { 5, -1, 22, -1, 11, 1 };

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

        return 0;
    }
}

void task2()
{
    task2_arrays::main();
}