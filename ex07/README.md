# 🟢 Exercise 07: ft_list_at

## 📝 Objective
Create the function `ft_list_at`, which returns the Nth element of the list, knowing that the first element of the list is when `nbr` equals 0.

## 💡 The Logic
This replicates standard array indexing (`arr[i]`) but for a linked list.
1. **Iteration:** We set up a `while` loop that increments an index counter `i`.
2. **Boundary Safety:** The loop runs as long as `i < nbr` and `begin_list` is not `NULL`.
3. **Return Value:** If the loop breaks naturally because `i == nbr`, we return the current node. If it breaks because `begin_list` hit `NULL` (meaning `nbr` was larger than the list itself), it safely returns a null pointer.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_at.c`](ft_list_at.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX07` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX07 ../tester.c ft_list_at.c -o test_ex07
   ./test_ex07
   ```
