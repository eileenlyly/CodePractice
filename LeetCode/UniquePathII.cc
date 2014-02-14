class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacle) {
        int n = obstacle.size();
        if (!n) return 0;
        int m = obstacle[0].size();
        vector<int> line(m,0);
        vector<vector<int>> path(n,line);
        if(obstacle[0][0] == 1) return 0;
        path[0][0] = 1;
        for(int i = 1; i < m; i++){
            if(obstacle[0][i] == 1) continue;
            else path[0][i] = path[0][i-1];
        }
        for(int i = 1; i < n; i++){
            if(obstacle[i][0] == 1) continue;
            else path[i][0] = path[i-1][0];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(obstacle[i][j] == 1) continue;
                else path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        return path[n-1][m-1];

    }
};