#include <iostream>
#include <vector>
#include <algorithm> // For reverse function

void reverse(std::vector<int>& nums, int start, int end) {
    while (start < end) {
        std::swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k > n

    // Step 1: Reverse the entire array
    reverse(nums, 0, n - 1);
    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);
    // Step 3: Reverse the remaining elements
    reverse(nums, k, n - 1);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3; // Rotate by 3 steps
    rotate(nums, k);

    std::cout << "Rotated array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
