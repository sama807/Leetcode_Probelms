#include<iostream>
#include<vector>
using namespace std;


bool isPalindrome(int x) {
        long long reversedX = 0;
        int originalX = x;

        while (x > 0) {
            int digit = x % 10;
            // Build the reversed integer
            reversedX = reversedX * 10 + digit;
            // Remove the last digit from x
            x /= 10;
        }

        // Check if the reversed integer is equal to the original integer
        return reversedX == originalX;
}
int main(){
    
    int number = 121;
    bool result = isPalindrome(number);

    std::cout << std::boolalpha;  // Print bool values as true/false
    std::cout << result << std::endl;

    return 0;
}
