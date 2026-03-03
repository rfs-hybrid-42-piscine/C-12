# 🟢 Exercise 14: ft_list_sort

## 📝 Objective
Create the function `ft_list_sort` which sorts the list's elements in ascending order by comparing two elements and their data using a comparison function.

## 💡 The Logic
While we could sort by detaching and reattaching memory pointers, doing a "Bubble Sort" by swapping the data payloads is significantly safer and fully compliant.
1. **Nested Traversal:** We set up an outer loop tracked by `curr`, and an inner loop tracked by `tmp = curr->next`.
2. **Evaluation:** We pass both payloads to the function: `cmp(curr->data, tmp->data)`.
3. **Data Swapping:** If `cmp` returns a value `> 0` (meaning `curr` is larger and they are out of order), we use a temporary `void *swap` variable to physically trade the data pointers between the two nodes. The nodes themselves never move.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_sort.c`](ft_list_sort.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX14` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX14 ../tester.c ft_list_sort.c -o test_ex14
   ./test_ex14
   ```
