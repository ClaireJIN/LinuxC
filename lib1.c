/*
Use Math.lib and write.func
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

#define FLAGS O_CREAT|O_TRUNC|O_WRONLY
#define BUFSIZE 5
#define INPUT_TIMES 10
int main(void) {
	int x;
	int n, nn = 0;
	int fd = open("file", FLAGS, 0600);
	double buf[BUFSIZE];
	memset(buf, 0, sizeof(double) * BUFSIZE);

	int old = time((time_t*)NULL);
	for (n = 0; n < INPUT_TIMES; n++) {
		scanf("%d", &x);
		double y = x * x;
        #if 1
        //Find empty buffer position
        while (nn < BUFSIZE && buf[nn]) 
        	nn++;
        //Buffer isn't full
        if (nn < BUFSIZE)
        	buf[nn] = y;
        //Buffer is full 
        else {
        	write(fd, buf, sizeof(double) * BUFSIZE);
        	memset(buf, 0, sizeof(double) * BUFSIZE);
        	nn = 0;
        	buf[nn] = y;
        }
        #endif
	}
	int new = time((time_t*)NULL);
    printf("%d\n", new - old);

}