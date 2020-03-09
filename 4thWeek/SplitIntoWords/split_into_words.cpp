//
// Created by Акбар on 10.03.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

vector<string> SplitIntoWords(const string& s);

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}