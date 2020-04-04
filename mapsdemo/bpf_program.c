#include<linux/bpf.h>
#include "bpf_helpers.h"
#include<errno.h>

//the below definition causes the verifier to allocate the map with the specified attributes
//prior to loading the eBPF program. The verifier then fixes the references to the map within eBPF
//program with the correct addresses. It also increments the reference count for these maps to 1
//so that the map is not cleaned up after the process loading the BPF program has exited while there
//are still kernel programs referencing it.
//For more details visit the SO Link : https://stackoverflow.com/questions/48122009/bpf-owner-of-a-map
//Additional details are present here : https://blogs.oracle.com/linux/notes-on-bpf-3
//Also refer : https://facebookmicrosites.github.io/bpf/blog/2018/08/31/object-lifetime.html for lifetime of BPF objects
struct bpf_map_def SEC("maps") my_map = {
    .type = BPF_MAP_TYPE_HASH,
    .key_size = sizeof(int),
    .value_size = sizeof(int),
    .max_entries = 100,
    .map_flags = BPF_F_NO_PREALLOC
};

SEC("tracepoint/syscalls/sys_enter_execve")
int bpf_prog(int argc, char **argv) {
    int key, value, result;
    key = 1, value = 1234;
    char success_msg[] = "Map updated with new element";
    char failure_msg[] = "Unable to place value in map";
    result = bpf_map_update_elem(&my_map, &key, &value, BPF_ANY);
    if (result == 0) {
        bpf_trace_printk(success_msg, sizeof(success_msg));
    } else {
        bpf_trace_printk(failure_msg, sizeof(failure_msg));
    }
    return 0;
}
char _license[] SEC("license") = "GPL";