void create_standard_sections(void)

{
  c2_fe_symbol *pcVar1;
  char *pcVar2;
  
  if (g_opt_fortran_frontend == 0) {
    g_text_section_sym = section_symbol_new((uint32_t)g_seg_name_text,0x107a045c,5);
    section_set_defaults(g_text_section_sym);
    pcVar1 = g_text_section_sym;
    (g_text_section_sym->u3e).label_flags = g_code_section_align;
    pcVar2 = g_seg_name_data;
    pcVar1->level = '\x01';
    (pcVar1->u44).section_class = '\0';
    (pcVar1->u4a).section.section_number = 1;
    g_data_section_sym = section_symbol_new((uint32_t)pcVar2,0x107a0454,2);
    section_set_defaults(g_data_section_sym);
    pcVar2 = g_seg_name_const;
    pcVar1 = g_data_section_sym;
    g_data_section_sym->level = '\0';
    (pcVar1->u44).section_class = '\x01';
    (pcVar1->u4a).section.section_number = 2;
    g_const_section_sym = section_symbol_new((uint32_t)pcVar2,0x107a012c,3);
    section_set_defaults(g_const_section_sym);
    pcVar2 = g_seg_name_bss;
    pcVar1 = g_const_section_sym;
    g_const_section_sym->level = '\0';
    (pcVar1->u44).section_class = '\x04';
    (pcVar1->u4a).section.section_number = 3;
    g_bss_section_sym = section_symbol_new((uint32_t)pcVar2,0x107a0450,4);
    section_set_defaults(g_bss_section_sym);
    pcVar1 = g_bss_section_sym;
    g_bss_section_sym->level = '\0';
    (pcVar1->u44).section_class = '\x03';
    (pcVar1->u4a).section.section_number = 4;
    if (g_opt_debug_info != 0) {
      g_debug_symbols_section = section_symbol_new(0x107a0134,0x107a5734,7);
      pcVar2 = g_section_default_class;
      (g_debug_symbols_section->u3e).label_flags = 1;
      g_debug_symbols_section->combine = '\0';
      g_debug_symbols_section->section_id = (uint32_t)pcVar2;
      g_debug_symbols_section->level = '\x01';
      (g_debug_symbols_section->u44).section_class = '\x13';
      (g_debug_symbols_section->u4a).section.section_number = 5;
      g_debug_types_section = section_symbol_new(0x107a5724,0x107a572c,8);
      pcVar2 = g_section_default_class;
      (g_debug_types_section->u3e).label_flags = 1;
      g_debug_types_section->combine = '\0';
      g_debug_types_section->section_id = (uint32_t)pcVar2;
      g_debug_types_section->level = '\x01';
      (g_debug_types_section->u44).section_class = '\x14';
      (g_debug_types_section->u4a).section.section_number = 6;
    }
    g_tls_section_sym = section_symbol_new((uint32_t)g_seg_name_tls,0x107a5720,9);
    section_set_defaults(g_tls_section_sym);
    pcVar1 = g_tls_section_sym;
    g_tls_section_sym->level = '\x01';
    (pcVar1->u44).section_class = '\v';
    (pcVar1->u4a).section.section_number = 7;
  }
  return;
}

