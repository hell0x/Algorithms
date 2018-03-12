int MaxSubSeqSum(int arr[], int left, int right) {
    if(left == right){
        if(arr[left] > 0){
            return arr[left];
        }else {
            return 0;
        }
    }

    int center = (left + right) / 2;
    int leftMaxSum = MaxSubSeqSum(arr, left, center); /* 分界线左侧最大子数列 */
    int rigthMaxSum = MaxSubSeqSum(arr, center+1, right); /* 分界线右侧最大子数列 */

    /* 以分界线往左求最大子数列 */
    int leftBorderSum = 0, maxLeftBorderSum = 0;
    for(int i=center; i>=left; i--) {
        leftBorderSum += arr[i];
        if(leftBorderSum > maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }
    }

    /* 以分界线往右求最大子数列 */
    int rightBorderSum = 0, maxRightBorderSum = 0;
    for(int j=center+1; j<=right; j++) {
        rightBorderSum += arr[j];
        if(rightBorderSum > maxRightBorderSum) {
            maxRightBorderSum = rightBorderSum;
        }
    }

    /* 跨越分界线最大子数列和 */
    int maxBorderSum = maxLeftBorderSum + maxRightBorderSum;

    return maxSum(leftMaxSum, rigthMaxSum, maxBorderSum);
}

/*
**  返回a, b, c三者最大值
*/
int maxSum(int a, int b, int c){
    if(a > b) {
        a = b;
    }
    if(a > c) {
        return a;
    }else {
        return c;
    }
}