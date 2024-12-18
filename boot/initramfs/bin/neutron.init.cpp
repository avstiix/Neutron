/*
 * The `neutron-init` program is the first user-space program executed by the microkernel 
 * after it has booted. Its main purpose is to initialize system services and then 
 * launch the user-space shell (`neutron-shell`). It serves as the entry point for the 
 * system to enter an interactive mode or begin additional setup tasks. This file is 
 * crucial because, without it, the system will not transition to user space or 
 * start any essential services.
 *
 * Warning
 * -------------------------------------
 * CRUCIAL FILE: If `neutron-init` fails or is missing, the kernel will not transition 
 * to user space, and the system will be stuck in the boot process. It must be correctly 
 * compiled and placed in the `bin/` directory of the `initramfs` to ensure system boot 
 * functionality.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Neutron Kernel initializing...\n");

    printf("Starting the Neutron shell...\n");

    execl("/bin/neutron-shell", "/bin/neutron-shell", NULL);

    perror("Failed to start shell");
    exit(1);
}