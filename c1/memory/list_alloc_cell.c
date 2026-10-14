int * __fastcall list_alloc_cell(int *list)

{
  uchar *puVar1;
  uchar *puVar2;
  int *cell;
  
  puVar1 = g_arenas[0].cur;
  cell = (int *)list[1];
  if (cell == (int *)0x0) {
    puVar2 = g_arenas[0].cur + 0xc;
    cell = (int *)g_arenas[0].cur;
    g_arenas[0].cur = puVar2;
    if (g_arenas[0].end < puVar2) {
      arena_grow(g_arenas);
      *(int *)puVar1 = *list;
      *list = (int)puVar1;
      return (int *)puVar1;
    }
  }
  else {
    list[1] = *cell;
    list_cell_clear(cell);
  }
  *cell = *list;
  *list = (int)cell;
  return cell;
}

