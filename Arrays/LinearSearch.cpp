#include <iostream>
#include <vector>

using namespace std;

int search( vector<int>& arr, int x){

    for( int i = 0; i < arr.size(); i++)
        if( arr[i] == x)
            return i;
    return -1;
}

int main(){

    vector<int>  arr = {2, 5, 8, 13, 41};

    int x = 13;
    int number = search(arr, x);

    if( number == -1)
        cout <<  "Not founded";
    else    
        cout << "Number at Founded " << number;
    return 0;
}