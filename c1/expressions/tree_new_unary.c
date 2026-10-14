c1_node * __cdecl tree_new_unary(c1_u8 op,c1_type *type,c1_node *operand)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  fe_arena *a;
  
  a = g_arenas + g_expr_arena_index;
  pcVar1 = (c1_node *)a->cur;
  pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar1[1].op;
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->op = op;
  pcVar1->kind = '\x01';
  pcVar1->left = operand;
  pcVar1->type = type;
  return pcVar1;
}

