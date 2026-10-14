void read_incremental_function_records(void)

{
  c2_incr_function_record *pcVar1;
  c2_coff_fn_section *pcVar2;
  uint16_t uVar3;
  uint16_t uVar4;
  uint32_t uVar5;
  c2_fe_symbol *pcVar6;
  c2_incr_id_cell *pcVar7;
  c2_coff_fn_section *pcVar8;
  uint16_t *puVar9;
  c2_incr_id_cell *pcVar10;
  int n;
  uint16_t local_10 [8];
  
  uVar5 = prevobj_read_dword();
  while (uVar5 != 0) {
    pcVar6 = fe_symbol_lookup_id(uVar5);
    if (((pcVar6 == (c2_fe_symbol *)0x0) || (pcVar6->cls != '\x04')) ||
       ((pcVar6->storage & 0x4000) == 0)) {
      n = 0;
      prevobj_read_word();
      uVar5 = prevobj_read_dword();
      while (uVar5 != 0) {
        uVar5 = prevobj_read_dword();
      }
      uVar5 = prevobj_read_dword();
      while (uVar5 != 0) {
        uVar5 = prevobj_read_dword();
      }
      uVar5 = prevobj_read_dword();
      if (uVar5 != 0) {
        puVar9 = local_10;
        do {
          uVar5 = incr_section_index_word(uVar5);
          *puVar9 = (uint16_t)uVar5;
          n = n + 1;
          puVar9 = puVar9 + 1;
          uVar5 = prevobj_read_dword();
        } while (uVar5 != 0);
      }
      if (((pcVar6 == (c2_fe_symbol *)0x0) || (pcVar6->cls != '\x04')) ||
         ((pcVar6->storage & 0xc000) != 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = pcVar6->id;
      }
      coff_incr_drop_sections(local_10,n,uVar5);
    }
    else {
      pcVar1 = pcVar6->incr;
      uVar4 = pcVar1->il_version;
      uVar3 = prevobj_read_word();
      if (((uVar4 != uVar3) || (g_incr_rebuild_line_info != 0)) || (uVar4 == 0xffff)) {
        pcVar6->fn_flags = pcVar6->fn_flags | 0x800;
      }
      uVar5 = prevobj_read_dword();
      pcVar10 = (c2_incr_id_cell *)0x0;
      while (uVar5 != 0) {
        pcVar7 = arena_alloc(0,8);
        pcVar7->sym_id = uVar5;
        if (pcVar10 == (c2_incr_id_cell *)0x0) {
          pcVar1->symbol_deps = pcVar7;
        }
        else {
          pcVar10->next = pcVar7;
        }
        uVar5 = prevobj_read_dword();
        pcVar10 = pcVar7;
      }
      uVar5 = prevobj_read_dword();
      pcVar10 = (c2_incr_id_cell *)0x0;
      if ((pcVar6->fn_flags & 0x800) == 0) {
        while (uVar5 != 0) {
          pcVar7 = arena_alloc(0,8);
          pcVar7->sym_id = uVar5;
          if (pcVar10 == (c2_incr_id_cell *)0x0) {
            pcVar1->callees = pcVar7;
          }
          else {
            pcVar10->next = pcVar7;
          }
          uVar5 = prevobj_read_dword();
          pcVar10 = pcVar7;
        }
      }
      else {
        while (uVar5 != 0) {
          uVar5 = prevobj_read_dword();
        }
      }
      uVar5 = prevobj_read_dword();
      pcVar2 = (c2_coff_fn_section *)0x0;
      while (uVar5 != 0) {
        pcVar8 = arena_alloc(0,8);
        uVar5 = incr_section_index_word(uVar5);
        pcVar8->number = uVar5;
        if (pcVar2 == (c2_coff_fn_section *)0x0) {
          pcVar1->sections = pcVar8;
        }
        else {
          pcVar2->next = pcVar8;
        }
        uVar5 = prevobj_read_dword();
        pcVar2 = pcVar8;
      }
    }
    uVar5 = prevobj_read_dword();
  }
  uVar5 = prevobj_read_dword();
  while (uVar5 != 0) {
    uVar4 = prevobj_read_word();
    pcVar6 = fe_symbol_lookup_id(uVar5);
    if ((pcVar6 != (c2_fe_symbol *)0x0) &&
       ((uVar3 = pcVar6->incr->il_version, uVar3 != uVar4 || (uVar3 == 0xffff)))) {
      pcVar6->fn_flags = pcVar6->fn_flags | 0x800;
    }
    uVar5 = prevobj_read_dword();
  }
  return;
}

