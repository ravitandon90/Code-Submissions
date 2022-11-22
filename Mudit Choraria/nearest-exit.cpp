class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, int>> q, tmp;
        tmp.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        vector<int> idx = {-1, 0, 1, 0, -1};
        int steps = 0;
        while(!tmp.empty()) {
            swap(q, tmp);
            steps++;
            while(!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int dx = idx[i] + curr.first;
                    int dy = idx[i + 1] + curr.second;
                    if(dx < 0 || dx >= maze.size() || dy < 0 || dy >= maze[0].size()) {
                        continue;
                    }
                    if(maze[dx][dy] == '.') {
                        if(dx == 0 || dx == maze.size() - 1 || dy == 0 || dy == maze[0].size() - 1) {
                            return steps;
                        }
                        tmp.push({dx, dy});
                        maze[dx][dy] = '+';
                    }
                }
            }
        }
        return -1;
    }
};