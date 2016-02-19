public class Solution {
	private int height,width;
	public int numIslands(char[][] grid) {
		height=grid.length;
		if(height==0)
			return 0;
		width=grid[0].length;
		int count=0;
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(DFS(grid,i,j))
					count++;
			}
		}
		return count;
	}
	boolean DFS(char[][] grid,int x,int y){
		if(x>=height || x<0 || y>=width || y<0)
			return false;
		boolean result=false;
		int[] dirx={1,0,-1,0};
		int[] diry={0,1,0,-1};
		if(grid[x][y]=='1'){
			grid[x][y]='0';
			result=true;
			for(int i=0;i<4;i++){
				result|=DFS(grid,x+dirx[i],y+diry[i]);
			}
		}
		return result;
	}
}
