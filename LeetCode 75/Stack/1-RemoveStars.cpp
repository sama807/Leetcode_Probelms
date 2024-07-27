#include <iostream>
#include <stack>
#include <string>
#include<algorithm>
using namespace std;

string removeStars(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '*') {
            if (!st.empty()) {
                st.pop(); // Remove the closest non-star character
            }
        } else {
            st.push(ch); // Push non-star characters onto the stack
        }
    }

    // Construct the result string from the stack
    string result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    // The characters in the stack will be in reverse order, so reverse the string
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string s = "leet**cod*e";
    string result = removeStars(s);
    cout << "Result: " << result << endl; // Output should be "lecoe"

    return 0;
}
