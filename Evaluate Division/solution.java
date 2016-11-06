c class Solution {

    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {

        Map<String,Map<String,Double>> graph = new HashMap<String, Map<String,Double>>();

        double[] res = new double[queries.length];

        for(int i=0;i<equations.length;i++){

            String from = equations[i][0];

            String to = equations[i][1];

            if(!graph.containsKey(from))

                graph.put(from,new HashMap<String,Double>());

            if(!graph.containsKey(to))

                graph.put(to,new HashMap<String,Double>());

            graph.get(from).put(to,values[i]);

            graph.get(to).put(from,1/values[i]);

        }

        for(int i=0;i<queries.length;i++){

            Set<String> visted = new HashSet();

            res[i] = dfs(graph,queries[i][0],queries[i][1],visted);

        }

        return res;

    }

        

    public double dfs(Map<String,Map<String,Double>> map, String cur,String target,Set<String> visited){

            if(!map.containsKey(cur))

                return -1;

            visited.add(cur);

            Map<String,Double> neighbour = map.get(cur);

            if(neighbour.containsKey(target))

                return neighbour.get(target);

            for(String point : neighbour.keySet()){

                double res=-1;

                if(!visited.contains(point))

                    res= dfs(map,point,target,visited);

                if(res!=-1)

                    return neighbour.get(point)*res;

            }

            return -1;

        }

}
