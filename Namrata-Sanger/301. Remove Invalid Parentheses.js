/*
Day 32
301. Remove Invalid Parentheses
Link: https://leetcode.com/problems/remove-invalid-parentheses/submissions/
Level : Hard
*/

var removeInvalidParentheses = function(s) {
  const ans = [];

  const isValid = s => {
    let cnt = 0;
    for (const ch of s) {
      if (ch == "(") cnt += 1;
      if (ch == ")") cnt -= 1;
      if (cnt < 0) return false;
    }
    return cnt == 0;
  };

  const dfs = (s, start, l, r) => {
    if (!l && !r) {
      if (isValid(s)) ans.push(s);
      return;
    }
    for (let i = start; i != s.length; i += 1) {
      if (i != start && s[i] == s[i - 1]) continue;
      if (r) {
        if (s[i] != ")") continue;
        dfs(s.substr(0, i) + s.substr(i + 1), i, l, r - 1);
      } else {
        if (s[i] != "(") continue;
        dfs(s.substr(0, i) + s.substr(i + 1), i, l - 1, r);
      }
    }
  };

  let l = 0, r = 0;
  for (const ch of s) {
    l += ch == "(";
    if (l == 0) {
      r += ch == ")";
    } else {
      l -= ch == ")";
    }
  }
  dfs(s, 0, l, r);
  return ans;
}
