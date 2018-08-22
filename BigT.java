/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class BigT {
    
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		int s = 0;
		
		while(s < t) {
		    
		    int n = sc.nextInt();
		    int k = sc.nextInt();
		    int[] arr = new int[n];
		    
		    for(int i = 0; i < n; i++) {
		        arr[i] = sc.nextInt();
		    }
		    
		    for(int i = 0; i <= n - k; i++) {
		    	
		    	int max = arr[i];
		    	for(int j = i+1; j < i + k; j++) {
		    		
		    		if(max < arr[j])
		    			max = arr[j];
		    	}
		    	
		    	System.out.print(max+ " ");
		    }
		    
		    System.out.println();
		    s++;
		    
		} 
		
		
	}
}