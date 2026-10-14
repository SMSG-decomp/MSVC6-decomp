c1_arg_item * __cdecl tmpl_argument_from_expression(c1_node *expr)

{
  byte bVar1;
  int iVar2;
  c1_node *pcVar3;
  c1_arg_item *pcVar4;
  
  if (expr == (c1_node *)0x0) {
    expr = tree_new_int_constant(0);
    expr->kind = expr->kind | 8;
  }
  pcVar4 = (c1_arg_item *)g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 0x14;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (pcVar4 == (c1_arg_item *)0x0) {
    pcVar4 = (c1_arg_item *)0x0;
  }
  else {
    bVar1 = *(byte *)((int)pcVar4 + 0xc);
    *(c1_u8 *)((int)pcVar4 + 4) = '\0';
    *(c1_u8 *)((int)pcVar4 + 5) = '\0';
    *(c1_u8 *)((int)pcVar4 + 6) = '\0';
    *(c1_u8 *)((int)pcVar4 + 7) = '\0';
    *(c1_u8 *)((int)pcVar4 + 8) = '\0';
    *(c1_u8 *)((int)pcVar4 + 9) = '\0';
    *(c1_u8 *)((int)pcVar4 + 10) = '\0';
    *(c1_u8 *)((int)pcVar4 + 0xb) = '\0';
    *(byte *)((int)pcVar4 + 0xc) = bVar1 & 0xfc ^ 1 | 4;
    pcVar4->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
    pcVar3 = tree_copy_to_arena(expr,0);
    *(c1_node **)((int)pcVar4 + 0x10) = pcVar3;
  }
  iVar2 = g_paren_depth;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffc;
  bVar1 = g_paren_level_flags[g_paren_depth];
  g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
  g_paren_level_flags[iVar2] = bVar1 & 0xfc | 0x2c;
  if ((expr->kind & 8) != 0) {
    pcVar4->kind = pcVar4->kind | 8;
  }
  return pcVar4;
}

