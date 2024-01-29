#include <iostream>
#include <unordered_set>

using namespace std;

bool isVowel(char c) {
    static unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    return vowels.find(c) != vowels.end();
}

string reverseVowels(string s) {
    int i = 0, j = s.length() - 1;

    while (i < j) {
        while (i < j && !isVowel(s[i]))
            i++;
        while (i < j && !isVowel(s[j]))
            j--;

        if (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    return s;
}

int main() {
    string input = "Hello World";
    string result = reverseVowels(input);

    cout << "Original string: " << input << endl;
    cout << "String with reversed vowels: " << result << endl;

    return 0;
}
