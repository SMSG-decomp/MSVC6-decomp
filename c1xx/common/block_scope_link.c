void __thiscall block_scope_link(c1xx_block_scope *block_scope,c1_symbol *sym)

{
  c1_sym_list *pcVar1;
  c1_symbol_detail cVar2;
  c1_u32 *pcVar3;
  c1_sym_list *pcVar4;
  c1_u32 cVar5;
  c1_sym_link *pcVar6;
  
  pcVar4 = (c1_sym_list *)g_arenas[4].cur;
  pcVar1 = g_list_cell_free_list;
  if (block_scope->symbols == (c1_sym_list *)0x0) {
    if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
         ((g_compile_flags_c8 & 0x10000000) != 0)) ||
        ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
      cVar5 = 0;
      if (g_list_cell_free_list == (c1_sym_list *)0x0) {
        if (g_scope_pool_left < 0xc) {
          pool_reserve((c1xx_pool *)&g_scope_pool,0xc);
        }
        g_scope_pool_left = g_scope_pool_left - 0xc;
        pcVar4 = (c1_sym_list *)g_scope_pool;
        g_scope_pool = g_scope_pool + 0xc;
      }
      else {
        pcVar3 = &g_list_cell_free_list->arena;
        g_list_cell_free_list = (c1_sym_list *)g_list_cell_free_list->head;
        *pcVar3 = 0;
        pcVar1->head = (c1_sym_link *)0x0;
        pcVar1->tail = (c1_sym_link *)0x0;
        pcVar4 = pcVar1;
      }
    }
    else {
      cVar5 = 4;
      g_arenas[4].cur = g_arenas[4].cur + 0xc;
      if (g_arenas[4].end < g_arenas[4].cur) {
        arena_grow(g_arenas + 4);
      }
    }
    if (pcVar4 == (c1_sym_list *)0x0) {
      pcVar4 = (c1_sym_list *)0x0;
    }
    else {
      pcVar4->arena = cVar5;
      pcVar4->head = (c1_sym_link *)0x0;
      pcVar4->tail = (c1_sym_link *)0x0;
    }
    block_scope->symbols = pcVar4;
  }
  pcVar1 = block_scope->symbols;
  pcVar6 = (c1_sym_link *)&sym->name;
  if (pcVar6 == (c1_sym_link *)0x0) {
    pcVar6 = (c1_sym_link *)0x0;
  }
  else {
    cVar2 = (c1_symbol_detail)pcVar1->tail;
    *(fe_name **)pcVar6 = *(fe_name **)pcVar6;
    sym->next = (c1_symbol *)0x0;
    sym->detail = cVar2;
  }
  if (pcVar1->tail != (c1_sym_link *)0x0) {
    if (g_empty_list_sentinel == (c1_symbol *)0x0) {
      g_empty_list_sentinel = sym_new_kind12();
    }
    if ((c1_symbol *)&pcVar1->tail[-1].position == g_empty_list_sentinel) {
      pcVar1->head = pcVar6;
      pcVar1->tail = pcVar6;
      return;
    }
    pcVar1->tail->next = pcVar6;
    pcVar1->tail = pcVar6;
    return;
  }
  pcVar1->head = pcVar6;
  pcVar1->tail = pcVar6;
  return;
}

