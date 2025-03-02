#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;
    
    // Find a candidate for the majority element
    for (int i = 1; i < nums.size(); ++i) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    
    // The candidate here should be the majority element
    return candidate;
}

int main() {
    std::vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int majority = majorityElement(nums);
    std::cout << "Majority Element: " << majority << std::endl;
    
    return 0;
}
