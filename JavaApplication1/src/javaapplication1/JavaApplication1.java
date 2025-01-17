package javaapplication1;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.concurrent.TimeUnit;

public class JavaApplication1 {

    public static int search(ArrayList<Integer> list, int x) 
{ 
    int n = list.size(); 
    for(int i = 0; i < n; i++) 
    { 
        if(list.get(i) == x) 
            return i; 
    } 
    return -1; 
} 
  public static int binarySearch(ArrayList<Integer> list, int x) 
    { 
        int l = 0, r = list.size() - 1; 
        while (l <= r) { 
            int m = l + (r - l) / 2; 
  
            // Check if x is present at mid 
            if (list.get(m) == x) 
                return m; 
  
            // If x greater, ignore left half 
            if (list.get(m) < x) 
                l = m + 1; 
  
            // If x is smaller, ignore right half 
            else
                r = m - 1; 
        } 
  
        // if we reach here, then element was 
        // not present 
        return -1; 
    }   
    
public static void main(String args[]) throws InterupptedException
{ 
    Scanner sc = new Scanner(System.in); // object for scanner
		System.out.print("Enter your No: ");
		int n = sc.nextInt();
     ArrayList<Integer> arrli = new ArrayList<Integer>(n); 
     
     Random rand = new Random();
     
     
     
     for (int i =0;i<n;i++){
         
         arrli.add(rand.nextInt(150));
         System.out.println(arrli.get(i));
     }
     
     for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arrli.get(j) > arrli.get(j+1)) 
                { 
                    // swap arr[j+1] and arr[i] 
                    int temp = arrli.get(j); 
                    arrli.set(j, arrli.get(j+1)); 
                    arrli.set(j+1, temp); 
                } 
     
     System.out.println("SORTED");
      for (int i =0;i<n;i++){
         System.out.println(arrli.get(i));
     }
    
     
  while (true)
  {
       Scanner sc2 = new Scanner(System.in); // object for scanner
		System.out.print("Enter your No to search: ");
		int x = sc2.nextInt();
		
	long startTime = System.nanoTime();
		
    int result = search(arrli, x);
    
    long endTime = System.nanoTime();
    
    long timeElapsed = endTime - startTime;
    
    long seconds = timeElapsed / 1000000000;
    
    System.out.println("Linear Search:");
    if(result == -1) 
        System.out.println("Element is not present in array"); 
    else
        System.out.println("Element is present at index " + result); 

    long startTime = System.nanoTime();
    
    int result2 = binarySearch(arrli, x);
    
    long endTime = System.nanoTime();
    
    long timeElapsed = endTime - startTime;
    
    long seconds = timeElapsed / 1000000000;
    
    System.out.println("Binary Search:");
        if (result2 == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at "
                               + "index " + result2);
  }
   } 
}
    

