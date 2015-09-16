//
// Created by Rui Chen on 9/16/15.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Texture.h"


void Texture :: loadTexture(string texturePath)
{
    FILE *f;
    char ch;
    int colres;
    unsigned char *mRGB;

    char* filename = new char[texturePath.length() + 1];
    strcpy(filename, texturePath.c_str());

    if(f=fopen(filename,"rb"))
    {
        char str[100];
        eatWhitespace(f);
        eatComments(f);
        eatWhitespace(f);
        fscanf(f,"%s",str);
        if(strcmp(str,"P6")!=0)
        {
            printf("Error: the texture image file must be of raw color PPM format,\n");
            printf("i.e., it must have P6 in the header. File: %s\n",filename);
            exit(1);
        }
        eatWhitespace(f);
        eatComments(f);
        eatWhitespace(f);
        fscanf(f,"%d %d",&width,&height);
        if(width<=0 || height<=0)
        {
            printf("Error: width and height of the image must be greater than zero. File: %s\n",filename);
            exit(1);
        }
        eatWhitespace(f);
        eatComments(f);
        eatWhitespace(f);
        fscanf(f,"%d",&colres);
        if(colres!=255)
        {
            printf("Error: color resolution must be 255.File: %s\n",filename);
        }
        /* gotta eat the newline too */
        ch=0;
        while(ch!='\n') fscanf(f,"%c",&ch);

//        if(tx==NULL)
//        {
//            printf("Error: could not allocate memory for texture struct. File: %s\n",filename);
//        }

        mRGB=(unsigned char*)malloc(3*width*height);

        if(mRGB==NULL)
        {
            printf("Error: could not allocate memory for the pixels of the texture. File: %s\n",filename);
            exit(1);
        }

        if(fread(mRGB,3*width*height,1,f)!=1)
        {
            printf("Error: could not read 3 x %d bytes of pixel info. File: %s\n",width*height,filename);
        }

        fclose(f);

        for (int i=0; i<3*width*height; i+=3)
            colors[i] = Color(mRGB[i], mRGB[i+1], mRGB[i+2]);

    }
    else
    {
        printf("Error: could not open %s.\n",filename);
    }

    delete[] filename;
    free(mRGB);
}


void Texture :: eatComments(FILE *f)
{
    int ch;
    while((ch=getc(f))=='#')
    {
        char str[1000];
        fgets(str,1000,f);
    }
    ungetc(ch,f);
}

void Texture :: eatWhitespace(FILE *f)
{
    int ch;
    ch=getc(f);
    while(ch==' ' || ch=='\t' || ch=='\n' || ch=='\f' || ch=='\r')
    {
        ch=getc(f);
    }
    ungetc(ch,f);
}

/* reads a ppm file with the P6 header (means raw RGB), returns a struct Texture */
/* the header looks like this:
 *---------
 * P6
 * # comments if you want to
 * width height
 * 255
 *---------
 * then follows RGBRGBRGBRGBRGB...
 */