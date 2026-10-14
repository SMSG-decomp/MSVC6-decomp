void __fastcall
coff_start_function(c2_fe_symbol *fn,char *source_file,int want_fpo_section,int first_line)

{
  uint8_t uVar1;
  byte bVar2;
  c2_incr_function_record *pcVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  c2_fe_symbol *pcVar6;
  c2_fe_symbol *pcVar7;
  uint uVar8;
  uint8_t *puVar9;
  byte *pbVar10;
  c2_coff_fn_section *pcVar11;
  int iVar12;
  uint32_t uVar13;
  uint16_t *puVar14;
  byte *pbVar15;
  char *pcVar16;
  bool bVar17;
  uint16_t section;
  char cVar18;
  int32_t iVar19;
  int32_t value;
  int iVar20;
  uint16_t auStack_10 [8];
  
  g_coff_function_first_line = first_line;
  if (g_coff_incremental_update != 0) {
    pcVar3 = fn->incr;
    pcVar11 = pcVar3->sections;
    if (pcVar11 == (c2_coff_fn_section *)0x0) {
      coff_reset_incr_slot_cursor();
    }
    else {
      iVar20 = 0;
      if (pcVar11 != (c2_coff_fn_section *)0x0) {
        puVar14 = auStack_10;
        do {
          iVar20 = iVar20 + 1;
          *puVar14 = (uint16_t)pcVar11->number;
          pcVar11 = pcVar11->next;
          puVar14 = puVar14 + 1;
        } while (pcVar11 != (c2_coff_fn_section *)0x0);
      }
      coff_incr_drop_sections(auStack_10,iVar20,0);
      pcVar3->sections = (c2_coff_fn_section *)0x0;
    }
  }
  coff_emit_symbol_once(fn);
  if ((g_opt_incremental != 0) && (g_incr_object_not_reusable == 0)) {
    if ((g_opt_edit_and_continue == 0) && (g_opt_ZX == 0)) {
      iVar20 = 0;
    }
    else {
      iVar20 = 1;
    }
    if ((first_line == 0) || ((g_opt_debug_info == 0 && (g_opt_line_numbers == 0)))) {
      iVar12 = 0;
    }
    else {
      uVar8 = 0xffffffff;
      pcVar16 = source_file;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar18 = *pcVar16;
        pcVar16 = pcVar16 + 1;
      } while (cVar18 != '\0');
      iVar12 = (~uVar8 - 1) / 0x12 + 8;
    }
    coff_alloc_symbol_slots(iVar12 + 3 + iVar20,0,g_incr_rebuild_line_info ^ 1);
  }
  uVar13 = fn->section_id;
  pcVar6 = fe_symbol_lookup_id(uVar13);
  coff_section_for_symbol(pcVar6);
  if (g_opt_debug_info != 0) {
    if (((fn->attrs & 0x20) == 0) && (g_opt_incremental == 0)) {
      g_debug_symbols_section = fe_symbol_lookup_id(7);
    }
    else {
      pcVar6 = fe_symbol_lookup_id(7);
      pcVar7 = fe_symbol_lookup_id(uVar13);
      g_debug_symbols_section = coff_new_comdat_section_symbol(pcVar7,pcVar6);
    }
  }
  pcVar6 = g_module_fpo_section;
  if (want_fpo_section != 0) {
    if (((fn->attrs & 0x20) == 0) && (g_opt_incremental == 0)) {
      g_coff_fpo_section = g_module_fpo_section;
    }
    else {
      pcVar7 = fe_symbol_lookup_id(uVar13);
      g_coff_fpo_section = coff_new_comdat_section_symbol(pcVar7,pcVar6);
    }
  }
  if (g_coff_last_file_name == (char *)0x0) {
    pbVar10 = (byte *)g_opt_f;
    pbVar15 = (byte *)source_file;
    pcVar16 = source_file;
    if (g_opt_f != (char *)0x0) {
      do {
        bVar2 = *pbVar10;
        bVar17 = bVar2 < *pbVar15;
        if (bVar2 != *pbVar15) {
LAB_1073e510:
          iVar20 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
          goto LAB_1073e4fd;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar10[1];
        bVar17 = bVar2 < pbVar15[1];
        if (bVar2 != pbVar15[1]) goto LAB_1073e510;
        pbVar10 = pbVar10 + 2;
        pbVar15 = pbVar15 + 2;
      } while (bVar2 != 0);
      iVar20 = 0;
LAB_1073e4fd:
      pcVar16 = source_file;
      if (iVar20 != 0) goto LAB_1073e3f8;
    }
LAB_1073e400:
    g_coff_last_file_name = pcVar16;
    if (g_opt_incremental == 0) goto LAB_1073e40d;
  }
  else {
LAB_1073e3f8:
    pcVar16 = g_coff_last_file_name;
    if (source_file == g_coff_last_file_name) goto LAB_1073e400;
  }
  if ((first_line != 0) && ((g_opt_debug_info != 0 || (g_opt_line_numbers != 0)))) {
    coff_add_file_symbol(source_file);
    g_coff_last_file_name = source_file;
  }
LAB_1073e40d:
  uVar8 = fn->storage >> 4 & 0xf;
  if (uVar8 == 3) {
    want_fpo_section._0_1_ = '\x03';
  }
  else {
    if (uVar8 != 5) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",0x250);
    }
    want_fpo_section._0_1_ = '\x02';
  }
  value = fn->offset;
  pcVar6 = fe_symbol_lookup_id(fn->section_id);
  section = (uint16_t)pcVar6->coff_section;
  uVar8 = (uint)(first_line != 0);
  uVar4 = coff_symbol_type_bits(fn);
  iVar19 = value;
  uVar5 = section;
  puVar9 = fe_symbol_external_name(fn);
  g_coff_function_symbol =
       coff_add_global_symbol(fn->id,(char *)puVar9,uVar5,(char)want_fpo_section,iVar19,uVar4,uVar8)
  ;
  if (((byte)fn->attrs & 0xc) == 0xc) {
    pcVar6 = cor_helper_symbol(fn,1);
    iVar20 = 0;
    uVar4 = coff_symbol_type_bits(pcVar6);
    cVar18 = '\x03';
    iVar19 = value;
    uVar5 = section;
    puVar9 = fe_symbol_external_name(pcVar6);
    uVar13 = coff_add_global_symbol(pcVar6->id,(char *)puVar9,uVar5,cVar18,iVar19,uVar4,iVar20);
    pcVar6->coff_symbol = uVar13;
    uVar1 = (fn->u4a).function.cor_type;
    pcVar6->flags31 = pcVar6->flags31 | 1;
    if (uVar1 == '\x03') {
      (fn->u4a).function.cor_type = '\0';
      pcVar6 = cor_helper_symbol(fn,1);
      iVar20 = 0;
      uVar5 = coff_symbol_type_bits(pcVar6);
      cVar18 = '\x03';
      puVar9 = fe_symbol_external_name(pcVar6);
      uVar13 = coff_add_global_symbol(pcVar6->id,(char *)puVar9,section,cVar18,value,uVar5,iVar20);
      pcVar6->coff_symbol = uVar13;
      bVar2 = pcVar6->flags31;
      (fn->u4a).function.cor_type = '\x03';
      pcVar6->flags31 = bVar2 | 1;
    }
  }
  if (fn->coff_symbol == 0) {
    fn->coff_symbol = g_coff_function_symbol;
    fn->flags31 = fn->flags31 | 1;
  }
  return;
}

