
// C++ code to linearly search x in arr[]. If x 
// is present then return its location, otherwise 
// return -1 
  
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>  

int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
void randomArray( int arr[],int inputSize){
	int i =0;
	for (i=0;i<inputSize;i++)
	{
		arr[i] = i;
	}
}
int main(void) 
{ 
    //int arr[] = { 2, 3, 4, 10, 40 };
	int inputSize;
	printf("what is input size?: ");
	scanf("%d", &inputSize);
	int arr[inputSize];
	randomArray(arr,inputSize);
	int i=0;
	for(i=0;i<inputSize;i++)
		printf("%d \n", arr[i]);
	bool  cont = true;
    
    int x = 0;
    int n = sizeof(arr) / sizeof(arr[0]); 
    

	while (cont)
	{
		printf("What number would you like to search?");
		scanf("%d", &x);
    
    	if (x == 70000)
    		cont = false;
		else
		{
			clock_t t; 
    	t = clock(); 
    	int result = search(arr, n, x); 
    	t = clock() - t; 
    	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
 		printf("search: %f seconds\n", time_taken);
    	(result == -1) ? printf("Element is not present in array") 
          	         : printf("Element is present at index %d", 
                            result); 
                            
    	printf("\n");
   
		 } 
	}
	return 0; 
} 
