class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < 9; i++){
            if(!isValidBlk(board[i])) return false;
        }
        for(int i = 0; i < 9; i++){
            vector<char> col;
            for(int j = 0; j < 9; j++){
                col.push_back(board[j][i]);
            }
            if(!isValidBlk(col)) return false;
        }
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                vector<char> blk;
                blk.insert(blk.begin(),board[i].begin()+j,board[i].begin()+j+3);
                blk.insert(blk.begin(),board[i+1].begin()+j,board[i+1].begin()+j+3);
                blk.insert(blk.begin(),board[i+2].begin()+j,board[i+2].begin()+j+3);
                if(!isValidBlk(blk)) return false;
            }
        }
        return true;
    }
    bool isValidBlk(vector<char> &blk){
        int len = blk.size();
        bool flag[len];
        std::fill(flag,flag+len,false);
        for(int i = 0; i < len; i++){
            if(blk[i] != '.'){
                int num = blk[i] - '1';
                if(flag[num]) return false;
                flag[num] = true;
            }
        }
        return true;
    }
};