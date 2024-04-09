# Minimum Input

This repository contains a C++ implementation for solving a minimum input question. The problem involves finding the minimum possible number by removing k digits from a given number string.

## Algorithm Overview

The algorithm follows these steps:

1. Define a function `fx` that takes a string `s` representing the number and an integer `k` indicating the number of digits to remove.
2. Initialize a stack `st` to store the digits of the number.
3. Iterate through each digit of the input string:
   - Compare the current digit with the top of the stack. If the current digit is smaller than the top of the stack and there are still digits to remove (`k > 0`), remove digits from the stack until either the stack is empty, or the top of the stack is smaller than or equal to the current digit.
   - If the stack is empty and the current digit is '0', continue to the next digit.
   - Push the current digit onto the stack.
4. If there are still digits to remove after processing all digits, pop digits from the stack until `k` becomes 0.
5. If the stack is empty, return "0" since no digits remain after removal.
6. Otherwise, construct the minimum number string by popping digits from the stack and appending them to the result string.
7. Return the result string.

## Implementation Details

The implementation is done in C++ and consists of a single main function. Here are the key points:

- Read the input string `s` and the integer `k` from the input file `input2.txt`.
- Call the function `fx` to find the minimum possible number after removing `k` digits.
- Output the result string to the output file `output2.txt`.

## Example

Suppose we have the following input:

```
Input:
1432219
3

```

Using the algorithm described above, the minimum possible number after removing 3 digits is "1219".

## Conclusion

This algorithm efficiently solves the problem of finding the minimum possible number by removing a specified number of digits from a given number string.