#include <iostream>
#include <vector>
#include <algorithm>

int maxOperations(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int operations = 0;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == k) {
            operations++;
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    return operations;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    int k = 5;

    int result = maxOperations(nums, k);
    std::cout << "Maximum number of operations: " << result << std::endl;

    return 0;
}
