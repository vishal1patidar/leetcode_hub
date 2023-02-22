class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = -1, totalWeight = 0;
        for (int weight : weights) {
            maxWeight = max(maxWeight, weight);
            totalWeight = totalWeight + weight;
        }
        //here weight and total weight work as left and right pointer of bunary search
        while (maxWeight < totalWeight) {
            int midWeight = maxWeight + (totalWeight - maxWeight) / 2;
            int daysNeeded = 1, currWeight = 0;
            for (int weight : weights) {
                if (currWeight + weight > midWeight) {
                    daysNeeded++;
                    currWeight = 0;
                }
                currWeight = currWeight + weight;
            }
            if (daysNeeded > days) {
                maxWeight = midWeight + 1;
            } else {
                totalWeight = midWeight;
            }
        }
        return maxWeight;
    }
};
// class Solution {
//     public int shipWithinDays(int[] weights, int days) {
//         int maxWeight = -1, totalWeight = 0;
//         for (int weight : weights) {
//             maxWeight = Math.max(maxWeight, weight);
//             totalWeight += weight;
//         }
//         int left = maxWeight, right = totalWeight;
//         while (left < right) {
//             int mid = (left + right) / 2;
//             int daysNeeded = 1, currWeight = 0;
//             for (int weight : weights) {
//                 if (currWeight + weight > mid) {
//                     daysNeeded++;
//                     currWeight = 0;
//                 }
//                 currWeight += weight;
//             }
//             if (daysNeeded > days) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         return left;
//     }
// }
