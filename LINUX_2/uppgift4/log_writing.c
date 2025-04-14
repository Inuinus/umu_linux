#include <stdarg.h>
#include <stdio.h>
#include <syslog.h>

int main(){
	openlog("log_writing", LOG_PID, LOG_USER);

	syslog(LOG_WARNING, "Hi from example application");
	syslog(LOG_INFO, "Information message");
	syslog(LOG_ERR, "Critical Error");

	closelog();

	return 0;
}
