 #include <stdio.h>
 #include <stdlib.h>
 #define STB_IMAGE_IMPLEMENTATION
 #include "stb_image.h"
 #define STB_IMAGE_WRITE_IMPLEMENTATION
 #include "stb_image_write.h"

void removecolor(long** blue,long** red,long** green,int colorno,int height,int width)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            switch(colorno)
            {
                case 1:
                {
                    if (red[i][j]>blue[i][j]&&red[i][j]>green[i][j])
                    {
                        red[i][j]=0;
                    }
                    break;
                }
                case 2:
                {
                    if (green[i][j]>blue[i][j]&&green[i][j]>red[i][j])
                    {
                        green[i][j]=0;
                    }
                    break;
                }
                case 3:
                {
                    if (blue[i][j]>red[i][j]&&blue[i][j]>green[i][j])
                    {
                        blue[i][j]=0;
                    }
                    break;
                }
            }
        }
    }
    FILE *blue_outfile = fopen("Q3_op_blue.dat", "w");
          if (blue_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    FILE *red_outfile = fopen("Q3_op_red.dat", "w");
          if (red_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    FILE *green_outfile = fopen("Q3_op_green.dat", "w");
          if (green_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fprintf(blue_outfile, "%ld,", blue[i][j]);
            fprintf(red_outfile, "%ld,", red[i][j]);
            fprintf(green_outfile, "%ld,", green[i][j]);
        }
        fprintf(blue_outfile, "%ld\n", blue[i][width-1]);
        fprintf(red_outfile, "%ld\n", red[i][width-1]);
        fprintf(green_outfile, "%ld\n", green[i][width-1]);
    }

}

void keepthiscoloronly(long** blue,long** red,long** green,int colorno,int height,int width)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            switch(colorno)
            {
                case 1:
                {
                    if (red[i][j]>blue[i][j]&&red[i][j]>green[i][j])
                    {
                        green[i][j]=0;
                        blue[i][j]=0;
                    }
                    break;
                }
                case 2:
                {
                    if (green[i][j]>blue[i][j]&&green[i][j]>red[i][j])
                    {
                        blue[i][j]=0;
                        red[i][j]=0;
                    }
                    break;
                }
                case 3:
                {
                    if (blue[i][j]>red[i][j]&&blue[i][j]>green[i][j])
                    {
                        green[i][j]=0;
                        red[i][j]=0;
                    }
                    break;
                }
            }
        }
    }
    FILE *blue_outfile = fopen("Q3_op_blue.dat", "w");
          if (blue_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    FILE *red_outfile = fopen("Q3_op_red.dat", "w");
          if (red_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    FILE *green_outfile = fopen("Q3_op_green.dat", "w");
          if (green_outfile == NULL) 
            {   
              printf("Error! Coud not create the file\n"); 
              exit(0); 
            } 
    
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fprintf(blue_outfile, "%ld,", blue[i][j]);
            fprintf(red_outfile, "%ld,", red[i][j]);
            fprintf(green_outfile, "%ld,", green[i][j]);
        }
        fprintf(blue_outfile, "%ld\n", blue[i][width-1]);
        fprintf(red_outfile, "%ld\n", red[i][width-1]);
        fprintf(green_outfile, "%ld\n", green[i][width-1]);
    }
}

int main(int argc, char const *argv[])
{
	int width, height, channels;
    int n;
	stbi_info("Q3_ip.jpg", &width, &height, &channels);
	int noofpixels=width*height;
    int colorno;
    long *blue[height]; 
    for (int i=0; i<height; i++) 
         blue[i] = (long *)malloc(width * sizeof(long));
    long *red[height]; 
    for (int i=0; i<height; i++) 
         red[i] = (long *)malloc(width * sizeof(long));  
    long *green[height]; 
    for (int i=0; i<height; i++) 
         green[i] = (long *)malloc(width * sizeof(long)); 
	FILE *blue_infile  = fopen("Q3_ip_Blue.dat", "r");
          if (blue_infile == NULL) 
            {   
              printf("Error! Coud not open file\n"); 
              exit(0); 
            } 
	FILE *red_infile  = fopen("Q3_ip_Red.dat", "r");
          if (red_infile == NULL) 
            {   
              printf("Error! Coud not open file\n"); 
              exit(0); 
            } 
	FILE *green_infile  = fopen("Q3_ip_Green.dat", "r");
          if (green_infile == NULL) 
            {   
              printf("Error! Coud not open file\n"); 
              exit(0); 
            }            
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width-1; ++j)
        {
            fscanf(blue_infile, "%ld,", &blue[i][j]);
            fscanf(red_infile, "%ld,", &red[i][j]);
            fscanf(green_infile, "%ld,", &green[i][j]);
        }
            fscanf(blue_infile, "%ld", &blue[i][width-1]);
            fscanf(red_infile, "%ld", &red[i][width-1]);
            fscanf(green_infile, "%ld", &green[i][width-1]);
    }
    while(1){
        printf("press 1 for remove all red shades\n");
        printf("press 2 for remove all green shades\n");
        printf("press 3 for remove all blue shades\n");
        printf("press 4 for preserve only red shades\n");
        printf("press 5 for preserve only green shades\n");
        printf("press 6 for preserve only blue shades\n");
        printf("press 7 for exit\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                removecolor(blue,red,green,1,height,width);
                printf("\n");
                break;
            }
            case 2:
            {
                removecolor(blue,red,green,2,height,width);
                printf("\n");
                break;
            }

            case 3:
            {
                removecolor(blue,red,green,3,height,width);
                printf("\n");
                break;
            }
            case 4:
            {
                keepthiscoloronly(blue,red,green,1,height,width);
                printf("\n");
                break;
            }

            case 5:
            {
                keepthiscoloronly(blue,red,green,2,height,width);
                printf("\n");
                break;
            }
            case 6:
            {
                keepthiscoloronly(blue,red,green,3,height,width);
                printf("\n");
                break;
            }
            case 7:
            {
                exit(0);
                break;
            }

            default:
            {
                printf("please enter value from the above values\n");
                break;
            }

        }
    }
	return 0;
}