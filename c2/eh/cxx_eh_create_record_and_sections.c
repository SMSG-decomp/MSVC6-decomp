void cxx_eh_create_record_and_sections(void)

{
  c2_fe_symbol *pcVar1;
  uint32_t uVar2;
  
  g_cxx_eh_next_offset = (g_cur_function->flags >> 0x10 & 1) * 4;
  g_cxx_eh_record = create_frame_eh_record(g_cxx_eh_next_offset + 0xc,1,"__$EHRec");
  if (g_ehdata_section == (c2_fe_symbol *)0x0) {
    uVar2 = fe_symbol_next_id();
    g_ehdata_section = section_symbol_new(0x107a03a8,0x107a33b0,uVar2);
    section_set_defaults(g_ehdata_section);
    pcVar1 = g_ehdata_section;
    g_ehdata_section->level = '\0';
    (pcVar1->u44).section_class = '\x11';
  }
  if (g_ehtext_section == (c2_fe_symbol *)0x0) {
    uVar2 = fe_symbol_next_id();
    g_ehtext_section = section_symbol_new(0x107a03a0,0x107a33a8,uVar2);
    section_set_defaults(g_ehtext_section);
    pcVar1 = g_ehtext_section;
    g_ehtext_section->level = '\0';
    (pcVar1->u44).section_class = '\x12';
  }
  return;
}

