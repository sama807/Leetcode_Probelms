#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {

    int k = 1; // Pointer for placing valid elements

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) {

            nums[k++] = nums[i]; 
        }
    }

    return k; // Return the count of elements not equal to val
}

int main() {
    vector<int> num = {1, 1, 2, 2, 3}; 

    int k = removeDuplicates(num);

    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
