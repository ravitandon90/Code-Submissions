class Solution {
public:
    int maximumSwap(int num) {
        string number=to_string(num);
        int i, xi=0, yi=0, maxIndex=number.size()-1;
        for(i = number.size()-1; i >= 0; i--){
            if(number[i] > number[maxIndex]) maxIndex=i;
            else if(number[i]<number[maxIndex]){
                xi=i;
                yi=maxIndex;
            }
        }
        swap(number[xi], number[yi]);
        return stoi(number);
    }
};