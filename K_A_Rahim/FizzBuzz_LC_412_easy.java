class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> list = new ArrayList<>();
        for(int i=0;i<n;i++)
        {
            int num = i + 1;
           if(num % 3 == 0 && num % 5 == 0) 
           {
             list.add("FizzBuzz");
           }
            else if(num % 3 == 0)
            {
               list.add("Fizz"); 
            }
            else if(num % 5 == 0)
            {
               list.add("Buzz"); 
            }
            else
            {
                list.add(""+num);
            }
        }
        return list;
    }
}