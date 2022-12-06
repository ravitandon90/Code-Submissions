class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> loss;
        for(auto match: matches) {
            if(!loss.count(match[0])) {
                loss[match[0]] = 0;
            }
            loss[match[1]]++;
        }

        vector<vector<int>> ans(2);
        for(const auto& [player, lossCount]: loss) {
            if(lossCount < 2) {
                ans[lossCount].push_back(player);
            }
        }

        return ans;
    }
};