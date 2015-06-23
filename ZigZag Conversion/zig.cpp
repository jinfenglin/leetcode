#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
	public:
		string convert(string s, int numRows) {
			if(numRows==1)
				return s;
			string result;
			vector<queue<char> > char_station;
			int model=(numRows-1)*2;
			for(int i=0;i<model;i++){
				char_station.push_back(queue<char>());
			}
			for(int i=0;i<s.size();i++){
				char_station[i%model].push(s[i]);
			}
			for(int i=0;i<numRows;i++){
				if(i==0 or i==numRows-1)
					while(!char_station[i].empty()){
						result.push_back(char_station[i].front());
						char_station[i].pop();
					}
				else{

					while(!char_station[i].empty()){
						result.push_back(char_station[i].front());
						char_station[i].pop();
						if(!char_station[model-i].empty())
						{
							result.push_back(char_station[model-i].front());
							char_station[model-i].pop();
							
						}
					}
				}				
			}			
			return result;
		}
};
int main(){
	string str="";
	Solution *sol=new Solution;
	cout<<sol->convert(str,2)<<endl;
}
