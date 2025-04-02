#include <stdio.h>
#include <ctype.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/rtc.h>
#include <zephyr/console/console.h>


LOG_MODULE_REGISTER(echo, LOG_LEVEL_ERR);

static const struct device *rtc_dev = DEVICE_DT_GET(DT_ALIAS(rtc));
struct rtc_time datetime = {
	.tm_sec = 0,
	.tm_min = 0,
	.tm_hour = 10,
	.tm_mday = 1,
	.tm_mon = 4 - 1,
	.tm_year = 2025 - 1900,
};

int *set_rtc_time(void);

int main(void)
{
	console_init();

	if (!device_is_ready(rtc_dev))
	{
		printk("The RTC device is not ready!\n");
		exit(1);
	}

	if (0 != rtc_set_time(rtc_dev, &datetime))
	{
		printk("Failed to set the RTC time!\n");
		exit(1);
	}

	char user_input;
	while(1){
		(void)printk("----------MENU---------- \n");
		(void)printk("S. Set time and date	   \n");
		(void)printk("G. Get time and date	   \n");
		(void)printk("------------------------ \n");

		
		user_input = console_getchar();
		if(toupper(user_input) == 'G'){
			(void) console_putchar(user_input);
			if (0 != rtc_get_time(rtc_dev, &datetime))
			{
				printk("\nFailed to get the RTC time!\n");
				exit(1);
			}
			else{
				(void) printk("\nTime: %04d-%02d-%02d %02d:%02d:%02d\n\n",
					datetime.tm_year + 1900, datetime.tm_mon + 1, datetime.tm_mday,
					datetime.tm_hour, datetime.tm_min, datetime.tm_sec);
			}
		}
		else if(toupper(user_input) == 'S'){
			(void) console_putchar(user_input);
			int _bool = set_rtc_time();
			if (_bool == 1){
				(void) printk("\nTime successfully set to: %04d-%02d-%02d %02d:%02d:%02d \n\n",
				   				datetime.tm_year + 1900, datetime.tm_mon + 1, datetime.tm_mday,
				   				datetime.tm_hour, datetime.tm_min, datetime.tm_sec);
			}
			else{
				(void) printk("\nFail to set time! \n\n");
			}
		}
		else{
			(void) printk("Wrong input! Try again \n\n");
		}
	}

	return 0;
}

int *set_rtc_time(void) {
    int date[6] = {0, 0, 0, 0, 0, 0};
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int _bool = 0;
    volatile int it = {0};

    (void) printk("\nEnter time in format of [YYYY-MM-DD hh:mm:ss]: ");

    while (1) {
        char user_input = console_getchar();
        if (user_input >= '0' && user_input <= '9') {
			(void)console_putchar(user_input);
            date[it] = date[it] * 10 + (user_input - '0');
        } else if ((user_input == '-' && it < 3) ||
                   (user_input == ':' && it >= 3 && it <= 5) ||
                   (user_input == ' ' && it == 2)) {
				(void)console_putchar(user_input);
            it++;
        } else if (user_input == '\r' || it > 5) {
            break;
        }
    }

    date[0] -= 1900;
    if (date[0] > 0) {
        if ((date[0] % 4 == 0 && date[0] % 100 != 0) || date[0] % 400 == 0) {
            days[date[1] - 1] = 29;
        }

        date[1] -= 1;
        if (date[1] > 0 && date[1] <= 12) {
            if (date[2] > 0 && date[2] < days[date[1]]) {
                if (date[3] < 25 && date[3] >= 0 && date[4] < 60 && date[4] >= 0 && date[5] < 60 && date[5] >= 0) {
                    datetime.tm_year = date[0];
                    datetime.tm_mon = date[1];
                    datetime.tm_mday = date[2];
                    datetime.tm_hour = date[3];
                    datetime.tm_min = date[4];
                    datetime.tm_sec = date[5];

					if (0 != rtc_set_time(rtc_dev, &datetime))
					{
						printk("\nFailed to set the RTC time!\n");
						exit(1);
					}

                    _bool = 1;
                } else {
                    (void) printk("\nTime is out of scope! \n");
                }
            } else {
                (void) printk("\nDay is out of scope! \n");
            }
        } else {
            (void) printk("\nMonth is out of scope! \n");
        }
    } else {
        (void) printk("\nYear is out of scope! \n");
    }

    return _bool;
}
