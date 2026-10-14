void __fastcall coff_symbol_hash_insert(c2_fe_symbol *sym)

{
  c2_coff_sym_cell *pcVar1;
  c2_coff_sym_cell *pcVar2;
  uint uVar3;
  
  pcVar2 = arena_alloc(7,8);
  uVar3 = sym->id;
  pcVar2->sym = sym;
  uVar3 = uVar3 & 0xf;
  pcVar1 = g_coff_pending_sections[uVar3];
  g_coff_pending_sections[uVar3] = pcVar2;
  pcVar2->next = pcVar1;
  return;
}

