#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    if (n <= 1) {
        return s;
    }

    int start = 0, maxLength = 1;
    bool table[1000][1000] = {false};

    for (int i = 0; i < n; i++) {
        table[i][i] = true;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            if (len == 2 && s[i] == s[j]) {
                table[i][j] = true;
                start = i;
                maxLength = len;
            } else if (s[i] == s[j] && table[i + 1][j - 1]) {
                table[i][j] = true;
                start = i;
                maxLength = len;
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
