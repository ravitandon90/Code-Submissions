/**
 * Problem Link - https://leetcode.com/problems/maximum-score-from-removing-stones
 */

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue <int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        int score = 0;

        while(pq.size() > 1) {
            int one = pq.top();
            pq.pop();
            int two = pq.top();
            pq.pop();

            one--;
            two--;
            score++;

            if(one > 0) pq.push(one);
            if(two > 0) pq.push(two);
        }

        return score;
    }
};
