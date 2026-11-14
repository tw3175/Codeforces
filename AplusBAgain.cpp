// test
// A. A+B Again?
// time limit per test1 second
// memory limit per test256 megabytes
// Given a two-digit positive integer n
// , find the sum of its digits.

// Input
// The first line contains an integer t
//  (1≤t≤90
// ) — the number of test cases.

// The only line of each test case contains a single two-digit positive integer n
//  (10≤n≤99
// ).

// Output
// For each test case, output a single integer — the sum of the digits of n
// .

// Example
// InputCopy
// 8
// 77
// 21
// 40
// 34
// 19
// 84
// 10
// 99
// OutputCopy
// 14
// 3
// 4
// 7
// 10
// 12
// 1
// 18

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans+=s[i]-'0';
        }
        cout<<ans<<endl;
    }
    return 0;
}