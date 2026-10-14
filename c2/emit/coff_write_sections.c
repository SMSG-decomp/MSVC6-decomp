void coff_write_sections(void)

{
  c2_coff_slot *slot;
  uint32_t value;
  c2_coff_section *pcVar1;
  size_t sVar2;
  uint uVar3;
  uint32_t slot_index;
  c2_fseek_fn *fseek_fn;
  uint32_t string_table_size;
  c2_coff_file_header file_header;
  c2_coff_order_cell *cell;
  
  slot_index = 0;
  if (g_coff_incremental_update != 0) {
    incr_renumber_sections();
    incr_fix_symbol_section_numbers();
    g_coff_section_numbers_final = 1;
  }
  if ((short)g_coff_header_section_count == 0) {
    coff_set_section_count_and_seek(0);
  }
  fseek_fn = fseek_exref;
  fseek(g_coff_object_file,(g_coff_header_section_count & 0xffff) * 0x28 + 0x14,0);
  if (g_opt_incremental != 0) {
    if (g_coff_incremental_update != 0) {
      uVar3 = (g_coff_header_section_count & 0xffff) * 0x28;
      if (g_coff_incr_data_start - 0x14 < uVar3) {
        coff_incr_grow_header_area((uVar3 - g_coff_incr_data_start) + 0x14);
      }
      g_coff_place_in_free_space = 1;
    }
    pcVar1 = coff_list_next(g_coff_sections);
    while (pcVar1 != (c2_coff_section *)0x0) {
      if (((pcVar1->flags & 0x10) != 0) && ((pcVar1->flags & 1) != 0)) {
        coff_place_section_data(pcVar1);
      }
      pcVar1 = coff_list_next(g_coff_sections);
    }
    if (g_coff_incremental_update == 0) {
      g_coff_data_end = ftell(g_coff_object_file);
    }
    else {
      fseek(g_coff_object_file,g_coff_data_end,0);
      g_coff_place_in_free_space = 0;
    }
  }
  pcVar1 = coff_list_next(g_coff_sections);
  while (pcVar1 != (c2_coff_section *)0x0) {
    if ((((g_opt_incremental == 0) || ((pcVar1->flags & 0x10) == 0)) && ((pcVar1->flags & 1) != 0))
       && ((pcVar1->flags & 4) == 0)) {
      coff_place_section_data(pcVar1);
    }
    pcVar1 = coff_list_next(g_coff_sections);
  }
  file_header.nsections = (uint16_t)g_coff_section_order->count;
  file_header.machine = g_coff_machine;
  file_header.timestamp = (*g_coff_timestamp_fn)();
  file_header.optional_header_size = 0;
  file_header.characteristics = 0;
  file_header.nsymbols = g_coff_symbol_slot_count;
  file_header.symbol_table = ftell(g_coff_object_file);
  if (g_opt_incremental != 0) {
    incr_stream_put_dword(file_header.timestamp);
    incr_stream_put_dword(g_coff_data_end);
    incr_write_free_ranges();
  }
  if (g_coff_symbol_slot_count != 0) {
    do {
      slot = g_coff_symbol_slots[slot_index];
      if (((g_opt_incremental != 0) && (slot->kind == 3)) && (value = slot->key, value != 0)) {
        incr_stream_put_dword(slot_index);
        incr_stream_put_dword(value);
      }
      coff_write_symbol_record(slot);
      slot_index = slot_index + 1;
      fseek_fn = fseek_exref;
    } while (slot_index < g_coff_symbol_slot_count);
  }
  if (g_opt_incremental != 0) {
    incr_stream_put_dword(0);
    incr_stream_put_dword(0);
  }
  (*fseek_fn)(g_coff_object_file,0,0);
  sVar2 = fwrite(&file_header,0x14,1,g_coff_object_file);
  if (sVar2 != 1) {
    (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x4e9);
  }
  ftell(g_coff_object_file);
  for (cell = g_coff_section_order->head; cell != (c2_coff_order_cell *)0x0; cell = cell->next) {
    if (cell->sec != (c2_coff_section_out *)0x0) {
      coff_write_section_header(cell->sec);
    }
  }
  fseek(g_coff_object_file,0,2);
  slot_index = coff_data_size(g_coff_string_table);
  string_table_size = slot_index + 4;
  sVar2 = fwrite(&string_table_size,4,1,g_coff_object_file);
  if (sVar2 != 1) {
    (*g_coff_error_fn)(0xe,"E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x4ff);
  }
  coff_write_section_data(g_coff_string_table);
  if (g_coff_trailer_data != (c2_coff_data *)0x0) {
    fseek(g_coff_object_file,0,2);
    coff_write_section_data(g_coff_trailer_data);
  }
  return;
}

