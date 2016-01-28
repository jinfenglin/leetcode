import java.util.*;
public class Solution {
	boolean valid(String num){
		if(num.length()==1)
			return true;
		boolean flag=false;
		for(int i=0;i<num.length();i++){
			char c=num.charAt(i);
			if(c=='0' && flag==false)
				return false;
			else
				flag=true;
		}
		if(Integer.parseInt(num)>255)
			return false;
		
		return true;
	}
	void DFS(String s,int index,List<String> res,String ans,int count){
		if(count>4)
			return ;
		if(count==4 && index==s.length()){
			res.add(ans);
			return ;
		}
		StringBuilder tmp=new StringBuilder();
		for(int i=0;i<3 && index+i<s.length();i++){
			tmp.append(s.charAt(index+i));			
			if(valid(tmp.toString())){
				if(count==3)
					DFS(s,index+i+1,res,ans+""+tmp,count+1);
				else
					DFS(s,index+i+1,res,ans+tmp+".",count+1);
			}
		}
	}
	public List<String> restoreIpAddresses(String s) {
		List<String> res=new ArrayList<String>();
		String ans="";
		DFS(s,0,res,ans,0);	
		return res;	
	}
	public static void main(String[] args){
		Solution sol=new Solution();
		System.out.println(sol.restoreIpAddresses("010010"));
	}
}
