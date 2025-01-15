#include <iostream>
using namespace std;

// ---------------------------- Brute Force ----------------------------

void bruteForceSearch(string text, string pattern)
{
    int n = text.length();    // Length of the text
    int m = pattern.length(); // Length of the pattern

    // Loop through the text to check all possible starting positions for pattern
    for (int i = 0; i <= n - m; i++) // i represents the starting index of the text window
    {
        int j = 0;

        // Compare pattern with the substring of text starting at index i
        while (j < m && text[i + j] == pattern[j])
        {
            j++; // If characters match, move to the next character
        }

        // If we have matched all characters of the pattern, we have found the pattern
        if (j == m) // Full match found
        {
            cout << "Pattern found at index " << i << endl; // Print the index where the pattern starts
        }
    }
}

// ---------------------------- Knuth–Morris–Pratt (KMP) ----------------------------

// Function to construct the LPS array (Longest Prefix Suffix) for the given pattern
void constructLps(string &pat, int *lps)
{
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // LPS[0] is always 0 as there's no proper prefix and suffix for a single character

    int i = 1;
    while (i < pat.length()) // Traverse through the pattern
    {
        // If characters match, increment the size of the LPS
        if (pat[i] == pat[len])
        {
            len++;        // Increase the length of the matching prefix-suffix
            lps[i] = len; // Store the value in the LPS array
            i++;          // Move to the next character in the pattern
        }
        else // If there is a mismatch
        {
            if (len != 0)
            {
                // Use the previous LPS value to avoid redundant comparisons
                len = lps[len - 1];
            }
            else
            {
                // If no matching prefix found, set LPS[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to search for the pattern in the given text using the KMP algorithm
void search(string &pat, string &txt)
{
    int n = txt.length(); // Length of the text
    int m = pat.length(); // Length of the pattern

    // Dynamically allocate memory for the LPS array
    int *lps = new int[m];
    constructLps(pat, lps); // Construct the LPS array for the given pattern

    int i = 0; // Pointer for the text
    int j = 0; // Pointer for the pattern

    // Traverse through the text to search for the pattern
    while (i < n)
    {
        // If characters match, move both pointers forward
        if (txt[i] == pat[j])
        {
            i++; // Move text pointer forward
            j++; // Move pattern pointer forward

            // If the entire pattern is matched, store the starting index
            if (j == m)
            {
                cout << "Pattern found at index " << i - j << endl;

                // Use LPS of the previous index to skip unnecessary comparisons
                j = lps[j - 1];
            }
        }
        else // If there's a mismatch
        {
            // Use the LPS value of the previous index to avoid redundant comparisons
            if (j != 0)
                j = lps[j - 1]; // Move the pattern pointer to the next possible matching position
            else
                i++; // If no prefix matched, move the text pointer forward
        }
    }

    delete[] lps;
}