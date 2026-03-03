# 🟢 Exercise 04: ft_list_push_back

## 📝 Objective
Create the function `ft_list_push_back`, which adds a new element of `t_list` type at the end of the list.

## 💡 The Logic
This combines node creation with tail-finding logic.
1. **Instantiation:** We use `ft_create_elem` to spawn the new node and assign the `data` to the given argument.
2. **Empty List Exception:** If the pointer at the beginning of the list is empty, we update it to point directly to our new node.
3. **Appending:** If the list already exists, we traverse it until `curr->next` is `NULL` (finding the tail), and then simply attach our new node to the tail's `next` pointer.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_push_back.c`](ft_list_push_back.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX04` flag to the compiler to selectively activate the test for this specific exercise! Because this function requires node creation, you must compile it alongside `ft_create_elem.c`!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX04 ../tester.c ft_list_push_back.c ../ex00/ft_create_elem.c -o test_ex04
   ./test_ex04
   ```
