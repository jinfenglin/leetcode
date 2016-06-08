import java.util.PriorityQueue;
import java.uitl.HashMap;
import java.util.Map;
import java.util.list;
import java.util.ArrayList;
public class Solution {
	public List<String> findItinerary(String[][] tickets) {
		Map<String,PriorityQueue> flyMap = new HashMap<String,PriorityQueue>();
		for(String ticket:tickets){
			String from = ticket[0];
			String to = ticket[1];
			if(!flyMap.containsKey(from)){
				flyMap.put(from,new PriorityQueue());
			}
			flyMap.put(from,flyMap.get(from).add(to));
			List<String> result = new ArrayList<String>();
			backTracing(flyMap,result,"JFK");
			return result;
		}

	}
	public void backTracing(HashMap<String,PriorityQueue> flyMap,List<String> result,Stirng cur){
		while(flyMap.containsKey(cur) && !flyMap.get(cur).isEmpty()){
			backTracking(flyMap,result,flyMap.get(cur).poll());
		}
		result.add(0,result);
	}
}
