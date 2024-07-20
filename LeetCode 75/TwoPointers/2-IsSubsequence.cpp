
/*Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
of the characters without disturbing the relative positions of the remaining characters. 
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).*/


#include<iostream>
#include<vector>
using namespace std;

bool isSubsequence(string s, string t) {
        
        int currentIndex = 0;
        int subSequenceCount = 0;

        for(int i= 0; i<t.size(); i++){

            if(s[currentIndex] == t[i]){
                currentIndex++;
                subSequenceCount++;
            }
        }
        
        return subSequenceCount == s.size();
        
}

int main(){

    string s = "ace";
    string t = "abcde";
    
    if (isSubsequence(s, t)) {
        std::cout << s << " is a subsequence of " << t << std::endl;
    } else {
        std::cout << s << " is not a subsequence of " << t << std::endl;
    }

    return 0;
}