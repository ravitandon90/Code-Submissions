class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        // 2 points always form a straight line
        if(size(coordinates) == 2) {
            return true;
        }
        int x1 = coordinates[0][0], x2 = coordinates[1][0];
        int y1 = coordinates[0][1], y2 = coordinates[1][1];
        int dx = x2 - x1, dy = y2 - y1;
        for (int i = 2; i < size(coordinates); i++)
        {
            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];
            // we compare the slopes of every point wrt first point
            // if we find them unequal, we return false immediately
            // slope = (y2 - y1) / (x2 - x1) but the denominator can be zero
            // so we compare (y3 - y1) * (x2 - x1) and (y2 - y1) * (x3 - x1)
            if (dy * (x3 - x1) != dx * (y3 - y1)) {
                return false;
            }
        }
        return true;
    }
};