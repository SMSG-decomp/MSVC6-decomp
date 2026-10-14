void __cdecl init_construct_remaining_elements(void)

{
  char cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  int iVar5;
  c1_node *pcVar6;
  c1_node *left;
  fe_name *name;
  c1_symbol *sym;
  c1_type *pcVar7;
  c1_symbol *pcVar8;
  uint uVar9;
  uint uVar10;
  c1_symbol *pcVar11;
  c1_type local_10;
  
  iVar5 = g_error_count;
  if ((g_init_remaining_error == 0) && (g_init_remaining_count != 0)) {
    pcVar7 = g_type_none;
    pcVar6 = tree_new_int_constant(g_init_remaining_offset);
    left = tree_new_symbol_ref(g_init_symbol,'\0');
    pcVar6 = tree_new_node('P',left,pcVar6,pcVar7);
    name = name_new_S();
    sym = sym_new_kind1_placeholder(name);
    uVar10 = g_symbol_size_table[g_init_symbol->kind & 0x1f];
    pcVar8 = g_init_symbol;
    pcVar11 = sym;
    for (uVar9 = uVar10 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      cVar2 = pcVar8->flags1;
      cVar3 = pcVar8->flags2;
      cVar4 = pcVar8->flags3;
      pcVar11->kind = pcVar8->kind;
      pcVar11->flags1 = cVar2;
      pcVar11->flags2 = cVar3;
      pcVar11->flags3 = cVar4;
      pcVar8 = (c1_symbol *)&pcVar8->flags4;
      pcVar11 = (c1_symbol *)&pcVar11->flags4;
    }
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      pcVar11->kind = pcVar8->kind;
      pcVar8 = (c1_symbol *)&pcVar8->flags1;
      pcVar11 = (c1_symbol *)&pcVar11->flags1;
    }
    sym->name = name;
    sym->kind = sym->kind & 0xdf;
    pcVar7 = g_init_symbol->type;
    cVar1 = (char)pcVar7->code;
    while (cVar1 < '\0') {
      pcVar7 = pcVar7->base;
      cVar1 = (char)pcVar7->code;
    }
    if ((pcVar7->flags & 0x3e0) != 0) {
      uVar10._0_2_ = pcVar7->code;
      uVar10._2_2_ = pcVar7->flags;
      local_10.base = pcVar7->base;
      local_10.extra = pcVar7->extra;
      local_10._0_4_ = uVar10 & 0xfc1fffff;
      local_10.debug_index = pcVar7->debug_index;
      pcVar7 = type_intern(&local_10);
    }
    sym->type = pcVar7;
    local_10.debug_index = 0;
    local_10.code = 0x83;
    local_10.flags = 0;
    local_10.extra.count = g_init_remaining_count;
    local_10.base = pcVar7;
    pcVar7 = type_intern(&local_10);
    sym->type = pcVar7;
    if ((g_init_symbol->flags23 & 1) != 0) {
      pcVar8 = sym_segment_record(g_init_symbol);
      sym_set_or_clear_segment(sym,(int)pcVar8);
    }
    pcVar6->type = sym->type;
    pcVar7 = conv_array_to_pointer_type(pcVar6);
    pcVar6->type = pcVar7;
    pcVar6 = expr_build_new('\0',0,sym,0,pcVar6,0);
    stmt_emit_expression(pcVar6);
    g_init_remaining_count = 0;
    if (iVar5 < g_error_count) {
      g_init_remaining_error = 1;
    }
  }
  return;
}

