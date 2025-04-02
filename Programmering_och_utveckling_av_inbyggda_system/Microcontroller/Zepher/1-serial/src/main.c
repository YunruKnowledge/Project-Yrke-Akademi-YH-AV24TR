/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of serial I/O
 *        Look at: https://docs.zephyrproject.org/latest/doxygen/html/group__console__api.html
 *                 https://docs.zephyrproject.org/latest/services/logging/index.html
 *
 * @version 0.1
 * @date 2025-03-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/console/console.h>

LOG_MODULE_REGISTER(echo, LOG_LEVEL_ERR);

int main(void)
{
	int chr;
	console_init();

	while (1)
	{
		chr = console_getchar();

		if (chr < 0)
		{
			LOG_ERR("An error occurred!");
		}
		else if (chr == '\r')
		{
			(void)console_putchar('\n');
		}
		else
		{
			(void)console_putchar(chr);
		}
	}

	return 0;
}
