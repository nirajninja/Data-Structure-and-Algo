void solve(vector<vector<int>>&image, int x, int y, int newc,int c)
    {
        int n=image.size();
        int m=image[0].size();
        if(x>=n || y>=m || x<0 || y<0 || image[x][y]!=c)
        {
            return ;
        }
       // if(image[x][y]==0) return;
        
        image[x][y]=newc;
        
        solve(image, x+1,y,newc,c);
        solve(image, x,y+1,newc,c);
        solve(image, x-1,y,newc,c);
        solve(image, x,y-1,newc,c);
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color=image[sr][sc];
        if(color==newColor) return image;
        solve(image, sr,sc, newColor,color);
        return image;
    }
