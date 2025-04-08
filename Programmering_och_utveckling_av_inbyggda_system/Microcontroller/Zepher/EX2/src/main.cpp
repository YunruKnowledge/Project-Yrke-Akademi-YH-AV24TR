#include <stdio.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/led.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define ZEPHYR_USER_NODE DT_PATH(zephyr_user)
const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(ZEPHYR_USER_NODE, led_gpios);

#define DELAY_LED 50	 // ms
#define DELAY_PRINT 1000 // ms

class Metro
{
	int64_t interval;
	int64_t previous_time;

public:
	Metro(int16_t _interval) : interval(_interval * 1000)
	{
		previous_time = k_uptime_ticks();
	}

	void toggle_led(const bool state)
	{
		gpio_pin_set(led.port, led.pin, state ? 1 : 0);
	}

	void print_to_terminal(void)
	{
		printk("Hello world \n");
	}

	bool check_interval(void)
	{
		bool status{false};
		int64_t current_time = k_uptime_ticks();

		if ((current_time - previous_time) >= interval)
		{
			previous_time = current_time;
			status = true;
		}

		return status;
	}
};

extern "C" int main(void)
{
	gpio_pin_configure(led.port, led.pin, GPIO_OUTPUT_INACTIVE);

	Metro led_task(DELAY_LED);
	Metro print_task(DELAY_PRINT);

	bool led_state = false;

	while (true)
	{
		if (print_task.check_interval())
		{
			print_task.print_to_terminal();
		}

		if (led_task.check_interval())
		{
			led_state = !led_state;
			led_task.toggle_led(led_state);
		}
	}
	return 0;
}
