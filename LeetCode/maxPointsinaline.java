/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    public int maxPoints(Point[] points) {
        int max = 0;
        for(int i = 0; i < points.length; i++){
            max = Math.max(max, countPointsinLine(points, points[i]));
        }
        return max;
    }
    private int countPointsinLine(Point[] points, Point p){
        HashMap<Double,Integer> slope_map = new HashMap<Double, Integer> ();
        int count_same = 0;
        int count_vertical = 0;
        int x = p.x;
        int y = p.y;
        for(int i = 0; i < points.length; i++){
            if(points[i].x == x){
                if(points[i].y == y) count_same++;
                else count_vertical++;
                continue;
            }
            double slope = (double)(points[i].y - y) / (points[i].x - x);
            pushToMap(slope,slope_map);
        }
        return Math.max(maxMap(slope_map),count_vertical) + count_same;
    }
    void pushToMap(double slope, HashMap<Double, Integer> map){
        if(!map.containsKey(slope)){
            map.put(slope, 1);
        } 
        else map.put(slope, map.get(slope) + 1);
        return;
    }
    int maxMap(HashMap<Double, Integer> map){
        int max = 0;
        for(Map.Entry<Double,Integer> entry : map.entrySet()) {
            max = Math.max(entry.getValue(), max);
        }
        return max;
    }
}