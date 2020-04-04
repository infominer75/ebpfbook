CLANG = clang

LINUXINCLUDE += -I

EXECABLE = monitor-exec

BPFCODE = bpf_program

BPFTOOLS = /software/bpf/prototype-kernel/kernel/samples/bpf/
BPFLOADER = $(BPFTOOLS)/bpf_load.c

CCINCLUDE += -I/usr/src/linux-source-4.15.0/linux-source-4.15.0/tools/testing/selftests/bpf
CCINCLUDE += -I/software/bpf/prototype-kernel/kernel/samples/bpf/

LOADINCLUDE += -I/usr/src/linux-source-4.15.0/linux-source-4.15.0/samples/bpf
LOADINCLUDE += -I/usr/src/linux-source-4.15.0/linux-source-4.15.0/tools/lib
LOADINCLUDE += -I/usr/src/linux-source-4.15.0/linux-source-4.15.0/tools/perf
LOADINCLUDE += -I/usr/src/linux-source-4.15.0/linux-source-4.15.0/tools/include
LOADINCLUDE += -I/usr/include/x86_64-linux-gnu
LIBRARY_PATH = -L/usr/local/lib64
LIBRARY_PATH += -L/software/bpf/libbpf/lib
BPFSO = -lbpf

.PHONY: clean $(CLANG) bpfload build

clean:
	rm -f *.o *.so $(EXECABLE)

build: ${BPFCODE.c} ${BPFLOADER}
	$(CLANG) -O2 -target bpf -c $(BPFCODE:=.c) $(CCINCLUDE) -o ${BPFCODE:=.o}

bpfload: build
	clang -o $(EXECABLE) -lelf $(LOADINCLUDE) $(LIBRARY_PATH) $(BPFSO) \
        $(BPFLOADER) loader.c

$(EXECABLE): bpfload

.DEFAULT_GOAL := $(EXECABLE)
