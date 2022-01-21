#include <pigpio.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define LOW 0
#define HIGH 1
#define IN_PORT 20
#define OUT_PORT 21

struct timespec in_ts;

void gettime_in() {
	clock_gettime(CLOCK_REALTIME, &in_ts);  //時刻の取得
	printf("%ld.%09ld\n", in_ts.tv_sec, in_ts.tv_nsec);
}

int main() {
	int ret;
	if (gpioInitialise() < 0) {
		perror("Failed to Initialize");
		return 0;
	}
	if (gpioSetMode(IN_PORT, PI_INPUT) != 0) {
		perror("Failed to Set INPUT mode");
		return 1;
	}
	ret = gpioSetISRFunc(IN_PORT, FALLING_EDGE, 0, gettime_in);
	if(ret < 0) printf("error");
	
	while(1) {
		usleep(100);
	}
	gpioTerminate();
}
