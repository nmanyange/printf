#include "main.h"

/**
 * int_params - clear struct
 * @params: parameter struct
 * @xy: argument pointer
 * Return: none
 */
void int_params(params_t *params, va_list xy)
{
	parsms->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UNIT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)xy;
}
