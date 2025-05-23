// #include <iostream>
// #include <vector>
// using namespace std;

// //BRUTE FORCE APPROACH

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     int m = nums1.size(), n = nums2.size();
//     vector<int> merged;
//     int i = 0, j = 0;

//     // Merge both arrays in sorted order using while loop
//     while (i < m && j < n) {
//         if (nums1[i] < nums2[j]) {
//             merged.push_back(nums1[i++]);
//         } else {
//             merged.push_back(nums2[j++]);
//         }
//     }

//     // Add remaining elements
//     while (i < m) {
//         merged.push_back(nums1[i++]);
//     }
//     while (j < n) {
//         merged.push_back(nums2[j++]);
//     }

//     // Find median
//     int total = merged.size();
//     if (total % 2 == 1) {
//         return merged[total / 2];
//     } else {
//         return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
//     }
// }

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1); // Ensure nums1 is the smaller
    }

    int m = nums1.size(), n = nums2.size();
    int low = 0, high = m;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            // Found correct partition
            if ((m + n) % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                return max(l1, l2);
            }
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0; // Should never reach here
}
