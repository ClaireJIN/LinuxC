#include <time.h>
#include <stdio.h>

int main(void) {
	time_t timestemp;
	char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	struct tm *p;
	time(&timestemp);
	printf("%s\n", asctime(gmtime(&timestemp)));
	p = localtime(&timestemp);
	printf("%dy-%dd-%dh-%dm  %s\n", 1900+p->tm_year, p->tm_mday, p->tm_hour, p->tm_min, wday[p->tm_wday]);
}