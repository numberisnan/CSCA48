////////////////////////////////////////////////////////////
// CSC A48 - Exercise 7 - Caesar Cipher Pic - Winter 2022
//
// Do not add any additional functions
// and do not leave any print statements
// in your final submission for testing!
//
// (c) F. Estrada, Feb 2022.
/////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

#define MAX_STR_LEN 2048

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
  if (line[0]!='P'||line[1]!='5')
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
/*
unsigned char offset(int i, unsigned char passPic[50][50]) {
  return passPic[(i/50)%50][i%50];
} */ 

unsigned char applyOffset(unsigned char c, unsigned char offset, int n) {
  int temp = (((int)c-1)+((int)offset*n))%255;
  return (temp < 0 ? temp + 255 : temp)+1; //Shifts entire set backwards, then applys offset and loopbacks on 255 chars, then shifts forward
}

#define offset(i, passPic) passPic[(i/50)%50][i%50]
#define encoded(c,offset,n) (((int)c-1)+((int)offset*n))%255
//#define applyOffset(c, offset, n) (char)encoded(c,offset,n)+1

void caesar_cipher(unsigned char p[MAX_STR_LEN], unsigned char P[50][50])
{
 // This function encodes the input text in plaintext[] using the caesar
 // cipher process using the image in passPic[][] for displacement values.
 // See Exercise handout for details
 //
 // The function must ensure that the 'end-of-string' delimiter is preserved,
 // and that no other character can become the 'end-of-string'. 
 // 
 // You want to make sure you understand what values can be stored in each
 // entry of the plaintext[] string, and you'll want to look at an ASCII table
 // to check that your function does the right thing.
 //
 // *** TEST your code with multiple input strings, using different passwords,
 //     and verify it works in 
 //     every case! if you get incomplete because your function failed our
 //     tests it means you did not test carefully enough.
  for(int i=0;p[i];i++)p[i]=applyOffset(p[i],offset(i,P),1);
  //for(int i=0;p[i];i++)p[i]=(char)(p[i]-1+(int)P[i/50][i%50])%255 +1;
}

void caesar_decipher(unsigned char c[MAX_STR_LEN], unsigned char P[50][50])
{
 // This function reverses the encryption process and returns the original
 // text given the encrypted string and the passPic[][]
 // 
 // The function has the same constraints as 'caesar_cipher()', that is, it
 // must respect the 'end-of-string' delimiter, and ensure no other
 // character becomes 'end-of-string' after decoding.
 //
 // Be smart about how you implement this function!
  for(int i=0;c[i];i++)c[i]=applyOffset(c[i],offset(i,P),-1);
}

#ifndef __testing

int main()
{
    
    unsigned char a_message[MAX_STR_LEN];//="éééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééééé";
    char temp;
    int i = 0;
    while ((temp = getchar()) != EOF) {
      a_message[i] = temp;
      i++;
    }
    a_message[i] = 0;
    fgets(a_message, MAX_STR_LEN, stdin);                        
    unsigned char passPic[50][50];
    
    readPGMimage("tile_1.pgm",&passPic[0][0],50,50);
                                     
    //printf("**** Original input message:\n\n");
    //printf("%s",a_message);

    // Encode the input test lines
    caesar_cipher(a_message,passPic);

    //printf("\n\n**** Encrypted text lines:\n\n");
    //printf("%s",a_message);

    // Decode the encrypted strings
    caesar_decipher(a_message,passPic);

    //printf("\n\n**** Decoded text lines (should be identical to original input!):\n\n");
    printf("%s",a_message);

    
    return 0;
    
}

#endif