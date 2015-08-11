#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<vector<string>> result;
		bool valid(set<pair<int,int>> queen,int i,int j,int n){
			for(int x=0;x<n;x++){
				pair<int,int> p1=pair<int,int>(x,j);
				pair<int,int> p2=pair<int,int>(i,x);

				if(queen.count(p1) or queen.count(p2))
					return false;
			}

			for(int x=i,y=j;x>=0 and y>=0;x--,y--){
				pair<int,int> p=pair<int,int>(x,y);
				if(queen.count(p))
					return false;
			}

			for(int x=i,y=i;x<n and y<n;x++,y++){
				pair<int,int> p = pair<int,int>(x,y);
				if(queen.count(p))
					return false;
			}
			for(int x=i,y=j;x>=0 and y<n;x--,y++)
			{
				pair<int,int> p=pair<int,int>(x,y);
				if(queen.count(p))
					return false;
			}
			for(int x=i,y=j;x<n and y>=0;x++,y--)
			{
				pair<int,int> p=pair<int,int>(x,y);
				if(queen.count(p))
					return false;
			}
			return true;
		}
		vector<string> make_vec(set<pair<int,int>> queue,int n){
			vector<string> board;
			for(int i=0;i<n;i++)
				board.push_back(string(n,'.'));

			for(pair<int,int> p:queue)
				board[p.first][p.second]='Q';
			return board;
		}
		void NQueens(int n,set<pair<int,int>> queen,int i){
			if(i==n){
				vector<string> sol= make_vec(queen,n);
				result.push_back(sol);
			}

			for(int j=0;j<n;j++){
				if(valid(queen,i,j,n))
				{
					queen.insert(pair<int,int>(i,j));
					NQueens(n,queen,i+1);
					queen.erase(pair<int,int>(i,j));
				}
			}
		}
		vector<vector<string>> solveNQueens(int n) {
			set<pair<int,int>> queen;
			NQueens(n,queen,0);
			return result;
		}
};
int main(){
	Solution *sol=new Solution;
	auto res=sol->solveNQueens(8);
	int i=0;
	for(vector<string> vs:res)
	{
		i++;
		for(string s:vs){
			cout<<s<<endl;
		}
		cout<<endl;
	}
	cout<<i<<endl;
}
