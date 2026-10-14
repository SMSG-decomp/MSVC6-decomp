c1_node * __cdecl tree_new_sized_int_constant(c1_u32 low,c1_u32 high,int size)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  fe_arena *a;
  
  a = g_arenas + g_expr_arena_index;
  pcVar1 = (c1_node *)a->cur;
  pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar1[1].op;
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->kind = '\x03';
  switch(size) {
  case 1:
  case 2:
  case 4:
    pcVar1->op = 'e';
    pcVar1->type = g_type_int32;
    pcVar1->left = (void *)low;
    pcVar1->right = (void *)high;
    return pcVar1;
  case 8:
    pcVar1->op = 'e';
    pcVar3 = g_type_int64;
    pcVar1->left = (void *)low;
    pcVar1->type = pcVar3;
    pcVar1->right = (void *)high;
    return pcVar1;
  case 0x10:
    pcVar1->op = 'e';
    pcVar1->type = g_type_int128;
  }
  pcVar1->left = (void *)low;
  pcVar1->right = (void *)high;
  return pcVar1;
}

