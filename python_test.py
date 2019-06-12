def linearsearch(arr, n, x): 
  
    for i in range (0, n): 
        if (arr[i] == x): 
            return i; 
    return -1; 

def binarySearch(arr, l, r, x): 
  
    while l <= r: 
  
        mid = l + (r - l)/2; 
          
        # Check if x is present at mid 
        if arr[mid] == x: 
            return mid 
  
        # If x is greater, ignore left half 
        elif arr[mid] < x: 
            l = mid + 1
  
        # If x is smaller, ignore right half 
        else: 
            r = mid - 1
      
    # If we reach here, then the element 
    # was not present 
    return -1  
# Driver Code 
arr = [ 2, 3, 4, 10, 40 ]; 
x = 140; 
n = len(arr); 
result = linearsearch(arr, n, x) 
if(result == -1): 
    print("Element is not present in array") 
else: 
    print("Element is present at index", result); 


# Function call 
result2 = binarySearch(arr, 0, len(arr)-1, x) 
  
if result2 != -1: 
    print ("Element is present at index % d" , result2 )
else: 
    print ("Element is not present in array")
