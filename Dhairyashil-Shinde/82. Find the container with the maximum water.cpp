class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int s = 0; //start
        int e = n-1; //end
        
        int area = 0;
        int maxArea = 0;
        
        while(s<e) {
            area = min(height[s], height[e]) * (e-s);
            
            if(area > maxArea)
                maxArea = area;
            
            if(min(height[s], height[e]) == height[s]) 
                s++;
            else
                e--;
        }
        return maxArea;
    }
};
