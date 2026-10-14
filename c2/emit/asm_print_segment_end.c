int __fastcall asm_print_segment_end(void *sec)

{
  char *pcVar1;
  
  if (sec != (void *)0x0) {
    if ((*(char *)((int)sec + 0x43) == '\a') && (*(char *)((int)sec + 0x52) != '\x05')) {
      sec = *(void **)((int)sec + 0x4a);
    }
    pcVar1 = *(char **)((int)sec + 0x18);
    if (*pcVar1 == '.') {
      pcVar1 = pcVar1 + 1;
    }
    asm_printf("%s\tENDS",pcVar1);
    g_asm_column = 0;
    asm_printf(g_asm_newline);
  }
  return 0;
}

