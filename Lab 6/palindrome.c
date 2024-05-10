#include <stdio.h>

int palindrome(int arr[], int n){
    int i = 0;
    int j = n-1;
    while(i < j){
        if(arr[i] != arr[j]){
            return 0;
        }
        
        i++;
        j--;
    }
    return 1;
}


int main(){

    int arr[5] = {1, 2, 3, 2, 1};
    int n = 5;
    palindrome(arr, n);
}