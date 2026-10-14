c2_fe_symbol * __fastcall asm_switch_segment(c2_fe_symbol *sec,int declare)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  uint32_t uVar4;
  
  if (sec != (c2_fe_symbol *)0x0) {
    if (sec != g_asm_current_segment) {
      g_asm_current_segment = (c2_fe_symbol *)asm_print_segment_end(g_asm_current_segment);
      pcVar1 = sec->name;
      if (*pcVar1 == '.') {
        pcVar1 = pcVar1 + 1;
      }
      iVar2 = asm_printf("%s\tSEGMENT",pcVar1);
      g_asm_column = g_asm_column + iVar2;
      if (declare != 0) {
        uVar4 = sec->storage;
        pcVar3 = "";
        pcVar1 = asm_align_keyword((sec->u3e).label_flags);
        asm_printf(" %s USE32%s \'%s\'",pcVar1,pcVar3,uVar4);
      }
      g_asm_column = 0;
      asm_printf(g_asm_newline);
    }
    return sec;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\list.c",0x5cc);
}

