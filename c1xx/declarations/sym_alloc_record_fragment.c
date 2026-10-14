byte * __cdecl
sym_alloc_record_fragment(c1_symbol *sym2,c1_type *list,void *sym_slot,c1_type *list_slot)

{
  fe_name *name;
  c1_u8 *pcVar1;
  byte *pbVar2;
  
  pcVar1 = g_arenas[0].cur;
  name = sym2->name;
  if ((void **)g_symbol_free_lists[g_symbol_size_class_table[0x12]] != (void **)0x0) {
    pbVar2 = sym_record_from_free_list_tail_2
                       (g_symbol_size_class_table[0x12],0,
                        (void **)g_symbol_free_lists[g_symbol_size_class_table[0x12]],name,list_slot
                       );
    return pbVar2;
  }
  g_arenas[0].cur = g_arenas[0].cur + (g_symbol_size_table[0x12] + 3 & 0xfffffffc);
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (pcVar1 == (c1_u8 *)0x0) {
    pcRam00000014 = list;
    return (byte *)0x0;
  }
  *pcVar1 = *pcVar1 & 0xf2 | 0x12;
  if (pcVar1 + 8 != (c1_u8 *)0x0) {
    *(fe_name **)(pcVar1 + 8) = name;
    pcVar1[0xc] = '\0';
    pcVar1[0xd] = '\0';
    pcVar1[0xe] = '\0';
    pcVar1[0xf] = '\0';
  }
  *(c1_type **)(pcVar1 + 0x14) = list;
  return pcVar1;
}

