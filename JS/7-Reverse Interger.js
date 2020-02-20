/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    var status = x >= 0 ? 1 : -1;
    var result = Number((x * status + "").split("").reverse().join("")) * status;
    return (result >= 2147483647 || result <= -2147483648) ? 0 : result;
};