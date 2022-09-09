import java.util.Scanner;


public class Algorithm_mergeSort {
    
    public boolean compare( int x, int y)
    {
        return (x>y);
    }

    public void print(int []arr, int size)
    {
        for(int i = 0; i < size ;i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }

    public void merge_array(int [] arr,int left,int middle,int right)
    {
        int n = middle - left + 1;
        int m = right - middle;

        int [] arrayA = new int [n];
        int [] arrayB = new int [m];

        //storing leftside sorted array in temp array
        for(int i = 0; i < n; i++)
            arrayA[i] = arr[left+i] ;

        //storing rightside sorted array in temp array
        for(int i = 0 ; i < m ; i++)
            arrayB[i] = arr[middle+1+i] ;

        //merging two temp arrays in a third one
        int i = 0, j= 0 , k = left;
        while(i < n && j < m)
        {
            if( compare (arrayA[i] , arrayB [j])) arr[k++] = arrayB[j++] ;
            else arr[k++] = arrayA[i++] ;
        }

        for(; i < n ; i++)
            arr[k++] = arrayA[i];
        for(; j < m; j++)
            arr[k++] = arrayB[j];
    }
    public void mergeSort(int []arr , int left , int right)
    {
        int middle = (left + right)/ 2;

        if(left < right) {
            mergeSort(arr, left, middle);
            mergeSort(arr, middle + 1, right);

            merge_array(arr, left, middle, right);
        }
    }

    public static void main(String []args)
    {
        Scanner scan = new Scanner(System.in);
        int n;
        n = scan.nextInt() ;

        int [] Array = new int[n];
        for( int i=0 ; i < n; i++) {
            Array[i] = scan.nextInt() ;
        }

        Algorithm_mergeSort object = new Algorithm_mergeSort() ;
        object.mergeSort(Array,0, n-1);
        object.print(Array , n);

    }
}
