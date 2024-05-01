target extended-remote localhost:3333
symbol-file \build\blinkx.elf
mon reset halt
flushregs
thb app_main