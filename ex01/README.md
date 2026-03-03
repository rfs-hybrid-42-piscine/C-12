# 🟢 Exercise 01: ft_list_push_front

## 📝 Objective
Create the function `ft_list_push_front`, which adds a new element of type `t_list` to the beginning of the list.

## 💡 The Logic
This exercise introduces pointer rerouting to insert data at the head of a chain.
1. **Instantiation:** We call our `ft_create_elem` function to build a new node, which automatically assigns the `data` to the given argument.
2. **Linking:** We take the new node's `next` pointer and aim it at the current first element of the list (`*begin_list`).
3. **Updating the Head:** We overwrite the `*begin_list` pointer with the memory address of our new node, officially making it the new start of the list.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_push_front.c`](ft_list_push_front.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX01` flag to the compiler to selectively activate the test for this specific exercise! Because this function requires node creation, you must compile it alongside **[`ft_create_elem.c`](../ex00/ft_create_elem.c)**!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX01 ../tester.c ft_list_push_front.c ../ex00/ft_create_elem.c -o test_ex01
   ./test_ex01
   ```
