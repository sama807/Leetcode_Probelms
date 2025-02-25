#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0; // Pointer for placing valid elements

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k++] = nums[i]; // Place the non-val element at index k
        }
    }

    return k; // Return the count of elements not equal to val
}

int main() {
    vector<int> num = {3, 2, 2, 3, 4, 3, 5}; 
    int val = 3;

    int k = removeElement(num, val);

    cout << "Number of elements not equal to " << val << ": " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
