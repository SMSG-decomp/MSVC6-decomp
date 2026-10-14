c1_node * __cdecl type_based_base(c1_type *type)

{
  c1_symbol *sym;
  byte bVar1;
  c1_node *pcVar2;
  uint uVar3;
  
  uVar3 = -(uint)((type->code & 0x80) != 0) & (uint)type;
  bVar1 = *(byte *)(uVar3 + 2) & 0x18;
  if (bVar1 == 8) {
    return (c1_node *)0x0;
  }
  if (bVar1 == 0x18) {
    sym = *(c1_symbol **)(uVar3 + 8);
    if (g_opt_Zi != '\0') {
      sym_mark_referenced(sym);
    }
    pcVar2 = expr_reference_named_entity(sym,0);
    return pcVar2;
  }
  return (c1_node *)type;
}

