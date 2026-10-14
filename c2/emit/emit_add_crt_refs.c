void emit_add_crt_refs(void)

{
  byte bVar1;
  c2_fe_symbol *pcVar2;
  c2_fe_symbol *pcVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  bool bVar8;
  
  if ((g_cur_func_sym != (c2_fe_symbol *)0x0) && (g_emit_coff_object == 0)) {
    pbVar6 = (byte *)g_cur_func_sym->name;
    pcVar7 = "_main";
    pbVar4 = pbVar6;
    do {
      bVar1 = *pbVar4;
      bVar8 = bVar1 < (byte)*pcVar7;
      if (bVar1 != *pcVar7) {
LAB_1076a73a:
        iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_1076a6f2;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar8 = bVar1 < (byte)pcVar7[1];
      if (bVar1 != pcVar7[1]) goto LAB_1076a73a;
      pbVar4 = pbVar4 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_1076a6f2:
    if (iVar5 != 0) {
      pcVar7 = "_WinMain";
      do {
        bVar1 = *pbVar6;
        bVar8 = bVar1 < (byte)*pcVar7;
        if (bVar1 != *pcVar7) {
LAB_1076a741:
          iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_1076a723;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar8 = bVar1 < (byte)pcVar7[1];
        if (bVar1 != pcVar7[1]) goto LAB_1076a741;
        pbVar6 = pbVar6 + 2;
        pcVar7 = pcVar7 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_1076a723:
      if (iVar5 != 0) goto LAB_1073f134;
    }
    fe_symbol_lookup_name("__acrtused");
  }
LAB_1073f134:
  if (g_floats_used != '\0') {
    fe_symbol_lookup_name("__fltused");
  }
  if (g_opt_fortran_frontend != 0) {
    g_debug_types_section = (c2_fe_symbol *)0x0;
    g_debug_symbols_section = (c2_fe_symbol *)0x0;
    g_text_section_sym = fe_symbol_lookup_id(5);
    g_data_section_sym = fe_symbol_lookup_id(2);
    g_const_section_sym = fe_symbol_lookup_id(3);
    g_bss_section_sym = fe_symbol_lookup_id(4);
    if (g_opt_debug_info != 0) {
      g_debug_types_section = fe_symbol_lookup_id(8);
      g_debug_symbols_section = fe_symbol_lookup_id(7);
    }
    pcVar3 = g_bss_section_sym;
    pcVar2 = g_debug_symbols_section;
    if (g_text_section_sym != (c2_fe_symbol *)0x0) {
      (g_text_section_sym->u4a).section.section_number = 1;
    }
    if (g_data_section_sym != (c2_fe_symbol *)0x0) {
      (g_data_section_sym->u4a).section.section_number = 2;
    }
    if (pcVar3 != (c2_fe_symbol *)0x0) {
      (pcVar3->u4a).section.section_number = 4;
    }
    if (g_const_section_sym != (c2_fe_symbol *)0x0) {
      (g_const_section_sym->u4a).section.section_number = 3;
    }
    if (pcVar2 != (c2_fe_symbol *)0x0) {
      (pcVar2->u4a).section.section_number = 5;
      (pcVar2->u3e).label_flags = 1;
      pcVar2->combine = '\0';
      pcVar2->level = '\x01';
    }
    pcVar2 = g_debug_types_section;
    if (g_debug_types_section != (c2_fe_symbol *)0x0) {
      (g_debug_types_section->u4a).section.section_number = 6;
      (pcVar2->u3e).label_flags = 1;
      pcVar2->combine = '\0';
      pcVar2->level = '\x01';
    }
  }
  return;
}

