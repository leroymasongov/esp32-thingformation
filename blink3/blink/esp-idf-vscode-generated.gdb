target extended-remote :3333
symbol-file /build/blink.elf
mon reset halt
flushregs
thb app_main
c