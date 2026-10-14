void __fastcall coff_add_reloc_typed(int offset,void *sym,uint16_t type)

{
  int iVar1;
  
  iVar1 = coff_section_current_offset(g_coff_code_section_id);
  coff_add_relocation(*(uint32_t *)((int)sym + 0x28),offset + iVar1,*(uint32_t *)((int)sym + 0x1c),
                      type);
  return;
}

