void __fastcall coff_add_reloc_type9(int fixup_delta,c2_fe_symbol *target)

{
  int iVar1;
  
  iVar1 = coff_section_current_offset(g_coff_code_section_id);
  coff_add_relocation(target->id,fixup_delta + iVar1,target->coff_symbol,9);
  return;
}

