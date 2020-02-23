/**
 * 
 * **/

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));

        s = " " + s, p = " " + p; //下标从1开始

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (!i && !j)
                {
                    f[i][j] = true;
                    continue;
                }
                if (p[j] == '.' || s[i] == p[j])
                    if (i && j)
                        f[i][j] = f[i - 1][j - 1];
                if (p[j] == '*')
                {
                    if (j >= 2)
                        f[i][j] = f[i][j - 2];
                    if (p[j - 1] == '.' || s[i] == p[j - 1])
                        if (i && j >= 2 && f[i - 1][j])
                            f[i][j] = f[i - 1][j];
                }
            }
        }
        return f[n][m];
    }
};

/** err => "c*a*b*"
class Solution {
public:
    bool isMatch(string s, string p) {
		int slen = s.size();
		int plen = p.size();

		// int sStr[slen]; 错误写法 LeetCode没检测出来
        // int pStr[plen];
        vector<int> sStr(slen); 
        vector<int> pStr(plen);
		// 字符转为ASCII码
		for (int i = 0; i < slen; i++) sStr[i] = s[i];
		// 字符转为ASCII码
		for (int j = 0; j < plen; j++) pStr[j] = p[j];

		bool end = false; // 是否到了p尾部
		int start = 0;    // 起始位
		int status = 0;   // 状态位
		for (int n = 0; n < plen; n++) {
			status = isType(pStr[n]);
			// 该位属于字符的情况
			if (status == 1) {
                if(n+1 != plen){
                	if(isType(pStr[n+1]) ==2){
                		continue;
                	}
                   	if (sStr[start] != pStr[n]) {
					   return false;
				    }
                }
				start++;
			}
			// 属于*情况
			if (status == 2) {
				
				// 相同数字遍历情况
				start = boolEnd(s, start, slen , p[n == 0 ? 0 : n -1]);
                if(start + 1 == slen && n + 1 == plen) return true;
			}

			// 属于.情况
			if (status == 3) {
				if (start == slen && n + 1 == plen) return true;
				if (start == slen && n + 1 != plen) return false;
				start++;
			}
		}
		return false;
	}

	int isType(int n) {
		// 大写字母
		if (n >= 65 && n <= 90) {
			return 1;
		}
		// 小写字母
		if (n >= 97 && n <= 122) {
			return 1;
		}
		// *类型
		if (n == 42) {
			return 2;
		}
		// .类型
		if (n == 46) {
			return 3;
		}

		return 0;
	}

	// 遇到*遍历所有相同字母，返回不相同的位置
	int boolEnd(string s, int start, int len , char p) {
		while (len != start + 1) {
			if (s[start] != p) {
				return start;
			}
			start++;
		}
		return start;
	}
};
**/