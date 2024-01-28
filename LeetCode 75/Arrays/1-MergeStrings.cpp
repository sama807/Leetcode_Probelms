/*You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.*/


#include<iostream>
#include<vector>
using namespace std;

string mergeAlternately(string word1, string word2) {
    
    string mergedString;
    int i=0, j=0;
    
    while(i< word1.size() && j<word2.size()){
        mergedString.push_back(word1[i]);
        mergedString.push_back(word2[j]);
        i++;
        j++;
    }

    while(i<word1.size()){
        mergedString.push_back(word1[i]);
        i++;
    }

    while(j<word2.size()){
        mergedString.push_back(word2[j]);
        j++;
    }

    for(int k=0; k<mergedString.size(); k++){
        cout<<mergedString[k];
    }

    return mergedString;
}

int main(){

    string a = "abcde";
    string b= "pqr";

    mergeAlternately(a,b);
    
    return 0;
}
