#include<bits/stdc++.h>
using namespace std;

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

int palindromPartitioning(string str, int start, int end){
    if(start == end){
        return 0;
    }

    if(isPalindrome(str, start, end)){
        return 0;
    }

    int ans = INT_MAX;

    for(int k = start;k<end;k++){
        int left = palindromPartitioning(str, start, k);
        int right = palindromPartitioning(str, k + 1, end);
        int result = 1 + left + right;

        ans = min(ans, result);
    }

    return ans;
}

int main(){
    string str = "abbac";
    int start = 0;
    int end = str.length() - 1;
    int result = palindromPartitioning(str, start, end);
    cout<<result<<endl;
    return 0;
}