c1_node * __cdecl label_new(int label_kind)

{
  uchar *puVar1;
  c1_symbol *pcVar2;
  
  pcVar2 = arena_alloc(g_arenas + 2,g_symbol_size_table[9] + 3 & 0xfffffffc);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = sym_init_kind(pcVar2,'\t',(void *)0x0,2);
  }
  pcVar2->detail = (void *)label_kind;
  pcVar2->type = g_type_int;
  label_register(pcVar2);
  puVar1 = g_arenas[2].cur;
  g_arenas[2].cur = g_arenas[2].cur + 0x18;
  if (g_arenas[2].end < g_arenas[2].cur) {
    arena_grow(g_arenas + 2);
  }
  puVar1[1] = '\x04';
  *puVar1 = '\x06';
  *(c1_symbol **)(puVar1 + 0x10) = pcVar2;
  *(c1_type **)(puVar1 + 4) = pcVar2->type;
  return (c1_node *)puVar1;
}

