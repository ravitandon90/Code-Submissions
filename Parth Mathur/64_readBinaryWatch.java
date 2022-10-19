class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> result = new ArrayList<>();
        
        //range 0-3 are hours and range 4-9 are minutes
        int[] arr = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};
        backtrack(arr, 0, 0, 0, num, result);
        return result;
    }

    public void backtrack(int[] arr, int position, int hours, int minutes, int limit, List<String> result) {
        //when num(limit) reaches to the zero, store hours and minutes into result list
        if (limit == 0) {
            //during recursion we might get e.g 4 + 8 = 12 hours which we must skip because max hour value could be 11
            if(hours <= 11 && minutes <= 59) {
                StringBuilder builder = new StringBuilder();
                builder.append(hours).append(":").append(minutes <= 9 ? "0" + minutes : minutes);
                result.add(builder.toString());
            }
            return;
        }

        //standard backtracking solution add new value do recursion and then remove it
        for (int i = position; i < arr.length; i++) {
            if (isHour(i)) hours += arr[i];
            else minutes += arr[i];

            backtrack(arr, i + 1, hours, minutes, limit - 1, result);

            if (isHour(i)) hours -= arr[i];
            else minutes -= arr[i];
        }
    }

    //Simple check by range: hours or minutes
    public boolean isHour(int position) {
        return position >= 0 && position <= 3;
    }
}
