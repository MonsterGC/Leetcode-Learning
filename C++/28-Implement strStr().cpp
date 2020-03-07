/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
**/

// Version BF
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack == needle) return 0;        
        int target = needle.size();
        if(target == 0) return 0;
        int len = haystack.size();
        if(target > len) return -1;
        
        string temp;
        int i = 0; 
        while(i <= len - target){
            temp = haystack.substr(i, target);
            if(needle==temp){
                return i;
            }
            i++; 
        }
        return -1;
    }
};

// Version KMP
class Solution {
public:
    int showNext(string s, int target) {
		string str1, str2;
		int num = 0;
		bool status = false;
		for(int j = 0;j < target-1;j++){
			if(s[j] != s[j+1]){
				status = true;
				break;
			}
		}
        if(!status){
            return target - 1;
        }
        for (int i = 0; i < target / 2; i++) {
				str1 = str1 + s[i];
				str2 = s[target - i - 1] + str2;
				if (str1 == str2) {
					num = str1.size();
			}
		}	
		return num;
	}
	int strStr(string haystack, string needle) {
		if (haystack == needle) return 0;
		int target = needle.size();
		if (target == 0) return 0;
		int len = haystack.size();
		if (target > len) return -1;

		int i = 0;
		int j = 0;
		int temp;
		while (i < len && j < target) {
			if (needle[j] != haystack[i]) {
				if (i == len - 1) return -1;
				if (j == 0) {
					i++;
                    continue;
				}
                temp = showNext(needle, j);
                j = temp ? temp : 0;
			}
			else {
				if (j == target - 1) return i - j;
				i++;j++;
			}
		}
		return -1;
	}
};

// Version Sunday 
class Solution {
public:
    // Calculated offset 
    int calShiftMat(string s , char chr){
    	int i = -1;
       	for(int temp = 0; temp < s.size() ; temp++){
       		if(s[temp] == chr) i = temp;
       	}
        return i;
    }
    int strStr(string haystack, string needle) {
        if (haystack == needle) return 0;
		int target = needle.size();
		if (target == 0) return 0;
		int len = haystack.size();
		if (target > len) return -1;

        int i = 0;
        int j = 0;
        int temp = 0;
        while(i < len && j < target){
            if(haystack[i] == needle[j]){
                if (j == target - 1) return i - j;
                i++;
                j++;
                continue;
            }
            if (i == len - 1) return -1;
            if(j == 0){
                i++;
                continue;
            }
            if(i + target - j > len) return -1;
            temp = calShiftMat(needle,haystack[i + target - j]);
            if(temp == -1){
                i++;
                continue;
            }
            i +=target - j - temp;
            j = 0;
        }
        return -1;
    }
};