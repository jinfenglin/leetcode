public class Solution {
	public List<String> letterCombinations(String digits) {
		List<String> table=new ArrayList<String>();
		table.add("");
		table.add("");
		table.add("abc");
		table.add("def");
		table.add("ghi");
		table.add("jkl");
		table.add("mno");
		table.add("pqrs");
		table.add("tuv");
		table.add("wxyz");
		return DFS(table,digits,0);
	}
	public List<String> DFS(List<String> table,String digits,int index){
		List<String> res=new ArrayList<String>();
		if(index==digits.length())
			return res;
		int num=digits.charAt(index)-'0';
		List<String> tmp=DFS(table,digits,index+1);
		for(char c:table[num]){	
			for(String s:tmp){
				res.add(c+s);
			}
		}
		return res;
	}
}
