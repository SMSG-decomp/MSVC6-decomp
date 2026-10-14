void __thiscall block_scope_link(c1_scope_object *block_scope,int symbol)

{
  int *piVar1;
  c1_scope_symbol_list *pcVar2;
  uint uVar3;
  c1_scope_symbol_list *pcVar4;
  fe_arena *a;
  int *piVar5;
  
  pcVar4 = g_scope_symbol_list_free;
  if ((block_scope->entries).buckets == (void **)0x0) {
    uVar3 = -(uint)(g_block_depth != '\0') & 2;
    if (uVar3 == 0) {
      if (g_scope_symbol_list_free == (c1_scope_symbol_list *)0x0) {
        if (g_scope_pool.left < 0xc) {
          pool_reserve(&g_scope_pool,0xc);
        }
        g_scope_pool.left = g_scope_pool.left - 0xc;
        pcVar4 = (c1_scope_symbol_list *)g_scope_pool.cur;
        g_scope_pool.cur = g_scope_pool.cur + 0xc;
      }
      else {
        piVar5 = &g_scope_symbol_list_free->arena;
        g_scope_symbol_list_free = (c1_scope_symbol_list *)g_scope_symbol_list_free->first;
        *piVar5 = 0;
        pcVar4->first = (int *)0x0;
        pcVar4->last = (int *)0x0;
      }
    }
    else {
      a = g_arenas + uVar3;
      pcVar4 = (c1_scope_symbol_list *)a->cur;
      pcVar2 = (c1_scope_symbol_list *)g_arenas[uVar3].end;
      a->cur = (uchar *)(pcVar4 + 1);
      if (pcVar2 < pcVar4 + 1) {
        arena_grow(a);
      }
    }
    if (pcVar4 == (c1_scope_symbol_list *)0x0) {
      pcVar4 = (c1_scope_symbol_list *)0x0;
    }
    else {
      pcVar4->arena = uVar3;
      pcVar4->first = (int *)0x0;
      pcVar4->last = (int *)0x0;
    }
    (block_scope->entries).list = pcVar4;
  }
  pcVar4 = (block_scope->entries).list;
  piVar5 = (int *)(symbol + 8);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar1 = pcVar4->last;
    *piVar5 = *piVar5;
    *(undefined4 *)(symbol + 0xc) = 0;
    *(int **)(symbol + 0x24) = piVar1;
  }
  if (pcVar4->last == (int *)0x0) {
    pcVar4->first = piVar5;
    pcVar4->last = piVar5;
    return;
  }
  if (g_empty_list_sentinel == (c1_symbol *)0x0) {
    g_empty_list_sentinel = sym_new_kind12();
  }
  if ((c1_symbol *)(pcVar4->last + -2) == g_empty_list_sentinel) {
    pcVar4->first = piVar5;
    pcVar4->last = piVar5;
    return;
  }
  pcVar4->last[1] = (int)piVar5;
  pcVar4->last = piVar5;
  return;
}

