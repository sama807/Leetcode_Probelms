#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size(); // If <=2 elements, return as is

    int k = 2; // Start writing from index 2 since the first two are always valid

    for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[k - 2]) { // Ensure at most 2 occurrences
            nums[k++] = nums[i]; // Write valid element
        }
    }

    return k; // Return number of unique elements allowed (at most twice each)
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 5}; 

    int k = removeDuplicates(nums);

    cout << "Number of valid elements: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
