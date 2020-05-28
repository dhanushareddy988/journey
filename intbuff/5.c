#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <emscripten.h>
void EMSCRIPTEN_KEEPALIVE buffer_overread(int start_pos, int end_pos) {
 char buf[200];
 char secret_password[256] = "dfghjkihgfcv";
 char msg[256] = "This is a very innocent message.";
 unsigned char e = end_pos;
 if (e > strlen(msg)) {
 printf("Do not try to read past the end.\n");
 } else {
 snprintf(buf,(end_pos - start_pos) + 1,"%s",&msg[start_pos]);
 printf("Contents: %s\n",buf);
 }
}