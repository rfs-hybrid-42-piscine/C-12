# 🟢 Exercise 08: ft_list_reverse

## 📝 Objective
Create the function `ft_list_reverse`, which reverses the order of a list's elements. The value of each element must remain the same.

## 💡 The Logic
This requires highly precise pointer gymnastics to invert the chain in-place.
1. **Three Pointers:** We need `prev` (initialized to `NULL`), `curr` (the current node), and `next` (to save our forward path).
2. **Inversion:** Inside the loop, we immediately save `curr->next` so we don't lose the list. Then, we flip the pointer backwards: `curr->next = prev`.
3. **Advancement:** We shift both `prev` and `curr` one step forward. Once `curr` hits `NULL`, the `prev` pointer will be sitting on the new head of the reversed list, which we assign back to `*begin_list`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_list_reverse.c`](ft_list_reverse.c)**

2. **Testing:**
   > **⚠️ Note for ex08:** The subject explicitly forbids turning in `ft_list.h` for this directory. Therefore, to compile the test from this folder, we must temporarily point the compiler to the header file residing in `ex00`.
   
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX08` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I ../ex00 -D EX08 ../tester.c ft_list_reverse.c -o test_ex08
   ./test_ex08
   ```
