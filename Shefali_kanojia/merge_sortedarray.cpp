class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
        {
            nums1[m+i]=nums2[i];
        }
        //now with the use of bubblesort inplace algo we can sort this num1 array.
        
      for(int k=1;k<=nums1.size()-1;k++  )      
      {
          for( int i=0;i<=nums1.size()-2;i++)
          {
              if(nums1[i]>nums1[i+1])
              {
                  swap(nums1[i],nums1[i+1]);
              }
          }
      }
    }
};