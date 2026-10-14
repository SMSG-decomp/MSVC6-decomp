c2_fe_symbol * __fastcall coff_select_data_section(c2_fe_symbol *sym,c2_fe_symbol *section)

{
  uint32_t id;
  c2_fe_symbol *owner;
  c2_fe_symbol *pcVar1;
  
  owner = fe_symbol_lookup_id(sym->section_id);
  id = section->section_id;
  pcVar1 = g_coff_data_comdat;
  if (id == 2) {
    if ((g_coff_data_comdat == (c2_fe_symbol *)0x0) ||
       ((g_coff_data_comdat->u4a).section.comdat_base != owner)) {
      g_coff_data_comdat = coff_new_comdat_section_symbol(owner,g_data_section_sym);
      return g_coff_data_comdat;
    }
  }
  else if (id == 3) {
    if ((g_coff_const_comdat == (c2_fe_symbol *)0x0) ||
       (pcVar1 = g_coff_const_comdat, (g_coff_const_comdat->u4a).section.comdat_base != owner)) {
      g_coff_const_comdat = coff_new_comdat_section_symbol(owner,g_const_section_sym);
      return g_coff_const_comdat;
    }
  }
  else if (id == g_il_last_section_id) {
    if ((g_coff_data_comdat == (c2_fe_symbol *)0x0) ||
       ((g_coff_data_comdat->u4a).section.comdat_base != owner)) {
      pcVar1 = fe_symbol_lookup_id(g_il_last_section_id);
      g_coff_data_comdat = coff_new_comdat_section_symbol(owner,pcVar1);
      return g_coff_data_comdat;
    }
  }
  else if (id == 4) {
    if ((g_coff_bss_comdat == (c2_fe_symbol *)0x0) ||
       (pcVar1 = g_coff_bss_comdat, (g_coff_bss_comdat->u4a).section.comdat_base != owner)) {
      g_coff_bss_comdat = coff_new_comdat_section_symbol(owner,g_bss_section_sym);
      return g_coff_bss_comdat;
    }
  }
  else if (id == 9) {
    if ((g_coff_tls_comdat == (c2_fe_symbol *)0x0) ||
       (pcVar1 = g_coff_tls_comdat, (g_coff_tls_comdat->u4a).section.comdat_base != owner)) {
      g_coff_tls_comdat = coff_new_comdat_section_symbol(owner,g_tls_section_sym);
      return g_coff_tls_comdat;
    }
  }
  else if (section == g_ehtext_section) {
    if ((g_coff_ehtext_comdat == (c2_fe_symbol *)0x0) ||
       (pcVar1 = g_coff_ehtext_comdat, (g_coff_ehtext_comdat->u4a).section.comdat_base != owner)) {
      g_coff_ehtext_comdat = coff_new_comdat_section_symbol(owner,g_ehtext_section);
      return g_coff_ehtext_comdat;
    }
  }
  else if (((byte)section->storage & 0x70) == 0x70) {
    if ((g_coff_ehdata_comdat == (c2_fe_symbol *)0x0) ||
       (pcVar1 = g_coff_ehdata_comdat, (g_coff_ehdata_comdat->u4a).section.comdat_base != owner)) {
      g_coff_ehdata_comdat = coff_new_comdat_section_symbol(owner,g_ehdata_section);
      return g_coff_ehdata_comdat;
    }
  }
  else {
    pcVar1 = fe_symbol_lookup_id(id);
  }
  return pcVar1;
}

