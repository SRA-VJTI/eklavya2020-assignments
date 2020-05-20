# Task 2
## Download 
[Download](https://github.com/SRA-VJTI/eklavya2020-assignments/releases/download/eklavya/Assignment_2.zip)
## Description
Given data contains the values obtained by a line sensor.
4 space separated values on each line gives the values of sensor at any instant

You have been given a scenario of a white line on black surface
there are regions on this line called nodes
there are turns at 90 degrees that bot has to take

**A turn looks like this**

```
                       |  |  
                       |  |
         ______________|  |
right-->|   ______________|  <-- left turn
 turn   |  |
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
        |  |
        |  |
        |  |

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

* The direction in which bot faces at start is NORTH
* We encode the direction as    

```
 ___________
|       |   |
| NORTH | 0 |
| EAST  | 1 |
| SOUTH | 2 |
| WEST  | 3 |
|_______|___|
```

## Task
Your task is to count the number of nodes, number of turns
and the direction bot faces at the end

The bot starts "On the line", "passes straight through nodes",
"turns left or right at turns" and stops when it reaches the "end of line"

This is a practically obtained data set
so discard any impractical values which may have been recorded
due to "sensor, motion and sharp turn errors"

## Input
* `data.txt` file contains the values obtained by a line sensor. 4 space separated values on each line gives the values of sensor at any instant
* The program on running must ask the name of the file to be read

## Output
* The program must output the number of nodes, number of turns and direction bot faces at the end.

## Submission Instructions
* You must create a zip file, which should contain source files, and screenshot of the output.

## Example

```
sra@sra20:~$ ./assignment
enter name of file to be read: data.txt
number of nodes: 1
number turns: 2
final direction: NORTH
```

* here second line is the input and third, fourth, fifth line is the required output

[Go back](tasks.md)
