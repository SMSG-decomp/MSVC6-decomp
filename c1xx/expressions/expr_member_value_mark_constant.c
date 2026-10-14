c1_node * __cdecl expr_member_value_mark_constant(c1_node *folded,c1_node *load,c1_symbol *sym)

{
  int iVar1;
  
  if ((folded->type->code & 0x110) != 0) {
    load->flags = load->flags | 1;
  }
  iVar1 = sym_has_reference_type(sym);
  if ((char)iVar1 != '\0') {
    load = expr_build_builtin_unary(0x3d,load);
  }
  if ((sym->flags3 & 4) != 0) {
    load->kind = load->kind | 8;
  }
  return load;
}

