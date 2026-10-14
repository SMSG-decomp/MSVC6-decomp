int __fastcall decl_scan_class_specifier(c1_decl_spec_scan *state)

{
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  c1_u8 *pcVar3;
  c1_type *pcVar4;
  int iVar5;
  c1xx_token *pcVar6;
  void *pvVar7;
  uint uVar8;
  
  g_compile_flags_c4 = g_compile_flags_c4 | 0x80000;
  pcVar3 = class_scan_head_tokens((ushort)g_tree_op_to_il_op[*state->token],state->spec);
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfff7ffff;
  if (pcVar3 == (c1_u8 *)0x0) {
    return 0;
  }
  if (*pcVar3 == 0xe5) {
    state->token = pcVar3;
    return 2;
  }
  if (*pcVar3 == '\x01') {
    pcVar6 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    state->token = (c1_u8 *)pcVar6;
    if ((g_compile_flags_c8 & 0x10000000) != 0) {
      pcVar6 = parse_skip_tokens_to_one_of(pcVar6,0x3e);
      state->token = &pcVar6->code;
      return 2;
    }
    pcVar6 = parse_skip_tokens_to_one_of(pcVar6,0x7f,1);
    state->token = &pcVar6->code;
    return 2;
  }
  if ((state->named_type != (c1_type *)0x0) || (state->basic_type != 0)) {
    diag_error(0xec,0x4c,(uint)*state->token,*(undefined4 *)(pcVar3 + 0x24));
    state->basic_type = 0;
  }
  pcVar2 = *(c1_symbol **)(pcVar3 + 0x24);
  state->type_sym = pcVar2;
  state->insert_fn = *(void **)(pcVar3 + 0x28);
  pcVar4 = sym_resolved_type_mark_used(pcVar2);
  state->named_type = pcVar4;
  pcVar2 = state->type_sym;
  if ((state->spec[3] & 0x40) == 0) {
    if ((((((pcVar2->detail).cls)->flags3e & 1) == 0) || ((state->spec[1] & 4) != 0)) ||
       (((state->spec[0] & 7) == 7 ||
        ((g_sizeof_depth != 0 || ((g_compile_flags_cc & 0x10000000) != 0)))))) goto LAB_10433a7e;
    diag_begin_global(g_token_position);
    pvVar7 = tmpl_template_of_instance(state->type_sym);
    if (g_ms_extensions == '\0') {
      diag_error(0x38a,*(undefined4 *)((int)pvVar7 + 8));
      diag_note(0x1903,state->type_sym->type,state->type_sym->name);
    }
    else {
      uVar8 = diag_warning_is_enabled(4,0x297);
      if (uVar8 != 0) {
        diag_warning(4,0x297,*(undefined4 *)((int)pvVar7 + 8));
        diag_note(0x1903,state->type_sym->type,state->type_sym->name);
      }
    }
    diag_end_global();
  }
  else if (((pcVar2 == (c1_symbol *)0x0) || ((pcVar2->kind & 0x1f) != 4)) ||
          ((((pcVar2->detail).cls)->flags3e & 1) == 0)) {
    diag_error(0x391,pcVar2);
  }
  pcVar1 = &((state->type_sym->detail).cls)->flags3f;
  *pcVar1 = *pcVar1 | 1;
LAB_10433a7e:
  if (((((state->type_sym->detail).cls)->flags3f & 1) != 0) && ((state->type_sym->flags2 & 4) != 0))
  {
    iVar5 = tmpl_check_specialization_after_instantiation(1,state);
    return iVar5;
  }
  if (*pcVar3 != '\"') {
    if (*pcVar3 != '#') {
      return 0;
    }
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
  }
  decl_check_type_unexpected((int)state);
  if ((state->spec[1] & 4) != 0) {
    diag_error(0x187,state->type_sym);
  }
  pcVar3 = decl_scan_make_specifier_token(state,*pcVar3);
  state->token = pcVar3;
  return 2;
}

