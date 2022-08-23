class Solution {
    public static final long MODULO = 1_000_000_007;

    public static void main(String[] args) {
        int[][] roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
        System.out.println(new Solution().countPaths(7, roads));
    }
    public int countPaths(int n, int[][] roads) {
        if(n == 1) return 1; // to handle the "only one node" case
        long[][] W = new long[n][n];
        long[][] counts = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                W[i][j] =Long.MAX_VALUE;
            }
        }
        for (int[] road : roads) {
            int u = road[0];
            int v = road[1];
            W[u][v] = road[2];
            W[v][u] = road[2];
            counts[u][v] = 1;
            counts[v][u] = 1;
        }
        long[][] prevD = W;
        for(int k = 0; k < n; k++){
            long[][] nextD = new long[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    long without = prevD[i][j];
                    long with = add(prevD[i][k], prevD[k][j]);
                    long withCount = (counts[i][k] * counts[k][j])%MODULO;
                    if(without < with) {
                        nextD[i][j] = without;
                    }
                    else if(without == with){
                        nextD[i][j] = without;
                        counts[i][j] = (counts[i][j] + withCount)%MODULO;
                    } else {
                        nextD[i][j] = with;
                        counts[i][j] = withCount;
                    }
                }
            }
            prevD = nextD;
        }
        return (int) counts[n-1][0];
    }
    
    // take care of overflows
    private static long add(long a, long b){
        return a ==  Long.MAX_VALUE || b == Long.MAX_VALUE ? Long.MAX_VALUE : a + b;
    }
}