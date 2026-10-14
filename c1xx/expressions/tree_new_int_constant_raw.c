c1_node * __cdecl tree_new_int_constant_raw(int value)

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
  pcVar1->kind = '\x03';
  local_10.base = (c1_type *)0x0;
  local_10.debug_index = 0;
  local_10.flags = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  pcVar1->op = 'e';
  local_10.code = 0x13;
  pcVar3 = type_intern(&local_10);
  pcVar1->type = pcVar3;
  pcVar1->left = (void *)value;
  pcVar1->right = (void *)(value >> 0x1f);
  return pcVar1;
}

