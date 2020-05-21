#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

static char direction[4][6] = {"EAST", "NORTH", "WEST", "SOUTH"};

int line_sensor_interpret(float line_sensor[4])
{
    if (line_sensor[0] > 0.7 && line_sensor[1] > 0.7 && line_sensor[2] > 0.7 && line_sensor[3] > 0.7)
    {
        return 2;
    }
    else if (line_sensor[0] < 0.5 && line_sensor[1] > 0.7 && line_sensor[2] > 0.7 && line_sensor[3] > 0.7)
    {
        return 1;
    }
    else if (line_sensor[0] > 0.7 && line_sensor[1] > 0.7 && line_sensor[2] > 0.7 && line_sensor[3] < 0.5)
    {
        return -1;
    }
    else if (line_sensor[0] < 0.5 && line_sensor[1] > 0.7 && line_sensor[2] > 0.7 && line_sensor[3] < 0.5)
    {
        return 0;
    }

    return 0;
}

int main()
{
    char filename[30];
    FILE* file_handle = NULL;
    float line_sensor[4], prev_line_sensor[4];
    int nodes = 0;
    int right_turns = 0;
    int left_turns = 0;
    int start_turn = 0;    

    printf("enter file name: ");
    scanf("%s", filename);
    file_handle = fopen(filename, "r");
    memset(prev_line_sensor, 0, 4); 
    memset(line_sensor, 0, 4);
    // memset is a C function, to set value to a consecutive memory block
    // Read more: https://www.geeksforgeeks.org/memset-c-example/

    if (file_handle == NULL)
    {
        printf("error reading file\n");
        exit(0);
    }
    
    while (fscanf(file_handle, "%f %f %f %f", &line_sensor[0], &line_sensor[1], &line_sensor[2], &line_sensor[3]) > 0)
    {
        if (abs(line_sensor_interpret(line_sensor)) == 1 && line_sensor_interpret(prev_line_sensor) == 0)
        {
            start_turn = 1;
        }

        if (line_sensor_interpret(line_sensor) == 0 && line_sensor_interpret(prev_line_sensor) == 1 && start_turn == 1)
        {
            right_turns++;
            start_turn = 0;
        } 
        else if (line_sensor_interpret(line_sensor) == 0 && line_sensor_interpret(prev_line_sensor) == -1 && start_turn == 1)
        {
            left_turns++;
            start_turn = 0;
        }
        else if ((line_sensor_interpret(line_sensor) == 1 || line_sensor_interpret(line_sensor) == -1 || line_sensor_interpret(line_sensor) == 0) && line_sensor_interpret(prev_line_sensor) == 2)
        {
            nodes++;
        }

        memcpy(prev_line_sensor, line_sensor, sizeof(float)*4);
        // memcpy is used to copy a block of memory to another block of memory
        // Read more: https://www.geeksforgeeks.org/memcpy-in-cc/
    }

    printf("number of nodes: %d\n", nodes);
    printf("number of left turns: %d\n", left_turns);
    printf("number of right turns: %d\n", right_turns);
    printf("direction: %s\n", direction[1+(left_turns-right_turns)%4]);
}