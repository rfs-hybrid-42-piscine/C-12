# 🟢 Exercise 03: ft_list_last

## 📝 Objective
Create the function `ft_list_last`, which returns the last element of the list.

## 💡 The Logic
This is slightly different from a standard iteration, as we must stop *on* the last node, rather than after it.
1. **Null Check:** If the list is empty, we immediately return `NULL`.
2. **Look-Ahead Traversal:** Instead of looping until the current node is `NULL`, we loop while `begin_list->next` exists. This guarantees that when the loop breaks, our pointer is sitting directly on the tail node.
3. **Return:** We return the pointer to this final node.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_last.c`](ft_list_last.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX03` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX03 ../tester.c ft_list_last.c -o test_ex03
   ./test_ex03
   ```
