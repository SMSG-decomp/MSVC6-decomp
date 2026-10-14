c1_node * __cdecl expr_member_function_address_for_type(c1_type *type,int sym)

{
  byte bVar1;
  char cVar2;
  c1_node *pcVar3;
  c1_symbol *sym_00;
  ushort uVar4;
  
  sym_00 = *(c1_symbol **)(**(int **)(sym + 0x14) + 8);
  if ((sym_00->flags1 & 4) == 0) {
    bVar1 = sym_00->kind & 0x1f;
    if ((bVar1 != 0x11) && (bVar1 != 8)) {
      diag_error(0x255,sym);
      pcVar3 = tree_new_zero_flagged();
      return pcVar3;
    }
    cVar2 = ovl_names_single_function(sym_00,'\x01');
    if (cVar2 == '\0') {
      if (type == (c1_type *)0x0) {
        pcVar3 = tree_new_zero_flagged();
        return pcVar3;
      }
      if (-1 < (char)type->code) {
        pcVar3 = tree_new_zero_flagged();
        return pcVar3;
      }
      uVar4 = type->code & 0x8f;
      if ((uVar4 != 0x8e) && (uVar4 != 0x86)) {
        pcVar3 = tree_new_zero_flagged();
        return pcVar3;
      }
      sym_00 = (c1_symbol *)
               ovl_find_function_with_type
                         (sym_00,type->base,0,0,(c1_symbol *)0x0,(c1_declarator *)0x0,1);
    }
    else {
      sym_00 = sym_first_function_of_overload_set(sym_00,'\x01');
    }
  }
  if (sym_00 != (c1_symbol *)0x0) {
    *(c1_symbol **)(**(int **)(sym + 0x14) + 8) = sym_00;
    pcVar3 = expr_address_of_member((c1_symbol *)sym);
    return pcVar3;
  }
  diag_error(0x233);
  pcVar3 = tree_new_zero_flagged();
  return pcVar3;
}

