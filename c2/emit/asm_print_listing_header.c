void __fastcall asm_print_listing_header(char *title)

{
  c2_fe_symbol *pcVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  asm_printf("\tTITLE\t%s\n\t.386P",title);
  g_asm_column = 0;
  asm_printf(g_asm_newline);
  asm_printf("include listing.inc");
  g_asm_column = 0;
  asm_printf(g_asm_newline);
  pcVar1 = g_section_list;
  if (g_opt_dos != 0) {
    iVar2 = asm_printf("if @Version gt 510\n.model FLAT\nelse\n");
    g_asm_column = g_asm_column + iVar2;
    pcVar1 = g_section_list;
  }
  for (; pcVar1 != (c2_fe_symbol *)0x0; pcVar1 = (pcVar1->u32).next_section) {
    if (((pcVar1->u44).section_class != '\n') && ((pcVar1->u44).section_class != '\t')) {
      asm_switch_segment(pcVar1,1);
      asm_print_segment_end(pcVar1);
    }
  }
  if (g_section_list == (c2_fe_symbol *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\mdlist.c",0x5d);
  }
  iVar2 = asm_printf("%s\tGROUP",g_segment_group_name);
  g_asm_column = g_asm_column + iVar2;
  iVar2 = 0;
  for (pcVar1 = g_section_list; pcVar1 != (c2_fe_symbol *)0x0; pcVar1 = (pcVar1->u32).next_section)
  {
    iVar4 = iVar2;
    if (pcVar1->level == '\0') {
      iVar4 = iVar2 + 1;
      if (iVar2 != 0) {
        asm_printf(",");
      }
      pcVar3 = pcVar1->name;
      if (*pcVar3 == '.') {
        pcVar3 = pcVar3 + 1;
      }
      iVar2 = asm_printf(" %s",pcVar3);
      g_asm_column = g_asm_column + iVar2;
    }
    iVar2 = iVar4;
  }
  g_asm_column = 0;
  asm_printf(g_asm_newline);
  if (g_opt_dos == 0) {
    pcVar3 = g_text_section_sym->name;
    if (*pcVar3 == '.') {
      pcVar3 = pcVar3 + 1;
    }
  }
  else {
    pcVar3 = "FLAT";
  }
  asm_printf("\tASSUME\tCS: %s, DS: %s, SS: %s\n",pcVar3,g_segment_group_name,g_segment_group_name);
  if (g_opt_dos != 0) {
    asm_printf("endif\n");
  }
  g_asm_current_segment = (c2_fe_symbol *)0x0;
  return;
}

