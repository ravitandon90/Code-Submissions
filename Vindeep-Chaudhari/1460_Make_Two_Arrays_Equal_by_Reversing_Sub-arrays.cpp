/**
 * Problem Link - https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
 */

// 1. First One

class Solution {
public:
    void reverseSubArray(vector<int>& arr, int start, int end) { 
        while(start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            
            start++;
            end--;
        }
    }
    
    int getIndexInArr(vector<int>& arr, int element, int fromIndex) {
        for(int i = fromIndex; i < arr.size(); i++) { 
            if(arr[i] == element) return i;
        }
        
        return -1;
    }
    
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        for(int i = 0; i < target.size(); i++) { 
            int targetEle = target[i];
            
            int targetEleIndex = getIndexInArr(arr, targetEle, i);
            if(targetEleIndex == -1) return false;
            if(targetEleIndex == i) continue;
            if(targetEleIndex < i) return false;
            
            reverseSubArray(arr, i, targetEleIndex);
        }
        
        return true;
    }
};

// 2. Second (Optimized)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < target.size(); i++) { 
            mp[target[i]]++;
            mp[arr[i]]--;
        }
        
        for(auto ele : mp) {
            if(ele.second < 0) {
                return false;
            }
        }
        
        return true;
    }
};