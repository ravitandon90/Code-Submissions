// https://leetcode.com/problems/interval-list-intersections/

class interval_list_intersections {
    public int[][] intervalIntersection(int[][] l1, int[][] l2) {
        ArrayList<int[]> ans = new ArrayList<>();
        int n = l1.length, m = l2.length, i = 0, j = 0;
        if (n == 0 || m == 0)
            return ans.toArray(new int[ans.size()][]);
        while (i < n && j < m) {
            int l = Math.max(l1[i][0], l2[j][0]);
            int r = Math.min(l1[i][1], l2[j][1]);
            if (l <= r)
                ans.add(new int[] { l, r });
            if (l1[i][1] < l2[j][1])
                i++;
            else
                j++;
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
