void __cdecl init_check_aggregate_or_constant(c1_symbol *sym,c1_node *init)

{
  undefined1 kind;
  ushort uVar1;
  int iVar2;
  int iVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_type *pcVar6;
  
  if (((sym == (c1_symbol *)0x0) || ((sym->flags2 & 1) != 0)) || (init == (c1_node *)0x0)) {
    return;
  }
  iVar2 = init_is_char_array_string_init(sym,init);
  if (iVar2 != 0) {
    uVar1 = expr_warn_array_bounds_overflow(sym,init);
    *(ushort *)&init->right = uVar1;
  }
  if ((g_compile_flags_c4 & 0x100000) == 0) {
    iVar3 = init_is_constant_initializer(sym,&init);
    if (iVar3 == 0) {
      diag_error(99);
      return;
    }
    init_check_dllimport_address(sym,init);
    if ((g_compile_flags_c4 & 0x100000) == 0) goto LAB_1061cc83;
  }
  iVar3 = sym_has_scalar_type(sym);
  pcVar5 = init;
  if (iVar3 != 0) {
    pcVar4 = tree_new_symbol_ref(sym);
    init_emit_runtime_assignment(pcVar4,pcVar5);
    init_end_record(sym);
    return;
  }
LAB_1061cc83:
  pcVar5 = init;
  pcVar6 = sym->type;
  uVar1 = pcVar6->code;
  if ((char)uVar1 < '\0') {
    pcVar5 = (c1_node *)(-(uint)((uVar1 & 0x80) != 0) & (uint)pcVar6);
    kind = pcVar5->op;
    if (((kind & 0x8f) == 0x83) && (iVar2 == 0)) {
      init_check_string_initializer(kind,pcVar6,pcVar5,init);
      return;
    }
  }
  else if ((uVar1 & 0x200) != 0) {
    if ((g_compile_flags_c4 & 0x100000) != 0) {
      sym->flags3 = sym->flags3 & 0xfb;
      pcVar4 = tree_new_symbol_ref(sym);
      init_emit_runtime_assignment(pcVar4,pcVar5);
      init_end_record(sym);
      return;
    }
    diag_error(0x4a,sym,pcVar6);
    return;
  }
  pcVar5 = tree_strip_casts_and_segment_bases(init);
  if ((g_compile_flags_c4 & 0x100000) == 0) {
    init_emit_symbol_data(sym,pcVar5,&g_il_in);
  }
  else {
    init_emit_runtime_element(sym,init);
  }
  if (iVar2 == 0) {
    if ((init->type->code & 0x8f) == 0x83) {
      pcVar6 = conv_array_to_pointer_type(init);
      init->type = pcVar6;
    }
    conv_check_conversion_to_type('t',sym->type,init);
  }
  else {
    g_constant_value = init_string_array_room(sym,(uint)pcVar5);
    g_constant_value_high = 0;
    if (g_constant_value != 0) {
      init_check_aggregate_or_constant_fragment(sym);
      return;
    }
  }
  init_end_record(sym);
  return;
}

