# Check Sum Possibility with MIPS32

  Functions respectively gets the target number, the array and the size of the array. It returns 1 if a subset of the array can sum up to the target number and otherwise if it is not possible, it outputs a 0. The sample output for six sample runs with 8 element array examples is as shown below. The numbers in parenthesis (black text) are for showing the possibility. Blue text is user input, red text is program output. 8 is the array size, 129 is the target number:
  
| Array Size | Target Number | Array Elements | Output |
| --- | --- | --- |
| 8 | 129 | 41 67 34 0 69 24 78 58 | Not possible! |
| 8 | 129 | 62 64 5 45 81 27 61 91 | Not possible! |
| 8 | 129 | 95 42 27 36 91 4 2 53 | Possible! |
| 8 | 129 | 92 82 21 16 18 95 47 26 | Possible! |
| 8 | 129 | 71 38 69 12 67 99 35 94 | Possible! |
| 8 | 129 | 3 11 22 33 73 64 41 11 | Not possible! |


## C++ Implementation and Test Cases

```cpp
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
```

## MIPS32 Implementation and Test Cases

