
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
	while (l <= r) { 
		int m = l + (r - l) / 2; 

		// Check if x is present at mid 
		if (arr[m] == x) 
			return m; 

		// If x greater, ignore left half 
		if (arr[m] < x) 
			l = m + 1; 

		// If x is smaller, ignore right half 
		else
			r = m - 1; 
	} 

	// if we reach here, then element was 
	// not present 
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
