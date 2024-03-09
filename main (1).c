//JUAN DE DIOS NUNEZ COP 3502C - LAB ASSIGNMENT 7
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr,int *arr2, int n);
void selectionSort(int *arr,int *arr2, int n);

int main(void) {
  int arr1BBSort[] = {97,16,45,63,13,22,7,58,72}; //initializing arrays
  int arr2BBSort[] = {90,80,70,60,50,40,30,20,10};
  int arr1SSort[] = {97,16,45,63,13,22,7,58,72};
  int arr2SSort[] = {90,80,70,60,50,40,30,20,10};
  int swapsBBsort[100] ={0}; //these are the arrays that will contain how many times a number has been swapped
  int swaps2BBsort[100]={0};
  int swapsSSort[100] ={0};
  int swaps2SSort[100]={0};
  int length = 9;
  printf("Bubble sort:\n");
  printf("array1:\n");
  bubbleSort(arr1BBSort,swapsBBsort,length);
  printf("array2:\n");
  bubbleSort(arr2BBSort,swaps2BBsort,length);
  printf("\n\nSelection sort:\n");
  printf("array1:\n");
  selectionSort(arr1SSort,swapsSSort,length);
  printf("array2:\n");
  selectionSort(arr2SSort,swaps2SSort, length);

}
void bubbleSort(int *arr,int *arr2, int n){ //creating bubble sort function
  int i, j, temp;
  for(i=0;i<n;i++) {
    for(j=0;j<n-1;j++) {
      if(arr[j]>arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        arr2[arr[j+1]]++; // adding one swap to the counter of j+1 since j+1 moved to arr[j]
        arr2[arr[j]]++;   //adding one swap to the counter of j since j moved to arr[j+1]
        arr2[0]++;
      }
    }
  }
    for(int i=0;i<9;i++){
      printf("%d:swapped %d times\n",arr[i],arr2[arr[i]]);
    }
  printf("Total number of swaps: %d\n" ,arr2[0]);
}

void selectionSort(int *arr,int *arr2, int n){ //creating Selection sort Function
  int temp, min_id;
  for (int i=0;i<n-1;i++){
    min_id = i;
    for (int j=i+1;j<n;j++){
      if (arr[j]<arr[min_id]){
        min_id = j;
      }
    }
    if (min_id != i){
      temp = arr[i];
      arr[i] = arr[min_id];
      arr[min_id] = temp;
      arr2[arr[i]]++; //adding one swap to the counter arr[i] since arr[i] swapped to arr[min_id]
      arr2[arr[min_id]]++; //adding one swap to the counter of arr[min_id] since it swapped with arr[i]
      arr2[0]++;
    }
  }
  for(int i=0;i<9;i++){
    printf("%d:swapped %d times\n",arr[i],arr2[arr[i]]);
  }
  printf("Total number of swaps: %d\n" ,arr2[0]);
}
