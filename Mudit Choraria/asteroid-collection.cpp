class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(auto i: asteroids) {
            if(i > 0) {
                s.push_back(i);
            } else {
                // destroy the positive ones
                while(!s.empty() && s.back() > 0 && s.back() < -i) {
                    s.pop_back();
                }
                // make sure that we can push
                if(s.empty() || s.back() < 0) {
                    s.push_back(i);
                } else if(s.back() == -i) {
                    // both explode
                    s.pop_back();
                }
            }
        }
        return s;
    }
};