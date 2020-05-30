## Check If a String Contains All Binary Codes of Size K

Given a binary string s and an integer k. Return True if any binary code of length k is a substring of s. Otherwise, return False.

---

We go through all the substrings of length k in s. We store each substring in a hashset, and at the end check if the length of the set is pow(2, k) wich is the number of binary codes of lengh k.
