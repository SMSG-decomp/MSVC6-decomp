void __cdecl pch_emit_pchsym_include_directive(void)

{
  c1_u8 *pcVar1;
  c1_node *literal;
  c1_node *pcVar2;
  short sVar3;
  void *pvVar4;
  char *pcVar5;
  fe_name *pfVar6;
  c1_scope_lookup *pcVar7;
  fe_name *name;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  fe_arena *a;
  char *pcVar11;
  char *pcVar12;
  char cVar13;
  
  pcVar5 = g_string_literal_cur;
  pvVar4 = g_data_seg_name;
  uVar8 = 0xffffffff;
  pcVar11 = PTR_s__INCLUDE___1065e1c4;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar13 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar13 != '\0');
  uVar8 = ~uVar8 - 1;
  pcVar11 = PTR_s__INCLUDE___1065e1c4;
  pcVar12 = g_string_literal_cur;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar9 = uVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar12 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar12 = pcVar12 + 1;
  }
  uVar9 = 0xffffffff;
  pcVar11 = g_pch_symbol_name;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar13 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar13 != '\0');
  uVar9 = ~uVar9;
  pcVar11 = g_pch_symbol_name;
  pcVar12 = pcVar5 + uVar8;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pcVar12 = pcVar12 + 4;
  }
  for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar12 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar12 = pcVar12 + 1;
  }
  sVar3 = (short)g_string_literal_cur;
  a = g_arenas + g_expr_arena_index;
  literal = (c1_node *)a->cur;
  pcVar2 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &literal[1].op;
  if (pcVar2 < literal + 1) {
    arena_grow(a);
  }
  literal->kind = '\x05';
  literal->op = '\a';
  literal->left = g_string_literal_cur;
  *(short *)&literal->right = ((short)(pcVar5 + uVar8) + (short)uVar9) - sVar3;
  type_string_literal_array(literal);
  pfVar6 = name_intern(g_string_literal_cur + uVar8);
  pcVar7 = scope_stack_lookup(g_current_scope,(int)pfVar6);
  if (pcVar7 != (c1_scope_lookup *)0x0) {
    pcVar1 = &pcVar7->sym->flags1;
    *pcVar1 = *pcVar1 | 2;
  }
  cVar13 = '\x01';
  pfVar6 = g_name_unnamed;
  name = name_intern(".drectve");
  g_data_seg_name = segment_lookup_or_declare(name,pfVar6,cVar13);
  p1inl_new_key_default((int)literal);
  g_file_scope_decl_since_body = 1;
  g_data_seg_name = pvVar4;
  return;
}

