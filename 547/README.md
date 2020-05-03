## Friend Circles

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

- - -

The idea is using an array where each time we have a new friend union one becomes the root of the other one. A friend circle becomes then like a tree. we through the matrix, if the two are already friends (they have the same root) we go on, and if not we merge the teo circles where they belong by having the root of the most populated tree become the root of the other tree.
