c1xx_token * __cdecl lex_classify_type_name(c1xx_token *token)

{
  c1xx_token *pcVar1;
  bool bVar2;
  c1_u8 *pcVar3;
  byte bVar4;
  int *name;
  c1_lookup_entry *pcVar5;
  c1_arena *a;
  char *pcVar6;
  c1xx_token *pcVar7;
  void *pvVar8;
  int iVar9;
  uint uVar10;
  c1_symbol *sym;
  c1_symbol *pcVar11;
  c1_symbol *sym_00;
  uint *puVar12;
  void **ppvVar13;
  
  if (token->code == '\x06') {
    token = (c1xx_token *)lex_compose_qualified_name((char *)token,0);
  }
  bVar4 = token->code;
  if (bVar4 == 6) {
    name = token->value;
    if ((name[2] & 0x20000U) == 0) {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      return token;
    }
  }
  else {
    if (bVar4 == 0x96) {
      name = token->value;
      bVar2 = true;
      pcVar11 = (c1_symbol *)*name;
      goto LAB_10407a21;
    }
    if (bVar4 != 0xe4) {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      return token;
    }
    name = token->value;
    if ((*(uint *)(*name + 8) & 0x20000) == 0) {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      return token;
    }
  }
  pcVar11 = (c1_symbol *)0x0;
  bVar2 = false;
LAB_10407a21:
  if ((g_compile_flags_c4 & 0x40) != 0) {
    pcVar5 = lookup_name_in_context(g_current_scope,name,0x132);
    if (pcVar5 == (c1_lookup_entry *)0x0) {
      pcVar11 = (c1_symbol *)0x0;
    }
    else {
      pcVar11 = pcVar5->sym;
    }
    if (pcVar11 == (c1_symbol *)0x0) {
      diag_error(0x41,token->value);
      return token;
    }
    if ((pcVar11->flags2 & 0x10) == 0) {
      diag_error(0x3d,token->value);
      return token;
    }
    pcVar7 = (c1xx_token *)token_new_decl_specifiers((int)pcVar11->type,0,(byte *)0x0,0);
    return pcVar7;
  }
  if ((g_compile_flags_c4 & 0x80000000) == 0) {
    if ((g_compile_flags_c4 & 1) != 0) {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      return token;
    }
    if ((g_paren_level_flags[g_paren_depth] & 2) != 0) {
      return token;
    }
    if (g_current_scope->qualified != '\0') {
      return token;
    }
  }
  if (bVar4 == 6) {
    pcVar5 = lookup_name_in_context(g_current_scope,name,0x132);
    if (pcVar5 == (c1_lookup_entry *)0x0) {
      pcVar11 = (c1_symbol *)0x0;
    }
    else {
      pcVar11 = pcVar5->sym;
    }
    if (pcVar11 == (c1_symbol *)0x0) {
      return token;
    }
  }
  else if (bVar4 == 0xe4) {
    pcVar11 = (c1_symbol *)name[2];
  }
  sym = (c1_symbol *)0x0;
  sym_00 = pcVar11;
  if ((pcVar11->kind & 0x1f) == 0x12) {
    sym_00 = *(c1_symbol **)(*(int *)pcVar11->type + 8);
    sym = pcVar11;
  }
  bVar4 = sym_00->kind & 0x1f;
  if (bVar4 == 0xf) {
    if ((sym_00->key_ref & 0x20000) == 0) {
      sym_00 = g_scope_vector->entries[(short)sym_00->key_ref];
    }
  }
  else if (bVar4 == 0x1a) {
    sym_00 = *(c1_symbol **)sym_00->type;
  }
  if ((sym_00->flags2 & 0x10) != 0) {
    if ((((g_paren_depth == 0) && ((g_compile_flags_c4 & 0x20000) != 0)) &&
        ((g_compile_flags_c4 & 0x18000000) == 0)) &&
       (((g_compile_flags_c8 & 0x18) == 0 &&
        (pcVar6 = lex_peek_token((uint *)&g_token_position), *pcVar6 == '6')))) {
      pcVar7 = (c1xx_token *)expr_lookup_identifier_tail(&token->code);
      return pcVar7;
    }
    if ((sym_00->flags2 & 0x20) != 0) {
      pvVar8 = sym_hiding_partner(sym_00);
      if (bVar2) {
        *(void **)(*(int *)sym->type + 8) = pvVar8;
        pcVar3 = g_arenas[4].cur;
        g_arenas[4].cur = g_arenas[4].cur + 8;
        if (g_arenas[4].end < g_arenas[4].cur) {
          arena_grow(g_arenas + 4);
        }
        if (pcVar3 == (c1_u8 *)0x0) {
          g_yylval = 0;
        }
        else {
          *(c1_symbol **)pcVar3 = sym;
          pcVar3[4] = '\0';
          pcVar3[5] = '\0';
          pcVar3[6] = '\0';
          pcVar3[7] = '\0';
          g_yylval = (uint)pcVar3;
        }
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar7 = (c1xx_token *)g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pcVar7 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        token = (c1xx_token *)0x0;
        if (pcVar7 != (c1xx_token *)0x0) {
          pcVar7->code = 0x96;
          puVar12 = &g_yylval;
          ppvVar13 = &pcVar7->value;
          for (iVar9 = 10; token = pcVar7, iVar9 != 0; iVar9 = iVar9 + -1) {
            *ppvVar13 = (void *)*puVar12;
            puVar12 = puVar12 + 1;
            ppvVar13 = ppvVar13 + 1;
          }
        }
      }
      return token;
    }
    if (bVar2) {
      if (g_ms_extensions == '\0') {
        access_check_member(sym);
      }
      else {
        pcVar11 = sym_new_scoped_copy(sym,4);
        g_pending_access_check[g_paren_depth] = pcVar11;
      }
    }
    else {
      g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
    }
    bVar4 = sym_00->kind & 0x1f;
    if (((bVar4 == 4) && ((g_paren_level_flags[g_paren_depth] & 1) != 0)) &&
       ((g_compile_flags_c8 & 8) == 0)) {
      return token;
    }
    if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
      pcVar11 = sym_00;
      if (bVar4 == 0x12) {
        pcVar11 = *(c1_symbol **)(*(int *)sym_00->type + 8);
      }
      if ((pcVar11->entity & 0xffffff) == 0) {
        if (0x7ffffffe < g_next_entity_id) {
          diag_fatal_simple(0x37);
        }
        uVar10 = pcVar11->entity ^ g_next_entity_id;
        g_next_entity_id = g_next_entity_id + 1;
        pcVar11->entity = uVar10 & 0xffffff ^ pcVar11->entity;
      }
      (*g_il_emitter->vtbl->reference_symbol)((int)pcVar11);
    }
    if (sym != (c1_symbol *)0x0) {
      sym_00 = sym;
    }
    if (((g_compile_flags_c8 & 0x100) != 0) && (g_paren_depth == 0)) {
      pcVar7 = (c1xx_token *)lex_classify_typedef_name_fragment(g_compile_flags_c8,sym_00);
      return pcVar7;
    }
    g_yylval = (uint)sym_00;
    if (g_token_arena_index == 0) {
      if (g_pool_default_left < 0x30) {
        pool_reserve((c1xx_pool *)&g_pool_default,0x30);
      }
      g_pool_default_left = g_pool_default_left - 0x30;
      pcVar7 = (c1xx_token *)g_pool_default;
      g_pool_default = g_pool_default + 0x30;
    }
    else {
      a = g_arenas + g_token_arena_index;
      pcVar7 = (c1xx_token *)a->cur;
      pcVar1 = (c1xx_token *)g_arenas[g_token_arena_index].end;
      a->cur = &pcVar7[1].code;
      if (pcVar1 < pcVar7 + 1) {
        arena_grow(a);
      }
    }
    if (pcVar7 == (c1xx_token *)0x0) {
      return (c1xx_token *)0x0;
    }
    pcVar7->code = '\x1e';
    puVar12 = &g_yylval;
    ppvVar13 = &pcVar7->value;
    for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
      *ppvVar13 = (void *)*puVar12;
      puVar12 = puVar12 + 1;
      ppvVar13 = ppvVar13 + 1;
    }
    return pcVar7;
  }
  return token;
}

