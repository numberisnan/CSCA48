/*
 * CSC A48 - Exercise 6, Winter 2022
 * (c) F.J. Estrada, Feb. 2022
 * 
 * You DO NOT NEED TO READ OR UNDERSTAND the image
 * reading/writing functions 'writePGMimage' and
 * 'readPGMimage'.
 *
 * Feel free to skip them! and go directly to the
 * extract_levelset() function which is where you
 * need to do your work (it's just above main() ).
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define is_safe(adj) adj[0] < 50 && adj[0] > 0 && adj[1] < 50 && adj[1] > 0

void writePGMimage(unsigned char *image, int size_x, int size_y)
{
    // Output a PGM image map from the specified array. It is assumed
    // the array has size (size_x x size_y) and is of type unsigned char.
    // The output file is 'output.pgm'
    
    FILE *f;
    f=fopen("output.pgm","w");
    if (f!=NULL)
    {
        fprintf(f,"P5\n");
        fprintf(f,"# Output for elevation_maps.c\n");
        fprintf(f,"%d %d\n",size_x,size_y);
        fprintf(f,"%d\n",255);
        fwrite(image,size_x*size_y*sizeof(unsigned char),1,f);
        fclose(f);
    }
}

void readPGMimage(const char *filename, unsigned char *image_array, int size_x, int size_y)
{
 // You DO NOT have to read or understand this function! it is
 // needed here to enable us to import a small image to work
 // with for the exercise.
 //
 // Reads the image stored in the specified file into the
 // specified image array. The image is assumed to be of size
 // (size_x x size_y) pixels. This should match the array size!

 FILE *f;
 char line[1024];
 int sizx,sizy;
 int i;

  f=fopen(filename,"rb+");
  if (f==NULL)
  {
   fprintf(stderr,"Unable to open file %s for reading, please check name and path\n",filename);
   return;
  }
  fgets(&line[0],1000,f);
  if (strcmp(&line[0],"P5\n")!=0)
  {
   fprintf(stderr,"Wrong file format, not a .pgm file or header end-of-line characters missing\n");
   fclose(f);
   return;
  }
  // Skip over comments
  fgets(&line[0],511,f);
  while (line[0]=='#')
   fgets(&line[0],511,f);
  sscanf(&line[0],"%d %d\n",&sizx,&sizy);           // Read file size
  if (sizx!=size_x||sizy!=size_y)
  {
    fprintf(stderr,"Image has different size from what was specified in the function call!\n");
    fclose(f);
    return;
  }

  fgets(&line[0],9,f);  	                // Read the remaining header line

  fread(image_array,sizx*sizy*sizeof(unsigned char),1,f);
      
  fclose(f);

  return;
}

// extract_levelset() is THE ONLY FUNCTION YOU NEED TO WORK ON.
void extract_levelset(unsigned char image_array[50][50], unsigned char levelset_map[50][50], int iy, int ix)
{
    // This function takes an image that represents an elevation map.
    // The image is indexed following the standard image indexing convention:
    //
    // The images we're working with have a size of 50x50, coordinates in the
    // array are (y,x) because arrays are indexed using the Math convention
    // where the first index is the row, and the second is the column. So,
    // if the initial coordiates (iy,ix) are (5,3), the corresponding entry
    // in the image array is
    //
    // image_array[5][3];
    //
    // The elevation map has pixels with values between 1 and 255 corresponding
    // to elevation (1 would be the lowest, 255 the highest). Pixels with the
    // same value have the same elevation *NOTE THAT THE ELEVATION MAP DOES
    // NOT CONTAIN ZEROS*
    //
    // Your task is as follows:
    // - Given the input elevation map in 'image_array'
    // - An initially empty image called 'levelset_map'
    // - And initial coordinates (ix, iy)
    //
    // Find all *connected* pixels that have the same elevation as the one at
    // (ix,iy) and copy those pixels to the levelset_map. 
    //
    // For example, if the initial coordinates are (10,5), your program must
    // check the elevation at image_array[10][5], then copy all connected
    // pixels with that elevation to the levelset_map.
    //
    // Example with a very tiny sample image:
    //
    // image_array:
    //
    // 1 1 1 2 3 3
    // 1 1 2 3 3 4
    // 1 2 2 2 4 4
    // 1 1 1 2 4 3
    // 1 1 2 2 3 3
    // 4 4 4 4 2 2
    //
    //
    // If we call the function with the image_array above, and initial
    // coordinates (1,1), it should produce
    //
    // levelset_map:
    //
    // 1 1 1 0 0 0
    // 1 1 0 0 0 0
    // 1 0 0 0 0 0
    // 1 1 1 0 0 0
    // 1 1 0 0 0 0
    // 0 0 0 0 0 0
    //
    // If we call the function with initial coordinates (0,4) it will
    // produce
    //
    // levelset_map:
    // 
    // 0 0 0 0 3 3
    // 0 0 0 3 3 0
    // 0 0 0 0 0 0
    // 0 0 0 0 0 0
    // 0 0 0 0 0 0
    // 0 0 0 0 0 0
    //
    // In effect, this function extracts the connected region in the image
    // array with the same elevation as that of the pixel at (ix,iy).
    //
    // ** A pixel is connected to its 4 neighbours: Above, below, left, and right**
    //
    // This function *must not change the contents* of the image_array!
    //
    // There are many ways to approach this problem, you're free to choose
    // whatever makes more sense to you. Make reasonable assumptions where
    // needed, and solve the problem!
    
    // TO DO: Complete this function!
    int height = image_array[iy][ix];
    levelset_map[iy][ix] = height;

    int change;
    int adj[4][2];
    while(change) {
        change = 0;
        for (int r = 0; r < 50; r++) {
            for (int c = 0; c < 50; c++) {
                adj[0][0] = r;
                adj[0][1] = c+1;
                adj[1][0] = r;
                adj[1][1] = c-1;
                adj[2][0] = r+1;
                adj[2][1] = c;
                adj[3][0] = r-1;
                adj[3][1] = c;
                for (int i = 0; i < 4; i++) {
                    if (is_safe(adj[i]) && levelset_map[r][c] != height && levelset_map[adj[i][0]][adj[i][1]] == height && image_array[r][c] == height) {
                        levelset_map[r][c] = height;
                        change = 1;
                        break;
                    }
                }
            }
        }
    }
}

#ifndef __testing
int main()
{
    unsigned char image_array[50][50];         // We'll be working with 50x50 images
    unsigned char levelset_map[50][50];        // This will contain the extracted region

    // Clear the levelset_map[][] to all zeros (all black)
    for (int i=0; i<50; i++)                
        for (int j=0; j<50; j++)
            levelset_map[i][j]=0;
        
    // Read the selected input image into image_array[][]
    readPGMimage("Mars_elevation_crop1.pgm",&image_array[0][0],50,50);

    fprintf(stderr,"Extracting levelset!\n");    
    extract_levelset(image_array, levelset_map, 5, 27);
    fprintf(stderr,"Done!\n");    
    
    writePGMimage(&levelset_map[0][0],50,50);
    return 0;
}
#endif
