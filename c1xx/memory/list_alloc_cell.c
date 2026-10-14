c1_pack_cell * __fastcall list_alloc_cell(c1_pack_stack *stack)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_pack_cell *cell;
  
  pcVar1 = g_arenas[0].cur;
  cell = stack->free_cells;
  if (cell == (c1_pack_cell *)0x0) {
    pcVar2 = g_arenas[0].cur + 0xc;
    cell = (c1_pack_cell *)g_arenas[0].cur;
    g_arenas[0].cur = pcVar2;
    if (g_arenas[0].end < pcVar2) {
      arena_grow(g_arenas);
      *(c1_pack_cell **)pcVar1 = stack->top;
      stack->top = (c1_pack_cell *)pcVar1;
      return (c1_pack_cell *)pcVar1;
    }
  }
  else {
    stack->free_cells = cell->next;
    list_cell_clear((int *)cell);
  }
  cell->next = stack->top;
  stack->top = cell;
  return cell;
}

