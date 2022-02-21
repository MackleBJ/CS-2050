/****************************
 * Author: Brett M.
 * Class: CS 2050
 * Semester: Spring 2022
 * Assignment: Lab 2
 * Date: 2/4/2022
 ***************************/

#include "lab2.h"

/* createIntArrayFromFile:
This function will take a file pointer, and an int pointer through which the resulting array size
will be passed back to the calling function. This function reads in the size and content of the array
from the given file pointer, and returns a pointer to the array on success or NULL on error.
*/

int * createIntArrayFromFile(FILE *file, int *size)
{
    int length;


    // Checks to see if we can read length from the file. 
    if(fscanf(file, "%d", &length) != 1) 
    {
        fclose(file);
        return NULL;
    }

    // Sets the value of size equal to the length found in the file. Thereby, allowing the
    // calling function to utilize the value. 
    *size = length;


    // Checks if the size of the requested array is 0 or less. 
    if(*size <= 0)
    {
        fclose(file);
        printf("The length of an array must be larger than 0.\n");
        return NULL;
    }

    // Allocates memory for an integer array so that we can copy the int values from file to array. 
    int * array = malloc((*size) * sizeof(int));


    // Checks to see if Malloc() failed to allocate memory for the array. 
    if(array == NULL)
    {
        fclose(file);
        printf("Malloc failed to allocate memory for the int array.\n");
        return NULL;  
    }

    // Iterates through the file and adds each int value to the int array. 
    for(int i = 0; i < *size; ++i) 
    {
        fscanf(file, "%d", array + i);
    }

    fclose(file);
    return array;
}

/*lastAddressOf:
This function will take an int array pointer and the size of the array, as well as an integer type
double pointer and a query integer to find in the array. It will look for the element in the array, and if
found, set the result pointer equal to the last address where it occurs in the array. The function will
return 0 if the element is found in the array, or 1 if not.
*/

int lastAddressOf(int *array, int size, int **result, int element)
{   
    // Default value is set to 1 so the element must be found to return a value of 0. 
    int isItFound = 1;


    // Checks to see if the array is NULL or if size is <= 0. 
    if(array == NULL || size <= 0)
    {
        return 1;
    }


    // Iterates through the array and looks for the element. If found it will override the 
    // value of isItFound to 0. Indicating that the query number (element) was found within the array. 
    for(int i = 0; i < size; i++)
    {
        if(array[i] == element)
        {
            // Sets the value of result to the address of the last location in the array that
            // the query number (element) was found. 
            *result = &array[i];
            isItFound = 0;
        }
    }


    return isItFound;
}

/*freeArray:
This function will take an array pointer, and free the memory allocated to the array.
*/

void freeArray(int * array)
{
    free(array);
}
