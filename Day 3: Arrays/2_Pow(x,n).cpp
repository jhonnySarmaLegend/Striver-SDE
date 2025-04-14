/*
   Question Link --> 
*/

//METHOD 1 (LOOP)
double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}

//METHOD 2 (BINARY EXPONENTIAL)
/*
  2^10 (x=2,n=10)

 2^10 
 n=10 is even hence, (2 x 2 ) ^ 5  = 4^5 (= 1024 from below)
 n=5 is odd , 4^1 x (4 x 4)^2 = 4 x 16^2  (=  4 X 256 from below)
 n=2 is even , (16x16)^1 = 256^1 = 256
 n=1 is odd, 256^1 x 256^0 = 256
  
  
*/
class Solution {
public:
    double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn>0) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
    }
};
