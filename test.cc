#include <unistd.h>

int main(void)
{

	char *arr[] = { "./a.out", 0 };

	execve("./a.out", arr, NULL);

	return(0);


}
