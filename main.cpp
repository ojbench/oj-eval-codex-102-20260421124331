#include <bits/stdc++.h>
using namespace std;

static inline int ch2val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return 10 + (c - 'A');
    if (c >= 'a' && c <= 'z') return 10 + (c - 'a');
    return 0; // input guarantees alnum only
}

static inline char val2ch(int v) {
    if (v < 10) return char('0' + v);
    return char('A' + (v - 10));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, B;
    if (!(cin >> m >> n >> B)) return 0;
    string s1, s2;
    s1.reserve(max(0, m - 1));
    s2.reserve(max(0, n - 1));
    cin >> s1 >> s2;

    int len1 = (int)s1.size();
    int len2 = (int)s2.size();
    int W = max(len1, len2);

    string out;
    out.resize(W);

    int carry = 0;
    for (int i = 0; i < W; ++i) {
        int d1 = 0, d2 = 0;
        if (i < len1) d1 = ch2val(s1[len1 - 1 - i]);
        if (i < len2) d2 = ch2val(s2[len2 - 1 - i]);
        int sum = d1 + d2 + carry;
        int digit = sum % B;
        carry = sum / B;
        out[W - 1 - i] = val2ch(digit);
    }

    // Fixed width: ignore any remaining carry beyond W digits
    // Ensure uppercase output
    for (char &c : out) c = (char)toupper((unsigned char)c);

    cout << out << '\n';
    return 0;
}

