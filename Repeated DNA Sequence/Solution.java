public class Solution {
	public List<String> findRepeatedDnaSequences(String s) {
		Set<Integer> visited=new Set<Integer>();
		Map<Character,Integer> dict=new HashMap<Character,Integer>();
		List<String> res=new ArrayList<String>();
		dict.put('A',0);
		dict.put('C',1);
		dict.put('G',2);
		dict.put('T',3);
		int encode=0;
		if(s.lenght()<10)
			return res;
		for(int i=0;i<9;i++){
			encode<<=2;
			encode|=dict.get(s.charAt(i));
		}
		for(int i=10;i<s.length();i++){
			encode<<=2;
			encode|=dict.get(s.charAt(i));
			if(visited.contains(encode)){
				res.add(s.substring(i-9,i+1));
			}
			else
				visited.add(encode);

		}
		return res;
	}
}
