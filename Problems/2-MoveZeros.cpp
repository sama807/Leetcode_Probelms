#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(std::vector<int>& nums) {

    int j = 0;  // Position to place the next non-zero element
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {

            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {

    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }

    return 0;
}
