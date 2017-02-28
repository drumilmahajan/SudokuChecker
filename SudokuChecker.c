bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {


    // Checking rows
    for(int i = 0; i < boardRowSize; i++) {
        //printf("%d\n", i);
        int matchArray[9] = {0,0,0,0,0,0,0,0,0};
        for(int j = 0; j < boardColSize; j++){
            //printf("%d\n", j);
            //printf("%d ### %c\n", (int)board[i][j], board[i][j]);
            if(board[i][j] != '.'){
                
                matchArray[(int)board[i][j] - 48 - 1]++;
            }
        }
        for(int k = 0; k < boardColSize; k++){
             if(matchArray[k] > 1){
                 return false;
             }
        }
    }
    
    //Checking coloumns;

    for(int i = 0; i < boardColSize; i++) {
        int matchArray[9] = {0,0,0,0,0,0,0,0,0};
        for(int j = 0; j < boardRowSize; j++){
            if(board[j][i] != '.')
                matchArray[(int)board[j][i] - 48 - 1]++;
        }
        for(int k = 0; k < boardRowSize; k++){
             if(matchArray[k] > 1){
                 return false;
             }
        }
    }
    
    // checking boxes;

    //int i = 0;
    for(int p = 0; p < 9; p = p + 3){
        int matchArray[9] = {0,0,0,0,0,0,0,0,0};
        for(int q = 0; q< 9; q++) {
            for(int r = p ; r < p + 3; r++) {
                if(board[q][r] != '.')
                    matchArray[(int)board[q][r] - 48 - 1]++;
            }
            if(q == 2 || q == 5 || q == 8){
                for(int i = 0; i < 9; i++) {
                    if(matchArray[i] > 1)
                        return false;
                    matchArray[i] = 0;   
                }   
            }
        } 
    }
    
    return true;
}