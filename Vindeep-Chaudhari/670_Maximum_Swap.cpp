/**
 * Problem Link - https://leetcode.com/problems/maximum-swap/
*/

class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);

        int maxIndex = -1, maxNum = INT_MIN;
        int leftIndex = -1, rightIndex = -1;

        for(int i = number.length()-1; i >= 0; i --) {
            int n = stoi(number.substr(i, 1));

            if(maxNum < n) {
                maxNum = n;
                maxIndex = i;
                continue;
            }

            if(n < maxNum) {
                leftIndex = i;
                rightIndex = maxIndex;
            }
        }

        if(leftIndex == -1) return num;

        char temp = number[leftIndex];
        number[leftIndex] = number[rightIndex];
        number[rightIndex] = temp;

        return stoi(number);
    }
};