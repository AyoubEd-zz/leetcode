## Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

- - -

There's a simple check to see if a string is a palindrom or not, we go from the center out and make sure the characters on the left and right pointer are always equal. In this problem we treat every character in the initial string as a potential center. We go through the whole string and check the longest palindromic substring we can obtain from that center.
