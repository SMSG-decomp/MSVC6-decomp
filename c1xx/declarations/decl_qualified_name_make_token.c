byte * __cdecl
decl_qualified_name_make_token
          (c1_u8 *cur_tok,c1_keyed_list *scope,void *name,c1_keyed_list *scope_saved,
          int leading_global,int has_ctor,int has_dtor,void *saved_name,int pair_second,
          int set_flags1_80,int set_flags3_01,char *token,int p2)

{
  c1_u8 *pcVar1;
  c1_arena *pcVar2;
  c1_overload_set *pcVar3;
  byte *pbVar4;
  int iVar5;
  uint *puVar6;
  byte *pbVar7;
  c1_symbol *pcVar8;
  uint *puVar9;
  
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)cur_tok);
  if (token == (char *)0x0) {
    if (g_token_arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pbVar4 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar2 = g_arenas + g_token_arena_index;
      pbVar4 = pcVar2->cur;
      pbVar7 = g_arenas[g_token_arena_index].end;
      pcVar2->cur = pbVar4 + 0x30;
      if (pbVar7 < pbVar4 + 0x30) {
        arena_grow(pcVar2);
      }
    }
    if (pbVar4 == (byte *)0x0) {
      pbVar4 = (byte *)0x0;
    }
    else {
      *pbVar4 = 0x96;
      puVar6 = &g_yylval;
      puVar9 = (uint *)(pbVar4 + 8);
      for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar9 = puVar9 + 1;
      }
    }
  }
  else {
    if (g_token_arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pbVar4 = g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      pcVar2 = g_arenas + g_token_arena_index;
      pbVar4 = pcVar2->cur;
      pbVar7 = g_arenas[g_token_arena_index].end;
      pcVar2->cur = pbVar4 + 0x30;
      if (pbVar7 < pbVar4 + 0x30) {
        arena_grow(pcVar2);
      }
    }
    if (pbVar4 == (byte *)0x0) {
      pbVar4 = (byte *)0x0;
      uRam00000000 = 0x96;
    }
    else {
      pbVar7 = pbVar4;
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined4 *)pbVar7 = *(undefined4 *)token;
        token = token + 4;
        pbVar7 = pbVar7 + 4;
      }
      *pbVar4 = 0x96;
    }
  }
  if (scope == (c1_keyed_list *)0x0) {
    if (saved_name != (void *)0x0) {
      *pbVar4 = 6;
      *(void **)(pbVar4 + 8) = saved_name;
      return pbVar4;
    }
    if (name != (void *)0x0) {
      *pbVar4 = 6;
      *(void **)(pbVar4 + 8) = name;
      return pbVar4;
    }
    if (*pbVar4 != 0x4a) {
      return g_token_colon_colon;
    }
  }
  else {
    if ((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
        ((g_compile_flags_c8 & 0x10000000) != 0)) ||
       (((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)) || (((byte)g_compile_flags_cc & 0x50) != 0)))) {
      iVar5 = 0;
    }
    else {
      iVar5 = 4;
    }
    pcVar3 = sym_new_overload_set_record(scope_saved,name,iVar5);
    if (*pbVar4 == 0x9f) {
      *pbVar4 = 0x9f;
      *(c1_overload_set **)(pbVar4 + 8) = pcVar3;
    }
    else {
      *pbVar4 = 0x96;
      pcVar1 = g_arenas[4].cur;
      g_arenas[4].cur = g_arenas[4].cur + 8;
      if (g_arenas[4].end < g_arenas[4].cur) {
        arena_grow(g_arenas + 4);
      }
      if (pcVar1 == (c1_u8 *)0x0) {
        pbVar4[8] = 0;
        pbVar4[9] = 0;
        pbVar4[10] = 0;
        pbVar4[0xb] = 0;
      }
      else {
        *(c1_overload_set **)pcVar1 = pcVar3;
        *(int *)(pcVar1 + 4) = pair_second;
        *(c1_u8 **)(pbVar4 + 8) = pcVar1;
      }
    }
    if ((char)leading_global != '\0') {
      if (g_current_scope->qualified != '\0') {
        diag_error(299,pcVar3,(uint)g_current_scope->access_op);
        pcVar3->flags3 = pcVar3->flags3 | 4;
      }
      pcVar3->flags3 = pcVar3->flags3 | 0x40;
    }
    if ((((g_compile_flags_c4 & 0x80000) != 0) && ((char)p2 == '\0')) &&
       (pcVar8 = pcVar3->list->head->sym, (pcVar8->kind & 0x1f) == 10)) {
      pbVar4 = decl_declarator_name_mark_fragment
                         (pcVar8,pbVar4,has_ctor,has_dtor,set_flags1_80,set_flags3_01);
      return pbVar4;
    }
    if (*pbVar4 == 0x96) {
      pcVar8 = (c1_symbol *)**(undefined4 **)(pbVar4 + 8);
    }
    else {
      pcVar8 = *(c1_symbol **)(pbVar4 + 8);
    }
    expr_resolve_overload_set_member(pcVar8,(c1_symbol *)0x0);
    if (has_ctor != 0) {
      pcVar8->flags1 = pcVar8->flags1 | 0x10;
    }
    if (has_dtor != 0) {
      pcVar8->flags1 = pcVar8->flags1 | 0x20;
    }
    if (set_flags1_80 != 0) {
      pcVar8->flags1 = pcVar8->flags1 | 0x80;
    }
    if (set_flags3_01 != 0) {
      pcVar8->flags3 = pcVar8->flags3 | 1;
      return pbVar4;
    }
  }
  return pbVar4;
}

