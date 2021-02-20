# Check Sum Possibility with MIPS32

  Functions respectively gets the target number, the array and the size of the array. It returns 1 if a subset of the array can sum up to the target number and otherwise if it is not possible, it outputs a 0. The sample output for six sample runs with 8 element array examples is as shown below. The numbers in parenthesis (black text) are for showing the possibility. Blue text is user input, red text is program output. 8 is the array size, 129 is the target number:
  
| Command | Description | Description |
| --- | --- | --- |
| git status | List all new or modified files | List all new or modified files |
| git diff | Show file differences that haven't been staged | Show file differences that haven't been staged |


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

