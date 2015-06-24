#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class Solution {
	public:
		string convert(string s, int numRows) {
			if(nRows <= 1) return s;  
			string result;  
			if(s.size() ==0) return result;  
			for(int i =0; i< nRows; i++)  
			{  
				for(int j =0, index =i; index < s.size();   
						j++, index = (2*nRows-2)*j +i)  
				{  
					result.append(1, s[index]);  //red element
					if(i ==0 || i == nRows-1)   //green element
					{            
						continue;  
					}  
					if(index+(nRows- i-1)*2 < s.size())  
					{  
						result.append(1, s[index+(nRows- i-1)*2]);  
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
