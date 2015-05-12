#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
	    for(int i=0;i<board.size();i++)
		    for(int j=0;j<board[i].size();j++){
			    if(board[i][j]!=word[0])
				    continue;
			    if (search(board,word.substr(1),i,j))
				    return true;
		    }
	    return false;
    }
    bool search(vector<vector<char> > board,string word,int row,int col){
	    if(word.size()==0)
		    return true;
	    board[row][col]=NULL;
	    if(row-1 >=0)
	    {
		   if(board[row-1][col]==word[0] and search(board,word.substr(1),row-1,col))
				    return true;
	    }    //search upper
	    if(col-1>=0)
	    {
		    if(board[row][col-1]==word[0] and search(board,word.substr(1),row,col-1))
			     return true;
	    }
	    if(col+1<board[row].size())
	    {
		   
		    if(board[row][col+1]==word[0] and search(board,word.substr(1),row,col+1))
			    return true;
	    } //search right
	    if(row+1<board.size())
	    {
		    if(board[row+1][col]==word[0] and search(board,word.substr(1),row+1,col))
			    return true;
	    } //search down
	    return false;
    }
};

int main()
{
	char ar1[]={'C','A','A'};
	char ar2[]={'A','A','A'};
	char ar3[]={'B','C','D'};
	vector<char> vec1(ar1,ar1+sizeof(ar1)/sizeof(char));
	vector<char> vec2(ar2,ar2+sizeof(ar2)/sizeof(char));
	vector<char> vec3(ar3,ar3+sizeof(ar3)/sizeof(char));
	vector<vector<char> > input;
	input.push_back(vec1);
	input.push_back(vec2);
	input.push_back(vec3);
	Solution *sol=new Solution;
	cout<<sol->exist(input,"AAB")<<endl;
	
}
