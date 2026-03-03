# 🟢 Exercise 11: ft_list_find

## 📝 Objective
Create the function `ft_list_find` which returns the address of the first element whose data, when compared to `data_ref` with `cmp`, causes `cmp` to return 0.

## 💡 The Logic
This acts as a dynamic search algorithm for a linked list.
1. **Traversal & Comparison:** We iterate through the chain, passing each node's data to the `cmp` function alongside `data_ref`.
2. **Early Return:** The moment `cmp` returns `0`, we have found our match. We immediately `return (begin_list)` to provide the address of that specific node and stop execution.
3. **Fallback:** If the entire `while` loop finishes without `cmp` ever returning `0`, we `return (NULL)` to signify the data does not exist in the list.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_find.c`](ft_list_find.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX11` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX11 ../tester.c ft_list_find.c -o test_ex11
   ./test_ex11
   ```
