#include <iostream>
#include <iomanip>
using namespace std;

const int MAXSIZE = 16;
static int values[MAXSIZE];
void initArray(int[], int);
void printArray(int[]);
// This initializes element arr[i] to val for each array element 
void initArray(int arr[], int val)
{
  for (int i = MAXSIZE; i >= 0; i--) //I got rid of i as a global variable and initilized it in this function.
    arr[i] = val;
  return;
}
// This prints the contents of the argument array, with each element printed as "index: value" on its own line
// For example, a 4-element array containing {10,11,12,13} would print as:
//   0: 10
//   1: 11
//   2: 12
//   3: 13     
void printArray(int arr[])
{
    for(int i = 0; i < MAXSIZE; i++){
        cout << setw(2) << i << ":" << setw(2) << arr[i] << endl; //Set width to 2.
    }
}//got rid of ; as functions do not have that at the end of them.
int main()
{
    int dummy;
    initArray(values,5);
    int *arr2 = NULL;
    arr2 = new int [MAXSIZE]; //I initilized the pointer as its own dynamic array. Before both arrays were altered together.
    for(int i = 0; i < MAXSIZE; i++){
    *(arr2 + i) = values[i];
    }
    values[0]=9;
    arr2[1]=8; 
    cout << "values is:" << endl;
    printArray(values);
    cout << endl << "arr2 is:" << endl;
    printArray(arr2);

    delete []arr2; //deleted the array as it is good practice.
    return 0;
}//got rid of the ; as functions do not have that at the end of them.

/* Running the code unedited led to the output being the same with only values 0-4 with a value other then 0. The both edits to the arrays happened to both of them. This is because arr2 points to the array and is not an array itself. Therefore to fix this program I made the pointer arr2 initialize as a dynamic array. */
