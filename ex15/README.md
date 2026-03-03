# 🟢 Exercise 15: ft_list_reverse_fun

## 📝 Objective
Create the function `ft_list_reverse_fun` which reverses the order of the elements in the list.

## 💡 The Logic
Unlike `ex08` which reversed the list by flipping the `next` pointers, this exercise restricts us from doing so. We must reverse the list by swapping the `data` payloads.
1. **Size Calculation:** We use a static helper function to count the total nodes in the list.
2. **Halfway Iteration:** We only need to iterate through the first half of the list (`size / 2`). If we iterate through the whole list, we will reverse it, and then accidentally reverse it back to normal!
3. **Mirror Swapping:** For the element at index `i`, we traverse a temporary pointer to find its mirror at index `size - i - 1`. We then swap their void data payloads.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_reverse_fun.c`](ft_list_reverse_fun.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX15` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX15 ../tester.c ft_list_reverse_fun.c -o test_ex15
   ./test_ex15
   ```
