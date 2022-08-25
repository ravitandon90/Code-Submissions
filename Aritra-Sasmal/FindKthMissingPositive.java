import java.util.HashSet;
import java.util.Set;

public class FindKthMissingPositive {
    public static int findKthPositive(int[] arr, int k) {
        int result = 0;
        Set<Integer> set = new HashSet<>();
        for(int i: arr)
            set.add(i);
        int En = arr[arr.length-1];
        for(int i=1, j=0; i<=En+k && j!=k; i++){
            if(!set.contains(i)) {
                result = i;
                j++;
            }
        }
        return result;
    }
}
