c1_decl_record * __thiscall decl_record_init_for_symbol(c1_decl_record *rec,c1_symbol *sym)

{
  int iVar1;
  c1_u32 *pcVar2;
  c1_decl_record *pcVar3;
  c1_u32 *pcVar4;
  
  pcVar3 = rec;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar3->spec_type = (c1_type *)0x0;
    pcVar3 = (c1_decl_record *)&pcVar3->chain_head;
  }
  if (sym == (c1_symbol *)0x0) {
    sym = sym_new_in_current_scope();
  }
  rec->sym = sym;
  pcVar2 = g_default_decl_specifiers;
  pcVar4 = rec->spec;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pcVar4 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar4 = pcVar4 + 1;
  }
  return rec;
}

