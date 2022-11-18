class Solution {
    public int getImportance(List<Employee> employees, int id) {
        HashMap<Integer, Employee> map = new HashMap<>();
        for(Employee e : employees){
            map.put(e.id, e);
        }
        Queue<Employee> q = new ArrayDeque<>();
        q.offer(map.get(id));
        int total = 0;
        while(!q.isEmpty()){
            Employee e = q.poll();
            total += e.importance;
            for(int val : e.subordinates){
                q.offer(map.get(val));
            }
        }
        return total;
    }
}
