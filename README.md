
algorithm analysis university studies

# Algorithm Analysis

This repository contains various algorithm analyses and applications. Below, you will find the relevant algorithms and example applications under each section.

## Dynamic Programming

### Longest Common Subsequence Finder (longest_common_subsequence.py)

The **Longest Common Subsequence (LCS)** algorithm aims to find the longest subsequence common to two sequences. It is commonly used in text comparison and bioinformatics. The following application, created using PyQt5, computes the LCS of two input sequences and displays the step-by-step solution.

#### Algorithm Explanation

The LCS algorithm finds the longest common subsequence of two sequences using dynamic programming. It uses a `dp` (dynamic programming) table and a directions table to track the steps. The algorithm compares characters from both sequences, moving diagonally (↖) on a match, and up (↑) or left (←) otherwise.

#### Usage

Follow these steps to run the application:

1. Install the required dependencies:

    ```bash
    pip install PyQt5
    ```

2. Run the `longest_common_subsequence.py` script:

    ```bash
    python longest_common_subsequence.py
    ```

3. When the application opens, enter two sequences and click the "Compute LCS" button.

#### Screenshot
![LCS_finder](https://github.com/rukiyeberna/algorithm_analysis/assets/117301103/980467c3-c17a-4e07-b449-44ec4bbfa83a)



## Other Sections


## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

