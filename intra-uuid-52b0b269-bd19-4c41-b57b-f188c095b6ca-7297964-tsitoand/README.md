*This project has been created as part of the 42 curriculum by **tsitoand**, **haranivo**.*

# Push_swap
## Description

The **push_swap** project is a programming project at 42 that involves creating a sorting algorithm to efficiently sort a stack of integers. The challenge requires participants to implement the algorithm using only two stacks and a limited set of operations.

The main goal is to sort the numbers with the least number of moves, testing both algorithmic efficiency and the programmer's ability to optimize the solution. The project focuses on understanding algorithms, data structures, and efficient problem-solving techniques.

Key features:
- Adaptive algorithm selection based on input disorder (inversion ratio).
- Multiple sorting strategies: insertion (O(n²)), range (O(n√n)), radix (O(n log n)).
- Custom libft and ft_printf libraries.
- Benchmarking with `--bench` flag (disorder %, ops counts).
- Hardcoded optima for small inputs (2, 3 and 5 elements).

This project was led by a pair of students at Antananarivo to improve peer-to-peer and teamwork skills.

### Operations
| Operators  | Instruction  | Action                                      |
|------------|--------------|---------------------------------------------|
| `sa`       | *swap inside stack a* | Switch the first two elements of stack A.     |
| `sb`       | *swap inside stack b*         | Switch the first two elements of stack B.     |
| `ss`       | `sa` + `sb` | Perform `sa` and `sb` simultaneously.       |
| `pa`       | *push to a* | Push the first element from stack B to stack A. |
| `pb`       | *push to b* | Push the first element from stack A to stack B. |
| `ra`       | *rotate in a* | Rotate stack A (shift all elements down).   |
| `rb`       | *rotate in b* | Rotate stack B.                             |
| `rr`       | `ra` + `rb` | Perform `ra` and `rb` simultaneously.       |
| `rra`      | *reverse rotate in a* | Reverse rotate stack A (shift all elements up). |
| `rrb`      | *reverse rotate in b* | Reverse rotate stack B.                     |
| `rrr`      | `rra` + `rrb` | Perform `rra` and `rrb` simultaneously.     |


## Instructions

### Compilation
```
make
```

### Usage
```
./push_swap [integers...] [optional flags]

./push_swap [optional flags] [integers...]

./push_swap   [integers...] [optinal flags] [integers...]
```

- **Integers**: Space-separated, any order/range.
- Outputs sequence of operations to stdout; sorts stack A if valid.

**Examples**:
```
$ ./push_swap 2 1 3
pb
ra
pa
```

**Flags**:
| Flag | Effect |
|------|--------|
| `--simple` | Insertion sort |
| `--medium` | Range/chunk sort |
| `--complex` | Radix sort |
| `--adaptive` | Auto-select by disorder (default) |
| `--bench` | Print stats post-sort |

Handles errors and returns "**Error\n**" in the following cases:

- Duplicate values
- Invalid integers
- Too many flags
## Algorithms

We implemented multiple algorithms, selected adaptively via \`compute_disorder\` (ratio of inversions to total pairs):

| Algorithm | Trigger | Complexity | Justification & Details |
|-----------|---------|------------|-------------------------|
| 2/3/5 elements | size≤5 | O(1) | Exhaustive optimal sequences. Manual sort. |
| Insertion | disorder <20% \| --simple | O(n²) | Rotate/push smallest to B, pa back. Efficient for nearly-sorted data. |
| Range | 20-50% \| --medium | O(n√n) | Divide into chunks (n/10 or n/30), pb ≤chunk via ra, pa max via rb/rrb. Balances rotations/pushes for medium disorder. |
| Radix | >50% \| --complex | O(n log n) | Index ranks, per bit (max_bits): pb if LSB=0 else ra; pa back. Stable, optimal for random/worst-case. |

**Adaptive (--adaptive/default)**: Thresholds ensure optimal complexity by adapting how the system behaves based on the input profile. It defines limits that help choose the most efficient approach, avoid unnecessary computation, and maintain good performance.

All use doubly-linked lists, exact ops only, move counters for benchmarking.

## Resources
- **Visualizer**: 
    - [YouTube tutorial](https://www.youtube.com/watch?v=wRvipSG4Mmk&t=1435s).
    - [Push swap visualizer](https://push-swap42-visualizer.vercel.app/) (website)
- **Slack**: *_cc_pushswap*
- **AI Usage**:
    - Helps better understand the project and its requirements
    - Assists in visualizing the algorithm
    - Helps find the best algorithm for the operators
    - Supports debugging using GDB
    - Structuring this README.md (sections, tables)

**Checkers**: External validators score moves efficiency.

---
**Author**: tsitoand & haranivo  
<center>
    Thanks for reading ME <3 <br>
    <b>2026-04-01</b>
</center>  