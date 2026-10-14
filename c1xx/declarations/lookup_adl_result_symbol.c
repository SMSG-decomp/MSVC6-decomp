c1_symbol * __cdecl lookup_adl_result_symbol(c1_vector *vec)

{
  c1_symbol *pcVar1;
  c1_symbol *pcVar2;
  void *name;
  c1_u8 *pcVar3;
  ushort uVar4;
  int iVar5;
  uint *cell;
  uint *cell_2;
  c1_symbol **entry;
  
  uVar4 = counted_array_count(&vec->count);
  iVar5 = (int)(short)uVar4;
  if (iVar5 == 1) {
    pcVar1 = (c1_symbol *)vec->arena;
    vector_release((int)vec);
    return pcVar1;
  }
  pcVar1 = (c1_symbol *)0x0;
  entry = (c1_symbol **)vec;
  cell_2 = (uint *)g_arenas[5].cur;
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    entry = (c1_symbol **)&((c1_vector *)entry)->arena;
    g_arenas[5].cur = (c1_u8 *)&((c1_symbol *)cell_2)->next;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if ((c1_symbol *)cell_2 == (c1_symbol *)0x0) {
      cell_2 = (uint *)0x0;
    }
    else {
      pcVar2 = *entry;
      ((c1_symbol *)cell_2)->flags4 = '\0';
      ((c1_symbol *)cell_2)->flags5 = '\0';
      ((c1_symbol *)cell_2)->scope_index = 0;
      *cell_2 = (uint)pcVar2;
      ((c1_symbol *)cell_2)->name = (fe_name *)0x0;
    }
    if (pcVar1 != (c1_symbol *)0x0) {
      ((c1_symbol *)cell_2)->name = (fe_name *)pcVar1;
    }
    pcVar1 = (c1_symbol *)cell_2;
    cell_2 = (uint *)g_arenas[5].cur;
  }
  name = *(void **)(*(int *)pcVar1 + 8);
  g_arenas[5].cur = &((c1_symbol *)cell_2)->kind + (g_symbol_size_table[0x1b] + 3 & 0xfffffffc);
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if ((c1_symbol *)cell_2 == (c1_symbol *)0x0) {
    cell = (uint *)0x0;
  }
  else {
    cell = (uint *)sym_init_kind((c1_symbol *)cell_2,'\x1b',name,5);
  }
  pcVar3 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 4;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  ((c1_symbol *)cell)->type = (c1_type *)pcVar3;
  *(c1_symbol **)pcVar3 = pcVar1;
  vector_release((int)vec);
  return (c1_symbol *)cell;
}

