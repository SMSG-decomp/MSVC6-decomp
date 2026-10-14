c1_node * __cdecl expr_check_member_reference_context(c1_symbol *sym,byte *sym2)

{
  int iVar1;
  byte bVar2;
  c1_node *pcVar3;
  c1_node *name;
  
  bVar2 = *sym2 & 0x1f;
  if (bVar2 == 5) {
    access_check_member(sym);
    pcVar3 = tree_new_value_constant((c1_symbol *)sym2);
    return pcVar3;
  }
  if (g_current_function == (c1_symbol *)0x0) {
    if ((bVar2 != 0x11) && (bVar2 != 8)) {
      diag_error(0x28e,sym2);
      return (c1_node *)0x0;
    }
    pcVar3 = tree_new_symbol_ref(sym,'\0');
    return pcVar3;
  }
  if ((*(byte *)((int)&g_current_function->tail + 8) & 1) != 0) {
    pcVar3 = expr_this_pointer((c1_symbol *)0x0);
    name = tree_new_symbol_ref(sym,'\0');
    pcVar3 = expr_build_member_access('S',pcVar3,name);
    if ((((pcVar3->op == '=') && ((sym->kind & 0x1f) == 0x12)) &&
        (iVar1 = *(int *)(*(int *)sym->type + 4), iVar1 != 0)) && (iVar1 == *(int *)(iVar1 + 4))) {
      pcVar3->right = sym;
      return pcVar3;
    }
    if ((pcVar3->op == 'S') && ((sym->kind & 0x1f) == 0x12)) {
      bVar2 = **(byte **)(*(int *)sym->type + 8) & 0x1f;
      if (((bVar2 == 0x11) || (bVar2 == 8)) &&
         ((iVar1 = *(int *)(*(int *)sym->type + 4), iVar1 != 0 && (iVar1 == *(int *)(iVar1 + 4)))))
      {
        *(c1_symbol **)((int)pcVar3->right + 0x14) = sym;
      }
    }
    return pcVar3;
  }
  if ((((g_current_function->flags1 & 4) == 0) && (bVar2 != 0x11)) && (bVar2 != 8)) {
    diag_error(0x146,g_current_function,sym);
    pcVar3 = tree_new_zero_flagged();
    return pcVar3;
  }
  if (((bVar2 != 0x11) && (bVar2 != 8)) && ((bVar2 != 3 && ((sym->kind & 0x1f) != 0x12)))) {
    diag_error(0x255,sym2);
    pcVar3 = tree_new_zero_flagged();
    return pcVar3;
  }
  pcVar3 = tree_new_symbol_ref(sym,'\0');
  return pcVar3;
}

