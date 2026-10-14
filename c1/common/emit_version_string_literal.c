void __cdecl emit_version_string_literal(void)

{
  char cVar1;
  c1_node *literal;
  c1_node *pcVar2;
  fe_arena *a;
  uint uVar3;
  uint uVar4;
  char *v_text;
  char *v_scan;
  char *literal_text;
  
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
    v_scan = g_opt_V_string;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *v_scan;
      v_scan = v_scan + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    *(short *)&literal->right = (short)uVar3;
    literal->left = &g_string_literal_buffer;
    v_text = g_opt_V_string;
    literal_text = &g_string_literal_buffer;
    for (uVar4 = (uVar3 & 0xffff) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)literal_text = *(undefined4 *)v_text;
      v_text = v_text + 4;
      literal_text = literal_text + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *literal_text = *v_text;
      v_text = v_text + 1;
      literal_text = literal_text + 1;
    }
    type_string_literal_array(literal);
    p1inl_new_key_default((int)literal);
    g_file_scope_decl_since_body = 1;
  }
  return;
}

