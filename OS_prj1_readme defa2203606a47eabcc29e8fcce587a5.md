# OS_prj1_readme

tag: homework

- 项目背景
    - 作为操作系统启动的部分，bootloader的重要性自不必言，一个可以支持大核加载和双系统乃至于多系统的bootoader更是值得学习和设计的
- 安装
    - 直接将oslab文件夹下载至2021UCAS秋季学期操作系统研讨课提供的Linux环境下即可

    ```bash
    git clone https://gitlab.agileserve.org.cn:8001/zhoupengyu19/oslab.git
    ```

    - 核心内容为在`oslab`目录下的虚拟镜像disk和在`./oslab/UCAS_OS/Project1-Bootloader` 目录下的

    ```bash
    bootblock.S
    createimage.c
    disk
    elf2char
    generateMapping
    head.S
    include
    kernel1.c
    kernel.c
    Makefile
    README.md
    riscv.lds
    ```

- 使用
    - 在`./oslab/UCAS_OS/Project1-Bootloader`处进行`make all`
    - 在`./oslab`处执行`sh run_qemu.sh`
    - 在`⇒`后输入loadboot
    - 若输入0，则进入小核kernel，会显示

        ```bash
        It's a bootloader...
        Hello OS
        bss check: t version: 0
        ```

        若输入1，则进入大核（因为初始化了一个大小为114514的int类型数组），会显示

        ```bash
        It's a bootloader...
        Hello OS
        bss check: t version: 1
        ```

        两个核所实现的功能是完全一致的，即在键盘敲击字符后，会在终端打印出来

    ```bash
    stu@stu:~/oslab/UCAS_OS/Project1-Bootloader$ cd
    stu@stu:~$ cd oslab/UCAS_OS/Project1-Bootloader/
    stu@stu:~/oslab/UCAS_OS/Project1-Bootloader$ make all
    gcc createimage.c -o  createimage -ggdb -Wall
    riscv64-unknown-linux-gnu-gcc -O2  -fno-builtin -nostdlib -T riscv.lds -Iinclude -Wall -mcmodel=medany -g  -o bootblock bootblock.S -e  main -g  -Ttext=0x50200000
    riscv64-unknown-linux-gnu-gcc -O2  -fno-builtin -nostdlib -T riscv.lds -Iinclude -Wall -mcmodel=medany -g  -o kernel1 kernel1.c head.S -Ttext=0x50200000
    riscv64-unknown-linux-gnu-gcc -O2  -fno-builtin -nostdlib -T riscv.lds -Iinclude -Wall -mcmodel=medany -g  -o kernel kernel.c head.S -Ttext=0x50200000
    ./createimage --extended bootblock kernel kernel1
    num of files is 3
    0x50200000: bootblock
    0
    0x50200000: kernel
    1
    0x50200000: kernel1
    896
    stu@stu:~/oslab/UCAS_OS/Project1-Bootloader$ cd ..
    stu@stu:~/oslab/UCAS_OS$ cd ..
    stu@stu:~/oslab$ sh run_qemu.sh
    run_qemu.sh: 3: [: unexpected operator
    qemu-system-riscv64: warning: No -bios option specified. Not loading a firmware.
    qemu-system-riscv64: warning: This default will change in a future QEMU release. Please use the -bios option to avoid breakages when this happens.
    qemu-system-riscv64: warning: See QEMU's deprecation documentation for details.

    U-Boot 2019.07 UCAS_OS v2.0 (Aug 24 2021 - 07:56:20 +0000)

    CPU:   rv64imafdcsu
    Model: riscv-virtio,qemu
    DRAM:  256 MiB
    In:    uart@60000000
    Out:   uart@60000000
    Err:   uart@60000000
    Net:   No ethernet found.
    Hit any key to stop autoboot:  0

    Device 0: QEMU VirtIO Block Device
                Type: Hard Disk
                Capacity: 0.4 MB = 0.0 GB (898 x 512)
    ... is now current device
    ** No partition table - virtio 0 **
    No ethernet found.
    No ethernet found.

    virtio read: device 0 block # 0, count 2 ... 2 blocks read: OK
    =>
    ```

- 主要项目负责人
    - 周鹏宇