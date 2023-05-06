.gba
.thumb

.open "rom.gba", "test.gba", 0x08000000

.org allocation
.area allocation_size
    .word 0xFEFEFEFE
    .importobj "build/linked.o"
    .word 0xFEFEFEFE
.endarea

.org 0x0811FEFC
.area 0x18, 0xFE
    ldr r3, =PartyMenuButtonHandler |1
    bx r3
    .pool
.endarea

.org 0x0811FB28
.area 0x3C, 0xFE
    ldr r3, =Task_HandleChooseMonInput |1
    bx r3
    .pool
.endarea

.close
