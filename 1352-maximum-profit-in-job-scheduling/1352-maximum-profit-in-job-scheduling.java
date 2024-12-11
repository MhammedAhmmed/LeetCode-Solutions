class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int len = startTime.length;
        int[][]activities = new int[len][3];
        
        for (int i =0 ; i < len; i++){
            activities[i][0] = startTime[i];
            activities[i][1] = endTime[i];
            activities[i][2] = profit[i];
        }
        
        return solve(activities);
    }

    public boolean nonOverlap(int[]first, int[]second){
        return second[0] >= first[1];
    }
    public int nextNonOverlapActivity(int[][]activities, int index){
        int l = index + 1;
        int r = activities.length - 1;

        int nextIndex = -1;
        while (l <= r){
            int mid = (l + r) / 2;

            if(nonOverlap(activities[index], activities[mid])){
                nextIndex = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return nextIndex;
    }
    public int maxNonOverlapActivities(int[][]activities, int[]dp, int index, int n){
        if (index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }

        int take = activities[index][2];
        int nextNonOverlapIndex = nextNonOverlapActivity(activities, index);
        if(nextNonOverlapIndex != -1){
            take += maxNonOverlapActivities(activities, dp, nextNonOverlapIndex, n);
        }

        int notTake = maxNonOverlapActivities(activities, dp, index + 1, n);

        return dp[index] = Math.max(take, notTake);
    }
    public int solve(int[][]activities){
        Arrays.sort(activities, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });

        int activitiesLen= activities.length;
        int[]dp = new int[activitiesLen];
        Arrays.fill(dp, -1);

        return maxNonOverlapActivities(activities, dp, 0, activitiesLen);
    }
}