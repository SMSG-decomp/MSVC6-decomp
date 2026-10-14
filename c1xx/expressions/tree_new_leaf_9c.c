c1_node * __cdecl tree_new_leaf_9c(int entity,c1_type *type)

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
  pcVar1->left = (void *)entity;
  pcVar1->kind = '\x04';
  pcVar1->op = 0x9c;
  pcVar1->type = type;
  return pcVar1;
}

