/**
 * Problem link - https://leetcode.com/problems/implement-strstr/
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> computeLPS(string needle) {

    vector<int> lps (needle.length(), 0);

    int i = 1, len = 0;
    while(i < needle.length()) {
        if(needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        } else if (len > 0) {
            len = lps[len-1];
        } else {
            lps[i] = 0;
            i++;
        }
    }

    return lps;
}

int strStr(string haystack, string needle) {
    if (needle.length() == 0) return 0;

    vector <int> lps = computeLPS(needle);

    int i = 0, j = 0;
    while(i < haystack.length()) {
        if(needle[j] == haystack[i]) {
            i++;
            j++;
        }

        if(j == needle.length()) return i-j;

        if(i < haystack.length() && needle[j] != haystack[i]) {
            if(j > 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }

    return -1;
}

int main() {
    // Insert Your Code Here. Here are the steps to get started: 
    // Step-I: Define the input format using the examples from the problem description. 
    // Step-II: Parse input from standard in. 
    // Step-III: Write your algorithm to generate the required output. 
    // Note: In case of any issues use #feedback channel on Discord. 
    
    string haystack, needle;
    cin>>haystack;
    cin>>needle;

    int index = strStr(haystack, needle);
    cout<<index<<endl;

    return 0;
}
