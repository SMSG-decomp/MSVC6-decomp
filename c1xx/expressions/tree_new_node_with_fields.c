c1_node * __cdecl
tree_new_node_with_fields(c1_u8 op,ushort unwind_count,void *state,ushort marker_flags)

{
  ushort uVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_arena *a;
  
  a = g_arenas + g_expr_arena_index;
  pcVar2 = (c1_node *)a->cur;
  pcVar3 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar2[1].op;
  if (pcVar3 < pcVar2 + 1) {
    arena_grow(a);
  }
  pcVar2->kind = '\0';
  pcVar2->op = op;
  uVar1 = *(ushort *)&pcVar2->right;
  pcVar2->type = g_type_void;
  pcVar2->left = state;
  *(ushort *)((int)&pcVar2->right + 2) = marker_flags;
  *(ushort *)&pcVar2->right = (uVar1 ^ unwind_count) & 0xfff ^ uVar1;
  return pcVar2;
}

