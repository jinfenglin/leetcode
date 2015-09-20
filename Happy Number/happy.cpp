#include <iostream>
#include <set>
using namespace std;
class Solution {
	public:int next_num(int n){
		       int digit;
		       int sum=0;
		       while(n){
			       digit=n%10;
			       n=n/10;
			       sum+=digit*digit;
		       }
		       return sum;

	       }
	       bool isHappy(int n) {
		       set<int> st;
		       while(st.find(n)==st.end()){
		       		st.insert(n);
				int next=next_num(n);
				n=next;
				//cout<<n<<endl;
				if(next==1)
					return true;
		       }
		       return false;

	       }
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->isHappy(19)<<endl;
}
