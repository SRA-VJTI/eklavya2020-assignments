# Task 1
## Download 
[Download](https://github.com/SRA-VJTI/eklavya2020-assignments/releases/download/eklavya/Assignment_1.zip)
## Description
Given data contains the values obtained by a line sensor.
4 space separated values on each line gives the values of sensor at any instant

You have been given a scenario of a white line on black surface
there are regions on this line called nodes

**A node looks like this**
```
        |  |
        |  |
    ____|  |____
    ____|  |____ <-- node here
        |  |
        |  |
        |  |
        |  |             ^
        |  |             |
        |  |             |
        |  | bot travels in this direction
```
**Line sensor placement**
```
    |  |
    |  |
____|  |____
____|  |____ 
    |  |
    |  |
   0|12|3
```
* 0, 1, 2, 3 are the location of the 4 line sensors

## Task
Your task is to count the number of nodes from the values given in data
            
The bot starts "On the line", "passes straight through nodes"
and stops when it reaches the "end of line"

This is a practically obtained data set
so discard any impractical values which may have been recorded
due to "sensor or motion errors" 

## Input
* `data.txt` file contains the values obtained by a line sensor. 4 space separated values on each line gives the values of sensor at any instant
* The program on running must ask the name of the file to be read

## Output
* The program must output the number of nodes it detected after reading the given .txt file

## Submission Instructions
* You must create a zip file, which should contain source files, and screenshot of the output.

## Example

```
sra@sra20:~$ ./assignment
enter name of file to be read: data.txt
number of nodes: 1
```

* here second line is the input and third line is the required output
[Go Back](tasks.md)
