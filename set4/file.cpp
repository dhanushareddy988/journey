#include <iostream>
using namespace std;

int main() {
  FILE *file = fopen("sd.txt", "rb");
  if (!file) {
    cout<<"cannot open file"<<endl;
    return 1;
  }
  while (!feof(file)) {
    char c = fgetc(file);
    if (c != EOF) {
      putchar(c);
    }
  }
  fclose (file);
  return 0;
}