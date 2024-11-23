class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        if (box.empty()) return {};  // Handle empty input
        vector<vector<char>> rotated(n, vector<char>(m,'.'));
        //rotate the box
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rotated[j][m - 1 - i]=box[i][j];
            }
        }
        // two pointer
        for(int j=0; j<rotated[0].size(); j++){
            int placer=rotated.size()-1;
            for(int i=placer; i>=0;i--){
                if(rotated[placer][j]=='.'){
                    if(rotated[placer][j]=='.' && rotated[i][j]=='#'){
                        swap(rotated[placer][j], rotated[i][j]);
                        placer--;
                    }
                    else if(rotated[i][j]=='*'){
                        placer=i-1;
                    }
                }
                else placer--;
                
            }
        }
        return rotated;
    }
};