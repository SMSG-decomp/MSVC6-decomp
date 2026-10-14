c1_node * __cdecl
expr_build_class_operator_delete_call_alias
          (void **next_cell,void **set_cell,void **cell,c1_node *args,char one_param_found,
          c1_symbol *cls)

{
  c1_symbol *pcVar1;
  char cVar2;
  byte bVar3;
  c1_symbol *pcVar4;
  int iVar5;
  c1_node *pcVar6;
  void **cell_00;
  c1_symbol *pcStack00000010;
  
  pcVar4 = *(c1_symbol **)cell[3];
  while ((pcStack00000010 = pcVar4, cell_00 = next_cell, set_cell != (void **)0x0 &&
         (cell_00 != (void **)0x0))) {
    iVar5 = sym_is_data_or_function_2((c1_symbol *)(set_cell + -2));
    if (((char)iVar5 == '\0') && (((uint)set_cell[-2] & 0x1f) != 0x1a)) {
      next_cell = cell_00[1];
    }
    else {
      next_cell = (void **)0x0;
    }
    if (one_param_found != '\0') break;
    pcVar1 = (c1_symbol *)(cell_00 + -2);
    bVar3 = *(byte *)(cell_00 + -2) & 0x1f;
    pcVar4 = pcVar1;
    if (bVar3 == 0x1a) {
      pcVar4 = *(c1_symbol **)cell_00[3];
    }
    iVar5 = **(int **)(*(int *)(((uint)pcVar4->type & -(uint)((pcVar4->type->code & 0x80) != 0)) + 8
                               ) + 0xc);
    if (iVar5 == 1) {
      one_param_found = '\x01';
      pcVar4 = pcVar1;
      if (bVar3 == 0x1a) {
        pcVar6 = expr_build_class_operator_delete_call_alias
                           (next_cell,set_cell,cell_00,args,'\x01',cls);
        return pcVar6;
      }
    }
    else {
      pcVar4 = pcStack00000010;
      if (iVar5 == 2) {
        pcVar4 = pcVar1;
        if (bVar3 == 0x1a) {
          pcVar4 = *(c1_symbol **)cell_00[3];
        }
        cVar2 = type_compare(*(c1_type **)
                              (*(int *)(*(int *)(((uint)pcVar4->type &
                                                 -(uint)((pcVar4->type->code & 0x80) != 0)) + 8) +
                                       0xc) + 0xc),PTR_104d151c,2);
        pcVar4 = pcStack00000010;
        if ((cVar2 != '\0') && (pcVar4 = pcVar1, (pcVar1->kind & 0x1f) == 0x1a)) {
          pcVar4 = *(c1_symbol **)cell_00[3];
        }
      }
    }
  }
  if (pcStack00000010 == (c1_symbol *)0x0) {
    diag_error(0x23d,cls);
    return (c1_node *)0x0;
  }
  if (one_param_found == '\0') {
    if ((g_minimal_rebuild != '\0') && (g_minimal_rebuild_tracker->current->tracked != '\0')) {
      mre_note_class_layout_use(g_minimal_rebuild_tracker,cls);
    }
    iVar5 = 2;
    pcVar6 = tree_new_int_constant(((cls->detail).cls)->size);
    args = tree_append_list_item(args,pcVar6,iVar5);
  }
  pcVar6 = tree_new_symbol_ref(pcStack00000010,'\0');
  pcVar6 = (c1_node *)expr_build_call(pcVar6,args);
  return pcVar6;
}

