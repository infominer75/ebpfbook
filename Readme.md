# Notes on eBPF Learning

This repository has been created to maintain a running record of complete examples that have serve as references for using 
the code examples from the book [Linux Observability with eBPF](https://www.oreilly.com/library/view/linux-observability-with/9781492050193/)

The original repo for the book is present here [bpftools - Linux Observability with eBPF](https://github.com/bpftools/linux-observability-with-bpf). However, the code snippets mentioned in the link require s vagrant based CentOS/Ubuntu setup with Linux Kernel version >=5.0.0

The snippets mentioned here work with Kernel version 4.15 which is available with Ubuntu 18.04 running on a desktop/laptop.  No Vagrant based environment is currently required to run these snippets.
The code snippets have *not* been validated or tested against a CentOS setup.

The snippets in this repository are being shared only as a reference and the authors of this repository are not responsible for  any errors/bugs that may be encountered within these snippets.

The snippets require the following additional dependencies to be downloaded and used as headers

* [libbpf](https://github.com/libbpf/libbpf.git)
* [Kernel protototype headers](https://github.com/netoptimizer/prototype-kernel.git)
