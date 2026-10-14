c1_node * __cdecl tree_new_value_constant(c1_symbol *sym)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_sym_list *pcVar3;
  c1_arena *a;
  
  a = g_arenas + g_expr_arena_index;
  pcVar1 = (c1_node *)a->cur;
  pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar1[1].op;
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->kind = '\x03';
  pcVar1->op = 'e';
  if (((sym->x28).members == (c1_sym_list *)0x0) || ((sym->x28).members == (c1_sym_list *)0x1)) {
    pcVar1->flags = pcVar1->flags | 1;
  }
  pcVar3 = (sym->x28).members;
  pcVar1->left = pcVar3;
  pcVar1->right = (void *)((int)pcVar3 >> 0x1f);
  pcVar1->type = sym->type;
  return pcVar1;
}

