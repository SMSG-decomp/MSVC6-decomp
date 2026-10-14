void __cdecl emit_version_string_literal(void)

{
  char cVar1;
  c1_node *literal;
  c1_node *pcVar2;
  c1_arena *a;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (g_opt_V_string != (char *)0x0) {
    a = g_arenas + g_expr_arena_index;
    literal = (c1_node *)a->cur;
    pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
    a->cur = &literal[1].op;
    if (pcVar2 < literal + 1) {
      arena_grow(a);
    }
    literal->kind = '\x05';
    literal->op = '\a';
    uVar3 = 0xffffffff;
    pcVar5 = g_opt_V_string;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    *(short *)&literal->right = (short)uVar3;
    literal->left = &g_string_literal_buffer;
    pcVar5 = g_opt_V_string;
    pcVar6 = &g_string_literal_buffer;
    for (uVar4 = (uVar3 & 0xffff) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    type_string_literal_array(literal);
    p1inl_new_key_default((int)literal);
    g_file_scope_decl_since_body = 1;
  }
  return;
}

