# DSA_PROBLEM

This repository is dedicated to creating and managing a collection of data structure and algorithm problems implemented in various programming languages.


## 1. Check for Pair with Given Sum in an Array
  Given an array of integers and an integer sum, find if there is a pair of elements in the array whose sum equals the given sum. 
  Return a `true` if it exists and `false` if it doesn't exists

  ### Test Cases
  1. Input `arr : [1,2,3,4,5,6], sum : 6` Output : `true`
  2. Input `arr : [1,4,45,6,10,-8], sum : 16` Output : `true`
  3. Input `arr : [1,2,3,9], sum : 8` Output : `false`
  4. Input `arr : [1,2,4,4], sum : 8` Output : `true`
  5. Input `arr : [0,-1,2,-3,1], sum : -2` Output : `true`
  6. Input `arr : [], sum : 5` Output : `false`
  7. Input `arr : [-1,0,1,2,-2], sum : 6` Output : `false`
  8. Input `arr : [-1,0,1,2,-2], sum : 0` Output : `true`

## 2. Isomorphic Strings
  Given two strings `s` and `t`, determine if they are isomorphic. Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`. 
  Return a `true` if it can be replaced or `false`.
  Where `s.length == t.length`

  ### Test Cases
  1. Input `s = "egg", t = "add"` Output : `true`
  2. Input `s = "foo", t = "bar"` Output : `false`
  3. Input `s = "paper", t = "title"` Output : `true`
  4. Input `s = "abacaba", t = "xyyxzxy"` Output : `true`
  5. Input `s = "apple%"", t = "orange$"` Output : `true`
  6. Input `s = "aab", t = "zcb"` Output : `false`
  7. Input `s = "ccccc", t = "aaabb"` Output : `false`
  8. Input `s = "", t = ""` Output : `true`


 ## Set project locally

  - To run java solution, verfiy JDK is installed in your system.
  - To run c++ solution, verfiy C++ complier is installed in your system.
    
  1. Clone the repository
       `git clone https://github.com/rohanjadhav05/dsa_problem_setter.git`

  2. Navigate to the problem_1
     a. To Run Java Solution
       - to run problem_1 in java complie the java code
           `javac solution1.java`
       - .class file we generated, run the .class file to get to check if all test cases are passed
           `java solution1`

     b. To Run c++ solution
       - complie the c++ code
         `g++ -o solution2 solution2.cpp`
       - run the c++ soltuion
         `./solution2`
     
