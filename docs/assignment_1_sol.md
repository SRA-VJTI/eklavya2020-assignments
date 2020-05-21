# Solution for Task 1 

We are asked to detect nodes in the given datasets.
Node is nothing but a white colored band perpendicular 
to the line that the bot follows. Hence we will be using mainly the 
Left most and Right most sensors for checking conditions pertaining to a node

## open the file

```
scanf("%s",filename);
    FILE* file = fopen (filename, "r");

    if ( file == NULL ) 
    { 
        printf( "%s does not exist",filename ) ;
        exit(0);
    } 
```

We ask the user to enter filename, and then
check if file exists. 
Then we read the file. 

## scanning the contents of the file

```
while(!feof (file))
    {
    	fscanf (file, "%f %f %f %f", &left_sensor_value,&mid_left_sensor,&mid_right_sensor,&right_sensor_value);
    	.
    	.
    	.
    	.
    	.
    }
```
 In this loop we keep reading the data file line by line and in
 every iteration we scan the next line.

 The conditions have been explained with the help of comments provided 
 in the code itself.

## printing the final answer

`printf("The number of nodes are: %d\n",counter);`

Detailed problem statement can be found [here](https://sra-vjti.github.io/eklavya2020-assignments/assignment_1.html).

```  
gcc solution_1.c  
./a.out  
```

**Output**  

```
Enter the filename: data.txt  
Number of nodes encountered are: 3!!  
    
Enter the filename: data_1.txt  
Number of nodes encountered are: 3!!  
```

## Code:

```c
{% include_relative solution_1.c %}
```