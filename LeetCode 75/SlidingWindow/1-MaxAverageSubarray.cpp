/*You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
Any answer with a calculation error less than 10-5 will be accepted.*/


#include <iostream>
#include <vector>
#include <limits>

double findMaxAverage(std::vector<int>& nums, int k) {
    // Calculate the sum of the first k elements
    double max_sum = 0;
    for (int i = 0; i < k; ++i) {
        max_sum += nums[i];
    }

    double current_sum = max_sum;
    // Use the sliding window technique
    for (int i = k; i < nums.size(); ++i) {
        current_sum += nums[i] - nums[i - k];
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum / k;
}

int main() {
    std::vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = findMaxAverage(nums, k);
    std::cout << "Maximum average value of subarray of length " << k << " is: " << result << std::endl;

    return 0;
}

