# 🟢 Exercise 17: ft_sorted_list_merge

## 📝 Objective
Create the function `ft_sorted_list_merge` which integrates the elements of a sorted list `begin2` into another sorted list `begin1`, so that `begin1` remains sorted by ascending order.

## 💡 The Logic
This is the ultimate test of pointer management. We use a highly elegant recursive "zip" algorithm to weave the two chains together.
1. **Base Cases:** If `begin1` is empty, we set it to `begin2`. 
2. **Comparison & Weaving:** We compare the heads of both lists. If the head of `begin2` is smaller, we detach it, slide it in front of `begin1`, and update the head pointer. 
3. **Recursion:** We then recursively call `ft_sorted_list_merge` on the `next` pointer, continuing to weave the smallest remaining node into the chain until both lists are perfectly zipped together without allocating any new memory.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_sorted_list_merge.c`](ft_sorted_list_merge.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX17` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX17 ../tester.c ft_sorted_list_merge.c -o test_ex17
   ./test_ex17
   ```
