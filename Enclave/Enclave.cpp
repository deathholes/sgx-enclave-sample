#include "Enclave.h"
#include "Enclave_t.h"  /* print_string */

#include "sgx_trts_exception.h"

#define MAX_STR_LEN 80
#define MAX_INT 923372036854775807

int exception_handler(sgx_exception_info_t *info)
{
    switch(info->exception_type)
		{
		case SGX_EXCEPTION_HARDWARE :
			break;
		case SGX_EXCEPTION_SOFTWARE :
			break;
		}
    switch (info->exception_vector)
    {
    case SGX_EXCEPTION_VECTOR_AC:
        break;
    case SGX_EXCEPTION_VECTOR_BP:
        break;
    case SGX_EXCEPTION_VECTOR_BR:
        break;
    case SGX_EXCEPTION_VECTOR_DB:
        break;
    case SGX_EXCEPTION_VECTOR_DE:
        break;
    case SGX_EXCEPTION_VECTOR_MF:
        break;
    case SGX_EXCEPTION_VECTOR_UD:
        break;
    case SGX_EXCEPTION_VECTOR_XM:
        break;
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

int add_hooks_for_exception()
{
    void *ret = sgx_register_exception_handler(10,exception_handler);
    if(ret !=  NULL)
    {
        ocall_print_string("registered");
    }
    else{
        ocall_print_string("not registered");
    }
    
    ret = sgx_register_exception_handler(0,exception_handler);
    if(ret !=  NULL)
    {
        ocall_print_string("registered");
    }
    else{
        ocall_print_string("not registered");
    }

}

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

void ecall_garble_up_string( char *string)
{
	add_hooks_for_exception();
    int len = strlen (string);
    int i=len;

	//arithmetic exception. can be handled. Type : HARDWARE , Type: SGX_EXCEPTION_VECTOR_DE
    int x = 5/0;		//After adding a breakpoint at line #11, in debug mode, it is showing that the control is reaching there.
    
	//SIGSEGV Error reading non allocated pointer.
    char *ch = NULL;
    ch[1] = 'y';		//But for this it is not showing.
	
    ocall_print_string(string);
    string[i] = '\0';

}
