#include <iostream>
using namespace std;
#include <vector>

vector<int> productExceptSelf(const vector<int>& nums) {
   
   int n = nums.size();
   vector<int>answer(n, 1);

   int leftProduct= 1, rightProduct= 1 ;
   for(int i=0 ; i<n; i++){
    answer[i] = leftProduct ;
    //Compute leftProduct 
      leftProduct*= nums[i];
   }
   for(int i=n-1; i>=0; i--){

    //Compute rightProduct and multiply it with the answer
    answer[i]*= rightProduct ;
    rightProduct*= nums[i];
   }
   return answer ;





}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = productExceptSelf(nums);

    std::cout << "Output: ";
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
