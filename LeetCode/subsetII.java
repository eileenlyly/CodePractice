public class Solution {
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        Arrays.sort(num);
        for( int i = 0; i < num.length/2; ++i ) 
        { 
            int temp = num[i]; 
            num[i] = num[num.length - i - 1]; 
            num[num.length - i - 1] = temp; 
        }
        res = getSubset(num,0,getNext(0,num));
        return res;
    }
    public int getNext(int s, int[]num){
        if(s >= num.length-1) return s;
        for(int i = s+1; i < num.length; i++){
            if(num[i] != num[s]) return i-1;
        }
        return num.length-1;
    }
    public ArrayList<ArrayList<Integer>> getSubset(int[]num, int s, int t){
        int dup = t - s + 1;
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(t > num.length-1){
            res.add(new ArrayList<Integer>());
            return res;
        };
        res = getSubset(num,t+1,getNext(t+1,num));
        int n = res.size();
        for(int i = 0; i < n; i++){
            ArrayList<Integer> subres = new ArrayList<Integer>(res.get(i));
            subres.add(num[s]);
            res.add(subres);
            for(int j = 0; j < dup-1; j++){
                subres = new ArrayList<Integer>(res.get(res.size()-1));
                subres.add(num[s]);
                res.add(subres);
            }
        }
        return res;
    }
}