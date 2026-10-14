byte * __cdecl
decl_qualified_name_scan_part_1
          (int *tmpl_rec,void *name,c1_keyed_list *scope,char op_byte,char first_lookup_hit,
          c1_u8 *cur_tok,c1_keyed_list *scope_saved,int leading_global,int nerrors,int has_ctor,
          int has_dtor,void *saved_name,byte *template_tok,int set_flags1_80,int set_flags3_01,
          c1_u8 saved_access_op,c1_u8 saved_reported,c1_u8 saved_access_op_2,c1_u8 saved_reported_2,
          char *token,int p2)

{
  byte bVar1;
  c1_u8 cVar2;
  int *tmpl_rec_00;
  fe_name *pfVar3;
  c1_scope_stack *pcVar4;
  c1_keyed_list *scope_00;
  c1_arena *pcVar5;
  c1_overload_set *pcVar6;
  void *pvVar7;
  fe_name *pfVar8;
  byte *pbVar9;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar10;
  c1_symbol *pcVar11;
  char *pcVar12;
  c1_decl_record *pcVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  fe_name *name_00;
  uint *puVar17;
  c1_u8 *pcVar18;
  byte *pbVar19;
  uint *puVar20;
  bool bVar21;
  short n;
  
  iVar16 = tmpl_rec[3];
LAB_104080cf:
  if (scope != (c1_keyed_list *)0x0) {
    if ((((scope->head != (c1_keyed_cell *)0x0) &&
         (pcVar11 = scope->head->sym, (pcVar11->kind & 0x1f) == 4)) &&
        ((((pcVar11->detail).cls)->flags3e & 1) != 0)) &&
       (pvVar7 = tmpl_template_of_instance(pcVar11), *(fe_name **)((int)pvVar7 + 8) == name)) {
      pbVar9 = decl_lookup_qualified_template_name_fragment
                         (pcVar11,scope,op_byte,first_lookup_hit,cur_tok,scope_saved,leading_global,
                          nerrors,has_ctor,has_dtor,saved_name,template_tok,iVar16,set_flags1_80,
                          set_flags3_01,saved_access_op,saved_reported,saved_access_op_2,
                          saved_reported_2,token,p2);
      return pbVar9;
    }
    pcVar11 = scope->head->sym;
    name_00 = name;
    if ((pcVar11->kind & 0x1f) == 0x19) goto LAB_1040810f;
    if (name != pcVar11->name) goto LAB_1040810f;
    if (has_ctor != 0) {
      diag_error(0x253,name);
    }
    if (has_dtor != 0) {
      diag_error(0x254,name);
    }
    has_ctor = 1;
    name_00 = g_name_ctor;
    saved_name = name;
    goto LAB_1040810f;
  }
  scope_00 = scope;
  if (nerrors == 0) {
    result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,name,1);
    if ((result == (c1_lookup_result *)0x0) ||
       (pcVar10 = lookup_check_ambiguous_symbol(result,'\x01'), pcVar10 == (c1_lookup_entry *)0x0))
    {
      pcVar11 = (c1_symbol *)0x0;
    }
    else {
      pcVar11 = pcVar10->sym;
    }
    if (pcVar11 == (c1_symbol *)0x0) {
      if (*cur_tok == 0x8e) {
        g_yylval = CONCAT31(g_yylval._1_3_,cur_tok[8]);
        if (g_token_arena_index == 0) {
          pbVar9 = pool_alloc_raw(&g_pool_default,0x30);
        }
        else {
          pcVar5 = g_arenas + g_token_arena_index;
          pbVar9 = pcVar5->cur;
          pbVar19 = g_arenas[g_token_arena_index].end;
          pcVar5->cur = pbVar9 + 0x30;
          if (pbVar19 < pbVar9 + 0x30) {
            arena_grow(pcVar5);
          }
        }
        if (pbVar9 == (byte *)0x0) {
          return (byte *)0x0;
        }
        *pbVar9 = 0x97;
        puVar17 = &g_yylval;
        puVar20 = (uint *)(pbVar9 + 8);
        for (iVar16 = 10; iVar16 != 0; iVar16 = iVar16 + -1) {
          *puVar20 = *puVar17;
          puVar17 = puVar17 + 1;
          puVar20 = puVar20 + 1;
        }
        return pbVar9;
      }
      diag_error(0x205,name);
      scope_00 = (c1_keyed_list *)0x0;
      nerrors = 1;
      scope_saved = (c1_keyed_list *)0x0;
    }
    else {
      if ((((pcVar11->kind & 0x1f) == 10) && ((pcVar11->flags2 & 0x10) != 0)) &&
         (((pcVar11->type->code & 0x200) != 0 &&
          ((pcVar11 = (pcVar11->type->extra).cls, (g_compile_flags_c4 & 0x80000) != 0 &&
           (pcVar12 = lex_peek_token((uint *)&g_token_position), *pcVar12 != -0x6b)))))) {
        diag_error(0xf2);
      }
      tree_list_arena_set(4);
      scope_00 = tree_new_list_cell((c1_keyed_list *)0x0,0,pcVar11);
      scope_saved = scope_00;
      tree_list_arena_restore();
    }
  }
LAB_10408131:
  cur_tok = token_next((c1_token_reader *)&g_token_position);
  if (*cur_tok != 0x95) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)cur_tok);
    if (token == (char *)0x0) {
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pbVar9 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar5 = g_arenas + g_token_arena_index;
        pbVar9 = pcVar5->cur;
        pbVar19 = g_arenas[g_token_arena_index].end;
        pcVar5->cur = pbVar9 + 0x30;
        if (pbVar19 < pbVar9 + 0x30) {
          arena_grow(pcVar5);
        }
      }
      if (pbVar9 == (byte *)0x0) {
LAB_1045b4ab:
        pbVar9 = (byte *)0x0;
      }
      else {
        *pbVar9 = 0x96;
LAB_10408417:
        puVar17 = &g_yylval;
        puVar20 = (uint *)(pbVar9 + 8);
        for (iVar14 = 10; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar20 = *puVar17;
          puVar17 = puVar17 + 1;
          puVar20 = puVar20 + 1;
        }
      }
    }
    else {
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pbVar9 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar5 = g_arenas + g_token_arena_index;
        pbVar9 = pcVar5->cur;
        pbVar19 = g_arenas[g_token_arena_index].end;
        pcVar5->cur = pbVar9 + 0x30;
        if (pbVar19 < pbVar9 + 0x30) {
          arena_grow(pcVar5);
        }
      }
      if (pbVar9 == (byte *)0x0) {
        pbVar9 = (byte *)0x0;
        uRam00000000 = 0x96;
      }
      else {
        pbVar19 = pbVar9;
        for (iVar14 = 0xc; iVar14 != 0; iVar14 = iVar14 + -1) {
          *(undefined4 *)pbVar19 = *(undefined4 *)token;
          token = token + 4;
          pbVar19 = pbVar19 + 4;
        }
        *pbVar9 = 0x96;
      }
    }
    if (scope_00 == (c1_keyed_list *)0x0) {
      if (saved_name != (void *)0x0) {
        *pbVar9 = 6;
        *(void **)(pbVar9 + 8) = saved_name;
        return pbVar9;
      }
      if (name != (fe_name *)0x0) {
        *pbVar9 = 6;
        *(void **)(pbVar9 + 8) = name;
        return pbVar9;
      }
LAB_1045b010:
      if (*pbVar9 != 0x4a) {
        pbVar9 = g_token_colon_colon;
      }
    }
    else {
      if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
           ((g_compile_flags_c8 & 0x10000000) != 0)) ||
          ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
           ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
        iVar14 = 0;
      }
      else {
        iVar14 = 4;
      }
      pcVar6 = sym_new_overload_set_record(scope_saved,name,iVar14);
      if (*pbVar9 == 0x9f) {
        *pbVar9 = 0x9f;
        *(c1_overload_set **)(pbVar9 + 8) = pcVar6;
      }
      else {
        *pbVar9 = 0x96;
        pcVar18 = g_arenas[4].cur;
        g_arenas[4].cur = g_arenas[4].cur + 8;
        if (g_arenas[4].end < g_arenas[4].cur) {
          arena_grow(g_arenas + 4);
        }
        if (pcVar18 == (c1_u8 *)0x0) {
          pbVar9[8] = 0;
          pbVar9[9] = 0;
          pbVar9[10] = 0;
          pbVar9[0xb] = 0;
        }
        else {
          *(c1_overload_set **)pcVar18 = pcVar6;
          *(int *)(pcVar18 + 4) = iVar16;
          *(c1_u8 **)(pbVar9 + 8) = pcVar18;
        }
      }
      if ((char)leading_global != '\0') {
        if (g_current_scope->qualified != '\0') {
          diag_error(299,pcVar6,(uint)g_current_scope->access_op);
          pcVar6->flags3 = pcVar6->flags3 | 4;
        }
        pcVar6->flags3 = pcVar6->flags3 | 0x40;
      }
      if ((((g_compile_flags_c4 & 0x80000) != 0) && ((char)p2 == '\0')) &&
         (pcVar11 = pcVar6->list->head->sym, (pcVar11->kind & 0x1f) == 10)) {
        pbVar9 = decl_declarator_name_mark_fragment
                           (pcVar11,pbVar9,has_ctor,has_dtor,set_flags1_80,set_flags3_01);
        return pbVar9;
      }
      if (*pbVar9 == 0x96) {
        pcVar11 = (c1_symbol *)**(undefined4 **)(pbVar9 + 8);
      }
      else {
        pcVar11 = *(c1_symbol **)(pbVar9 + 8);
      }
      expr_resolve_overload_set_member(pcVar11,(c1_symbol *)0x0);
      if (has_ctor != 0) {
        pcVar11->flags1 = pcVar11->flags1 | 0x10;
      }
      if (has_dtor != 0) {
        pcVar11->flags1 = pcVar11->flags1 | 0x20;
      }
      if (set_flags1_80 != 0) {
        pcVar11->flags1 = pcVar11->flags1 | 0x80;
      }
      if (set_flags3_01 != 0) {
        pcVar11->flags3 = pcVar11->flags3 | 1;
        return pbVar9;
      }
    }
    return pbVar9;
  }
  name = (fe_name *)0x0;
  op_byte = '\x01';
  saved_name = (void *)0x0;
  do {
    cur_tok = token_next((c1_token_reader *)&g_token_position);
    scope = scope_00;
    switch(*cur_tok) {
    case '\0':
      diag_fatal_simple(4);
    default:
      diag_error(0x24d,(uint)*cur_tok);
      scope_saved = (c1_keyed_list *)0x0;
      pbVar9 = decl_qualified_name_make_token
                         (cur_tok,(c1_keyed_list *)0x0,(void *)0x0,(c1_keyed_list *)0x0,
                          leading_global,has_ctor,has_dtor,saved_name,iVar16,set_flags1_80,
                          set_flags3_01,token,p2);
      return pbVar9;
    case 'J':
      if (scope_00 == (c1_keyed_list *)0x0) {
        diag_error(0x285);
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pbVar9 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pbVar9 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (pbVar9 == (byte *)0x0) {
          pbVar9 = (byte *)0x0;
        }
        else {
          *pbVar9 = 0x4a;
          puVar17 = &g_yylval;
          puVar20 = (uint *)(pbVar9 + 8);
          for (iVar16 = 10; iVar16 != 0; iVar16 = iVar16 + -1) {
            *puVar20 = *puVar17;
            puVar17 = puVar17 + 1;
            puVar20 = puVar20 + 1;
          }
        }
        goto LAB_1045b010;
      }
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pbVar9 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pbVar9 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (pbVar9 == (byte *)0x0) goto LAB_1045b4ab;
      *pbVar9 = 0x9f;
      goto LAB_10408417;
    case 'Y':
      goto switchD_10407eb1_caseD_59;
    case 0x8c:
    case 0x8d:
      if ((char)leading_global == '\0') {
        diag_error(0x342,(uint)*cur_tok);
      }
      if ((g_compile_flags_c8 & 8) != 0) {
        diag_error(0x2d2,(uint)*cur_tok,(uint)*cur_tok);
      }
      g_yylval = CONCAT31(g_yylval._1_3_,2);
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pbVar9 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pbVar9 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (pbVar9 == (byte *)0x0) {
        return (byte *)0x0;
      }
      *pbVar9 = *cur_tok;
      puVar17 = &g_yylval;
      puVar20 = (uint *)(pbVar9 + 8);
      for (iVar16 = 10; iVar16 != 0; iVar16 = iVar16 + -1) {
        *puVar20 = *puVar17;
        puVar17 = puVar17 + 1;
        puVar20 = puVar20 + 1;
      }
      return pbVar9;
    case 0x97:
      cur_tok = lex_operator_function_id();
      cVar2 = g_token_class[*cur_tok];
      if (cVar2 == '\x01') goto LAB_10408131;
      if (cVar2 == 0x8e) {
        name = *(void **)(cur_tok + 0xc);
        op_byte = cur_tok[8];
        goto LAB_104080cf;
      }
      if (cVar2 == 0x8f) {
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        pbVar9 = decl_qualified_name_make_token
                           (cur_tok,scope_00,(void *)0x0,scope_saved,leading_global,has_ctor,
                            has_dtor,saved_name,iVar16,set_flags1_80,set_flags3_01,token,p2);
        return pbVar9;
      }
    case '\x06':
    case 0xe4:
      if (*cur_tok == 6) {
        name = *(void **)(cur_tok + 8);
        if (((((fe_name *)name)->flags & 0x4000000) == 0) ||
           (pcVar12 = lex_peek_token((uint *)&g_token_position), *pcVar12 != 'D')) {
          if (((((fe_name *)name)->flags & 0x8000000) != 0) &&
             (pcVar12 = lex_peek_token((uint *)&g_token_position), *pcVar12 == 'D')) {
            if (scope_00 == (c1_keyed_list *)0x0) {
              pcVar11 = (c1_symbol *)0x0;
            }
            else {
              pcVar11 = scope_00->head->sym;
            }
            tmpl_resolve_function_template_name_token(&cur_tok,pcVar11);
          }
        }
        else {
          if (scope_00 == (c1_keyed_list *)0x0) {
            pcVar11 = (c1_symbol *)0x0;
          }
          else {
            pcVar11 = scope_00->head->sym;
          }
          tmpl_resolve_template_name_token(&cur_tok,pcVar11,(char)leading_global);
        }
      }
      if (*cur_tok == 0xe4) {
        tmpl_rec_00 = *(int **)(cur_tok + 8);
        name = (void *)*tmpl_rec_00;
        if (tmpl_rec_00[1] == 1) {
          pbVar9 = decl_qualified_name_scan_part_1
                             (tmpl_rec_00,name,scope_00,'\x01',first_lookup_hit,cur_tok,scope_saved,
                              leading_global,nerrors,has_ctor,has_dtor,saved_name,template_tok,
                              set_flags1_80,set_flags3_01,saved_access_op,saved_reported,
                              saved_access_op_2,saved_reported_2,token,p2);
          return pbVar9;
        }
      }
      goto LAB_104080cf;
    case 0xab:
      template_tok = token_next((c1_token_reader *)&g_token_position);
      if (*template_tok == 6) {
        uVar15 = *(uint *)(template_tok + 8);
        if (((*(uint *)(uVar15 + 8) & 0x4000000) == 0) ||
           (pcVar12 = lex_peek_token((uint *)&g_token_position), *pcVar12 != 'D')) {
          if (((*(uint *)(uVar15 + 8) & 0x8000000) == 0) ||
             (pcVar12 = lex_peek_token((uint *)&g_token_position), *pcVar12 != 'D')) {
            n = 0x387;
            goto LAB_1045aa0a;
          }
          if (scope_00 == (c1_keyed_list *)0x0) {
            pcVar11 = (c1_symbol *)0x0;
          }
          else {
            pcVar11 = scope_00->head->sym;
          }
          tmpl_resolve_function_template_name_token(&template_tok,pcVar11);
        }
        else {
          if (scope_00 == (c1_keyed_list *)0x0) {
            pcVar11 = (c1_symbol *)0x0;
          }
          else {
            pcVar11 = scope_00->head->sym;
          }
          tmpl_resolve_template_name_token(&template_tok,pcVar11,(char)leading_global);
        }
      }
      else {
        uVar15 = (uint)*template_tok;
        n = 0x386;
LAB_1045aa0a:
        diag_error(n,uVar15);
      }
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)template_tok);
    }
  } while( true );
switchD_10407eb1_caseD_59:
  cur_tok = token_next((c1_token_reader *)&g_token_position);
  if (*cur_tok != 6) {
    diag_error(0x263,(uint)*cur_tok);
    return cur_tok;
  }
  name = *(void **)(cur_tok + 8);
  uVar15 = ((fe_name *)name)->flags & 0x4000000;
  if (((uVar15 != 0) || ((((fe_name *)name)->flags & 0x20000) != 0)) &&
     ((uVar15 != 0 || (pcVar12 = lex_peek_token((uint *)&g_token_position), *pcVar12 == 'D')))) {
    if (scope_00 == (c1_keyed_list *)0x0) {
      pcVar11 = (c1_symbol *)0x0;
    }
    else {
      pcVar11 = scope_00->head->sym;
    }
    tmpl_resolve_template_name_token(&cur_tok,pcVar11,(char)leading_global);
    if (*cur_tok == 0xe4) {
      name = (void *)**(undefined4 **)(cur_tok + 8);
    }
    else {
      name = *(void **)(cur_tok + 8);
    }
  }
  if (scope_00 == (c1_keyed_list *)0x0) {
    if (nerrors == 0) {
      diag_error(0x24c,name);
      nerrors = 1;
    }
    goto LAB_10408131;
  }
  if (((scope_00->head != (c1_keyed_cell *)0x0) &&
      (pcVar11 = scope_00->head->sym, (pcVar11->kind & 0x1f) == 4)) &&
     (bVar1 = ((pcVar11->detail).cls)->flags3e, (bVar1 & 1) != 0)) {
    if (((g_compile_flags_cc & 0x200000) != 0) && ((bVar1 & 2) != 0)) {
      pbVar9 = decl_qualified_name_destructor_cold
                         (pcVar11,name,scope_00,'\x01',first_lookup_hit,cur_tok,scope_saved,
                          leading_global,nerrors,has_ctor,has_dtor,template_tok,iVar16,set_flags1_80
                          ,set_flags3_01,saved_access_op,saved_reported,saved_access_op_2,
                          saved_reported_2,token,p2);
      return pbVar9;
    }
    pvVar7 = tmpl_template_of_instance(pcVar11);
    if (*(fe_name **)((int)pvVar7 + 8) == name) {
      name = pcVar11->name;
      g_yylval = (uint)name;
      if (g_token_arena_index == 0) {
        pcVar18 = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        pcVar18 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (pcVar18 == (c1_u8 *)0x0) {
        cur_tok = (c1_u8 *)0x0;
      }
      else {
        *pcVar18 = *cur_tok;
        puVar17 = &g_yylval;
        puVar20 = (uint *)(pcVar18 + 8);
        for (iVar14 = 10; cur_tok = pcVar18, iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar20 = *puVar17;
          puVar17 = puVar17 + 1;
          puVar20 = puVar20 + 1;
        }
      }
    }
  }
  pcVar11 = scope_00->head->sym;
  if ((pcVar11->kind & 0x1f) == 0x19) {
    diag_error(0x24c,name);
    return (byte *)0x0;
  }
  if (name == pcVar11->name) goto LAB_10407fd1;
  first_lookup_hit = '\x01';
  pcVar18 = expr_build_member_access_implicit(g_current_scope,name);
  pcVar4 = g_current_scope;
  if (pcVar18 == (c1_u8 *)0x0) {
    pbVar9 = (byte *)0x0;
  }
  else {
    pbVar9 = *(byte **)pcVar18;
  }
  if (pbVar9 == (byte *)0x0) {
    first_lookup_hit = '\0';
    saved_reported = g_current_scope->reported;
    pcVar11 = g_current_scope->qual_class;
    saved_access_op = g_current_scope->access_op;
    cVar2 = g_current_scope->qualified;
    g_current_scope->reported = '\0';
    pcVar4->qual_class = (c1_symbol *)0x0;
    pcVar4->access_op = '\x01';
    pcVar4->qualified = '\0';
    pcVar18 = expr_build_member_access_implicit(g_current_scope,name);
    if (pcVar18 == (c1_u8 *)0x0) {
      pbVar9 = (byte *)0x0;
    }
    else {
      pbVar9 = *(byte **)pcVar18;
    }
    if (cVar2 == '\0') {
      g_current_scope->qual_class = (c1_symbol *)0x0;
      g_current_scope->access_op = '\x01';
      g_current_scope->qualified = '\0';
      g_current_scope->reported = '\0';
    }
    else {
      g_current_scope->qual_class = pcVar11;
      g_current_scope->access_op = saved_access_op;
      g_current_scope->qualified = '\x01';
      g_current_scope->reported = saved_reported;
    }
    if (pbVar9 != (byte *)0x0) goto LAB_1045abd0;
  }
  else {
LAB_1045abd0:
    if ((*pbVar9 & 0x1f) == 0x12) {
      pbVar9 = *(byte **)(**(int **)(pbVar9 + 0x14) + 8);
    }
    if (((pbVar9[0x20] & 7) == 7) && ((**(ushort **)(pbVar9 + 0x14) & 0x300) != 0)) {
      if (*(int *)(pcVar18 + 4) == 0) {
        bVar21 = false;
      }
      else {
        bVar21 = *(char *)(*(int *)(pcVar18 + 4) + 8) == -6;
      }
      pcVar11 = scope_saved->head->sym;
      if (*(c1_symbol **)(*(ushort **)(pbVar9 + 0x14) + 4) == pcVar11) {
        if (!bVar21) {
          diag_warning(4,0x61,0x49,name,0x53,pcVar11);
        }
        pcVar4 = g_current_scope;
        saved_reported_2 = g_current_scope->reported;
        saved_access_op_2 = g_current_scope->access_op;
        pcVar11 = g_current_scope->qual_class;
        cVar2 = g_current_scope->qualified;
        if (first_lookup_hit == '\0') {
          g_current_scope->reported = '\0';
          pcVar4->qual_class = (c1_symbol *)0x0;
          pcVar4->access_op = '\x01';
          pcVar4->qualified = '\0';
        }
        lookup_name_in_context(g_current_scope,name,0x132);
        scope = scope_saved;
        if (cVar2 == '\0') {
          g_current_scope->qual_class = (c1_symbol *)0x0;
          g_current_scope->access_op = '\x01';
          g_current_scope->qualified = '\0';
          g_current_scope->reported = '\0';
        }
        else {
          g_current_scope->qual_class = pcVar11;
          g_current_scope->access_op = saved_access_op_2;
          g_current_scope->qualified = '\x01';
          g_current_scope->reported = saved_reported_2;
        }
        goto LAB_10407fd1;
      }
    }
  }
  diag_error(0x20b,scope_saved->head->sym,name);
  scope = scope_saved;
LAB_10407fd1:
  if (has_dtor != 0) {
    diag_error(0x254,name);
  }
  if (has_ctor != 0) {
    diag_error(0x253,name);
  }
  has_dtor = 1;
  name_00 = g_name_dtor;
  saved_name = name;
LAB_1040810f:
  scope_00 = lookup_qualified_name(scope,name_00,(c1_type *)0x0,(char)p2);
  pcVar18 = g_arenas[5].cur;
  name = name_00;
  scope_saved = scope_00;
  if (scope_00 == (c1_keyed_list *)0x0) {
    if (g_class_depth < 0) {
      has_dtor = 0;
      has_ctor = 0;
    }
    else {
      if (has_dtor != 0) {
        g_arenas[5].cur = g_arenas[5].cur + 0x58;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar18 == (c1_u8 *)0x0) {
          pcVar18 = (c1_u8 *)0x0;
        }
        else {
          *(void **)pcVar18 = saved_name;
          pcVar18[0x28] = '\0';
          pcVar18[0x29] = '\0';
          pcVar18[0x2a] = '\0';
          pcVar18[0x2b] = '\0';
          pcVar18[0x30] = '\x01';
          pcVar18[0x4c] = '\0';
          pcVar18[0x4d] = '\0';
          pcVar18[0x4e] = '\0';
          pcVar18[0x4f] = '\0';
          pcVar13 = arena_alloc(g_arenas + 5,0x4c);
          if (pcVar13 == (c1_decl_record *)0x0) {
            pcVar18[4] = '\0';
            pcVar18[5] = '\0';
            pcVar18[6] = '\0';
            pcVar18[7] = '\0';
            *(int *)(pcVar18 + 0x24) = g_token_position;
          }
          else {
            pcVar13 = decl_record_init_default
                                (pcVar13,*(void **)pcVar18,*(c1_overload_set **)(pcVar18 + 0x28));
            *(c1_decl_record **)(pcVar18 + 4) = pcVar13;
            *(int *)(pcVar18 + 0x24) = g_token_position;
          }
        }
        pcVar18[0x55] = pcVar18[0x55] | 0x80;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pbVar9 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pbVar9 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (pbVar9 == (byte *)0x0) {
          return (byte *)0x0;
        }
        *(c1_u8 **)(pbVar9 + 8) = pcVar18;
        *pbVar9 = 0xa7;
        return pbVar9;
      }
      if (has_ctor != 0) {
        g_arenas[5].cur = g_arenas[5].cur + 0x58;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar18 == (c1_u8 *)0x0) {
          pcVar18 = (c1_u8 *)0x0;
        }
        else {
          *(void **)pcVar18 = saved_name;
          pcVar18[0x28] = '\0';
          pcVar18[0x29] = '\0';
          pcVar18[0x2a] = '\0';
          pcVar18[0x2b] = '\0';
          pcVar18[0x30] = '\x01';
          pcVar18[0x4c] = '\0';
          pcVar18[0x4d] = '\0';
          pcVar18[0x4e] = '\0';
          pcVar18[0x4f] = '\0';
          pcVar13 = arena_alloc(g_arenas + 5,0x4c);
          if (pcVar13 == (c1_decl_record *)0x0) {
            pcVar18[4] = '\0';
            pcVar18[5] = '\0';
            pcVar18[6] = '\0';
            pcVar18[7] = '\0';
            *(int *)(pcVar18 + 0x24) = g_token_position;
          }
          else {
            pcVar13 = decl_record_init_default
                                (pcVar13,*(void **)pcVar18,*(c1_overload_set **)(pcVar18 + 0x28));
            *(c1_decl_record **)(pcVar18 + 4) = pcVar13;
            *(int *)(pcVar18 + 0x24) = g_token_position;
          }
        }
        pcVar18[0x55] = pcVar18[0x55] | 0x40;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pbVar9 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pcVar5 = g_arenas + g_token_arena_index;
          pbVar9 = pcVar5->cur;
          pbVar19 = g_arenas[g_token_arena_index].end;
          pcVar5->cur = pbVar9 + 0x30;
          if (pbVar19 < pbVar9 + 0x30) {
            arena_grow(pcVar5);
          }
        }
        if (pbVar9 == (byte *)0x0) {
          return (byte *)0x0;
        }
        *(c1_u8 **)(pbVar9 + 8) = pcVar18;
        *pbVar9 = 0xa7;
        return pbVar9;
      }
    }
    pcVar11 = scope->head->sym;
    if (((pcVar11->flags2 & 4) == 0) &&
       (pfVar3 = pcVar11->name, pfVar8 = class_current_definition_name(), pfVar3 == pfVar8)) {
      if (op_byte != '\x01') {
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pbVar9 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pcVar5 = g_arenas + g_token_arena_index;
          pbVar9 = pcVar5->cur;
          pbVar19 = g_arenas[g_token_arena_index].end;
          pcVar5->cur = pbVar9 + 0x30;
          if (pbVar19 < pbVar9 + 0x30) {
            arena_grow(pcVar5);
          }
        }
        if (pbVar9 == (byte *)0x0) {
          return (byte *)0x0;
        }
        *(fe_name **)(pbVar9 + 0xc) = name_00;
        *pbVar9 = 0x8e;
        pbVar9[8] = op_byte;
        return pbVar9;
      }
      if (*cur_tok == '\x06') {
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pbVar9 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pcVar5 = g_arenas + g_token_arena_index;
          pbVar9 = pcVar5->cur;
          pbVar19 = g_arenas[g_token_arena_index].end;
          pcVar5->cur = pbVar9 + 0x30;
          if (pbVar19 < pbVar9 + 0x30) {
            arena_grow(pcVar5);
          }
        }
        if (pbVar9 == (byte *)0x0) {
          return (byte *)0x0;
        }
        *pbVar9 = 6;
        *(fe_name **)(pbVar9 + 8) = name_00;
        *(int *)(pbVar9 + 0xc) = g_token_position;
        return pbVar9;
      }
    }
    nerrors = nerrors + 1;
  }
  goto LAB_10408131;
}

