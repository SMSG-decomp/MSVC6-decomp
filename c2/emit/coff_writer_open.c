uint32_t __fastcall coff_writer_open(c2_coff_open *desc)

{
  int iVar1;
  
  if (desc->version != 1) {
    return 0;
  }
  g_coff_source_file = desc->source_file;
  g_coff_alloc_fn = desc->alloc_fn;
  g_coff_machine = desc->machine;
  g_coff_line_info = desc->line_info;
  g_coff_open_reserved._0_2_ = desc->reserved0;
  g_coff_open_reserved._2_2_ = desc->reserved1;
  g_coff_section_numbers_final = (int)(g_coff_incremental_update == 0);
  g_coff_object_file = desc->object_file;
  g_coff_timestamp_fn = (g_coff_timestamp_fn_fn *)desc->timestamp_fn;
  g_coff_error_fn = desc->error_fn;
  g_coff_sections = coff_new_fixup_list(300);
  g_coff_section_order = (*g_coff_alloc_fn)(0x10);
  if (g_coff_incremental_update == 0) {
    g_coff_symbol_slots = malloc(0x1000);
    if (g_coff_symbol_slots == (c2_coff_slot **)0x0) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x33f);
    }
    g_coff_symbol_slot_capacity = 0x3ff;
  }
  g_coff_header_section_count._0_2_ = 0;
  g_coff_header_section_count._2_2_ = 0;
  g_coff_cur_code_section = g_coff_code_section_id;
  g_coff_current_section = (c2_coff_section *)0x0;
  g_coff_writer_mode = 1;
  reset_writer_lists();
  g_coff_string_table = coff_new_section_chunk(1,0);
  if (g_coff_incremental_update != 0) {
    iVar1 = coff_incr_load_previous_object();
    if (iVar1 == 0) {
      g_coff_symbol_slots = malloc(0x1000);
      if (g_coff_symbol_slots == (c2_coff_slot **)0x0) {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x35f);
      }
      g_coff_symbol_slot_capacity = 0x3ff;
    }
    if (g_coff_incremental_update != 0) {
      coff_find_first_type6_slot();
      goto LAB_10758f31;
    }
  }
  coff_add_file_symbol(g_coff_source_file);
LAB_10758f31:
  if ((desc->comp_id != 0) && (g_coff_incremental_update == 0)) {
    coff_add_symbol("@comp.id",(uint16_t)_g_coff_abs_section_id,'\x03',desc->comp_id,0,0);
  }
  return 1;
}

