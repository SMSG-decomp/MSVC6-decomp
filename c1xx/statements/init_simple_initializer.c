void __cdecl init_simple_initializer(c1_symbol *sym,c1_node *value)

{
  c1_type *pcVar1;
  c1_u32 cVar2;
  ushort uVar3;
  c1_symbol *pcVar4;
  int iVar5;
  int iVar6;
  c1_node *pcVar7;
  byte type_code_lo;
  c1_type *pcVar8;
  c1_conversion *conv;
  c1_type local_10;
  
  if (sym == (c1_symbol *)0x0) {
    return;
  }
  if ((sym->flags3 & 4) != 0) {
    return;
  }
  if ((value != (c1_node *)0x0) && (value->op == 0xe8)) {
    value = property_build_access('t',value,(c1_node *)0x0);
  }
  pcVar4 = sym_class_needing_init(sym);
  if (pcVar4 != (c1_symbol *)0x0) {
    init_construct_class_object(sym,(int)value);
    return;
  }
  if (value == (c1_node *)0x0) {
    return;
  }
  value = fold_static_const_member(value);
  if (g_token_class[value->op] == '`') {
    if (value->right != (void *)0x0) {
      diag_error(0x4e);
    }
    value = value->left;
  }
  value = init_record_constant_value(sym,value);
  conv = (c1_conversion *)g_arenas[5].cur;
  if (value == (c1_node *)0x0) {
    return;
  }
  g_arenas[5].cur = g_arenas[5].cur + 0x50;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  cVar2 = g_compile_flags_cc;
  if (conv == (c1_conversion *)0x0) {
    conv = (c1_conversion *)0x0;
  }
  else {
    pcVar1 = sym->type;
    conv->op = 't';
    *(c1_u8 *)((int)conv + 1) = ((cVar2 & 0x80000) != 0) + '\x01';
    *(c1_u8 *)((int)conv + 2) = '\x04';
    *(c1_node **)((int)conv + 4) = value;
    if (value == (c1_node *)0x0) {
      local_10.base = (c1_type *)0x0;
      local_10.debug_index = 0;
      local_10.code = 0x80f;
      local_10.flags = 0;
      local_10.extra.cls = (c1_symbol *)0x0;
      pcVar8 = type_intern(&local_10);
    }
    else {
      pcVar8 = value->type;
    }
    *(c1_type **)((int)conv + 8) = pcVar8;
    *(c1_type **)((int)conv + 0xc) = pcVar1;
    conv_compute_conversion(conv);
  }
  iVar5 = init_is_char_array_string_init(sym,value);
  if (iVar5 != 0) {
    uVar3 = init_check_array_bounds(sym,value);
    *(ushort *)&value->right = uVar3;
  }
  if (((g_compile_flags_c4 & 0x100000) == 0) &&
     (iVar6 = init_aggregate_element(sym,(int *)&value,(int)conv), iVar6 == 0)) {
    if ((sym->flags22 & 2) != 0) {
      diag_error(0x1e2);
      return;
    }
    init_begin_dynamic_initializer(sym);
    g_init_dynamic_offset = g_init_offset;
    g_init_turned_dynamic = 1;
  }
  if ((iVar5 == 0) && ((conv->flags4e & 1) == 0)) {
    conv_report_cannot_convert(conv,'\x01');
    return;
  }
  if (((g_compile_flags_c4 & 0x100000) != 0) && (iVar6 = sym_has_scalar_type(sym), iVar6 != 0)) {
LAB_10425cc5:
    pcVar7 = tree_new_symbol_ref(sym,'\0');
    init_emit_initializer_expression(pcVar7,conv);
    init_end_declaration(sym);
    return;
  }
  pcVar1 = sym->type;
  uVar3 = pcVar1->code;
  if ((char)uVar3 < '\0') {
    pcVar8 = (c1_type *)(-(uint)((uVar3 & 0x80) != 0) & (uint)pcVar1);
    type_code_lo = (byte)pcVar8->code;
    if ((type_code_lo & 0x8f) == 0x83) {
      if (iVar5 == 0) {
        init_check_string_initializer(type_code_lo,pcVar1,pcVar8,sym,value);
        return;
      }
      goto LAB_10425da7;
    }
  }
  else if ((uVar3 & 0x200) != 0) {
    if ((g_compile_flags_c4 & 0x100000) == 0) {
      diag_error(0x4a,sym,pcVar1);
      return;
    }
    sym->flags4 = sym->flags4 & 0xfb;
    goto LAB_10425cc5;
  }
  if (iVar5 == 0) {
    value = conv_apply_conversion(conv,(c1_node *)0x0);
  }
LAB_10425da7:
  pcVar7 = tree_strip_casts_and_segment_bases(value);
  if ((g_compile_flags_c4 & 0x100000) == 0) {
    init_emit_symbol_data(sym,pcVar7,&g_il_in);
  }
  else {
    init_emit_element_store(sym,value,&conv->op);
  }
  if (iVar5 != 0) {
    g_constant_value = init_string_array_room(sym,(uint)pcVar7);
    g_constant_value_high = 0;
    if (g_constant_value != 0) {
      init_emit_data((c1_symbol *)0x0);
    }
  }
  init_end_declaration(sym);
  return;
}

