/**
 * @param {number[]} num
 * @param {number} k
 * @return {number[]}
 */
var addToArrayForm = function(num, k) {
    for(let i=num.length-1; i>=0; i--){
        num[i] = num[i] + k;
        k = Math.floor(num[i] / 10);
        num[i] = num[i] % 10;
    }
    if(k){
        let data = k.toString().split("");
        data = data.map(d=>parseInt(d));
        num = [...data,...num];
    }
    return num;
};
