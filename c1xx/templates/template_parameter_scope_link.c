void __thiscall
template_parameter_scope_link
          (c1xx_template_parameter_scope *template_parameter_scope,c1_symbol *sym)

{
  c1_sym_list *pcVar1;
  c1_symbol_detail cVar2;
  c1_arena *a;
  c1_sym_list *pcVar3;
  c1_u32 cVar4;
  c1_sym_link *pcVar5;
  
  if (template_parameter_scope->symbols == (c1_sym_list *)0x0) {
    if ((((g_block_depth == '\0') ||
         ((-1 < g_class_depth || ((g_compile_flags_c8 & 0x10000000) != 0)))) ||
        (((g_compile_flags_c8 & 0x40000000) != 0 &&
         ((((byte)g_compile_flags_cc & 8) == 0 && ((g_compile_flags_c4 & 0x200) == 0)))))) ||
       (((byte)g_compile_flags_cc & 0x50) != 0)) {
      cVar4 = 0;
    }
    else {
      cVar4 = 4;
    }
    a = g_arenas + cVar4;
    pcVar3 = (c1_sym_list *)a->cur;
    pcVar1 = (c1_sym_list *)g_arenas[cVar4].end;
    a->cur = (c1_u8 *)(pcVar3 + 1);
    if (pcVar1 < pcVar3 + 1) {
      arena_grow(a);
    }
    if (pcVar3 == (c1_sym_list *)0x0) {
      pcVar3 = (c1_sym_list *)0x0;
    }
    else {
      pcVar3->arena = cVar4;
      pcVar3->head = (c1_sym_link *)0x0;
      pcVar3->tail = (c1_sym_link *)0x0;
    }
    template_parameter_scope->symbols = pcVar3;
  }
  else {
    pcVar5 = template_parameter_scope->symbols->head;
    if (pcVar5 != (c1_sym_link *)0x0) {
      do {
        if (pcVar5->name == sym->name) {
          diag_error(0x3df,sym);
          return;
        }
      } while ((pcVar5 != (c1_sym_link *)0x0) &&
              (pcVar5 = pcVar5->next, pcVar5 != (c1_sym_link *)0x0));
    }
  }
  pcVar3 = template_parameter_scope->symbols;
  pcVar5 = (c1_sym_link *)&sym->name;
  if (pcVar5 == (c1_sym_link *)0x0) {
    pcVar5 = (c1_sym_link *)0x0;
  }
  else {
    cVar2 = (c1_symbol_detail)pcVar3->tail;
    *(fe_name **)pcVar5 = *(fe_name **)pcVar5;
    sym->next = (c1_symbol *)0x0;
    sym->detail = cVar2;
  }
  if (pcVar3->tail != (c1_sym_link *)0x0) {
    if (g_empty_list_sentinel == (c1_symbol *)0x0) {
      g_empty_list_sentinel = sym_new_kind12();
    }
    if ((c1_symbol *)&pcVar3->tail[-1].position == g_empty_list_sentinel) {
      pcVar3->head = pcVar5;
      pcVar3->tail = pcVar5;
      return;
    }
    pcVar3->tail->next = pcVar5;
    pcVar3->tail = pcVar5;
    return;
  }
  pcVar3->head = pcVar5;
  pcVar3->tail = pcVar5;
  return;
}

