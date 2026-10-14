void __thiscall decl_merge_attributes_tail_thread(byte flags23,c1_symbol *sym)

{
  sym->flags23 = flags23 | 0x10;
  sym->flags2 = sym->flags2 & 0xf7;
  return;
}

