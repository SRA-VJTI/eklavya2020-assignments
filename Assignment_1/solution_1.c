#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[20];
    printf("Enter the name of data file:  ");
    scanf("%s",filename);
    FILE* file = fopen (filename, "r");

    if ( file == NULL ) 
    { 
        printf( "%s does not exist",filename ) ;
        exit(0);
    } 

    /*from here on number of nodes will be counted: 

    */ 
    int counter = 0;
    float left_sensor_value, right_sensor_value, mid_left_sensor, mid_right_sensor;
    int former_white_space = 0, white_space=0;
    int node_start=0, node_end=0;       //declaration of variables 

    while(!feof (file))
    {
        
        fscanf (file, "%f %f %f %f", &left_sensor_value,&mid_left_sensor,&mid_right_sensor,&right_sensor_value);
        if(left_sensor_value > 0.6 && right_sensor_value > 0.6)     //Here we check if the left and right sensors lie on a white surface
                white_space = 1;
        else
                white_space = 0;

        if (white_space!=former_white_space && white_space == 1)        // condition for entering the all white space
        {    
            node_start=1;
        }
        else if (white_space!=former_white_space && white_space == 0)   // condition for leaving the all white space
        {
            node_end=1; 
        }

        if(node_start && node_end)                          // only after the bot has successfully detected that it has started and left an all white space 
        {                                                   // can we say that it is a node.
            counter++;                                      // hence when this condition is satisfied we can increase the counter indicating number of nodes
            node_end=0;
            node_start=0;
        }

        former_white_space = white_space;
    }
    printf("The number of nodes are: %d\n",counter);
    // end

    getchar();
    return 0;
}