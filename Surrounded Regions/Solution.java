import java.util.*;
public class Solution {
	void labelZ(char[][] board,int x,int y){
		int x_len=board.length;
		int y_len=0;
		if(x_len>0)
			y_len=board[0].length;
		else
			return ;
		board[x][y]='Z';
		if(x+1<x_len-1 && board[x+1][y]=='O')
			labelZ(board,x+1,y);
		if(x-1>0 && board[x-1][y]=='O')
			labelZ(board,x-1,y);
		if(y+1<y_len-1 && board[x][y+1]=='O')
			labelZ(board,x,y+1);
		if(y-1>0 && board[x][y-1]=='O')
			labelZ(board,x,y-1);
	}
	public void solve(char[][] board) {
		int x_len=board.length;
		int y_len=0;
		if(x_len>0)
			y_len=board[0].length;
		else
			return ;
		for(int i=0;i<y_len;i++){
			if(board[0][i]=='O')
				labelZ(board,0,i);
			if(board[x_len-1][i]=='O')
				labelZ(board,x_len-1,i);
		}
		for(int i=0;i<x_len;i++){
			if(board[i][y_len-1]=='O')
				labelZ(board,i,y_len-1);
			if(board[i][0]=='O')
				labelZ(board,i,0);
		}
		for(int i=0;i<x_len;i++)
			for(int j=0;j<y_len;j++){
				if(board[i][j]=='Z')
					board[i][j]='O';
				else if(board[i][j]=='O')
					board[i][j]='X';
			}
	}
}
