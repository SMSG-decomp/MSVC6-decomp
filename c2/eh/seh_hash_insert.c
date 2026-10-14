void __fastcall seh_hash_insert(c2_seh_symbol_cell **table,c2_symbol *s)

{
  c2_seh_symbol_cell *pcVar1;
  c2_seh_symbol_cell *pcVar2;
  uint uVar3;
  
  pcVar2 = arena_alloc(4,8);
  uVar3 = s->id;
  pcVar2->symbol = s;
  uVar3 = uVar3 & 0xf;
  pcVar1 = table[uVar3];
  table[uVar3] = pcVar2;
  pcVar2->next = pcVar1;
  return;
}

