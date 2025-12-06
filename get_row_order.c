#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

/*
example
raw: "abcdefghi"
row: 4
ouput: agbfhceid

from left to right, from top to bottom
a     g
b   f h
c e   i
d

*/
int str_reorder(char* praw, char* pout, int k)
{
        if(praw == NULL || pout == NULL)
        {
                return -1;
        }

        if(k < 1)
                return -1;


        int tmp_mod = 2 * k - 2;
        int i = 0;
        int j = 0;
        int len = strlen(praw);

        if(tmp_mod == 0)
        {
                memcpy(pout,praw,len);
                return 0;
        }           

        for(i=0;i<k;i++)
        {
                for(j=0;j<len;j++)
                {
                        if(j % tmp_mod == i || j % tmp_mod == 2*k-2-i)
                        {
                                *(pout++) = *(praw+j);
                        }
                }
        }
        return 0;


}
int main(int argc, char** argv)
{
        
        char *praw;
        int row;
        char *pout;
        int len;

        if(argv[1]==NULL || argv[2]==NULL)
        {
                printf("input error\n");
                return 0;
        }

        praw = argv[1];
        row = atoi(argv[2]);

        printf("The raw stirng is %s\n", praw);
        printf("The row is %d\n", row);

        len = strlen(praw);
        pout = malloc(len + 1);

        memset(pout, 0x00, len + 1);

        str_reorder(praw, pout, row);

        printf("the final ouput is\n%s\n", pout);

        free(pout);
        return 0;
}

