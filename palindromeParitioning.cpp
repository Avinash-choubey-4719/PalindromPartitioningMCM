#include<bits/stdc++.h>
using namespace std;

int t[1001][1001];

bool isPalindrome(string str, int start, int end){
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int min(int a, int b){
    return a<b?a:b;
}

int palindromePartitioning(string str, int start, int end){
    if(start == end){
        return 0;
    }

    if(isPalindrome(str, start, end)){
        return 0;
    }

    if(t[start][end] != -1){
        return t[start][end];
    }

    int ans = INT_MAX;
    int left;
    int right;

    for(int k = start;k<end;k++){
        if(t[start][k] == -1){
            left = palindromePartitioning(str, start, k);
            t[start][k] = left;
        }

        else{
            left = t[start][k];
        }

        if(t[k + 1][end] == -1){
            right = palindromePartitioning(str, k + 1, end);
            t[k + 1][end] = right;
        }

        else{
            right = t[k + 1][end];
        }

        int result = 1 + left + right;

        ans = min(ans, result);
    }

    return t[start][end] = ans;
}

int main(){

    memset(t, -1, sizeof(t));

    string str = "nitin";
    int start = 0;
    int end = str.length() - 1;
    int result = palindromePartitioning(str, start, end);
    cout<<result<<endl;
    return 0;
}