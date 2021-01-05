#include <stdio.h>
#define S 50


void
shift_element (int *arr, int i)
{
  int k = 0;
  int temp=*(arr+k);
  int temp2 = 0;
  for(k=0;k<i;k++){
      temp2=*(arr+k+1);
     *(arr+k+1)=temp;
     temp=temp2;
      
      
      
  }
 
}

void
insertion_sort (int *arr, int len)
{
  int temp = 0;
  for(int i=1;i<len;i++){
      int k =i;
      temp = *(arr+i);
      while(k>=0){
      if(*(arr+i)<*(arr+k-1))
      k--;
      else
      break;
  }
      
      shift_element (arr+k, i-k);
      *(arr+k)=temp;
}
}

int
main ()
{
    
  int arr[S];
  
  for (int j = 0; j < S; j++)
    {
      scanf ("%d", &arr[j]);
    }
   
  insertion_sort (arr, S);
   printf ("%d", *arr);
  for (int i = 1; i < S; i++)
    {
      printf (",%d", *(arr+i));
    }
  printf ("\n");
  return 0;
}
