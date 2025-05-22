#include <iostream>
#include <vector>
using namespace std;

//BRUTE FORCE APPROACH

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> merged;
    int i = 0, j = 0;

    // Merge both arrays in sorted order using while loop
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i++]);
        } else {
            merged.push_back(nums2[j++]);
        }
    }

    // Add remaining elements
    while (i < m) {
        merged.push_back(nums1[i++]);
    }
    while (j < n) {
        merged.push_back(nums2[j++]);
    }

    // Find median
    int total = merged.size();
    if (total % 2 == 1) {
        return merged[total / 2];
    } else {
        return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
    }
}
