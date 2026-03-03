# 🟢 Exercise 10: ft_list_foreach_if

## 📝 Objective
Create the function `ft_list_foreach_if`, which applies the function given as an argument to some of the list's elements, specifically when `cmp` with `data_ref` returns 0.

## 💡 The Logic
This combines the iterator pattern with a conditional dispatch.
1. **Validation:** We ensure neither `f` nor `cmp` are `NULL`.
2. **Evaluation:** During our traversal, we evaluate the current node's data against the reference: `cmp(begin_list->data, data_ref)`. 
3. **Conditional Execution:** If `cmp` evaluates to `0` (meaning a match), we execute `f(begin_list->data)`. If it does not equal `0`, we simply skip the execution and advance to the next node.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_foreach_if.c`](ft_list_foreach_if.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX10` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX10 ../tester.c ft_list_foreach_if.c -o test_ex10
   ./test_ex10
   ```
