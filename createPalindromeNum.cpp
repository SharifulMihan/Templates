#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

// Palindrome Generator.
ll createPalindromeNum(ll n,bool isOddLength){
    ll palindrome = n;
    ll origin;
    if (isOddLength) origin = n/10;
    else origin = n;

    while(origin>0){
        palindrome = palindrome*10 + origin%10;
        origin /= 10;
    }
    return palindrome;
}

// Print Palindrome in ascending Order.
void printPalindromeAscendingOrder(ll n){
    int range = (log10(n)+1)*2 - 1;

    for (int i = 1; i <= range; i= 2*i + 1)
    {
        string binStr = bitset<8>(i).to_string();
        int binInt = stoi(binStr);
    
        if(binInt > n) break;
        for (int j = binInt-1; j <= binInt*9; ++j){
            ll pal = createPalindromeNum(j,true);
            if(pal > n) break;
            cout<<pal<<endl;   
        }
        for (int j = binInt-1; j <= binInt*9; ++j){
            ll pal = createPalindromeNum(j,false);
            if(pal > n) break;
            cout<<pal<<endl;
        }
    }
}

int main(){
    printPalindromeAscendingOrder(300);
}