#include <iostream>
#include <vector>
#include <algorithm>

namespace task1_remove_min {
    using namespace std;

    template <typename T>
    void remove_min(vector<T>& arr) {
        if (arr.empty()) {
            return;
        }

        const T minValue = *min_element(arr.begin(), arr.end()); // vector methods for returning first and last indexes
        arr.erase(remove(arr.begin(), arr.end(), minValue), arr.end());
    }

    template <>
    void remove_min<char*>(vector<char*>& charVec) {
        if (charVec.empty()) {
            return;
        }

        const auto theSmallestWord = *min_element(charVec.begin(), charVec.end(),
            [](const char* firstElem, const char* lastElem) {
                return strlen(firstElem) < strlen(lastElem);
            });

        const int minLength = strlen(theSmallestWord);
        charVec.erase(remove_if(charVec.begin(), charVec.end(), 
            [minLength](const char* word) {
                return strlen(word) == minLength;
            }), charVec.end());
    }

    int tmain() {
        cout << "\n\n Task 1" << endl;
     
        int n;
        do {
            cout << " Enter size of an array (1 <= n <= 20): ";
            cin >> n;

            if (cin.fail() || n < 0 || n > 20) {
                cin.clear();
                cout << " Invalid input." << endl;
            }
        } while (cin.fail() || n < 0 || n > 20);

        vector<double> arr(n);  // Fill arr
        for (int i = 0; i < n; i++) {
            cout << " Enter [" << i << "] element: ";
            cin >> arr[i];
        }

        cout << "\n Before removing min elems: " << endl;   // Output arr before removing elements
        for (const auto& elem : arr) {
            cout << elem << " ";
        }

        remove_min(arr);

        cout << "\n After removing min elems: " << endl;    // After removing
        for (const auto& elem : arr) {
            cout << elem << " ";
        }

        cout << " \n\n char template: ";
        do {
            cout << " Enter size of an array (1 <= n <= 20): ";
            cin >> n;

            if (cin.fail() || n < 0 || n > 20) {
                cin.clear();
                cout << " Invalid input." << endl;
            }
        } while (cin.fail() || n < 0 || n > 20);

        cin.ignore();

        vector<char*> words;
        for (int i = 0; i < n; i++) {
            char* word = new char[50];
            cout << " Enter [" << i << "] word: ";
            cin.getline(word, 50);
            words.push_back(word);
        }

        cout << "\n Before removing the smallest word: " << std::endl;
        for (auto word : words) {
            cout << word << " ";
        }

        remove_min(words);
        cout << "\n After removing the smallest word: " << std::endl;
        for (auto word : words) {
            cout << word << " ";
        }
        cout << "\n";

        for (auto word : words) {   // free words array
            delete[] word;
        }

        return 0;
    }
}

void task1()
{
    task1_remove_min::tmain();
}