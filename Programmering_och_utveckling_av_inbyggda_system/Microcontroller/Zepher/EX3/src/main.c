#include <zephyr/drivers/counter.h>
#include <zephyr/drivers/led.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <zephyr/sys/printk.h>

LOG_MODULE_REGISTER(led_pwm);

#define PWM_LED_NODE DT_NODELABEL(pwm_led)
#define PWM_LED_PERIOD DT_PWMS_PERIOD(PWM_LED_NODE)

#define DELAY_MS 30
#define STEP 1
#define MAX_BRIGHTNESS 100
#define MIN_BRIGHTNESS 0

int main(void)
{
	const struct pwm_dt_spec pwm_led = PWM_DT_SPEC_GET(PWM_LED_NODE);
	if (!pwm_is_ready_dt(&pwm_led))
	{
		LOG_ERR("Error: didn't find %s device", DT_NODE_FULL_NAME(PWM_LED_NODE));
		return EXIT_FAILURE;
	}

	bool fade_in = true;
	uint8_t precent = 0;

	while (true)
	{
		if (fade_in)
		{
			precent += STEP;

			if (precent >= MAX_BRIGHTNESS)
			{
				fade_in = false;
			}
			else
			{
				;
			}
		}
		else
		{
			precent -= STEP;

			if (precent <= MIN_BRIGHTNESS)
			{
				fade_in = true;
			}
			else
			{
				;
			}
		}

		pwm_set_pulse_dt(&pwm_led, precent * 100000);
		printk("DEBUG: precent %d\n", precent);
		k_msleep(DELAY_MS);
	}
	return EXIT_SUCCESS;
}
