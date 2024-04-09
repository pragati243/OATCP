# Patching Array

This repository contains a C++ implementation for solving the patching array problem. The problem involves finding the minimum number of patches required to make the array containing positive integers from 1 to n inclusive.

## Algorithm Overview

The algorithm follows these steps:

1. Define a function `fx` that takes a vector `nums` containing integers and an integer `n`.
2. Initialize variables `mx` and `ans` to 0.
3. Iterate through each element `num` in the `nums` vector:
   - While `num` is greater than `(mx + 1)`, increment `ans`, and update `mx` to `2 * mx + 1`.
     - If `mx` becomes greater than or equal to `n`, return `ans`.
   - Update `mx` by adding `num`.
     - If `mx` becomes greater than or equal to `n`, return `ans`.
4. If `mx` is still less than `n`, increment `ans` until `mx` becomes greater than or equal to `n`.
5. Return `ans` as the minimum number of patches required.

## Implementation Details

The implementation is done in C++ and consists of a single main function. Here are the key points:

- Read the input vector `nums` and the integer `n` from the input file `sample_input1.txt`.
- Call the function `fx` to find the minimum number of patches required.
- Output the result to the output file `sample_output1.txt`.

## Example

Suppose we have the following input:

```
Input:
1 3
6

```

Using the algorithm described above, the minimum number of patches required to make the array containing positive integers from 1 to 6 is 1.

## Conclusion

This algorithm efficiently solves the problem of finding the minimum number of patches required to make the array containing positive integers from 1 to n inclusive.