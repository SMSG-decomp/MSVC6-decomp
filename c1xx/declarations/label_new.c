c1_node * __cdecl label_new(int label_kind)

{
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  
  pcVar2 = arena_alloc(g_arenas + 4,g_symbol_size_table[9] + 3 & 0xfffffffc);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = sym_init_kind(pcVar2,'\t',(void *)0x0,4);
  }
  (pcVar2->detail).value = label_kind;
  pcVar2->type = g_type_int;
  label_register(pcVar2);
  pcVar1 = g_arenas[4].cur;
  g_arenas[4].cur = g_arenas[4].cur + 0x18;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  pcVar1[1] = '\x04';
  *pcVar1 = '\x06';
  *(c1_symbol **)(pcVar1 + 0x10) = pcVar2;
  *(c1_type **)(pcVar1 + 4) = pcVar2->type;
  return (c1_node *)pcVar1;
}

