/*Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k 
and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false..*/


#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX


bool increasingTriplet(std::vector<int>& nums) {
    int first = INT_MAX;
    int second = INT_MAX;

    for (int num : nums) {
        if (num <= first) {
            first = num; // Update first if num is smaller than or equal to first
        } else if (num <= second) {
            second = num; // Update second if num is smaller than or equal to second
        } else {
            // If we find a number greater than both first and second, we found our triplet
            return true;
        }
    }

    return false; // No increasing triplet found
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> nums2 = {5, 4, 3, 2, 1};
    std::vector<int> nums3 = {2, 1, 5, 0, 4, 6};

    std::cout << std::boolalpha; // Print boolean values as true/false
    std::cout << "For nums1, increasing triplet exists: " << increasingTriplet(nums1) << std::endl;
    std::cout << "For nums2, increasing triplet exists: " << increasingTriplet(nums2) << std::endl;
    std::cout << "For nums3, increasing triplet exists: " << increasingTriplet(nums3) << std::endl;

    return 0;
}

