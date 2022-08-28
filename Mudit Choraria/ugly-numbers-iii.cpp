class Solution {
 public:
  int nthUglyNumber(int n, long a, long b, long c) {
      long ab = a * b / __gcd(a, b);
      long ac = a * c / __gcd(a, c);
      long bc = b * c / __gcd(b, c);
      long abc = a * bc / __gcd(a, bc);
      int l = 1;
      int r = 2 * 1e9;
      int ans = r;
      
      while(l <= r) {
          int mid = l + (r - l) / 2;
          if(mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc >= n) {
              ans = mid;
              r = mid - 1;
          } else {
              l = mid + 1;
          }
      }
      return ans;
  }
};
