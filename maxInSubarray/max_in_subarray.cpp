/*

This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.

*/

#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>


void max_in_sub_array(int k, int length, int arr[]);

//pre condition: k<size of array
void max_in_sub_array(int k, int length, int arr[])
{
    for(int i=0; i< length - k +1; i++){ // simple off by one error
        int max = arr[i];
        for(int j=0; j<k; j++){
            if(arr[j+i]> max){
                max = arr[j+i];
            }
        }
        std::cout<< max << std::endl;
    }
    return;
}


int main(void)
{
    int size = 6;
    int arr[6] = {10,5,2,7,8,7};
    max_in_sub_array(3, size, arr);


    return 0;
}
