## Implement strStr()

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

- - -

The Rabin-Karp algorithm is a string searching algorithm that uses rolling hashing to find patterns in strings. 

Instead of comparing needle with each substring of the same length in haystack, we compute the hash of both and only compare when they have the same hash.
