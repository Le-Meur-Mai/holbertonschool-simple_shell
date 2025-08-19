#include "main.h"
/**
 * _Wexitstatus - Extracts the exit status of a process
 * @status: The status value returned by wait
 *
 * Return: The exit status (8 bits) of the process
 *
 * Description:
 * This function mimics the behavior of the WEXITSTATUS macro.
 * It shifts the status 8 bits to the right and masks it with
 * 0xFF to extract the actual exit code of a terminated child
 * process.
 */
int _Wexitstatus(int status)
{
	return ((status >> 8) & 0xFF);
}
