int comprimento_rec (char* s)
	if (s[0] == '\0')
		return 0;
	else
		return 1 + comprimento_rec(&s[1]);

