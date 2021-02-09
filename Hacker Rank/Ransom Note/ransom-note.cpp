#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> words;
    vector<string> magazine {"give", "me", "one", "grand", "today", "night"};

    for (auto const &word : magazine)
        words[word]++;

    cout << words["give"] << endl;
    cout << words["me"] << endl;

    return 0;
}
