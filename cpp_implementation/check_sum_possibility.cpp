#include <iostream>

using namespace std;

int CheckSumPossibility(int num, int arr[], int size);

int main() { 

    int arraySize; 
    int arr[100]; 
    int num; 
    int returnVal; 
    
    cout << "Give array size:";
    cin >> arraySize; 
    cout << "Give target number:";
    cin >> num; 
    
    for(int i = 0; i < arraySize; ++i){ 
        cout << "Give number:";
        cin >> arr[i]; 
    } 
    
    returnVal = CheckSumPossibility(num, arr, arraySize); 
    if(returnVal == 1){ 
        cout << "Possible!" << endl; 
    } 
    else{ 
        cout << "Not possible!" << endl; 
    } 
    
    return 0; 
}

int CheckSumPossibility(int num, int arr[], int size){

    if (num == 0){
        return true;
    }
    if (size == 0){
        return false;
    }

    int x = CheckSumPossibility(num, arr, size - 1);

    int y = CheckSumPossibility(num - arr[size - 1], arr, size - 1);

    return x || y;

}
