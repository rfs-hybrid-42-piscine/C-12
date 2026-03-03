# 🟢 Exercise 00: ft_create_elem

## 📝 Objective
Create the function `ft_create_elem`, which creates a new element of `t_list` type.

## 💡 The Logic
This exercise establishes the foundational building block for all linked lists.
1. **Memory Allocation:** We use `malloc` to dynamically allocate enough memory for a single `t_list` structure.
2. **Initialization:** We assign the `data` pointer of the newly created struct to the argument provided.
3. **Safety:** We explicitly set the `next` pointer to `NULL` to signify that this node is currently unlinked and sits at the end of a chain.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_create_elem.c`](ft_create_elem.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX00` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX00 ../tester.c ft_create_elem.c -o test_ex00
   ./test_ex00
   ```
