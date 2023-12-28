#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();

    int k = 1; 

    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[i - 1]) {
            // Move unique elements to the front of the array
            nums[k] = nums[i];
            ++k;
        }
    }

    // Resize the vector to keep only the unique elements
    nums.resize(k);

    return k; 
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 4, 4};
    int newSize = removeDuplicates(arr);

    cout << "New Size: " << newSize << endl;

    cout << "Unique Elements: ";
    for (int i = 0; i < newSize; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
