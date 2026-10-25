class Solution {
    bool checkRows(vector<vector<char>>& board)
    {
        unordered_map<char, int> mp;
        for(auto& vec:board)
        {
            for(auto& item: vec) {
                if(item >= '1' && item <= '9') 
                {
                    mp[item]++;
                    if(mp[item]>1) return false;
                }
            }
            mp.clear();
        }
        return true;
    }
    bool checkCols(vector<vector<char>>& board) {
        unordered_map<char, int> mp;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char item = board[j][i];
                if(item >= '1' && item <= '9') {
                    mp[item]++;
                    if(mp[item])
                        if(mp[item]>1) return false;
                }
            }
            mp.clear();
        }
        return true;
    }
    bool checkSubBoxes(vector<vector<char>>& board) {
        unordered_map<char, int> mp;
        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {
                mp[board[i][j]]++;
                mp[board[i+1][j]]++;
                mp[board[i+2][j]]++;
                
                mp[board[i][j+1]]++;
                mp[board[i+1][j+1]]++;
                mp[board[i+2][j+1]]++;
                
                mp[board[i][j+2]]++;
                mp[board[i+1][j+2]]++;
                mp[board[i+2][j+2]]++;
                

                for(const auto& item:mp) {
                    if(item.first != '.' && item.second > 1)
                        return false;
                }
                mp.clear();
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(checkRows(board) && checkCols(board) && checkSubBoxes(board)) 
            return true;
        else return false;
    }
};
