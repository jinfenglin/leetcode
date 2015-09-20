#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
	public:
		string fractionToDecimal(int numerator, int denominator) {
			string res="";
			bool sign=true;
			if(numerator<0)
				sign=!sign;
			if(denominator<0)
				sign=!sign;
			if(!sign and numerator!=0)
				res+="-";
			unordered_map<long,long> mp;
			long num=numerator;
			num=abs(num);
			long de=denominator;
			de=abs(de);
			long integer=num/de;
			res+=to_string(integer);
			long remain=num%de;
			if(remain){
				res+=".";
				long loc=res.size();
				while(remain!=0 and mp.find(remain)==mp.end())//not find key
				{
					//cout<<remain<<endl;
					mp[remain]=loc;
					remain*=10;
					if(remain<de){
						res+="0";
						loc++;
					}else{
						int digit=remain/de;
						remain=remain%de;
						res+=to_string(digit);
						loc++;
					}
				}
				if(remain!=0){
					loc=mp[remain];
					res.insert(loc,"(");
					res+=")";
				}

			}
			return res;

		}
};
int main(){
	Solution *sol=new Solution();
	cout<<sol->fractionToDecimal(1,INT_MIN)<<endl;
}
