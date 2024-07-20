/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.*/


#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {

    int nonZeroPointer = 0;

    for (int current = 0; current < nums.size(); ++current) {
        if (nums[current] != 0) {
            swap(nums[current], nums[nonZeroPointer]);
            ++nonZeroPointer;
        }
    } 
       
    
}


int main(){

    vector<int> v = {1,2,0,3,0};
    moveZeroes(v);

     for (int num : v) {
        cout << num << " ";
    }
    return 0;
}
