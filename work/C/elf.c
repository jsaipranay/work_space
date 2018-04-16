juluri@juluri:~$ readelf -a a.out
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              EXEC (Executable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x400520
  Start of program headers:          64 (bytes into file)
  Start of section headers:          4520 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         9
  Size of section headers:           64 (bytes)
  Number of section headers:         30
  Section header string table index: 27

Section Headers:
  [Nr] Name              Type             Address           Offset
       Size              EntSize          Flags  Link  Info  Align
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .interp           PROGBITS         0000000000400238  00000238
       000000000000001c  0000000000000000   A       0     0     1
  [ 2] .note.ABI-tag     NOTE             0000000000400254  00000254
       0000000000000020  0000000000000000   A       0     0     4
  [ 3] .note.gnu.build-i NOTE             0000000000400274  00000274
       0000000000000024  0000000000000000   A       0     0     4
  [ 4] .gnu.hash         GNU_HASH         0000000000400298  00000298
       000000000000001c  0000000000000000   A       5     0     8
  [ 5] .dynsym           DYNSYM           00000000004002b8  000002b8
       0000000000000090  0000000000000018   A       6     1     8
  [ 6] .dynstr           STRTAB           0000000000400348  00000348
       0000000000000073  0000000000000000   A       0     0     1
  [ 7] .gnu.version      VERSYM           00000000004003bc  000003bc
       000000000000000c  0000000000000002   A       5     0     2
  [ 8] .gnu.version_r    VERNEED          00000000004003c8  000003c8
       0000000000000040  0000000000000000   A       6     1     8
  [ 9] .rela.dyn         RELA             0000000000400408  00000408
       0000000000000018  0000000000000018   A       5     0     8
  [10] .rela.plt         RELA             0000000000400420  00000420
       0000000000000078  0000000000000018   A       5    12     8
  [11] .init             PROGBITS         0000000000400498  00000498
       000000000000001a  0000000000000000  AX       0     0     4
  [12] .plt              PROGBITS         00000000004004c0  000004c0
       0000000000000060  0000000000000010  AX       0     0     16
  [13] .text             PROGBITS         0000000000400520  00000520
       00000000000001f2  0000000000000000  AX       0     0     16
  [14] .fini             PROGBITS         0000000000400714  00000714
       0000000000000009  0000000000000000  AX       0     0     4
  [15] .rodata           PROGBITS         0000000000400720  00000720
       000000000000000e  0000000000000000   A       0     0     4
  [16] .eh_frame_hdr     PROGBITS         0000000000400730  00000730
       0000000000000034  0000000000000000   A       0     0     4
  [17] .eh_frame         PROGBITS         0000000000400768  00000768
       00000000000000f4  0000000000000000   A       0     0     8
  [18] .init_array       INIT_ARRAY       0000000000600e10  00000e10
       0000000000000008  0000000000000000  WA       0     0     8
  [19] .fini_array       FINI_ARRAY       0000000000600e18  00000e18
       0000000000000008  0000000000000000  WA       0     0     8
  [20] .jcr              PROGBITS         0000000000600e20  00000e20
       0000000000000008  0000000000000000  WA       0     0     8
  [21] .dynamic          DYNAMIC          0000000000600e28  00000e28
       00000000000001d0  0000000000000010  WA       6     0     8
  [22] .got              PROGBITS         0000000000600ff8  00000ff8
       0000000000000008  0000000000000008  WA       0     0     8
  [23] .got.plt          PROGBITS         0000000000601000  00001000
       0000000000000040  0000000000000008  WA       0     0     8
  [24] .data             PROGBITS         0000000000601040  00001040
       0000000000000010  0000000000000000  WA       0     0     8
  [25] .bss              NOBITS           0000000000601050  00001050
       0000000000000008  0000000000000000  WA       0     0     1
  [26] .comment          PROGBITS         0000000000000000  00001050
       000000000000004f  0000000000000001  MS       0     0     1
  [27] .shstrtab         STRTAB           0000000000000000  0000109f
       0000000000000108  0000000000000000           0     0     1
  [28] .symtab           SYMTAB           0000000000000000  00001928
       0000000000000648  0000000000000018          29    45     8
  [29] .strtab           STRTAB           0000000000000000  00001f70
       000000000000026d  0000000000000000           0     0     1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), l (large)
  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)

There are no section groups in this file.

Program Headers:
  Type           Offset             VirtAddr           PhysAddr
                 FileSiz            MemSiz              Flags  Align
  PHDR           0x0000000000000040 0x0000000000400040 0x0000000000400040
                 0x00000000000001f8 0x00000000000001f8  R E    8
  INTERP         0x0000000000000238 0x0000000000400238 0x0000000000400238
                 0x000000000000001c 0x000000000000001c  R      1
      [Requesting program interpreter: /lib64/ld-linux-x86-64.so.2]
  LOAD           0x0000000000000000 0x0000000000400000 0x0000000000400000
                 0x000000000000085c 0x000000000000085c  R E    200000
  LOAD           0x0000000000000e10 0x0000000000600e10 0x0000000000600e10
                 0x0000000000000240 0x0000000000000248  RW     200000
  DYNAMIC        0x0000000000000e28 0x0000000000600e28 0x0000000000600e28
                 0x00000000000001d0 0x00000000000001d0  RW     8
  NOTE           0x0000000000000254 0x0000000000400254 0x0000000000400254
                 0x0000000000000044 0x0000000000000044  R      4
  GNU_EH_FRAME   0x0000000000000730 0x0000000000400730 0x0000000000400730
                 0x0000000000000034 0x0000000000000034  R      4
  GNU_STACK      0x0000000000000000 0x0000000000000000 0x0000000000000000
                 0x0000000000000000 0x0000000000000000  RW     10
  GNU_RELRO      0x0000000000000e10 0x0000000000600e10 0x0000000000600e10
                 0x00000000000001f0 0x00000000000001f0  R      1

 Section to Segment mapping:
  Segment Sections...
   00     
   01     .interp 
   02     .interp .note.ABI-tag .note.gnu.build-id .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rela.dyn .rela.plt .init .plt .text .fini .rodata .eh_frame_hdr .eh_frame 
   03     .init_array .fini_array .jcr .dynamic .got .got.plt .data .bss 
   04     .dynamic 
   05     .note.ABI-tag .note.gnu.build-id 
   06     .eh_frame_hdr 
   07     
   08     .init_array .fini_array .jcr .dynamic .got 

Dynamic section at offset 0xe28 contains 24 entries:
  Tag        Type                         Name/Value
 0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]
 0x000000000000000c (INIT)               0x400498
 0x000000000000000d (FINI)               0x400714
 0x0000000000000019 (INIT_ARRAY)         0x600e10
 0x000000000000001b (INIT_ARRAYSZ)       8 (bytes)
 0x000000000000001a (FINI_ARRAY)         0x600e18
 0x000000000000001c (FINI_ARRAYSZ)       8 (bytes)
 0x000000006ffffef5 (GNU_HASH)           0x400298
 0x0000000000000005 (STRTAB)             0x400348
 0x0000000000000006 (SYMTAB)             0x4002b8
 0x000000000000000a (STRSZ)              115 (bytes)
 0x000000000000000b (SYMENT)             24 (bytes)
 0x0000000000000015 (DEBUG)              0x0
 0x0000000000000003 (PLTGOT)             0x601000
 0x0000000000000002 (PLTRELSZ)           120 (bytes)
 0x0000000000000014 (PLTREL)             RELA
 0x0000000000000017 (JMPREL)             0x400420
 0x0000000000000007 (RELA)               0x400408
 0x0000000000000008 (RELASZ)             24 (bytes)
 0x0000000000000009 (RELAENT)            24 (bytes)
 0x000000006ffffffe (VERNEED)            0x4003c8
 0x000000006fffffff (VERNEEDNUM)         1
 0x000000006ffffff0 (VERSYM)             0x4003bc
 0x0000000000000000 (NULL)               0x0

Relocation section '.rela.dyn' at offset 0x408 contains 1 entries:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
000000600ff8  000400000006 R_X86_64_GLOB_DAT 0000000000000000 __gmon_start__ + 0

Relocation section '.rela.plt' at offset 0x420 contains 5 entries:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
000000601018  000100000007 R_X86_64_JUMP_SLO 0000000000000000 __stack_chk_fail + 0
000000601020  000200000007 R_X86_64_JUMP_SLO 0000000000000000 printf + 0
000000601028  000300000007 R_X86_64_JUMP_SLO 0000000000000000 __libc_start_main + 0
000000601030  000400000007 R_X86_64_JUMP_SLO 0000000000000000 __gmon_start__ + 0
000000601038  000500000007 R_X86_64_JUMP_SLO 0000000000000000 __isoc99_scanf + 0

The decoding of unwind sections for machine type Advanced Micro Devices X86-64 is not currently supported.

Symbol table '.dynsym' contains 6 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@GLIBC_2.4 (2)
     2: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND printf@GLIBC_2.2.5 (3)
     3: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@GLIBC_2.2.5 (3)
     4: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
     5: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __isoc99_scanf@GLIBC_2.7 (4)

Symbol table '.symtab' contains 67 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000400238     0 SECTION LOCAL  DEFAULT    1 
     2: 0000000000400254     0 SECTION LOCAL  DEFAULT    2 
     3: 0000000000400274     0 SECTION LOCAL  DEFAULT    3 
     4: 0000000000400298     0 SECTION LOCAL  DEFAULT    4 
     5: 00000000004002b8     0 SECTION LOCAL  DEFAULT    5 
     6: 0000000000400348     0 SECTION LOCAL  DEFAULT    6 
     7: 00000000004003bc     0 SECTION LOCAL  DEFAULT    7 
     8: 00000000004003c8     0 SECTION LOCAL  DEFAULT    8 
     9: 0000000000400408     0 SECTION LOCAL  DEFAULT    9 
    10: 0000000000400420     0 SECTION LOCAL  DEFAULT   10 
    11: 0000000000400498     0 SECTION LOCAL  DEFAULT   11 
    12: 00000000004004c0     0 SECTION LOCAL  DEFAULT   12 
    13: 0000000000400520     0 SECTION LOCAL  DEFAULT   13 
    14: 0000000000400714     0 SECTION LOCAL  DEFAULT   14 
    15: 0000000000400720     0 SECTION LOCAL  DEFAULT   15 
    16: 0000000000400730     0 SECTION LOCAL  DEFAULT   16 
    17: 0000000000400768     0 SECTION LOCAL  DEFAULT   17 
    18: 0000000000600e10     0 SECTION LOCAL  DEFAULT   18 
    19: 0000000000600e18     0 SECTION LOCAL  DEFAULT   19 
    20: 0000000000600e20     0 SECTION LOCAL  DEFAULT   20 
    21: 0000000000600e28     0 SECTION LOCAL  DEFAULT   21 
    22: 0000000000600ff8     0 SECTION LOCAL  DEFAULT   22 
    23: 0000000000601000     0 SECTION LOCAL  DEFAULT   23 
    24: 0000000000601040     0 SECTION LOCAL  DEFAULT   24 
    25: 0000000000601050     0 SECTION LOCAL  DEFAULT   25 
    26: 0000000000000000     0 SECTION LOCAL  DEFAULT   26 
    27: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    28: 0000000000600e20     0 OBJECT  LOCAL  DEFAULT   20 __JCR_LIST__
    29: 0000000000400550     0 FUNC    LOCAL  DEFAULT   13 deregister_tm_clones
    30: 0000000000400580     0 FUNC    LOCAL  DEFAULT   13 register_tm_clones
    31: 00000000004005c0     0 FUNC    LOCAL  DEFAULT   13 __do_global_dtors_aux
    32: 0000000000601050     1 OBJECT  LOCAL  DEFAULT   25 completed.6973
    33: 0000000000600e18     0 OBJECT  LOCAL  DEFAULT   19 __do_global_dtors_aux_fin
    34: 00000000004005e0     0 FUNC    LOCAL  DEFAULT   13 frame_dummy
    35: 0000000000600e10     0 OBJECT  LOCAL  DEFAULT   18 __frame_dummy_init_array_
    36: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS ddd.c
    37: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS crtstuff.c
    38: 0000000000400858     0 OBJECT  LOCAL  DEFAULT   17 __FRAME_END__
    39: 0000000000600e20     0 OBJECT  LOCAL  DEFAULT   20 __JCR_END__
    40: 0000000000000000     0 FILE    LOCAL  DEFAULT  ABS 
    41: 0000000000600e18     0 NOTYPE  LOCAL  DEFAULT   18 __init_array_end
    42: 0000000000600e28     0 OBJECT  LOCAL  DEFAULT   21 _DYNAMIC
    43: 0000000000600e10     0 NOTYPE  LOCAL  DEFAULT   18 __init_array_start
    44: 0000000000601000     0 OBJECT  LOCAL  DEFAULT   23 _GLOBAL_OFFSET_TABLE_
    45: 0000000000400710     2 FUNC    GLOBAL DEFAULT   13 __libc_csu_fini
    46: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTab
    47: 0000000000601040     0 NOTYPE  WEAK   DEFAULT   24 data_start
    48: 0000000000601050     0 NOTYPE  GLOBAL DEFAULT   24 _edata
    49: 0000000000400714     0 FUNC    GLOBAL DEFAULT   14 _fini
    50: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@@GLIBC_2
    51: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND printf@@GLIBC_2.2.5
    52: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@@GLIBC_
    53: 0000000000601040     0 NOTYPE  GLOBAL DEFAULT   24 __data_start
    54: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
    55: 0000000000601048     0 OBJECT  GLOBAL HIDDEN    24 __dso_handle
    56: 0000000000400720     4 OBJECT  GLOBAL DEFAULT   15 _IO_stdin_used
    57: 00000000004006a0   101 FUNC    GLOBAL DEFAULT   13 __libc_csu_init
    58: 0000000000601058     0 NOTYPE  GLOBAL DEFAULT   25 _end
    59: 0000000000400520     0 FUNC    GLOBAL DEFAULT   13 _start
    60: 0000000000601050     0 NOTYPE  GLOBAL DEFAULT   25 __bss_start
    61: 000000000040060d   145 FUNC    GLOBAL DEFAULT   13 main
    62: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _Jv_RegisterClasses
    63: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __isoc99_scanf@@GLIBC_2.7
    64: 0000000000601050     0 OBJECT  GLOBAL HIDDEN    24 __TMC_END__
    65: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
    66: 0000000000400498     0 FUNC    GLOBAL DEFAULT   11 _init

Version symbols section '.gnu.version' contains 6 entries:
 Addr: 00000000004003bc  Offset: 0x0003bc  Link: 5 (.dynsym)
  000:   0 (*local*)       2 (GLIBC_2.4)     3 (GLIBC_2.2.5)   3 (GLIBC_2.2.5)
  004:   0 (*local*)       4 (GLIBC_2.7)  

Version needs section '.gnu.version_r' contains 1 entries:
 Addr: 0x00000000004003c8  Offset: 0x0003c8  Link: 6 (.dynstr)
  000000: Version: 1  File: libc.so.6  Cnt: 3
  0x0010:   Name: GLIBC_2.7  Flags: none  Version: 4
  0x0020:   Name: GLIBC_2.2.5  Flags: none  Version: 3
  0x0030:   Name: GLIBC_2.4  Flags: none  Version: 2

Displaying notes found at file offset 0x00000254 with length 0x00000020:
  Owner                 Data size	Description
  GNU                  0x00000010	NT_GNU_ABI_TAG (ABI version tag)
    OS: Linux, ABI: 2.6.24

Displaying notes found at file offset 0x00000274 with length 0x00000024:
  Owner                 Data size	Description
  GNU                  0x00000014	NT_GNU_BUILD_ID (unique build ID bitstring)
    Build ID: 96894b420258ba35cbc1d46733530678f995c22a

