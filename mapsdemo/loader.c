#include <stdio.h>
#include "bpf_load.h"
#include<bpf/bpf.h>
#include<errno.h>

int main(int argc, char **argv) {
  int ret = load_bpf_file("bpf_program.o");
  if (ret != 0) {
    printf("The kernel didn't load the BPF program\n");
    printf("Return code: %d\n", ret);
    return -1;
  } else {
    printf("Loaded BPF program with return code: %d\n", ret);
  }
  //read the value from the BPF map created by the loaded eBPF program and print it to the screen
  int key = 1, value, result;
  while(1){
    result = bpf_map_lookup_elem(map_data[0].fd, &key, &value);
    if (result == 0) {
      printf("Value read from map: '%d'\n", value);
    } else {
      printf("Failed to read value from map: %d (%s)\n", result, strerror(errno));
    }
  }
  
  return 0;
}

