c1_node * __cdecl tree_new_enumerator_constant(c1_symbol *sym)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  void *pvVar3;
  fe_arena *a;
  
  a = g_arenas + g_expr_arena_index;
  pcVar1 = (c1_node *)a->cur;
  pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar1[1].op;
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->kind = '\x03';
  pcVar1->op = 'e';
  pvVar3 = (void *)(sym->x28).value;
  pcVar1->left = pvVar3;
  pcVar1->right = (void *)((int)pvVar3 >> 0x1f);
  pcVar1->type = g_type_int;
  return pcVar1;
}

