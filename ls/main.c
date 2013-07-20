#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		fprintf(stderr,"usage: ls directory");
		exit(1);
	}

	DIR	*dp;
	struct dirent *dirp;
	
	if( (dp = opendir(argv[1])) == NULL)
	{
		fprintf(stderr,"can't open %s",argv[1]);
		exit(2);
	}

	while ( dirp = readdir(dp) )
		printf("%s\n",dirp->d_name);
	exit(0);
}

