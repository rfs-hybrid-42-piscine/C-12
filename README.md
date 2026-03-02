*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-piscine-artwork/main/assets/covers/cover-c12.png" alt="C 12 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 C 12: Linked Lists</h1>
  <p><i>Mastering dynamic data structures, non-contiguous memory, and advanced pointers.</i></p>
  
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette badge" />
</div>

---

## 💡 Description
**C 12** introduces one of the most fundamental data structures in computer science: **The Linked List**.

Up until now, you have worked with arrays, which require memory to be allocated in one continuous, fixed-size block. Linked lists solve this limitation. Every "element" (or node) in a linked list is dynamically allocated anywhere in memory, storing its own data and a pointer to the `next` element. You will learn how to create, traverse, modify, and sort these complex chains of memory without losing track of your pointers and causing segmentation faults!

Every single exercise in this module relies on the custom `t_list` structure defined in your `ft_list.h` file:
```c
typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}                   t_list;
```

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise. It focuses on the fundamental logic of C programming, emphasizing manual memory manipulation and edge-case management.*

### 🔹 List Creation & Navigation
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: ft_create_elem`](ex00)** | **Node Instantiation:** Creating the building blocks of a linked list. <br><br>**Logic:** Uses `malloc` to allocate memory for a single `t_list` struct. Assigns the `void *data` argument to the node's data field, and safely initializes `next` to `NULL` to signify it is an unlinked node. |
| **[`ex01: ft_list_push_front`](ex01)** | **Prepending:** Adding an element to the start of the list. <br><br>**Logic:** Calls `ft_create_elem` to make a new node. Sets the new node's `next` pointer to the current `begin_list`, and then updates the `begin_list` pointer to make the new node the head. |
| **[`ex02: ft_list_size`](ex02)** | **Iteration:** Counting the total number of nodes. <br><br>**Logic:** Initializes a counter. Uses a temporary pointer to traverse the list (`current = current->next`) until it hits `NULL`, incrementing the counter at each step. |
| **[`ex03: ft_list_last`](ex03)** | **Finding the Tail:** Retrieving the final node in the chain. <br><br>**Logic:** Traverses the list, stopping specifically when `current->next == NULL` rather than when `current` itself is `NULL`, returning the node. |
| **[`ex04: ft_list_push_back`](ex04)** | **Appending:** Adding an element to the absolute end of the list. <br><br>**Logic:** Uses `ft_list_last` logic to find the tail node, then simply attaches a newly created `ft_create_elem` node to the tail's `next` pointer. |
| **[`ex05: ft_list_push_strs`](ex05)** | **Array to List:** Converting an array of strings into a linked list. <br><br>**Logic:** Iterates through the provided `strs` array. Since the subject states the first element of the array must be at the *end* of the list, we iterate from `0` to `size` and continuously use `ft_list_push_front`, automatically pushing `strs[0]` to the very back. |

### 🔍 Data Extraction & Memory Management
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex06: ft_list_clear`](ex06)** | **Memory Destruction:** Safely deleting an entire list. <br><br>**Logic:** Traverses the list. For each node, it must first execute `free_fct(current->data)` to free the payload, then save `current->next` into a temporary variable, and finally `free(current)` before moving to the saved next node. |
| **[`ex07: ft_list_at`](ex07)** | **Index Retrieval:** Finding a node at a specific "index". <br><br>**Logic:** Traverses the list while maintaining a counter. If the counter reaches the `unsigned int nbr` parameter, it returns that node. If it hits `NULL` first, it returns `NULL`. |
| **[`ex08: ft_list_reverse`](ex08)** | **Pointer Inversion:** Reversing the chain strictly by modifying memory addresses. <br><br>**Logic:** Requires three pointers (`prev`, `current`, `next`). As it traverses, it points `current->next` backwards to `prev`, then shifts all three pointers one step forward. The data payloads remain completely untouched. |
| **[`ex09: ft_list_foreach`](ex09)** | **Mapping:** Applying a function to every payload. <br><br>**Logic:** Traverses the list and passes `current->data` to the `void (*f)(void *)` function pointer. |
| **[`ex10: ft_list_foreach_if`](ex10)** | **Conditional Mapping:** Applying a function only if a condition is met. <br><br>**Logic:** Traverses the list. Evaluates `cmp(current->data, data_ref)`. If it evaluates to `0`, it applies the `f` function pointer to the data. |
| **[`ex11: ft_list_find`](ex11)** | **Searching:** Returning the first node that matches a condition. <br><br>**Logic:** Traverses the list evaluating `cmp`. The moment it returns `0`, the function immediately returns that node's data and terminates. |

### 👑 Advanced Manipulation & Sorting
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex12: ft_list_remove_if`](ex12)** | **Targeted Destruction:** Removing and freeing specific nodes from the middle of a list. <br><br>**Logic:** Highly complex pointer manipulation. If `cmp == 0`, it must bridge the gap by linking the `previous` node directly to the `next` node, safely apply `free_fct` to the data, and `free` the isolated node without losing the chain. |
| **[`ex13: ft_list_merge`](ex13)** | **List Concatenation:** Attaching one list to another. <br><br>**Logic:** Traverses `begin_list1` to find its tail, then simply sets its `next` pointer to point to the head of `begin_list2`. |
| **[`ex14: ft_list_sort`](ex14)** | **List Sorting:** Reordering nodes in ascending order. <br><br>**Logic:** Because manipulating node pointers in a bubble sort is notoriously error-prone, a common approach is to traverse the list and strictly swap the `void *data` payloads between nodes if the `cmp` function returns `> 0`. |
| **[`ex15: ft_list_reverse_fun`](ex15)** | **Data Inversion:** Reversing a list by swapping payloads. <br><br>**Logic:** Unlike `ex08`, this function reverses the list by physically swapping the `data` values between nodes (e.g., swapping the head's data with the tail's data) without ever touching the `next` pointers. |
| **[`ex16: ft_sorted_list_insert`](ex16)** | **Ordered Insertion:** Adding a new node into an already sorted list. <br><br>**Logic:** Traverses the sorted list while evaluating `cmp`. Once it finds the precise spot where the new data is larger than `current` but smaller than `current->next`, it splices the new node into the chain. |
| **[`ex17: ft_sorted_list_merge`](ex17)** | **Zip Merging:** Combining two sorted lists into one continuously sorted list. <br><br>**Logic:** The most efficient way is to attach `begin_list2` to `begin_list1` using the logic from `ft_list_merge`, and then executing the sorting logic from `ft_list_sort` on the newly unified list. |

---

## 🛠️ Instructions

### 🧪 Compilation & Testing (The Master Test)
Unlike standard types, testing linked lists requires you to manually build chains of memory in a testing file.

To make testing incredibly easy while avoiding "undefined reference" linker errors, the **[`tester.c`](tester.c)** file in the root directory uses **C Preprocessor Macros** (`#ifdef`). This allows you to selectively compile and test only the exercises you want.

1. **Clone the repository:**
   You can clone this module directly, or pull the entire 42 Piscine parent repository which includes this module as a submodule.

   **Option A: Clone this module directly**
   ```bash
   git clone git@github.com:rfs-hybrid-42-piscine/C-12.git C-12
   cd C-12
   ```

   **Option B: Clone the parent repository (with submodules)**
   ```bash
   git clone --recurse-submodules git@github.com:rfs-hybrid/42-Piscine.git 42-Piscine
   cd 42-Piscine/C-12
   ```
   *(Note: The `--recurse-submodules` flag ensures all nested module repositories are populated immediately.)*

2. **Test a Single Exercise:**
   Pass the corresponding `-D EX**` flag to activate that specific test block inside **[`tester.c`](tester.c)**. Note that testing higher-level functions often requires compiling the lower-level creation functions alongside them!
   ```bash
   # Example for ex01 (requires ex00 to create the elements first):
   cc -Wall -Wextra -Werror -D EX01 tester.c ex00/ft_create_elem.c ex01/ft_list_push_front.c -o test_ex01
   ./test_ex01
   ```

3. **Test Multiple Exercises Together:**
   You can chain multiple `-D` flags to test several functions at once, provided you include all their `.c` files in the command.
   ```bash
   # Example for ex02 and ex04:
   cc -Wall -Wextra -Werror -D EX02 -D EX04 tester.c ex02/ft_list_size.c ex04/ft_list_push_back.c -o test_multiple
   ./test_multiple
   ```

5. **Test ALL Exercises at Once:**
   By passing the `-D TEST_ALL` master flag, you can activate the entire testing suite in one go!
   ```bash
   cc -Wall -Wextra -Werror -D TEST_ALL tester.c ex00/*.c ex01/*.c ex02/*.c ... -o test_all
   ./test_all
   ```

> **⚠️ WARNING for 42 Students:** Do not push **[`tester.c`](tester.c)** or any executable files to your final Moulinette repository! They are strictly for local testing purposes. Submitting unauthorized files will result in a 0.

### 🚨 The Norm
Moulinette relies on a program called `norminette` to check if your files comply with the Norm. Every single `.c` and `.h` file must pass. 

**The 42 Header:**
Before writing any code, every file must start with the standard 42 header. `norminette` will automatically fail any file missing this specific signature.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 04:11:30 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/02 04:11:31 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Run the following command before pushing:
```bash
norminette -R CheckForbiddenSourceHeader <file.c>
```

---

## 📚 Resources & References

* [GeeksforGeeks: Linked Lists in C](https://www.geeksforgeeks.org/data-structures/linked-list/) - Visualizations and explanations of linked list memory manipulation.
* [Computerphile: Linked Lists](https://www.youtube.com/watch?v=njTh_OwMljA) - Excellent conceptual breakdown of why lists are used over arrays.
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.
* [Official 42 Norminette Repository](https://github.com/42School/norminette) - The open-source linter enforcing the strict 42 coding standard.

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All C functions were built manually to strictly comply with the 42 Norm and deeply understand manual memory manipulation, enforcing the concept that learning is about developing the ability to find an answer, not just getting one directly.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students.
