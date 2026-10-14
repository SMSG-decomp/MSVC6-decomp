c1_u8 * __thiscall decl_scan_make_specifier_token(c1_decl_spec_scan *state,c1_u8 token_code)

{
  c1_type *pcVar1;
  c1_u8 *pcVar2;
  c1_arena *a;
  c1_u8 *pcVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  bool bVar8;
  void *unaff_retaddr;
  
  if (state->result != (c1_u8 *)0x0) {
    return state->result;
  }
  if (state->type == (c1_type *)0x0) {
    pcVar1 = state->named_type;
    state->type = pcVar1;
    if ((((state->has_declspec != '\0') && ((state->spec[0] & 7) == 1)) &&
        ((pcVar1->code & 0x300) != 0)) &&
       ((((((pcVar1->extra).cls)->detail).cls)->flags3e & 0x80) != 0)) {
      pcVar3 = class_check_local_class_extern(unaff_retaddr,token_code,state);
      return pcVar3;
    }
  }
  if ((state->spec[0] & 7) == 0) {
    state->spec[0] = state->spec[0] | 0x20;
  }
  iVar5 = g_token_arena_index;
  g_yylval_spec_insert_fn = state->insert_fn;
  g_yylval_spec_type_sym = state->type_sym;
  g_yylval_spec_type = state->type;
  bVar8 = g_token_arena_index == 0;
  pcVar3 = state->spec;
  puVar6 = &g_yylval;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *(uint *)pcVar3;
    pcVar3 = pcVar3 + 4;
    puVar6 = puVar6 + 1;
  }
  if (bVar8) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar3 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + iVar5;
    pcVar3 = a->cur;
    pcVar2 = g_arenas[iVar5].end;
    a->cur = pcVar3 + 0x30;
    if (pcVar2 < pcVar3 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar3 == (c1_u8 *)0x0) {
    state->result = (c1_u8 *)0x0;
    return (c1_u8 *)0x0;
  }
  *pcVar3 = token_code;
  puVar6 = &g_yylval;
  puVar7 = (uint *)(pcVar3 + 8);
  for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  state->result = pcVar3;
  return pcVar3;
}

