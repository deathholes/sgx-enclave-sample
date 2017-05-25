#define MAX_STR_LEN 80

int strlen(char * str)
{
    int len = 0;
    while (len < MAX_STR_LEN && *str != '\0')
    {
        len ++;
        str ++;
    }
    return len;
}

int ecall_generate_random_number()
{
    return 4;
}

void ecall_garble_up_string( char *string)
{
    int i=0;
    int len = strlen (string);
    for(;i< len ; i++)
    {
        string[i] = string[i/4];
    }
}
