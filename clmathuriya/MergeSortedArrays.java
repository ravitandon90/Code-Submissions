class Solution {
    //88. Merge Sorted Array 
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=0;
        int j=0;
        while(i<m+j && j<n){
            if(nums1[i]>nums2[j]){
                int temp=m+n-1;
                while(temp>i){
                    nums1[temp]=nums1[temp-1];
                    temp--;
                }
                nums1[i]=nums2[j];
                j++;
            }
            i++;
        }
        while(j<n){
            nums1[i]=nums2[j];
            i++;
            j++;
        }
        
    }
}
