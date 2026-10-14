c1_node * __cdecl tree_new_symbol_ref(c1_symbol *sym)

{
  byte bVar1;
  byte *pbVar2;
  c1_symbol *sym_00;
  c1_node *pcVar3;
  c1_node *pcVar4;
  fe_arena *a;
  c1_type *type;
  
  if (sym == (c1_symbol *)0x0) {
    return (c1_node *)0x0;
  }
  a = g_arenas + g_expr_arena_index;
  pcVar4 = (c1_node *)a->cur;
  pcVar3 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar4[1].op;
  if (pcVar3 < pcVar4 + 1) {
    arena_grow(a);
  }
  pcVar4->op = '\x06';
  pcVar4->kind = '\x04';
  pcVar4->left = sym;
  if ((sym->flags1 & 4) != 0) {
    diag_error(0x113,sym);
    return (c1_node *)0x0;
  }
  pcVar4->type = sym->type;
  if (((((sym->flags23 & 1) != 0) && (bVar1 = sym->kind & 0x1f, bVar1 != 7)) && (bVar1 != 8)) &&
     (pbVar2 = sym_segment_record(sym), (*pbVar2 & 0x1f) != 0xe)) {
    type = pcVar4->type;
    sym_00 = sym_segment_record(sym);
    pcVar3 = expr_reference_named_entity(sym_00);
    pcVar4 = tree_new_node(']',pcVar4,pcVar3,type);
    return pcVar4;
  }
  return pcVar4;
}

