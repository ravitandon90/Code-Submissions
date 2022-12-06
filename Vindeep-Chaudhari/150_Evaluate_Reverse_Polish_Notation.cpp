/**
 * Problem Link - https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <string> st;

        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
                long long num1 = stoll(st.top());
                st.pop();
                long long num2 = stoll(st.top());
                st.pop();
                long long ans;
                if(tokens[i] == "+") {
                    ans = num1+num2;
                } else if (tokens[i] == "-") {
                    ans = num2-num1;
                } else if (tokens[i] == "/") {
                    ans = num2/num1;
                } else if (tokens[i] == "*") {
                    ans = num2*num1;
                }
                st.push(to_string(ans));
            } else {
                st.push(tokens[i]);
            }
        }

        return stoll(st.top());
    }
};
