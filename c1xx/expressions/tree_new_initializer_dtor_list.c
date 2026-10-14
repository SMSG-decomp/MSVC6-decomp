c1_node * __cdecl tree_new_initializer_dtor_list(c1_node *item,c1_value_cell *dtors)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  c1_arena *a;
  c1_type local_10;
  
  a = g_arenas + g_expr_arena_index;
  pcVar1 = (c1_node *)a->cur;
  pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar1[1].op;
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->left = item;
  pcVar1->kind = '\a';
  pcVar1->op = 0xb5;
  pcVar1->right = dtors;
  local_10.base = (c1_type *)0x0;
  local_10.debug_index = 0;
  local_10.code = 0x80e;
  local_10.flags = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  pcVar3 = type_intern(&local_10);
  pcVar1->type = pcVar3;
  return pcVar1;
}

