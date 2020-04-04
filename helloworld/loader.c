#include <stdio.h>
#include "bpf_load.h"

int main(int argc, char **argv) {
  int ret = load_bpf_file("bpf_program.o");
  if (ret != 0) {
    printf("The kernel didn't load the BPF program\n");
    printf("Return code: %d\n", ret);
    return -1;
  } else {
    printf("Loaded BPF program with return code: %d\n", ret);
  }
  read_trace_pipe();
  return 0;
}

