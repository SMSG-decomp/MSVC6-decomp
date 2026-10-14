c1_node * __cdecl tree_new_node(c1_u8 op,c1_node *left,c1_node *right,c1_type *type)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_arena *a;
  
  a = g_arenas + g_expr_arena_index;
  pcVar1 = (c1_node *)a->cur;
  pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar1[1].op;
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->op = op;
  pcVar1->kind = '\x02';
  pcVar1->type = type;
  pcVar1->left = left;
  pcVar1->right = right;
  return pcVar1;
}

