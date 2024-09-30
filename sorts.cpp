#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include <string.h>

#include "String.cpp"
#include "array.cpp"

void print_arr(int *arr, int count){
    printf("[");
    for (int i = 0; i < count; i++){
        printf("%d", arr[i]);
        if (i < count - 1){
            printf(",");
        }
    }
    
    printf("]\n");
}

void bubble_sort(int *arr, int count){
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
            if (arr[i] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

#define print_arr(arr, arr_count) for (int i = 0; i < arr_count; i++) \
                                  { \
                                      printf("%d", arr[i]); \
                                      if (i < arr_count - 1) printf(", "); \
                                  }
                                  
#define swap(arr, i, j) int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
                                
int partition(int *arr, int low, int high){
    int pivot = arr[low];
    
    int i = low - 1;
    int j = high + 1;
    
    while (1){
        do {i++;} while (arr[i] < pivot);
        do {j--;} while (arr[j] > pivot);
        
        if (i >= j) return j;
        
        swap(arr, i, j);
    }
}

void q_sort(int *arr, int low, int high){
    if (low < 0 || high < 0 || low >= high) return;
    
    int partition_index = partition(arr, low, high);
    q_sort(arr, low, partition_index);
    q_sort(arr, partition_index + 1, high);
}


void sort(int *arr, int arr_count){
    q_sort(arr, 0, arr_count - 1);
}

int main(){
    const int count = 10000;
    //int arr[count];
    
    // String str = String("[Aboba, chings] asdd");
    // char separators[] = {'[', ']', ',', ' '};
    // int separators_count = 4;
    
    // Array<String> splitted = split_str(str, separators, separators_count);
    
    // for (int i = 0; i < splitted.count; i++){
    //     printf("%s\n", splitted.get(i).line);
    // }
    
    // double a = 1;
    
    // int i = 0;
    
    // while (i < 100000){
    //     if (a <= 0){
    //         a = 1;
    //     }
    
    //     a *= 2;
    //     printf("i = %f: %d\n", i, a);
    //     i++;
    //}
    
    printf("NULL: %p\n", NULL);
}
