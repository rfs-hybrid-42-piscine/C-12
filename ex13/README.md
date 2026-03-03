# 🟢 Exercise 13: ft_list_merge

## 📝 Objective
Create the function `ft_list_merge` which places elements of a list `begin2` at the end of another list `begin1`. Element creation is not authorised.

## 💡 The Logic
This concatenates two chains together by linking the tail of one to the head of the other.
1. **Empty List Safeguards:** If `begin1` itself is `NULL`, we do nothing. If `*begin1` is `NULL` (meaning the first list is empty), we simply set `*begin1 = begin2` and return.
2. **Finding the Tail:** We create a `curr` pointer and traverse the first list until `curr->next == NULL`.
3. **The Splice:** We assign `curr->next = begin2`. The two lists are now permanently merged into one contiguous chain.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_merge.c`](ft_list_merge.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX13` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX13 ../tester.c ft_list_merge.c -o test_ex13
   ./test_ex13
   ```
