c1_symbol * __cdecl
param_list_add_compiler_formal_front_or_back
          (int at_tail,c1_sym_list **list,void *name,c1_type *type)

{
  c1_symbol *pcVar1;
  c1_symbol_detail cVar2;
  c1_sym_list *pcVar3;
  c1_u32 *pcVar4;
  c1_symbol *pcVar5;
  c1_sym_list *pcVar6;
  c1_arena *a;
  c1_u32 cVar7;
  c1_sym_link *pcVar8;
  
  pcVar5 = decl_new_compiler_formal(name,type);
  pcVar6 = g_list_cell_free_list;
  if (*list == (c1_sym_list *)0x0) {
    cVar7 = (g_class_depth < 0) + 3;
    if (cVar7 == 0) {
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
    else {
      a = g_arenas + cVar7;
      pcVar6 = (c1_sym_list *)a->cur;
      pcVar3 = (c1_sym_list *)g_arenas[cVar7].end;
      a->cur = (c1_u8 *)(pcVar6 + 1);
      if (pcVar3 < pcVar6 + 1) {
        arena_grow(a);
      }
    }
    if (pcVar6 == (c1_sym_list *)0x0) {
      pcVar6 = (c1_sym_list *)0x0;
    }
    else {
      pcVar6->arena = cVar7;
      pcVar6->head = (c1_sym_link *)0x0;
      pcVar6->tail = (c1_sym_link *)0x0;
    }
    *list = pcVar6;
  }
  pcVar6 = *list;
  if (at_tail != 0) {
    pcVar8 = (c1_sym_link *)&pcVar5->name;
    if (pcVar8 == (c1_sym_link *)0x0) {
      pcVar8 = (c1_sym_link *)0x0;
    }
    else {
      cVar2 = (c1_symbol_detail)pcVar6->tail;
      *(fe_name **)pcVar8 = *(fe_name **)pcVar8;
      pcVar5->next = (c1_symbol *)0x0;
      pcVar5->detail = cVar2;
    }
    if (pcVar6->tail != (c1_sym_link *)0x0) {
      if (g_empty_list_sentinel == (c1_symbol *)0x0) {
        g_empty_list_sentinel = sym_new_kind12();
      }
      if ((c1_symbol *)&pcVar6->tail[-1].position != g_empty_list_sentinel) {
        pcVar6->tail->next = pcVar8;
        pcVar6->tail = pcVar8;
        return pcVar5;
      }
      pcVar6->head = pcVar8;
      pcVar6->tail = pcVar8;
      return pcVar5;
    }
    pcVar6->head = pcVar8;
    pcVar6->tail = pcVar8;
    return pcVar5;
  }
  pcVar8 = (c1_sym_link *)&pcVar5->name;
  if (pcVar8 == (c1_sym_link *)0x0) {
    pcVar8 = (c1_sym_link *)0x0;
  }
  else {
    pcVar1 = (c1_symbol *)pcVar6->head;
    *(fe_name **)pcVar8 = *(fe_name **)pcVar8;
    pcVar5->next = pcVar1;
    (pcVar5->detail).cls = (c1_class_record *)0x0;
  }
  if (pcVar6->head == (c1_sym_link *)0x0) {
    pcVar6->tail = pcVar8;
    pcVar6->head = pcVar8;
    return pcVar5;
  }
  if (g_empty_list_sentinel == (c1_symbol *)0x0) {
    g_empty_list_sentinel = sym_new_kind12();
  }
  if ((c1_symbol *)&pcVar6->head[-1].position == g_empty_list_sentinel) {
    pcVar6->tail = pcVar8;
    pcVar6->head = pcVar8;
    return pcVar5;
  }
  pcVar6->head[1].type.alias = (c1_using_alias *)pcVar8;
  pcVar6->head = pcVar8;
  return pcVar5;
}

