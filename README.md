# Check Sum Possibility with MIPS32

  Functions respectively gets the target number, the array and the size of the array. It returns 1 if a subset of the array can sum up to the target number and otherwise if it is not possible, it outputs a 0. Recursive backtracking algorithm used for implementation. The sample output for six sample runs with 8 element array examples is as shown below. 
  
| Array Size | Target Number | Array Elements | Output |
| --- | --- | --- | --- |
| 8 | 129 | 41 67 34 0 69 24 78 58 | Not possible! |
| 8 | 129 | 62 64 5 45 81 27 61 91 | Not possible! |
| 8 | 129 | 95 42 27 36 91 4 2 53 | Possible! |
| 8 | 129 | 92 82 21 16 18 95 47 26 | Possible! |
| 8 | 129 | 71 38 69 12 67 99 35 94 | Possible! |
| 8 | 129 | 3 11 22 33 73 64 41 11 | Not possible! |


## C++ Implementation

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

## MIPS32 Implementation

```assembly
## int CheckSumPossibility(int num, int arr[], int size)
CheckSumPossibility:

	## if (num == 0)
	beq $a1, $zero, numIsZero
	## if (size == 0)
	beq $a3, $zero, sizeIsZero

	## Adjust stack
	addi $sp, $sp, -16 #adjust stack for 4 items
	sw $ra, 0($sp) #save $ra
	sw $a1, 4($sp) #save argument num
	sw $a3, 8($sp) #save argument size
	
	addi $a3, $a3, -1 # size - 1 
	## CheckSumPossibility(num, arr, size - 1);
	jal CheckSumPossibility
	
	lw $a1, 4($sp) # load argument num
	lw $a3, 8($sp) # load argument size
	sw $v0, 12($sp) # save last returned value
	
	addi $a3, $a3, -1 # size - 1
   
   	# get the last element of the array arr[size - 1]
	move $s1, $a3
	mul $s1, $s1, 2
	mul $s1, $s1, 2
	lw $s0, arr($s1)

    	sub $a1, $a1, $s0 # num - arr[size - 1]
    	## CheckSumPossibility(num - arr[size - 1], arr, size - 1);
    	jal CheckSumPossibility
    	lw $t4, 12($sp)
    	
    	## return x || y;
    	or $v0, $t4, $v0
    	lw $ra, 0($sp)
    	add $sp, $sp, 16
    	jr $ra
	
	numIsZero:
	## return true;
	li $v0, 1
	jr $ra
	 
	sizeIsZero:
	## return false;
	li $v0, 0
	jr $ra

```

