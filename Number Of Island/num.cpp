#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		void helper(int x,int y,vector<vector<char>>& grid){
			int x_len=grid.size();
			if(x_len==0)
				return;
			int y_len=grid.size();
			if(x<0 or x>=x_len or y<0 or y>=y_len)
				return ;
			if(grid[x][y]=='1')
				grid[x][y]='0';
			else
				return;
			helper(x-1,y,grid);
			helper(x+1,y,grid);
			helper(x,y-1,grid);
			helper(x,y+1,grid);

		}
		int numIslands(vector<vector<char>>& grid) {
			int x_len=grid.size();
			if(x_len==0)
				return 0;
			int y_len=grid[0].size();
			int count=0;
			for(int i=0;i<x_len;i++)
				for(int j=0;j<y_len;j++){
					if(grid[i][j]=='1')
						count++;
					helper(i,j,grid);
				}
			return count;
		}
};
int main(){
}
