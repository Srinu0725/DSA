class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m =boxGrid.size();
        int n =boxGrid[0].size();

        vector<vector<char>>rotatebox(n,vector<char>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rotatebox[i][j] = boxGrid[m-1-j][i]; //or this can be transpose + reverse for 90 degrees
                
            }
        }

        for(int col = 0;col<m;col++){
            int bottom = n-1;
            for(int row=n-1;row>=0;row--){
                if(rotatebox[row][col] == '*'){
                    bottom = row-1;
                }else if(rotatebox[row][col] =='#'){
                    swap(rotatebox[row][col],rotatebox[bottom][col]);
                    bottom--;
                }
            }

        }

        return rotatebox;

        
    }
};