uint16_t __fastcall coff_select_comdat_section(uint16_t section)

{
  c2_coff_section *desc;
  undefined4 prev_section;
  
  desc = coff_chunked_array_get(g_coff_sections,(uint)section);
  prev_section = _g_coff_cur_code_section;
  if (desc == (c2_coff_section *)0x0) {
    return g_coff_code_section_id;
  }
  if ((desc->flags & 2) != 0) {
    g_coff_current_section = desc;
    _g_coff_cur_code_section = CONCAT22(g_coff_cur_code_section_2,section);
    g_coff_current_section_data = desc->active->data;
    return (uint16_t)prev_section;
  }
  return g_coff_code_section_id;
}

