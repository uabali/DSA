/* https://www.geeksforgeeks.org/find-second-largest-element-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int SecondLargest( vector<int> &arr){
  
  int size = arr.size();
  /*array size for 6*/
  /*2-5-16-51-4-1*/
  /*0-1-2-3-4-5*/

  sort( arr.begin() , arr.end());
  int i =0;
  for(i = size - 2 ; i >= 0 ; i--){
      if( arr[i] != arr[size - 1])
        return  arr[i];
  }
    return -1;
}

int main() {
    vector<int> arr = { 2, 5, 16, 51, 4, 1 };
    cout<<SecondLargest(arr);
    return 0;
}