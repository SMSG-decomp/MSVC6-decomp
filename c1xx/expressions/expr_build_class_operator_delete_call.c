c1_node * __cdecl
expr_build_class_operator_delete_call(c1_symbol *delete_set,c1_node *pointer,c1_symbol *cls)

{
  c1_symbol *pcVar1;
  c1_symbol *sym;
  bool bVar2;
  char cVar3;
  byte bVar4;
  c1_node *pcVar5;
  int iVar6;
  c1_symbol *pcVar7;
  c1_node *pcVar8;
  c1_symbol *next_cell;
  c1_symbol *cell;
  fe_name **set_cell;
  c1_symbol *local_8;
  
  pcVar5 = tree_append_list_item((c1_node *)0x0,pointer,2);
  local_8 = (c1_symbol *)0x0;
  bVar2 = false;
  sym = *(c1_symbol **)(*(int *)delete_set->type + 8);
  set_cell = &sym->name;
  next_cell = (c1_symbol *)0x0;
  if (((set_cell != (fe_name **)0x0) &&
      (iVar6 = sym_is_data_or_function_2(sym), next_cell = (c1_symbol *)set_cell,
      (char)iVar6 == '\0')) && ((sym->kind & 0x1f) != 0x1a)) {
    next_cell = (c1_symbol *)sym->type;
  }
  while ((cell = next_cell, set_cell != (fe_name **)0x0 && (cell != (c1_symbol *)0x0))) {
    iVar6 = sym_is_data_or_function_2(sym);
    if (((char)iVar6 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
      next_cell = *(c1_symbol **)&cell->flags4;
    }
    else {
      next_cell = (c1_symbol *)0x0;
    }
    if (bVar2) break;
    pcVar1 = (c1_symbol *)((int)&cell[-1].tail + 4);
    bVar4 = *(byte *)((int)&cell[-1].tail + 4) & 0x1f;
    pcVar7 = pcVar1;
    if (bVar4 == 0x1a) {
      pcVar7 = *(c1_symbol **)cell->next;
    }
    iVar6 = **(int **)(*(int *)(((uint)pcVar7->type & -(uint)((pcVar7->type->code & 0x80) != 0)) + 8
                               ) + 0xc);
    if (iVar6 == 1) {
      bVar2 = true;
      local_8 = pcVar1;
      if (bVar4 == 0x1a) {
        pcVar5 = expr_build_class_operator_delete_call_alias
                           ((void **)next_cell,set_cell,(void **)cell,pcVar5,'\x01',cls);
        return pcVar5;
      }
    }
    else if (iVar6 == 2) {
      pcVar7 = pcVar1;
      if (bVar4 == 0x1a) {
        pcVar7 = *(c1_symbol **)cell->next;
      }
      cVar3 = type_compare(*(c1_type **)
                            (*(int *)(*(int *)(((uint)pcVar7->type &
                                               -(uint)((pcVar7->type->code & 0x80) != 0)) + 8) + 0xc
                                     ) + 0xc),PTR_104d151c,2);
      if ((cVar3 != '\0') && (local_8 = pcVar1, (pcVar1->kind & 0x1f) == 0x1a)) {
        local_8 = *(c1_symbol **)cell->next;
      }
    }
  }
  if (local_8 == (c1_symbol *)0x0) {
    diag_error(0x23d,cls);
    return (c1_node *)0x0;
  }
  if (!bVar2) {
    if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) {
      mre_note_class_layout_use(g_minimal_rebuild_tracker,cls);
    }
    iVar6 = 2;
    pcVar8 = tree_new_int_constant(((cls->detail).cls)->size);
    pcVar5 = tree_append_list_item(pcVar5,pcVar8,iVar6);
  }
  pcVar8 = tree_new_symbol_ref(local_8,'\0');
  pcVar5 = (c1_node *)expr_build_call(pcVar8,pcVar5);
  return pcVar5;
}

