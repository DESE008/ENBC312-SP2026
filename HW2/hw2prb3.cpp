#include <iostream>
#include <string>
using namespace std;

char modeLetter(string word) {
    int mode[256] = {0};

    for (int i = 0; i < word.length(); i++) {
        mode[word[i]]++;
    }

    int maxMode = 0;
    char letter;

    for (int i = 0; i < word.length(); i++) {
        if (mode[word[i]] > maxMode) {
            maxMode = mode[word[i]];
            letter = word[i];
        }
    }

    return letter;
}

int main() {
    string input;

    cout << "Enter a word: ";
    cin >> input;

    char letter  = modeLetter(input);

    cout << "Most frequent letter is : '" << letter << "'" << endl;

    return 0;
}


