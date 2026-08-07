class Solution {
public:
    vector<vector<string>> ans ;
    bool valid_col( int col , vector<string>&board ){
        int n = board.size() ;

        for(  int i = 0 ; i < n ; i ++){
            if( board[i][col] == 'Q'){
                return 0 ;
            }
        }
        return 1 ;
    }

    bool valid_diagonal( vector<string>& board , int i , int j){

        int n = board.size() ;

        for( int idx = 0 ; idx < n ; idx++){
            int jdx = idx - ( i-j);
            if( jdx < n && jdx >= 0 && board[idx][jdx] == 'Q') return 0 ;
        }

        for( int idx = 0 ; idx < n ; idx++){
            int jdx = ( i + j) - idx ;

            if( jdx < n && jdx >= 0 && board[idx][jdx] == 'Q') return 0 ;
        }
        return 1 ;
    }



    void generate( vector<string>& board , int row ){
        if( row == board.size()){
            ans.push_back(board);
            return ;
        }

        int n = board.size() ;

        for( int i = 0 ; i < n ; i++){
            if( valid_col( i , board) && valid_diagonal(board , row , i)){
                board[row][i] = 'Q';
                generate(board , row + 1);

                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        string s ;
        for( int i = 0 ; i < n ; i++){
            s.push_back('.');
        }

        vector<string> board( n , s);

        generate(board , 0);

        return ans ;
    }
};