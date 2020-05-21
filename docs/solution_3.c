#include <stdio.h>
#include <stdlib.h>

int main()
{

  FILE *f,*distance_file,*strength_file;
  unsigned char c[10];
  unsigned char checksum = 0x00;
  unsigned long Distance;
  unsigned long Strength;
  char filename[10];

  printf("Enter the file name: ");
  scanf("%s",filename);
	
  f = fopen(filename, "r");            	 //Input file
  distance = fopen("distance.txt","w");  //Storing the distance data into distance.txt
  signal = fopen("signal.txt","w");      //Storing the signal strength value into singal.txt

  fseek(f, 0, SEEK_SET);

  while(!feof(f))
  {
      fread(c, sizeof(unsigned char), 10, f);		//Reading first 10 bytes
        //If basic condition is not satisfied then not calculating checksum further.
      if( (c[0] == 0x59) && (c[1]== 0x59) && (c[9]== 0x0a))	
       {
          for(int i = 0; i < 8; i++)
          {
            checksum += c[i]; 
          }
          if(checksum == c[8])
          {
              //Now extracting dist L and dist H from the data:
              //More info on : https://stackoverflow.com/questions/10748506/what-does-it-mean-to-bitwise-left-shift-an-unsigned-char-with-16
            Distance=(c[3]<<8)|(c[2]);			
            Strength = (c[5]<<8)|(c[4]);
            printf("%lu :: %lu  \n",Distance,Strength);
            fprintf(distance_file,"%lu \n",Distance);		//Distance is stored in text file using pointer distance_file
            fprintf(strength_file,"%lu \n",Strength);		//Strength is stored in text file using pointer strength_file
          }
          else
          {
            printf("Checksum did not match\n");
          }
          checksum = 0x00;
      }
      else
      {
          printf("First Two Bytes aren't 0x59 and 0x59\n");
      }
  }
  fclose(distance_file);
  fclose(strength_file);
  fclose(f);

  return 0;

}
