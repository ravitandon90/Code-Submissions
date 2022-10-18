// MERGE SORT SOLUTION
class Solution {
public:
    vector<vector<int>> getSkyline(const vector<vector<int>>& buildings) {
        int n = buildings.size();
        if(n == 0) {
            return {};
        }
        if(n == 1) {
            return {{buildings[0][0], buildings[0][2]}, {buildings[0][1], 0}};
        }
        const vector<vector<int>> left = getSkyline({buildings.begin(), buildings.begin() + n / 2});
        const vector<vector<int>> right = getSkyline({buildings.begin() + n / 2, buildings.end()});
        return merge(left, right);
    }
private:
    vector<vector<int>> merge(const vector<vector<int>>& left, const vector<vector<int>>& right) {
        vector<vector<int>> ans;
        int i = 0, j = 0, leftY = 0, rightY = 0;
        while(i < left.size() && j < right.size()) {
            if(left[i][0] < right[j][0]) {
                leftY = left[i][1];
                addPoint(ans, left[i][0], max(left[i++][1], rightY));
            } else {
                rightY = right[j][1];
                addPoint(ans, right[j][0], max(right[j++][1], leftY));
            }
        }
        while (i < left.size()) {
            addPoint(ans, left[i][0], left[i++][1]);
        }
        while (j < right.size()) {
            addPoint(ans, right[j][0], right[j++][1]);
        }
        return ans;
    }
    
    void addPoint(vector<vector<int>>& ans, int x, int y) {
        if(!ans.empty()) {
            if(ans.back()[0] == x) {
                ans.back()[1] = y;
                return;
            }
            if(ans.back()[1] == y) {
                return;
            }
        }
        ans.push_back({x, y});
    }
};

/*
// MULTI-SET SOLUTION
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<vector<int>> events;
        
        for(auto b: buildings) {
            events.push_back({b[0], b[2]});
            events.push_back({b[1], -b[2]});
        }
        
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        
        for(auto event: events) {
            int x = event[0];
            int h = abs(event[1]);
            int isEntering = event[1] > 0;
            if(isEntering) {
                if(h > maxHeight()) {
                    ans.push_back({x, h});
                }
                set.insert(h);
            } else {
                set.erase(set.equal_range(h).first);
                if(h > maxHeight()) {
                    ans.push_back({x, maxHeight()});
                }
            }
        }
        return ans;
    }
private:
    multiset<int> set;
    int maxHeight() {
        return set.empty() ? 0 : *rbegin(set);
    }
};
*/