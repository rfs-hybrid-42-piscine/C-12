# 🟢 Exercise 02: ft_list_size

## 📝 Objective
Create the function `ft_list_size`, which returns the number of elements in the list.

## 💡 The Logic
This requires a standard linked list iteration algorithm.
1. **The Counter:** We initialize an integer size counter to 0.
2. **Traversal:** Using a `while (begin_list)` loop, we move down the chain by continuously assigning `begin_list = begin_list->next`.
3. **Evaluation:** For every valid node we land on before hitting `NULL`, we increment the counter, returning the final integer once the loop breaks.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_size.c`](ft_list_size.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX02` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX02 ../tester.c ft_list_size.c -o test_ex02
   ./test_ex02
   ```
