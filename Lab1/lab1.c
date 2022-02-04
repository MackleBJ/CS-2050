/****************************
 * Author: Brett M.
 * Class: CS 2050
 * Semester: Spring 2022
 * Assignment: Lab 1
 * Date: 1/28/2022
 ***************************/

#include "lab1.h"

/* 
This function will take an integer array, an integer representing the size of the array, and a result
pointer. This function will calculate the average of all the elements in the array which are even, and
place the result in the result pointer. The function will return 0 on error, or the number of elements
averaged on success.
*/

int avgEven(int *array, int size, float *result)
{   
    // Returns 0 for error when there is nothing to read in the array or array is NULL.
    if(size == 0 || array == NULL)
    {
        return 0;
    }

    int counter = 0;
    int total = 0;

    // Iterates through the array. Counts and totals all the even numbers found. 
    for(int i = 0; i < size; i++)
    {
        if((array[i]%2) == 0)
        {
            counter++;
            total += array[i];
        }
    }
    
    // Returns 0 for error when there are no even numbers found. You can't divide by 0. 
    if(counter == 0)
    {
        return 0;
    }
    // Returns number of even integers and assigns 'result' to the average of all even numbers.
    else
    {
        *result = (total/counter);
        return counter;
    }

}
