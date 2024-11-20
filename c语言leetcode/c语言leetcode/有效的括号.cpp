bool isValid(char* s)
{
	int lenn = strlen(s);
	char* stack = (char*)malloc(sizeof(char) * lenn);
	int top = -1;
	for (int i = 0; i < lenn; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			stack[++top] = s[i];
		}
		if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (top == -1)
			{
				free(stack);
				return false;
			}
			if ((s[i] == ')' && stack[top--] != '(') || (s[i] == ']' && stack[top--] != '[') || (s[i] == '}' && stack[top--] != '{'))
			{
				free(stack);
				return false;
			}

		}
	}
	free(stack);
	return top == -1;
}