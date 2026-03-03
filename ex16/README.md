# 🟢 Exercise 16: ft_sorted_list_insert

## 📝 Objective
Create the function `ft_sorted_list_insert` which creates a new element and inserts it into a list sorted so that it remains sorted in ascending order.

## 💡 The Logic
This requires dynamically evaluating sequence direction and injecting a node into the middle of a chain.
1. **Instantiation:** We use `ft_create_elem` to allocate the new node with the provided data.
2. **Finding the Slot:** We traverse the list with a `prev` and `curr` pointer, stopping when `cmp(curr->data, new->data) > 0` (meaning we've found a node larger than our new one).
3. **The Splice:** We point `new->next = curr`. If `prev` is `NULL` (meaning the new node is the smallest and should be at the front), we update `*begin_list`. Otherwise, we point `prev->next = new`, seamlessly splicing it into the sequence.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_sorted_list_insert.c`](ft_sorted_list_insert.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-12` directory. You must pass the `-D EX16` flag to the compiler to selectively activate the test for this specific exercise! Because this function requires node creation, you must compile it alongside `ft_create_elem.c`!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX16 ../tester.c ft_sorted_list_insert.c ../ex00/ft_create_elem.c -o test_ex16
   ./test_ex16
   ```
