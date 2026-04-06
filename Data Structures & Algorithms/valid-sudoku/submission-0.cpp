class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
                for(int i=0;i<9;i++){
            unordered_map<char,int>row;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    row[board[i][j]]++;
                    if(row[board[i][j]]>1){
                        return false;
                    }
                }
            }
        }
        for(int j=0;j<9;j++){
            unordered_map<char,int>col;
            for(int i=0;i<9;i++){
                if(board[i][j]!='.'){
                    col[board[i][j]]++;
                    if(col[board[i][j]]>1){
                        return false;
                    }
                }
            }
        }
        for(int starti=0;starti<9;starti+=3){
            for(int startj=0;startj<9;startj+=3){
                unordered_map<char,int> box;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(board[starti+i][startj+j]!='.'){
                            box[board[starti+i][startj+j]]++;
                            if(box[board[starti+i][startj+j]]>1){
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
        
    }
};
