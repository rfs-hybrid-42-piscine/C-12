# 🟢 Exercise 12: ft_list_remove_if

## 📝 Objective
Create the function `ft_list_remove_if` which removes from the list all elements whose data, when compared to `data_ref` using `cmp`, causes `cmp` to return 0. The data must be freed using `free_fct`.

## 💡 The Logic
This is arguably the most dangerous memory manipulation exercise in the Piscine. You must delete a node from the middle of a chain without breaking the links.
1. **Three Pointers:** We track `prev` (starts at `NULL`), `curr`, and `next`.
2. **Bridging the Gap:** If `curr` matches the condition, we must remove it. If `prev` is `NULL` (meaning `curr` is the head of the list), we update the head pointer to `next`. Otherwise, we bridge the gap by pointing `prev->next` directly to `next`, bypassing `curr` entirely.
3. **Destruction:** With `curr` safely isolated, we call `free_fct(curr->data)` and then `free(curr)`. We do *not* update `prev` here, because the `next` node has now slid into `curr`'s old position.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_remove_if.c`](ft_list_remove_if.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX11` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX12 ../tester.c ft_list_remove_if.c -o test_ex12
   ./test_ex12
   ```
