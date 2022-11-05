class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flowerbedSize=flowerbed.size();
        if(n > (flowerbedSize+1)/2){
            return false;
        }
        int start=-1;
        for(int i=0;i<flowerbedSize;i++){
            if(flowerbed[i]==1){
                if(start==-1){
                    n-=(i)/2;
                }
                else if(i-start > 2){
                    n-=(i-start-2)/2;
                }
                start=i;
            }
        }
        if(start==-1){
            return n<=(flowerbedSize+1)/2;
        }
        n-=(flowerbedSize-start-1)/2;
        return (n<=0);
    }
};
