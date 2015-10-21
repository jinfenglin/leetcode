#include<iostream>
using namespace std;

class Solution {
	public:
		int hIndex(vector<int>& citationss) {
			sort(citationss.begin(),citationss.end());
			citationss.insert(0,0);
			for(int i=citationss.size()-1;i>0;i--){
				if(citationss[i-1]<citationss.size()-i)		
					return citationss.size()-i;		
			}
			
			return 0;
		}
};
int main(){
}
