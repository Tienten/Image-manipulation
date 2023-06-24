//CS310 Project 1 P2
//File: imagestack.c
//Name: Tien Phan
//Date: 09/25/2022

#include <stdio.h>
#include <stdlib.h>

int ind(int r, int c, int n, int n_cols, int n_mat){ //find value at index
   return r * n_cols * n_mat + c * n_mat + n;
 }

void sort(int* arr, int length) {  //sort function

  for(int i = 0; i < length-1; i++) {
    int min_index = i;
    for(int j = i+1; j < length; j++) {
       if(arr[j] < arr[min_index]) {
           min_index = j;
       }
    }
     int temp = arr[i];
     arr[i] = arr[min_index];
     arr[min_index] = temp;
  }
}



int main(int argc, char** argv){
  int n_rows, n_cols;
  int max_value;
  int n_mat = argc - 2 ;
  int *arr;
  FILE *infile1;
  //FILE *infile2;
  char type[3];
  infile1 = fopen(argv[1], "r");

  fscanf(infile1,"%s", type); //scan the first file to know the size for malloc
  fscanf(infile1, "%d", &n_cols);
  fscanf(infile1, "%d", &n_rows);
  fscanf(infile1, "%d", &max_value);
  arr = malloc(sizeof(int) * n_rows * n_cols * n_mat);  //dynamic allocation
  fclose(infile1);
  int i = 0;
  for(int n = 0; n<n_mat; n++){  // loop to open 9 files
    infile1 = fopen(argv[n+1], "r");

    fscanf(infile1,"%s", type);
    fscanf(infile1, "%d", &n_cols);
    fscanf(infile1, "%d", &n_rows);
    fscanf(infile1, "%d", &max_value);
    for(int r = 0; r < n_rows; r++) {   //loop to scan all the value and store into a 3D array
        for(int c = 0; c < n_cols; c++) {
          i = ind(r, c, n, n_cols, n_mat);
          fscanf(infile1, "%d", &arr[i]);
       }
    }
  }
    fclose(infile1);
   FILE *output = fopen(argv[argc-1], "w");
   fprintf(output, "P2\n");
   fprintf(output, "%d %d\n", n_cols, n_rows);
   fprintf(output, "%d\n", max_value);
     for(int r = 0; r < n_rows; r++) {  //loop tp get the value from the 3D array
       for(int c = 0; c < n_cols; c++) {
         int array[n_mat];  //create a new array to store value with the same position in each matrixes
         for(int n = 0; n<n_mat;n++){
           int i = ind(r, c, n, n_cols, n_mat);
           array[n] = arr[i];  // add to array
         }
        sort(array, n_mat);  //sort the array
        int m = array[n_mat/2];  //get the median value
        fprintf(output,"%d ",m); //put to output file
     }
   }
   fclose(output);
 }
