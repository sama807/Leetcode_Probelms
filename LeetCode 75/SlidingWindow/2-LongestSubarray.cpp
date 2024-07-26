#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = 0; // Two pointers for the window
    int maxLen = 0; // Maximum length of subarray with only 1's
    int countZeros = 0; // Count of zeros in the current window

    while (right < n) {
        if (nums[right] == 0) {
            countZeros++;
        }

            // If number of zeros in the current window exceeds 1, move left pointer
        while (countZeros > 1) {
            if (nums[left] == 0) {
                countZeros--;
            }
            left++;
        }

            // Calculate the maximum length of subarray with only 1's
        maxLen = max(maxLen, right - left);

        right++;
        }

        // If all elements are 1's, we should return n-1 since we can delete any one 1
    if (maxLen == n) {
        return n - 1;
     }

    return maxLen;
}


int main() {


    // Example usage:
    vector<int> nums1 = {1, 1, 0, 1};
    cout << "Longest subarray length after deletion: " << longestSubarray(nums1) << endl;

    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << "Longest subarray length after deletion: " << longestSubarray(nums2) << endl;

    vector<int> nums3 = {1, 1, 1};
    cout << "Longest subarray length after deletion: " << longestSubarray(nums3) << endl;

    vector<int> nums4 = {0, 0, 0};
    cout << "Longest subarray length after deletion: " << longestSubarray(nums4) << endl;

    return 0;
}
