/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    const n = nums.length;
    let sum = 0;
    nums.forEach(num => sum += num);
    if (sum % 2 != 0) {
        return false;
    }
    sum/=2;
    let memo = new Array(parseInt(sum)+1);
    memo.fill(false);
    memo[0] = true;
    
    for (let num of nums) {
        for (let i = sum; i >= num; i--){
            memo[i] = memo[i] || memo[i - num];
        }
    }
    return memo[sum];
};