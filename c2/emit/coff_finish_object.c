void __cdecl coff_finish_object(void)

{
  c2_coff_sym_cell *pcVar1;
  uint32_t characteristics;
  c2_coff_fn_section *fn_section;
  int iVar2;
  uint8_t value;
  uint16_t *puVar3;
  c2_coff_sym_cell **ppcVar4;
  uint16_t section_numbers [8];
  c2_incr_function_record *incr;
  c2_fe_symbol *sym;
  
  ppcVar4 = g_coff_pending_sections;
  do {
    for (pcVar1 = *ppcVar4; pcVar1 != (c2_coff_sym_cell *)0x0; pcVar1 = pcVar1->next) {
      sym = pcVar1->sym;
      characteristics = coff_align_characteristic((sym->u3e).label_flags);
      coff_section_set_flags((uint16_t)sym->coff_section,characteristics);
      if (sym->offset != 0) {
        coff_pad_section_to_offset(sym);
      }
    }
    ppcVar4 = ppcVar4 + 1;
  } while ((int)ppcVar4 < 0x107996c0);
  coff_check_extended_relocs();
  if (g_opt_incremental != 0) {
    g_incr_info_buffer = arena_alloc(0,0x2800);
    g_incr_info_free = 0x2800;
    if (g_incr_object_not_reusable == 0) {
      value = '\x05';
    }
    else {
      value = '\0';
    }
    g_incr_info_cursor = g_incr_info_buffer;
    incr_stream_put_byte(value);
    incr_write_compile_options();
    sym = g_function_list;
    if (g_coff_incremental_update != 0) {
      for (; sym != (c2_fe_symbol *)0x0; sym = sym->next_function) {
        incr = sym->incr;
        fn_section = incr->sections;
        if (fn_section != (c2_coff_fn_section *)0x0) {
          iVar2 = 0;
          if (fn_section != (c2_coff_fn_section *)0x0) {
            puVar3 = section_numbers;
            do {
              iVar2 = iVar2 + 1;
              *puVar3 = (uint16_t)fn_section->number;
              fn_section = fn_section->next;
              puVar3 = puVar3 + 1;
            } while (fn_section != (c2_coff_fn_section *)0x0);
          }
          coff_incr_drop_sections(section_numbers,iVar2,0);
          incr->sections = (c2_coff_fn_section *)0x0;
        }
      }
    }
  }
  coff_write_sections();
  if (g_opt_incremental != 0) {
    if (g_coff_incremental_update != 0) {
      incr_remap_function_section_indices();
    }
    incr_write_function_records();
    incr_write_extern_names();
    incr_write_flagged_global_ids();
    if (g_incr_stream_written == 0) {
      iVar2 = pdb_stream_replace(g_incr_info_buffer,0x2800 - g_incr_info_free);
      if (iVar2 == 0) {
        iVar2 = 0x1a7;
        goto LAB_10780319;
      }
    }
    else {
      iVar2 = pdb_stream_append(g_incr_info_buffer,0x2800 - g_incr_info_free);
      if (iVar2 == 0) {
        iVar2 = 0x1a4;
LAB_10780319:
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coff.c",iVar2);
      }
    }
  }
  coff_free_symbol_slots();
  fclose(g_object_file);
  g_object_file_open = 0;
  return;
}

