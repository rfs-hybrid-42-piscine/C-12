# 🟢 Exercise 05: ft_list_push_strs

## 📝 Objective
Create the function `ft_list_push_strs`, which creates a new list that includes all the strings pointed to by the elements in `strs`. The first element of the array must be at the end of the list.

## 💡 The Logic
This acts as an array-to-list converter with a specific ordering trick.
1. **Initial Node:** We create the very first node using `strs[0]`.
2. **Reverse Iteration Illusion:** We iterate through the rest of the array from index `1` to `size`. For each string, we create a node and push it to the *front* of our developing list (`new->next = list`). 
3. **The Result:** Because we continuously push new elements to the front, the very first element we created (`strs[0]`) gets naturally pushed to the absolute end of the list, perfectly fulfilling the subject's requirement!

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_push_strs.c`](ft_list_push_strs.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX05` flag to the compiler to selectively activate the test for this specific exercise! Because this function requires node creation, you must compile it alongside `ft_create_elem.c`!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX05 ../tester.c ft_list_push_strs.c ../ex00/ft_create_elem.c -o test_ex05
   ./test_ex05
   ```
