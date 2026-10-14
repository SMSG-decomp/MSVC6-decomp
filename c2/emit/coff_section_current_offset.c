int __fastcall coff_section_current_offset(uint16_t section)

{
  c2_coff_section *pcVar1;
  uint32_t uVar2;
  c2_coff_section *pcVar3;
  
  pcVar1 = g_coff_current_section;
  if (section == g_coff_code_section_id) {
    pcVar3 = coff_chunked_array_get(g_coff_sections,_g_coff_cur_code_section & 0xffff);
    if (g_coff_current_section != pcVar3) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x9b3);
    }
  }
  else {
    pcVar1 = coff_chunked_array_get(g_coff_sections,(uint)section);
  }
  if (pcVar1 != (c2_coff_section *)0x0) {
    if ((pcVar1->flags & 1) != 0) {
      uVar2 = coff_data_size(pcVar1->active->data);
      return uVar2 + pcVar1->base;
    }
    return 0;
  }
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\coffemit.c",0x9bc);
}

