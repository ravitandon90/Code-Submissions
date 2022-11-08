class Solution {
public:

    static bool myfunction(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), myfunction);
        //custom sort (in increasing order of numberOfUnitsPerBox as we have to return  maximum total number of units )
        
        //Greedily pick boxes till capacity is full
        int ans = 0;
        for (int i = 0; i < boxTypes.size(); i++ ) {
            
            int curr = min(boxTypes[i][0], truckSize); //choosing minimum between boxes from available boxes and capacity left
            
            ans += boxTypes[i][1] * curr; //adding units in ans
            
            truckSize -= curr; //reducing the capacity
            
            if (truckSize == 0) //capacity full
                break;              
        }
        
        return ans;
    }
};
