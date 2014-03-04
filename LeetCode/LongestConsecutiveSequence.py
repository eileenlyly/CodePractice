public class Solution {
    public int longestConsecutive(int[] num) {
        HashMap<Integer, Boolean> num_map = new HashMap<Integer, Boolean>();
        for(int i = 0; i < num.length; i++){
            num_map.put(num[i],true);
        }
        int longest = 0;
        for(int k : num_map.keySet()){
            if (!num_map.get(k)) continue;
            int m = k - 1;
            int n = k + 1;
            while(num_map.containsKey(m)){
                num_map.put(m,false);
                m--;
            } 
            while(num_map.containsKey(n)){
                num_map.put(n,false);
                n++;
            }
            longest = Math.max(longest, n-m-1);
        }
        return longest;
    }
}