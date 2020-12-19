package Array;
/*
  ***** PROGRAM TO LEFT ROTATE AN ARRAY WITH (D) UNIT *****
  
  Input Format
  size -> single integer in a line
  array element -> space separated integers in this line
  rotation count -> single integer in a line

  sample:
  8
  3 45 67 22 4 12 43 90
  5
*/

import java.io.*;

class ArrayRotationBlockSwapAlgo {
  public static void main(String args[]) throws Exception{
    BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
    String inputLine[];
    inputLine = input.readLine().trim().split(" ");
    Integer size = Integer.parseInt(inputLine[0]);

    inputLine = input.readLine().trim().split(" ");
    Integer arr[] = new Integer[size];
    for(int i = 0; i < size; i++) {
      arr[i] = Integer.parseInt(inputLine[i]);
    }

    inputLine = input.readLine().trim().split(" ");
    Integer d = Integer.parseInt(inputLine[0]);

    ArrayRotationBlockSwapAlgo algo = new ArrayRotationBlockSwapAlgo();
    algo.blockSwapRotaion(arr, 0, size - 1, d, size - d);
    algo.printArray(arr, size);
  }

  public void blockSwapRotaion(Integer arr[], Integer startIndex, Integer endIndex, Integer leftSize, Integer rightSize) {
    if (rightSize == leftSize) {
      swap(arr, startIndex, endIndex - leftSize + 1, leftSize);
      return;
    } else if (leftSize < rightSize) {
      swap(arr, startIndex, endIndex - leftSize + 1, leftSize);
      blockSwapRotaion(arr, startIndex, endIndex - leftSize, leftSize, rightSize - leftSize);
    } else {
      swap(arr, startIndex, endIndex - rightSize + 1,  rightSize);
      blockSwapRotaion(arr, startIndex + rightSize, endIndex, leftSize - rightSize, rightSize);
    }
  }

  public void swap(Integer arr[], Integer firstArrayIn, Integer secondArrayIn, Integer size) {
    Integer temp;
    for (int i = 0; i < size; i++) {
      temp = arr[firstArrayIn + i];
      arr[firstArrayIn + i] = arr[secondArrayIn + i];
      arr[secondArrayIn + i] = temp;      
    }
  }

  public void printArray(Integer arr[], Integer size) { 
    int i; 
    for(i = 0; i < size; i++) 
      System.out.print(arr[i] + " "); 
    System.out.println(); 
  }
}
