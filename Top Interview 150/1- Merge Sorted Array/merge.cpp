#include<iostream>
#include<vector>
using namespace std;


// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
// representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, 
// nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are 
// set to 0 and should be ignored. nums2 has a length of n.

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    int i = m - 1;  // Pointer for nums1
    int j = n - 1;  // Pointer for nums2
    int k = m + n - 1;  // Pointer for the merged array
    
    // Merge in reverse order
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    
    // If there are remaining elements in nums2, copy them
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

        
}

int main(){
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};  // nums1 has extra space
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

}