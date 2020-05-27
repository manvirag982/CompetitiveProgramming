class Solution {
   public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if (n <= 1) return;
        for (int i = 0; i <= (n - 1) / 2; i++)
            swap(s[i], s[n - i - 1]);
    }
};