void __cdecl
token_stream_put_function_header(c1_symbol *sym,c1xx_token_stream *stream,int arena_index)

{
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  c1_u8 *pcVar3;
  int iVar4;
  arena *a;
  uint *puVar5;
  uint *puVar6;
  c1_sym_list *param_scope;
  c1xx_block_scope *bound_scope;
  c1_symbol *header_word;
  
  if ((g_compile_flags_c8 & 0x40000000) == 0) {
    pcVar3 = g_arenas[arena_index].cur;
    pcVar1 = g_arenas[arena_index].end;
    a = g_arenas + arena_index;
    a->cur = pcVar3 + 8;
    if (pcVar1 < pcVar3 + 8) {
      arena_grow(a);
    }
    iVar4 = g_pending_function_word;
    if (pcVar3 == (c1_u8 *)0x0) {
      g_yylval = 0;
    }
    else {
      *(c1_sym_list **)pcVar3 = g_pending_parameter_scope;
      *(int *)(pcVar3 + 4) = iVar4;
      g_yylval = (uint)pcVar3;
    }
    if (arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar3 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar3 = arena_alloc(a,0x30);
    }
    if (pcVar3 != (c1_u8 *)0x0) {
      *pcVar3 = 0xd5;
      puVar5 = &g_yylval;
      puVar6 = (uint *)(pcVar3 + 8);
      for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      goto LAB_1041c5ac;
    }
  }
  else {
    pcVar3 = g_arenas[arena_index].cur;
    pcVar1 = g_arenas[arena_index].end;
    a = g_arenas + arena_index;
    a->cur = pcVar3 + 0x24;
    if (pcVar1 < pcVar3 + 0x24) {
      arena_grow(a);
    }
    param_scope = g_pending_parameter_scope;
    iVar4 = g_token_position;
    bound_scope = g_tmpl_bound_scope;
    header_word = g_tmpl_current_instance;
    pcVar2 = g_tmpl_current_template;
    if (pcVar3 == (c1_u8 *)0x0) {
      g_yylval = 0;
    }
    else {
      *(int *)(pcVar3 + 4) = g_pending_function_word;
      *(c1_sym_list **)pcVar3 = param_scope;
      *(c1_symbol **)(pcVar3 + 8) = pcVar2;
      *(c1_symbol **)(pcVar3 + 0xc) = header_word;
      *(c1_symbol **)(pcVar3 + 0x10) = sym;
      *(c1xx_block_scope **)(pcVar3 + 0x14) = bound_scope;
      pcVar3[0x18] = '\0';
      pcVar3[0x19] = '\0';
      pcVar3[0x1a] = '\0';
      pcVar3[0x1b] = '\0';
      *(int *)(pcVar3 + 0x1c) = iVar4;
      pcVar3[0x20] = '\0';
      pcVar3[0x21] = '\0';
      pcVar3[0x22] = '\0';
      pcVar3[0x23] = '\0';
      g_yylval = (uint)pcVar3;
    }
    if (arena_index == 0) {
      pcVar3 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      pcVar3 = arena_alloc(a,0x30);
    }
    if (pcVar3 != (c1_u8 *)0x0) {
      *pcVar3 = 0xca;
      puVar5 = &g_yylval;
      puVar6 = (uint *)(pcVar3 + 8);
      for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      goto LAB_1041c5ac;
    }
  }
  pcVar3 = (c1_u8 *)0x0;
LAB_1041c5ac:
  (*stream->vtbl->append)(stream,(int)pcVar3);
  if (arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar3 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    pcVar3 = a->cur;
    a->cur = pcVar3 + 0x30;
    if (a->end < pcVar3 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar3 == (c1_u8 *)0x0) {
    (*stream->vtbl->append)(stream,0);
    return;
  }
  *pcVar3 = 0xc9;
  *(c1_symbol **)(pcVar3 + 8) = sym;
  (*stream->vtbl->append)(stream,(int)pcVar3);
  return;
}

