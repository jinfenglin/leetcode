import java.util.*;
public class Solution {
	public String simplifyPath(String path) {
		String[] paths=path.split("/");
		Stack<String> pStack=new Stack<String>();
		StringBuilder res=new StringBuilder();
		for(int i=0;i<paths.length;i++){
			String content=paths[i];
			//System.out.println(content);
			if(content.equals("..") ){
				if(!pStack.isEmpty())
					pStack.pop();
			}else if(content.equals(".") || content.equals(""))
				continue;
			else{
				pStack.push(content);
			}		
		}
		while(!pStack.empty()){
			String top=pStack.peek();
			pStack.pop();
			res.insert(0,"/"+top);
		}
		if(res.length()==0)
			return "/";
		return res.toString();

	}
	public static void main(String[] args){
		Solution sol=new Solution();
		System.out.println(sol.simplifyPath("/home/a/.."));
	}
}
