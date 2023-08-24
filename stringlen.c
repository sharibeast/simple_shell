
/**
 * _strlen - this function gives out the length of a str
 * @s: string ptr
 * Return: string length
 */
int _strlen(char *s)
{
	int n = 0;

	while (*(s + n) != '\0')
	{
		n++;
	}
	return (n);
}