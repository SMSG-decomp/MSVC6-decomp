void __thiscall sym_list_append_2(void *list,c1_symbol *sym)

{
  c1_sym_list *pcVar1;
  int iVar2;
  c1_symbol_detail cVar3;
  c1_u32 *pcVar4;
  c1_u32 cVar5;
  c1_sym_list *pcVar6;
  c1_arena *a;
  fe_name **ppfVar7;
  
  pcVar6 = g_list_cell_free_list;
  if (*(int *)list != 0) goto LAB_104315b9;
  if (((byte)g_compile_flags_cc & 0x48) == 0) {
    cVar5 = (g_class_depth < 0) + 3;
    if (cVar5 == 0) goto LAB_1043160e;
    a = g_arenas + cVar5;
    pcVar6 = (c1_sym_list *)a->cur;
    pcVar1 = (c1_sym_list *)g_arenas[cVar5].end;
    a->cur = (c1_u8 *)(pcVar6 + 1);
    if (pcVar1 < pcVar6 + 1) {
      arena_grow(a);
    }
  }
  else {
    cVar5 = 0;
LAB_1043160e:
    if (g_list_cell_free_list == (c1_sym_list *)0x0) {
      if (g_scope_pool_left < 0xc) {
        pool_reserve((c1xx_pool *)&g_scope_pool,0xc);
      }
      g_scope_pool_left = g_scope_pool_left - 0xc;
      pcVar6 = (c1_sym_list *)g_scope_pool;
      g_scope_pool = g_scope_pool + 0xc;
    }
    else {
      pcVar4 = &g_list_cell_free_list->arena;
      g_list_cell_free_list = (c1_sym_list *)g_list_cell_free_list->head;
      *pcVar4 = 0;
      pcVar6->head = (c1_sym_link *)0x0;
      pcVar6->tail = (c1_sym_link *)0x0;
    }
  }
  if (pcVar6 == (c1_sym_list *)0x0) {
    pcVar6 = (c1_sym_list *)0x0;
  }
  else {
    pcVar6->arena = cVar5;
    pcVar6->head = (c1_sym_link *)0x0;
    pcVar6->tail = (c1_sym_link *)0x0;
  }
  *(c1_sym_list **)list = pcVar6;
LAB_104315b9:
  iVar2 = *(int *)list;
  ppfVar7 = &sym->name;
  if (ppfVar7 == (fe_name **)0x0) {
    ppfVar7 = (fe_name **)0x0;
  }
  else {
    cVar3 = *(c1_symbol_detail *)(iVar2 + 8);
    *ppfVar7 = *ppfVar7;
    sym->next = (c1_symbol *)0x0;
    sym->detail = cVar3;
  }
  if (*(int *)(iVar2 + 8) != 0) {
    if (g_empty_list_sentinel == (c1_symbol *)0x0) {
      g_empty_list_sentinel = sym_new_kind12();
    }
    if ((c1_symbol *)(*(int *)(iVar2 + 8) + -8) != g_empty_list_sentinel) {
      *(fe_name ***)(*(int *)(iVar2 + 8) + 4) = ppfVar7;
      *(fe_name ***)(iVar2 + 8) = ppfVar7;
      return;
    }
    *(fe_name ***)(iVar2 + 4) = ppfVar7;
    *(fe_name ***)(iVar2 + 8) = ppfVar7;
    return;
  }
  *(fe_name ***)(iVar2 + 4) = ppfVar7;
  *(fe_name ***)(iVar2 + 8) = ppfVar7;
  return;
}

