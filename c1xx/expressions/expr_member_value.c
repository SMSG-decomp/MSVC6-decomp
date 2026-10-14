c1_node * __cdecl expr_member_value(c1_symbol *sym,c1_node *n)

{
  c1_node *pcVar1;
  int iVar2;
  c1_node *folded;
  
  pcVar1 = tree_new_rvalue(n);
  if ((sym->flags5 & 0x40) != 0) {
    folded = fold_static_const_member(pcVar1);
    if ((folded->kind & 7) == 3) {
      pcVar1 = expr_member_value_mark_constant(folded,pcVar1,sym);
      return pcVar1;
    }
  }
  iVar2 = sym_has_reference_type(sym);
  if ((char)iVar2 != '\0') {
    pcVar1 = expr_build_builtin_unary(0x3d,pcVar1);
  }
  if ((sym->flags3 & 4) != 0) {
    pcVar1->kind = pcVar1->kind | 8;
  }
  return pcVar1;
}

