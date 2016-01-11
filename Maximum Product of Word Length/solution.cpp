#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
    	vector<int> states;
	int res=0;
	for(string word:words){
		int tmp=0;
		for(char ch:word){
			tmp|= 1<<(ch-'a'); 
		}
		states.push_back(tmp);
	}	
	for(int i=0;i<words.size();i++){
		for(int j=i+1;j<words.size();j++){
			if((states[i]&states[j])==0){
				int lenA=words[i].size();
				int lenB=words[j].size();
				res=max(lenA*lenB,res);
			}
		}
	}
	return res;
    }
};
int main(){
}
