c1_symbol * __cdecl sym_alloc_record(int unused,uint kind,int arena)

{
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  uchar *puVar3;
  fe_arena *a;
  
  a = g_arenas + arena;
  pcVar2 = (c1_symbol *)a->cur;
  pcVar1 = &pcVar2->kind + (g_symbol_size_table[kind & 0xff] + 3 & 0xfffffffc);
  puVar3 = g_arenas[arena].end;
  a->cur = pcVar1;
  if (puVar3 < pcVar1) {
    arena_grow(a);
  }
  return pcVar2;
}

