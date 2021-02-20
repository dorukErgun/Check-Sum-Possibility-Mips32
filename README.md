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

```mips32
.data 
	#int arr[100]; 
	arr: .space 400 #Since we want our array to be sized at most 100
	possible: .asciiz "Possible!"
	not_possible: .asciiz "Not possible!"
	give_array_size: .asciiz "Give array size:"
	give_target_number: .asciiz "Give target number:"
	give_number: .asciiz "Give number:"

.text
.globl main

main:	
	## cout << "Give array size:"
	li $v0, 4
	la $a0, give_array_size
	syscall

	## cin >> arraySize; 
	li $v0, 5 # load syscall read_int into $v0.
	syscall # make the syscall.
	move $a3, $v0 # move the arraySize to $a3

	## cout << "Give target number:"
	li $v0, 4
	la $a0, give_target_number
	syscall

	## cin >> num; 
	li $v0, 5 # load syscall read_int into $v0.
	syscall # make the syscall.
	move $a1, $v0 # move the number read_int into $a1.

	## int arr[100];
	lw $a2, arr
			
	## for(int i = 0;
	li $t0, 0 
	
	Loop: 
		## i < arraySize;
    		beq $a3, $t0, next # branch next if eq 
    		## ++i
    		addi $t0, $t0, 1 # increment counter 
 
 		## cout << "Give number:"
		li $v0, 4
		la $a0, give_number
		syscall
 
    		## cin >> arr[i]; 		
    		li $v0, 5 # load syscall read_int into $v0.
    		syscall # make the syscall.
    		
    		## Fill the array
    		sw $v0, arr($t1)
    		addi $t1, $t1, 4

    		j Loop #jumps back to the top of loop 
    		
    	next: 
    	
    	## returnVal = CheckSumPossibility(num, arr, arraySize);
    	jal CheckSumPossibility
    	move $t4, $v0
	
	## if(returnVal == 1)
	bgtz $t4, possibleT
		## cout << "Not possible!" << endl;
		li $v0, 4
    		la $a0, not_possible
    		syscall
    		## return 0;
    		li $v0, 10 # System call code for exit
		syscall # Exit
    	
    	possibleT:
    		## cout << "Possible!" << endl;
		li $v0, 4
    		la $a0, possible
    		syscall
    		## return 0;
    		li $v0, 10 # System call code for exit
		syscall # Exit
    		
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

