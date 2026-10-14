void __fastcall coff_add_reloc_type7(int offset,void *sym)

{
  int iVar1;
  
  iVar1 = coff_section_current_offset(g_coff_code_section_id);
  coff_add_relocation(*(uint32_t *)((int)sym + 0x28),offset + iVar1,*(uint32_t *)((int)sym + 0x1c),7
                     );
  return;
}

