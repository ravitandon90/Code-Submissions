class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n=citations.length;
        int ans=-1;
        int l=0;
        int h=citations.length-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(citations[mid]==n-mid) return citations[mid];
            else if(citations[mid]<n-mid) l=mid+1; 
            else h=mid-1; 
        }
        return n-l;
    }
}
