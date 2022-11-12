/**
 * Problem Link - https://leetcode.com/problems/can-place-flowers
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0; i < flowerbed.size(); i++) {
        if(flowerbed[i] == 1) continue;
        if(n == 0) break;
          bool forward = false;
          if(i + 1 < flowerbed.size() && flowerbed[i+1] == 0) {
              forward = true;
          } else if (i + 1 >= flowerbed.size()) {
              forward = true;
          }
          bool backward = false;
          if(i - 1 >= 0 && flowerbed[i-1] == 0) {
              backward = true;
          } else if (i-1 < 0) {
              backward = true;
          }

          if(forward && backward) {
              flowerbed[i] = 1;
              n--;
          }
        }
        if(n == 0) return true;

        return false;
    }
};