# 🟢 Exercise 06: ft_list_clear

## 📝 Objective
Create the function `ft_list_clear`, which removes and frees all links from the list. The `free_fct` is used to free each data payload.

## 💡 The Logic
This is a critical memory management function designed to prevent leaks.
1. **Saving the Path:** Before freeing a node, we absolutely must save its `next` pointer into a temporary variable. If we free the node first, we lose the address to the rest of the chain!
2. **Deep Freeing:** We apply `free_fct` to `begin_list->data` to ensure any dynamically allocated strings/structs inside the node are cleaned up.
3. **Node Destruction:** We call `free()` on the node itself, then move our current pointer to the saved `next` node to continue the wipe.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_clear.c`](ft_list_clear.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX06` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX06 ../tester.c ft_list_clear.c -o test_ex06
   ./test_ex06
   ```
