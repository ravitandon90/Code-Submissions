class Solution {
    public int[] frequencySort(int[] nums) {
        // element, frequency
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int num: nums){
            map.put(num, map.getOrDefault(num, 0)+1);
        }
        
        // list of element and frequency
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        
        for(int key: map.keySet()){
            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(key);
            temp.add(map.get(key));
            list.add(temp);
        }
        
        // sorting the array according to frequency
        Collections.sort(list, (x, y) -> (x.get(1) == y.get(1) && x.get(0) < y.get(0)) ? 1 : ((x.get(1) > y.get(1)) ? 1 : -1));
        
        // replacing the array
        int idx = 0;
        for(ArrayList<Integer> pair: list){
            int element = pair.get(0);
            int freq = pair.get(1);
            
            while(freq>0){
                nums[idx++] = element;
                freq--;
            }
        }
        
        // returning the array
        return nums;
    }
}
