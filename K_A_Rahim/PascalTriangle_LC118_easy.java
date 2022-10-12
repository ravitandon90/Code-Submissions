class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new ArrayList<>();
        ArrayList<Integer> topRowList = new ArrayList<>();
        topRowList.add(1);
        list.add(topRowList);
        for(int i=1;i<numRows;i++)
        {
            ArrayList<Integer> rowList = new ArrayList<>();
            rowList.add(1);
             int offset = 0;
            for(int j=1;j<i;j++)
            {  
              int num1 = list.get(i-1).get(offset);
              int num2 = list.get(i-1).get(offset+1);
              rowList.add(num1+num2);
              offset++;
            }
            rowList.add(1);
          list.add(rowList);
        }
        return list;
    }
}