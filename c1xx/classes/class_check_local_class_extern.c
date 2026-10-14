c1_u8 * class_check_local_class_extern(void *ret_addr,c1_u8 token_code,c1_decl_spec_scan *state)

{
  c1_u8 *pcVar1;
  c1_arena *a;
  c1_u8 *pcVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  bool bVar7;
  
  diag_error(0x270);
  if ((state->spec[0] & 7) == 0) {
    state->spec[0] = state->spec[0] | 0x20;
  }
  iVar4 = g_token_arena_index;
  g_yylval_spec_insert_fn = state->insert_fn;
  g_yylval_spec_type_sym = state->type_sym;
  g_yylval_spec_type = state->type;
  bVar7 = g_token_arena_index == 0;
  pcVar2 = state->spec;
  puVar5 = &g_yylval;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *(uint *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar5 = puVar5 + 1;
  }
  if (bVar7) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar2 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + iVar4;
    pcVar2 = a->cur;
    pcVar1 = g_arenas[iVar4].end;
    a->cur = pcVar2 + 0x30;
    if (pcVar1 < pcVar2 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar2 == (c1_u8 *)0x0) {
    state->result = (c1_u8 *)0x0;
    return (c1_u8 *)0x0;
  }
  *pcVar2 = token_code;
  puVar5 = &g_yylval;
  puVar6 = (uint *)(pcVar2 + 8);
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  state->result = pcVar2;
  return pcVar2;
}

