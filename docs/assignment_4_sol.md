# Solution for Task 4

Given line sensor data of a line following bot in a maze following Left follow rule, 
write left follow algorithm and give dynamic output for encountered turn, type of junction and direction facing. 

## Algorithm:

```
We have unique conditional statements for 
    Turn left
    Straight + Right
    Turn right
    Dead end

within each, we have called the type_of_junction() function 
just to be sure about what kind of turn or junction we have encountered.

the return_direction() function gives us the direction at that instant

ample amount of comments in the rest of the code will
help you understand in depth how it works.
```
 
### Detailed problem statement can be found [here](https://sra-vjti.github.io/eklavya2020-assignments/bonus.html).  

_Password_ is `1N5L6R_east2000`.  

```  
gcc solution_4.c  
./a.out  
```

**Output**  
```
Enter the filename: data.txt
LEFT TURN       PLUS                    West      
RIGHT TURN      ONLY RIGHT              North     
LEFT TURN       LEFT + STRAIGHT         West      
RIGHT TURN      ONLY RIGHT              North     
STRAIGHT        RIGHT + STRAIGHT        North     
RIGHT TURN      ONLY RIGHT              East      
RIGHT TURN      ONLY RIGHT              South     
LEFT TURN       PLUS                    East      
RIGHT TURN      ONLY RIGHT              South     
LEFT TURN       ONLY LEFT               East      
LEFT TURN       ONLY LEFT               North     
STRAIGHT        RIGHT + STRAIGHT        North     
STOP            END                     North      
```    

## Code:

```c
{% include_relative solution_4.c %}
```