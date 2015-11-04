#include <iostream>
using namespace std;
class Solution {
	public:
	    int dotflag=false;
	    int eflag=false;
		bool isdigit(char num){
			int n=num-'0';
			if(n>=0 and n<=9)
				return true;
			else
				return false;
		}
		bool SignState(string str,int i){
			int len=str.size();
			char next;
			if(i+1<len)
				next=str[i+1];
			else
				return false;
			if(isdigit(next))
				return digitState(str,i+1);
			else if(next=='.')
				return dotState(str,i+1);
			return false;
		}
		bool digitState(string str,int i){
		    //cout<<str[i];
			int len=str.size();
			char next;
			if(i+1<len)
				next=str[i+1];
			else
				return true;
			if(isdigit(next))
				return digitState(str,i+1);
			else if(next=='.')
				return dotState(str,i+1);
			else if(next=='e' or next=='E')
				return EState(str,i+1);
			return false;
		}
		bool EState(string str,int i){
		    //cout<< str[i]<<endl;
			int len=str.size();
			dotflag=true;
			if(eflag)
			    return false;
			eflag=true;
			char next;
			if(i+1<len)
				next=str[i+1];
			else
				return false;
			if(isdigit(next))
				return digitState(str,i+1);
			else if(next=='.')
				return false;
			else if(next=='+' or next=='-')
				return SignState(str,i+1);
			return false;
			/*if(i==len-1)
				return false;
			i++;
			if(i<len and (str[i]=='+' or str[i]=='-'))
			    i++;
			while(i<len and isdigit(str[i]))
				i++;
			return i==len;*/
		}
		bool dotState(string str,int i){
		    //cout<<str[i];
		    if (dotflag)
		        return false;
		    dotflag=true;
			int len=str.size();
			int start=i-1;
			while(start>=0 and (str[start]==' ' or str[start]=='+' or str[start]=='-'))
				start--;
			char next;
			if(i+1<len)
				next=str[i+1];
			else if(start>=0)
				return true;
			else
				return false;
			//cout<<str[i];
			if(isdigit(next))
				return digitState(str,i+1);
			else if((next=='e' or next=='E') and start>=0)
			    return EState(str,i+1);
			return false;
		}
		
		bool isNumber(string s) {
			int i=0;
			int len=s.size();
			if(len==0)
				return 0;
			while(i<len and s[i]==' ')
				i++;
			int j=len-1;
			while(j>=0 and s[j]==' ')
				j--;
			s=s.substr(0,j+1);
			if(isdigit(s[i]))
				return digitState(s,i);
			else if(s[i]=='.')
				return dotState(s,i);
			else if(s[i]=='+' or s[i]=='-')
				return SignState(s,i);
			return false;
		}
};





