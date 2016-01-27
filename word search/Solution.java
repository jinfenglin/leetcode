public class Solution {
	private int xLen,yLen;
	boolean visited[][];
	boolean validBoundary(int x,int y){
		if(x<0 || x>=xLen || y<0 || y>=yLen)
			return false;
		return true;
			
	}
	boolean DFS(char[][] board,String word,int x,int y,int index){
		if(!validBoundary(x,y) || board[x][y]!=word.charAt(index) || visited[x][y])
		    return false;
		else if(index==word.length()-1 && word.charAt(index)==board[x][y])
			return true;
		int[] xDir={1,0,-1,0};
		int[] yDir={0,1,0,-1};
		visited[x][y]=true;
		for(int i=0;i<4;i++){
			if(DFS(board,word,x+xDir[i],y+yDir[i],index+1))
				return true;
		}
		visited[x][y]=false;
		return false;	
	}
	public boolean exist(char[][] board, String word) {
		xLen=board.length;
		if(xLen==0)
			yLen=0;
		else
			yLen=board[0].length;
		visited= new boolean[xLen][yLen];
		for(int i=0;i<xLen;i++)
			for(int j=0;j<yLen;j++){
				if(DFS(board,word,i,j,0))
					return true;
			}
		return false;
	}
}
