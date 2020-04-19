## Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

- - -

We have to pointers, once to mark the begining of our substring and another that explores our original string that narks the end.

We go through all the characters of the string with our second pointer and store the latest index in a map, once we find a repeated character we update our max and move our first pointer past all the characters before the repeated character(the repeated character included) to mark the begining of a new substring.  
