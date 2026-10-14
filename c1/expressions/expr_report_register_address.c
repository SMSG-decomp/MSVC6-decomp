c1_node * __cdecl expr_report_register_address(c1_symbol *sym,c1_type pointer_type)

{
  byte bVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  
  if (g_sizeof_depth == 0) {
    diag_error(0x67,0x31);
  }
  pcVar2 = tree_new_symbol_ref(sym);
  if (pcVar2 != (c1_node *)0x0) {
    bVar1 = sym->kind & 0x1f;
    if (((bVar1 == 7) || (bVar1 == 8)) || (bVar1 == 6)) {
      pointer_type.base = sym->type;
      pointer_type.debug_index = 0;
      pointer_type.code = 0x4086;
      pointer_type.flags = (byte)(pointer_type.base)->flags & 0x1f;
      pointer_type.extra.sym = (c1_symbol *)0x0;
      pcVar3 = type_intern(&pointer_type);
      pcVar2->type = pcVar3;
    }
    else if ((sym->flags4 & 4) == 0) {
      pcVar2 = tree_new_rvalue(pcVar2);
      return pcVar2;
    }
    return pcVar2;
  }
  return (c1_node *)0x0;
}

