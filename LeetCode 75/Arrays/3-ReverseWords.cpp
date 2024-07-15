#include <iostream>
#include <string>
#include <algorithm> // for std::reverse

std::string reverseWords(const std::string& s) {
    std::string reversedStr;
    int n = s.size();

    // Traverse the string from end to start
    int i = n - 1;
    while (i > 0) {
        // Skip leading spaces
        while (i > 0 && s[i] == ' ') {
            i--;
        }

        int j = i;
        // Find the end of the current word
        while (j > 0 && s[j] != ' ') {
            j--;
        }

        // Extract the current word
        std::string newStr = s.substr(j + 1, i - j);

        // Append the current word to the result string
        reversedStr += newStr;

        // Add a space if there are more words
        if (j > 0) {
            reversedStr += ' ';
        }

        // Move to the next word
        i = j - 1;
    }

    return reversedStr;
}

int main() {
    std::string str = " sky is blue ";
    std::cout << "Original string: " << str << std::endl;
    std::cout << "Reversed words: " << reverseWords(str) << std::endl;

    return 0;
}
