#include <iostream>
#include <vector>
#include<string>
using namespace std;

int compress(vector<char>& chars) {
    int size = chars.size();
    if (size == 0) return 0;

    int writeIndex = 0;
    int i = 0;

    while (i < size) {
        char currentChar = chars[i];
        int count = 0;

        while (i < size && chars[i] == currentChar) {
            i++;
            count++;
        }

        chars[writeIndex++] = currentChar;

        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[writeIndex++] = c;
            }
        }
    }

    return writeIndex;
}

int main() {
    vector<char> s1 = {'a', 'a', 'b', 'b', 'b'};
    int newLength1 = compress(s1);
    cout << "Compressed length: " << newLength1 << endl;
    for (int i = 0; i < newLength1; i++) {
        cout << s1[i];
    }
    cout << endl;

    vector<char> s2 = {'a', 'b', 'c'};
    int newLength2 = compress(s2);
    cout << "Compressed length: " << newLength2 << endl;
    for (int i = 0; i < newLength2; i++) {
        cout << s2[i];
    }
    cout << endl;

    return 0;
}
