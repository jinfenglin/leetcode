#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
	    if(n==0)
		    return "";
	    int num=(n-1)%26;
	    int rest=(n-num-1)/26;
	    char ch=num+65;
	    string result=convertToTitle(rest);
	    result.insert(result.end(),ch);
	    return result;
    }
	    };
int main(){
	Solution *sol=new Solution;
	cout<<sol->convertToTitle(52)<<endl;
}

