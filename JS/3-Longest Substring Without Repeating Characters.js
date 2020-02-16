/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var start =0 , end =0 ,length = 0,result = 0;
    var len = s.length;
    while(end < len){
        var temp = s[end];
        for(let i=start ; i < end; i++){
            if(temp == s[i]){
                start = i + 1;
                length = end - start;
                break;
            }
        }
        end++;
        length++;
        result = Math.max(result,length);
    }
    return result;
};