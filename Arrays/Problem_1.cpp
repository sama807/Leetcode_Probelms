/*Given an integer array nums return an array answer such that answer[i] is equal to the product of all elements of nums except num[i]
(where index match)*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>&nums )
{
    int n = nums.size();

    //Intializing all elements with 1 and of size equal to the num
    vector<int>answer( n, 1);
    int index = 0;
    for(int i=0;  i<n;  i++ ){

        int product = 1;
        for(int j=0; j<n ; j++){
            //Check if index match or not
            if (index!=j){

                product *= nums[j];

            }
        }
        answer[index] = product;
        index++;

    }
    return answer;
}

int main(){

    vector<int> nums = {2, 3, 4, 5};
    vector<int> result = productExceptSelf(nums);
    
    // Print the result
    for (int i : result) {
        std::cout << i << " ";
    }
    
    return 0;

}