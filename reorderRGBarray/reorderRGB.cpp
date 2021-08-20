/*
[HARD]

This problem was asked by Google.

Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

*/


// first pass of the array is counting how many of each letter there is so we can calculate which index each letter is supposed to be in
// second pass is swapping the letters. We will keep track of the indexes where the letters are suppposed to be, according to the size of the array and the count of each letter that there is 

#pragma once
#include <cstdlib>
#include <cstdio>
#include <iostream>

int main(void)
{
    int countR=0;
    int countG=0;
    int countB=0;
    int size =7; // size of array

    char arr[7] = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};

    for(int i=0; i< size; i++)
    {
        if(arr[i] == 'R'){
            countR++;
        }
        else if(arr[i]== 'G'){
            countG++;
        }
        else if(arr[i]== 'B'){
            countB++;
        }
    }
    //std::cout <<"number of Rs: " << countR<< std::endl;
    //std::cout <<"number of Gs: " << countG<< std::endl;
    //std::cout <<"number of Bs: " << countB<< std::endl;

    int firstIndexR = 0;
    int firstIndexG = firstIndexR + countR; //0 + 3- will be fourth spot
    int firstIndexB = firstIndexG + countG;
    std::cout <<"index of Rs: " << firstIndexR<< std::endl;
    std::cout <<"index of Gs: " << firstIndexG<< std::endl;
    std::cout <<"index of Bs: " << firstIndexB<< std::endl;

    int indexR = firstIndexR;
    int indexG = firstIndexG;
    int indexB = firstIndexB;
    
    char temp = 0;

    for(int i=0; i< size; i++) //go through array and swap
    {
        switch(arr[i])
        {
            case 'R':
                if(i<firstIndexG) //the element is in the correct place
                {
                    //do nothing
                }
                else {//swap with element ar IndexR
                temp =  arr[indexR];
                arr[indexR] = arr[i];
                arr[i] = temp;

                indexR++;

                }

            break; //end case R
            case 'G':
                if(i >= firstIndexG && i< firstIndexB) //the element is in the correct place
                {
                    //do nothing
                }
                else {//swap with element ar firstIndexG
                    temp =  arr[indexG]; // the letter that shouldn't be there 
                    arr[indexG] = arr[i]; //put G at the right spot- indexG
                    arr[i] = temp;

                    indexG++;
 
                }
                break;

            case 'B':
                if(i >= firstIndexB) //must put the first index here because if it is just index then we might be on the very forst B or G and the index has moved ahead and it will make us swap even though it is in the correct spot
                {
                    //do nothing
                }
                else {//swap with element ar firstIndexR
                    temp =  arr[indexB];
                    arr[indexB] = arr[i];
                    arr[i] = temp;

                    indexB++;
                }
                break;
        } // end switch



    } // end for

    // print array to see if it worked
    for(int i=0; i<size; i++)
    {
        std::cout<<arr[i];
    }
    std::cout<< "\n" << std::endl;



    return 0;
}
