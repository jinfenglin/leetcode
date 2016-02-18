public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
	    Map<String,List<String>> map= new HashMap<String,List<String>>();
	    List<List<String>> res=new ArrayList<List<String>>();
	    for(String str:strs){
		    String newStr=hashCode(str);
		    List<String> list=map.get(newStr);
		    if(list==null)
			    list=new ArrayList();
		    list.add(newStr);
	    }
	    for(String key:map.keySet()){
	    	List<String> ls=map.get(key);
		Collection.sort(ls);
		res.add(ls);
	    }
	    return res;
    }
    private String hashCode(String str){
	    char[] array=str.toCharArray(str);
	    Arrays.sort(array);
	    return new String(array);
    }
}
