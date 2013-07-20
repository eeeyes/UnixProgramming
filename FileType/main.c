#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc,char* argv[])
{
	int i;
	struct stat buf;
	char* ptr;
	mode_t fileMode;

	for(i=1;i<argc;i++)
	{
		if( lstat(argv[i],&buf) < 0)
		{
			fprintf(stderr,"lstat error");
			exit(4);
		}

		fileMode = buf.st_mode;

		if( S_ISREG(fileMode) )
			ptr = "regular file";
		else if ( S_ISDIR(fileMode) )	
			ptr = "directory";
		else if ( S_ISCHR(fileMode) )
			ptr = "character special";
		else if ( S_ISBLK(fileMode) )
			ptr = "block special";
		else if ( S_ISFIFO(fileMode) )
			ptr = "fifo";
		else if ( S_ISLNK(fileMode) )
			ptr = "symbol link";
		else if ( S_ISSOCK(fileMode) )
			ptr = "socket";
		else 
			ptr = "unknown mode";

		printf ("%s\n",ptr);
	}

	exit(0);
}
