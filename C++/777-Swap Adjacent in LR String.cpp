/**
 In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.
 * **/
static const auto io_speed_up = [] {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    bool canTransform(string start, string end)
    {
        int len1 = start.size();
        int len2 = end.size();
        if (len1 != len2)
            return false;
        if (start == end)
            return true;
        vector<int> result(6, 0);
        for (auto c : start)
            result[4] += c == 'X';
        for (auto c : end)
            result[5] += c == 'X';
        if (result[4] != result[5] || result[4] == 0 || result[5] == 0)
            return false;
        for (int i = 0; i < len1; i++)
        {
            result[0] += start[i] == 'L';
            result[1] += end[i] == 'L';
            result[2] += start[i] == 'R';
            result[3] += end[i] == 'R';
            if (result[0] > result[1] || result[2] < result[3])
                return false;
        }
        return true;
    }
};