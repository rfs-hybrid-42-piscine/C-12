# 🟢 Exercise 09: ft_list_foreach

## 📝 Objective
Create the function `ft_list_foreach`, which applies the function given as an argument to each of the list's elements.

## 💡 The Logic
This is the linked list equivalent of the `ft_foreach` array iterator from C 11.
1. **Validation:** We verify that the function pointer `f` is not `NULL` to prevent a crash.
2. **Traversal:** We establish a standard `while (begin_list)` loop to iterate through the entire chain.
3. **Execution:** For every node we land on, we pass its void payload directly into the function: `f(begin_list->data)`. We then move to the next node.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_foreach.c`](ft_list_foreach.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX09` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX09 ../tester.c ft_list_foreach.c -o test_ex09
   ./test_ex09
   ```
