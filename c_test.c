
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
  
  int binarySearch(int arr[], int l, int r, int x) 
{ 
	if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 

void randomArray( int arr[],int inputSize){
	int i =0;
	for (i=0;i<inputSize;i++)
	{
		arr[i] = rand()%200;
	}
}
int main() 
{ 
    //int arr[] = { 2, 3, 4, 10, 40 };
	int inputSize, result;
	printf("what is input size?: ");
	scanf("%d", &inputSize);
	
	int arr[inputSize];
	randomArray(arr,inputSize);
	bool  cont = true;
    int i = 0;
    clock_t t;
	clock_t end;
    double temp;
    double time_taken;
    
    double start, done;
    
     
    for(i=0;i<inputSize;i++)
    	printf("%d \n", arr[i]);
    int x = 0;
    int n = sizeof(arr) / sizeof(arr[0]); 
    

	while (cont)
	{
		printf("What number would you like to search?");
		scanf("%d", &x);
    
    	if (x == 700000000)
    		cont = false;
		else
		{ 
    	t = clock();
    	
    	int result = search(arr, inputSize, x);
    	
		end = clock(); 
		
		start = (double) t;
		done = (double) end;
		
		temp = done - start;
		
		printf("\n\n++++++++++++ \n\n%lf %lf\n\n", start, done);
    	
		time_taken = temp/CLOCKS_PER_SEC; // in seconds 
  
 		printf("search (linear): %lf seconds\n", time_taken);
    	(result == -1) ? printf("Element is not present in array") 
          	         : printf("Element is present at index %d", 
                            result); 
                            
    	printf("\n\n");
    	
    	t = clock(); 
    	int result2 = binarySearch(arr, 0, n - 1, x); 
		end = clock();
		
		start = (double) t;
		done = (double) end;
		
		temp = done - start;
		
		printf("\n\n++++++++++++ \n\n%lf %lf\n\n", start, done);
    	
		time_taken = temp/CLOCKS_PER_SEC; // in seconds 
  
 		printf("search (binary): %lf seconds\n", time_taken);
    	
    	(result2 == -1) ? printf("Element is not present"
							" in array") 
					: printf("Element is present at "
							"index %d", 
							result); 
	
   		printf("\n\n");
    
		 } 
	}
	return 0; 
} 
