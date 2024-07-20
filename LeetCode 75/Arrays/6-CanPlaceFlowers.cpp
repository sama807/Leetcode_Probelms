#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {

    int size = flowerbed.size();
    int count = 0;
    for(int i = 0; i < size; i++) {
        if(flowerbed[i] == 0) {
            bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
            bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);
            if(emptyLeft && emptyRight) {
                flowerbed[i] = 1;
                count++;
                if(count >= n) {
                    return true;
                }
            }
        }
    }
    return count >= n;
}


int main() {

    vector<int> v = {1,0,0,0,1};
    cout<<canPlaceFlowers(v, 1);

    return 0;
}
