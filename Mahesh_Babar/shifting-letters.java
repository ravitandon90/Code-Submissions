// https://leetcode.com/problems/shifting-letters/

class shifting_letters {
    public String shiftingLetters(String s, int[] shifts) {
        int l = shifts.length;

        // Since letters loop around, the shift can only have a value from 0 to 25.
        // We can use the modulus operator to keep it within this range.

        // Set the shift of the last index.
        shifts[l - 1] = shifts[l - 1] % 26;

        // The cumulative shift for an index i is the sum of shifts from i to l-1.
        // Since the shifts from i+1 to l-1 are already accumulated in shifts[i+1],
        // we just add this value to the current shift.
        for (int i = l - 2; i >= 0; i--)
            shifts[i] = (shifts[i + 1] + shifts[i]) % 26;

        char c[] = s.toCharArray();

        // Perform the shifts.
        for (int i = 0; i < l; i++)
            c[i] = (char) (((c[i] - 'a') + shifts[i]) % 26 + 'a');

        return new String(c);
    }
}
