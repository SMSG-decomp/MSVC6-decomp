void __cdecl pch_emit_pchsym_include_directive(void)

{
  c1_u8 *pcVar1;
  c1_node *literal;
  c1_node *pcVar2;
  short sVar3;
  void *pvVar4;
  char *pcVar5;
  void *pvVar6;
  c1_lookup_entry *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  c1_arena *a;
  c1_u32 *dst;
  char *src;
  char *src_4;
  c1_u32 *dst_2;
  char *src_3;
  char *src_2;
  fe_name *seg_class;
  char cVar11;
  
  pcVar5 = g_string_literal_cur;
  pvVar4 = g_data_seg_name;
  uVar8 = 0xffffffff;
  src_4 = g_pch_symbol_include_option;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar11 = *src_4;
    src_4 = src_4 + 1;
  } while (cVar11 != '\0');
  uVar8 = ~uVar8 - 1;
  dst = (c1_u32 *)g_pch_symbol_include_option;
  dst_2 = (c1_u32 *)g_string_literal_cur;
  for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *dst_2 = *dst;
    dst = dst + 1;
    dst_2 = dst_2 + 1;
  }
  for (uVar9 = uVar8 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(char *)dst_2 = (char)*dst;
    dst = (c1_u32 *)((int)dst + 1);
    dst_2 = (c1_u32 *)((int)dst_2 + 1);
  }
  uVar9 = 0xffffffff;
  src_3 = g_pch_symbol_name;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar11 = *src_3;
    src_3 = src_3 + 1;
  } while (cVar11 != '\0');
  uVar9 = ~uVar9;
  src = g_pch_symbol_name;
  src_2 = pcVar5 + uVar8;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)src_2 = *(undefined4 *)src;
    src = src + 4;
    src_2 = src_2 + 4;
  }
  for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *src_2 = *src;
    src = src + 1;
    src_2 = src_2 + 1;
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
  uVar9 = 0x132;
  pvVar6 = name_intern(g_string_literal_cur + uVar8);
  pcVar7 = lookup_name_in_context(g_current_scope,pvVar6,uVar9);
  if (pcVar7 != (c1_lookup_entry *)0x0) {
    pcVar1 = &pcVar7->sym->flags2;
    *pcVar1 = *pcVar1 | 8;
  }
  cVar11 = '\x01';
  seg_class = g_name_unnamed;
  pvVar6 = name_intern(".drectve");
  g_data_seg_name = segment_lookup_or_declare(pvVar6,seg_class,cVar11);
  p1inl_new_key_default((int)literal);
  g_file_scope_decl_since_body = 1;
  g_data_seg_name = pvVar4;
  return;
}

