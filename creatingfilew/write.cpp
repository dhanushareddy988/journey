#include <iostream>
#include <string.h>
using namespace std;
int main() {
	FILE *handle = fopen("test", "wb");
	fputs("hello from file!", handle);
    fputs("This shows how to write!", handle);
	fclose(handle);
	handle = fopen("test", "r");
	char str[256] = {};
	fgets(str, 255, handle);
	cout<<str<<endl;;

	return 0;
}