// CS310 Project 1 Part 1
// File: image.c
// Name: Tien Phan
// Date: 09/19/2022
//Colaboration Declaration: assistance received from Sofia

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
  FILE *filename = fopen(argv[1],"r");//open file and assign pointer
  char type[2];
  int rows, cols;
  int max_value;

//check for file
  if (filename == NULL){
    printf("This %s is NULL\n", argv[1]);
  }
  printf("it's working\n");

  fscanf(filename,"%s", type);
  fscanf(filename, "%d", &cols);
  fscanf(filename, "%d", &rows);
  fscanf(filename, "%d", &max_value);
  int arr[rows][cols];

  //Scan all the item in rows and cols
  for(int r = 0; r < rows; r++) {
    for(int c = 0; c < cols; c++) {
      fscanf(filename,"%d", &arr[r][c]);
    }
  }
  fclose(filename);


//Negative file
  FILE *filename_2 = fopen(argv[2], "w");

  if (filename_2 == NULL){
    printf("File not open\n");
  }

  fprintf(filename_2, "P2\n");
  fprintf(filename_2, "%d %d\n", cols, rows);
  fprintf(filename_2, "%d\n", max_value);

  for(int r_n = 0; r_n < rows; r_n++){
    for(int c_n = 0; c_n < cols; c_n++){
      fprintf(filename_2, "%d ", 255 - arr[r_n][c_n]); //Change the value
    }
  }
    fclose(filename_2);

//Rotation file

  FILE *filename_3 = fopen(argv[3], "w");
  if (filename_3 == NULL){
    printf("File not open\n");
  }

  fprintf(filename_3, "P2\n");
  fprintf(filename_3, "%d %d\n", rows, cols);
  fprintf(filename_3, "%d\n", max_value);

  for(int c_r = 0; c_r < cols; c_r++){  // start from cols
    for(int r_r = rows-1; r_r > -1; r_r--){  //each cols, go through rows from bottom up
      fprintf(filename_3,"%d ", arr[r_r][c_r]);
    }
  }

  fclose(filename_3);
}
