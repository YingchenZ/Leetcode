import java.util.*;

class Solution {
    public static int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] o1, int[] o2){
                return o1[0] - o2[0];
            }
        });

        List<int[]> ans = new ArrayList<>();
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int[] interval : intervals){
            if( start <= interval[0] && interval[0] <= end){
                end = Math.max(interval[1], end);
            }
            else if(end < interval[0]){
                ans.add(new int[]{start, end});
                start = interval[0];
                end = interval[1];
            }
        }
        ans.add(new int[]{start, end});

        return ans.toArray(new int[ans.size()][]);
    }

    private static void printResult(int[][] result){
        System.out.print("[");
        for(int i = 0; i < result.length; i++){
            System.out.print(Arrays.toString(result[i]));
            System.out.print(i == result.length - 1? "]\n":",");
        }
    }

    // Intervals = [[6, 8],[1, 9],[2, 4],[4, 7]]   
    // Merged Intervals = [[1, 9]]
    
    // Intervals = [[1, 4],[0, 2],[3, 5]]
    // Merged Intervals = [[0, 5]]
    
    // Intervals = [[1, 4],[4, 5]]
    // Merged Intervals = [[1, 5]]
    
    // Intervals = [[1, 3],[2, 6],[8, 10],[15, 18]]
    // Merged Intervals = [[1, 6],[8, 10],[15, 18]]

    public static void main(String[] args){
        int[][][] testSet = new int[][][]{
            new int[][]{new int[]{6,8}, new int[]{1,9 }, new int[]{2,4 }, new int[]{4,7}},
            new int[][]{new int[]{1,4}, new int[]{0,2}, new int[]{3,5}},
            new int[][]{new int[]{1,4}, new int[]{4,5}},
            new int[][]{new int[]{1,3}, new int[]{2,6}, new int[]{8,10}, new int[]{15,18}}
        };

        for(int[][] test : testSet){
            System.out.print("Intervals = ");
            printResult(test);
            System.out.print("Merged Intervals = ");
            int[][] result = merge(test);
            printResult(result);
            System.out.println();
        }
    }
}