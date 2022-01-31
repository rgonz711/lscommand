//Raul Gonzalez
//RedID 824258754
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int option;
    int n;
    struct dirent *pDirent;
    int hflag = 0;
    int i;

    DIR *pDir;

//parsing for -h in command line
    while ((option = getopt(argc, argv, "h")) != -1)
    {
        switch (option)
        {
        case 'h':
            hflag = 1;
            break;
        }
    }

//if -h is identified
    if (hflag == 1)
    {
        //prints current directory with -h flag
        if (argc == 2)
        {
            pDir = opendir("./");

            while ((pDirent = readdir(pDir)) != NULL)
            {
                puts(pDirent->d_name);
            }
        }
        else
        {
// assumption that -h will be the first argument
            for (n = 2; n < argc; n++)
            {

                pDir = opendir(argv[n]);

                if (pDir == NULL)
                {
                    printf("Cannot access '%s'\n", argv[n]);

                    return 0;
                }
                printf(argv[n]);
                printf(" \n");

                // prints including hidden files

                while ((pDirent = readdir(pDir)) != NULL)
                {
                    puts(pDirent->d_name);
                }
                printf("... \n");
            }
        }
    }
    else
    {
        //prints current directory if no argument
        if (argc == 1)
        {
            pDir = opendir("./"); //opens directory to be read
            puts(".");
            while ((pDirent = readdir(pDir)) != NULL)//reads directory
            {
                if (pDirent->d_name[0] != '.')
                {
                    puts(pDirent->d_name);
                }
            }
        }
        else
        {

            for (n = 1; n < argc; n++)
            {

                pDir = opendir(argv[n]);

                if (pDir == NULL)
                {
                    printf("Cannot access '%s'\n", argv[n]);

                    return 0;
                }
                printf(argv[n]);
                printf(" \n");
                //does not print hidden files
                while ((pDirent = readdir(pDir)) != NULL)
                {
                    if (pDirent->d_name[0] != '.')
                    {
                        puts(pDirent->d_name);
                    }
                }
                printf("... \n");
            }

           
//close directory
            closedir(pDir);
            return 0;
        }
    }
}
