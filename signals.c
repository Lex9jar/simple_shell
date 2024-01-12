#include "shell.h"

/**
 * handle_Ctrl_C - Handles the Ctrl+C signal
 * @sig: Signal to handle
 *
 * return: void.
 */
void handle_Ctrl_C(int sig)
{
	char *prompt = "\n#cisfun$ ";

	(void)sig;
	s_printf(prompt);
}
/**
 * handle_Ctrl_L - Handles the Ctrl+C signal,
 * which clears the screen
 * @sig: Signal to handle
 *
 * Return: void.
 */
void handle_Ctrl_L(int sig)
{
	(void)sig;
	s_printf("\033[2J\033[H");
}
