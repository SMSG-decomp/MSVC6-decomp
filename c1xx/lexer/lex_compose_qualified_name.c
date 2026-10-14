byte * __cdecl lex_compose_qualified_name(char *token,int p2)

{
  byte bVar1;
  c1_u8 cVar2;
  c1xx_scope *pcVar3;
  c1_sym_list *pcVar4;
  int *tmpl_rec;
  c1_scope_stack *pcVar5;
  byte *pbVar6;
  c1_lookup_entry *pcVar7;
  c1_type *pcVar8;
  c1_arena *pcVar9;
  c1_overload_set *pcVar10;
  void *pvVar11;
  void *pvVar12;
  c1_u8 *pcVar13;
  byte *pbVar14;
  char *pcVar15;
  c1_lookup_result *result;
  c1_decl_record *pcVar16;
  uint uVar17;
  int iVar18;
  c1_keyed_list *scope;
  fe_name *pfVar19;
  fe_name *name;
  c1_symbol *pcVar20;
  uint *puVar21;
  uint *puVar22;
  bool bVar23;
  short n;
  byte bVar24;
  char first_lookup_hit;
  int leading_global;
  int iVar25;
  int has_ctor;
  int has_dtor;
  fe_name *saved_name;
  byte *template_tok;
  int pair_second;
  int set_flags1_80;
  int set_flags3_01;
  c1_u8 saved_access_op;
  c1_u8 saved_reported;
  c1_u8 saved_access_op_2;
  c1_u8 saved_reported_2;
  c1_keyed_list *scope_saved;
  
  pbVar6 = token_next((c1_token_reader *)&g_token_position);
  scope = (c1_keyed_list *)0x0;
  if (token != (char *)0x0) {
    uVar17 = *(uint *)(*(int *)(token + 8) + 8);
    if (((uVar17 & 0x4000000) == 0) && (((uVar17 & 0x20000) == 0 || (*pbVar6 != 0x44)))) {
      if (((uVar17 & 0x8000000) != 0) && (*pbVar6 == 0x44)) {
        pbVar6 = decl_qualified_name_scan_part_2
                           (pbVar6,(c1_keyed_list *)0x0,first_lookup_hit,leading_global,template_tok
                            ,saved_access_op,saved_reported,saved_access_op_2,saved_reported_2,token
                            ,p2);
        return pbVar6;
      }
    }
    else {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar6);
      tmpl_resolve_template_name_token((c1_u8 **)&token,(c1_symbol *)0x0,'\0');
      pbVar6 = token_next((c1_token_reader *)&g_token_position);
    }
  }
  if (*pbVar6 != 0x95) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar6);
    return (byte *)token;
  }
  iVar25 = 0;
  scope_saved = (c1_keyed_list *)0x0;
  set_flags1_80 = 0;
  set_flags3_01 = 0;
  if (token == (char *)0x0) {
    leading_global = CONCAT31(leading_global._1_3_,1);
    tree_list_arena_set(4);
    scope = tree_new_list_cell((c1_keyed_list *)0x0,0,g_current_scope->global_ns);
    scope_saved = scope;
    tree_list_arena_restore();
    goto LAB_10407e72;
  }
  leading_global = (uint)leading_global._1_3_ << 8;
  if (*token == -0x1c) {
    pfVar19 = (fe_name *)**(undefined4 **)(token + 8);
  }
  else {
    pfVar19 = *(fe_name **)(token + 8);
  }
  g_compile_flags_c4 = g_compile_flags_c4 | 0x10;
  pcVar7 = (c1_lookup_entry *)lookup_name_mask_121(g_current_scope,pfVar19);
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffffffef;
  if (pcVar7 == (c1_lookup_entry *)0x0) {
    pcVar7 = (c1_lookup_entry *)expr_build_member_access_implicit(g_current_scope,pfVar19);
    if (pcVar7 == (c1_lookup_entry *)0x0) {
      pcVar20 = (c1_symbol *)0x0;
    }
    else {
      pcVar20 = pcVar7->sym;
    }
    if ((pcVar20 != (c1_symbol *)0x0) && (bVar24 = pcVar20->kind & 0x1f, bVar24 != 0x16)) {
      if (bVar24 == 0x12) {
        pcVar20 = *(c1_symbol **)(*(int *)pcVar20->type + 8);
      }
      pcVar8 = pcVar20->type;
      if ((pcVar8->code & 0x800) != 0) goto LAB_10407e0f;
      if (((pcVar20->storage & 7) == 7) && ((pcVar8->code & 0x300) != 0)) {
        if ((pcVar7->scope == (c1xx_scope *)0x0) || (pcVar7->scope->kind != 0xfa)) {
          bVar23 = false;
        }
        else {
          bVar23 = true;
        }
        scope = scope_saved;
        pcVar13 = expr_build_arrow_member_implicit(g_current_scope,((pcVar8->extra).cls)->name);
        if (pcVar13 == (c1_u8 *)0x0) {
          pbVar14 = (byte *)0x0;
        }
        else {
          pbVar14 = *(byte **)pcVar13;
        }
        scope_saved = scope;
        if ((pbVar14 != (byte *)0x0) && ((*pbVar14 & 0x1f) == 0x12)) {
          if (!bVar23) {
            diag_warning(4,0x61,0x53,pcVar20,0x53,pbVar14);
          }
          pcVar7 = lookup_name_in_context(g_current_scope,pfVar19,0x132);
          if (pcVar7 == (c1_lookup_entry *)0x0) {
            pcVar20 = (c1_symbol *)0x0;
          }
          else {
            pcVar20 = pcVar7->sym;
          }
          if ((pcVar20->kind & 0x1f) == 0x12) {
            pcVar20 = *(c1_symbol **)(*(int *)pcVar20->type + 8);
          }
          pcVar7 = (c1_lookup_entry *)
                   lookup_name_mask_121(g_current_scope,((pcVar20->type->extra).cls)->name);
          scope_saved = scope;
          if (pcVar7 == (c1_lookup_entry *)0x0) {
            pcVar20 = (c1_symbol *)0x0;
          }
          else {
            pcVar20 = pcVar7->sym;
          }
          goto LAB_10407e11;
        }
      }
    }
LAB_1045a8a3:
    pcVar7 = lookup_name_in_context(g_current_scope,pfVar19,0x132);
    if (pcVar7 == (c1_lookup_entry *)0x0) {
      pcVar20 = (c1_symbol *)0x0;
    }
    else {
      pcVar20 = pcVar7->sym;
    }
    if (pcVar20 != (c1_symbol *)0x0) {
      bVar24 = pcVar20->kind & 0x1f;
      if (bVar24 != 0x16) {
        if (bVar24 == 0x12) {
          pcVar20 = *(c1_symbol **)(*(int *)pcVar20->type + 8);
        }
        if ((pcVar20->flags2 & 0x10) == 0) goto LAB_1045a8f3;
        if ((pcVar20->type->code & 0x200) == 0) {
          pcVar15 = lex_peek_token((uint *)&g_token_position);
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar6);
          if (*pcVar15 != 'Y') {
            return (byte *)token;
          }
          g_compile_flags_c4 = g_compile_flags_c4 | 0x40;
          pbVar6 = token_new_decl_specifiers((int)pcVar20->type,0,(byte *)0x0,0);
          return pbVar6;
        }
        pcVar20 = (pcVar20->type->extra).cls;
      }
      if (pcVar20 != (c1_symbol *)0x0) goto LAB_10407e19;
    }
LAB_1045a8f3:
    diag_error(0x28d,0x49,pfVar19);
    iVar25 = 1;
  }
  else {
LAB_10407e0f:
    pcVar20 = pcVar7->sym;
LAB_10407e11:
    if (pcVar20 == (c1_symbol *)0x0) goto LAB_1045a8a3;
LAB_10407e19:
    if ((pcVar20->kind & 0x1f) == 0x12) {
      scope = (c1_keyed_list *)pcVar20->type;
      scope_saved = scope;
    }
    else {
      tree_list_arena_set(4);
      scope = tree_new_list_cell((c1_keyed_list *)0x0,0,pcVar20);
      scope_saved = scope;
      tree_list_arena_restore();
    }
    if (g_current_scope->qualified == '\0') {
      pcVar3 = pcVar7->scope;
      pcVar4 = *(c1_sym_list **)(*(int *)scope + 8);
      if (((pcVar3->kind == 0xff) && (*(char *)&pcVar3[1].outer != '\0')) &&
         (((pcVar4->arena & 0x100000) == 0 ||
          ((((uint)(pcVar4[1].tail)->name & 0x200) != 0 && (pcVar4 == (pcVar3->body).symbols)))))) {
        set_flags1_80 = 1;
      }
      else if (pcVar3->kind == 0xfc) {
        set_flags3_01 = 1;
      }
    }
  }
LAB_10407e72:
  has_ctor = 0;
  has_dtor = 0;
  pair_second = 0;
LAB_10407e80:
  pfVar19 = (fe_name *)0x0;
  bVar24 = 1;
  saved_name = (fe_name *)0x0;
  do {
    pbVar6 = token_next((c1_token_reader *)&g_token_position);
    pcVar8 = (c1_type *)scope;
    switch(*pbVar6) {
    case 0:
      diag_fatal_simple(4);
    default:
      diag_error(0x24d,(uint)*pbVar6);
      pbVar6 = decl_qualified_name_make_token
                         (pbVar6,(c1_keyed_list *)0x0,(void *)0x0,(c1_keyed_list *)0x0,
                          leading_global,has_ctor,has_dtor,saved_name,pair_second,set_flags1_80,
                          set_flags3_01,token,p2);
      return pbVar6;
    case 6:
    case 0xe4:
      goto switchD_10407eb1_caseD_6;
    case 0x4a:
      if ((c1_type *)scope == (c1_type *)0x0) {
        diag_error(0x285);
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pbVar6 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pbVar6 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (pbVar6 == (byte *)0x0) {
          pbVar6 = (byte *)0x0;
        }
        else {
          *pbVar6 = 0x4a;
          puVar21 = &g_yylval;
          puVar22 = (uint *)(pbVar6 + 8);
          for (iVar25 = 10; iVar25 != 0; iVar25 = iVar25 + -1) {
            *puVar22 = *puVar21;
            puVar21 = puVar21 + 1;
            puVar22 = puVar22 + 1;
          }
        }
        goto LAB_1045b010;
      }
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pbVar6 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pbVar6 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (pbVar6 == (byte *)0x0) goto LAB_1045b4ab;
      *pbVar6 = 0x9f;
      goto LAB_10408417;
    case 0x59:
      pbVar6 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar6 != 6) {
        diag_error(0x263,(uint)*pbVar6);
        return pbVar6;
      }
      pfVar19 = *(fe_name **)(pbVar6 + 8);
      uVar17 = pfVar19->flags & 0x4000000;
      if (((uVar17 != 0) || ((pfVar19->flags & 0x20000) != 0)) &&
         ((uVar17 != 0 || (pcVar15 = lex_peek_token((uint *)&g_token_position), *pcVar15 == 'D'))))
      {
        if ((c1_type *)scope == (c1_type *)0x0) {
          pcVar20 = (c1_symbol *)0x0;
        }
        else {
          pcVar20 = *(c1_symbol **)(*(int *)scope + 8);
        }
        tmpl_resolve_template_name_token((c1_u8 **)&stack0xffffffc4,pcVar20,(char)leading_global);
        if (*pbVar6 == 0xe4) {
          pfVar19 = (fe_name *)**(undefined4 **)(pbVar6 + 8);
        }
        else {
          pfVar19 = *(fe_name **)(pbVar6 + 8);
        }
      }
      if ((c1_type *)scope != (c1_type *)0x0) {
        if (((*(int *)scope != 0) &&
            (pcVar20 = *(c1_symbol **)(*(int *)scope + 8), (pcVar20->kind & 0x1f) == 4)) &&
           (bVar1 = ((pcVar20->detail).cls)->flags3e, (bVar1 & 1) != 0)) {
          if (((g_compile_flags_cc & 0x200000) != 0) && ((bVar1 & 2) != 0)) {
            pbVar6 = decl_qualified_name_destructor_cold
                               (pcVar20,pfVar19,scope,bVar24,first_lookup_hit,pbVar6,scope_saved,
                                leading_global,iVar25,has_ctor,has_dtor,template_tok,pair_second,
                                set_flags1_80,set_flags3_01,saved_access_op,saved_reported,
                                saved_access_op_2,saved_reported_2,token,p2);
            return pbVar6;
          }
          pvVar11 = tmpl_template_of_instance(pcVar20);
          if (*(fe_name **)((int)pvVar11 + 8) == pfVar19) {
            pfVar19 = pcVar20->name;
            g_yylval = (uint)pfVar19;
            if (g_token_arena_index == 0) {
              pbVar14 = pool_alloc_raw(&g_pool_default,0x30);
            }
            else {
              pbVar14 = arena_alloc(g_arenas + g_token_arena_index,0x30);
            }
            if (pbVar14 == (byte *)0x0) {
              pbVar6 = (byte *)0x0;
            }
            else {
              *pbVar14 = *pbVar6;
              puVar21 = &g_yylval;
              puVar22 = (uint *)(pbVar14 + 8);
              for (iVar18 = 10; pbVar6 = pbVar14, iVar18 != 0; iVar18 = iVar18 + -1) {
                *puVar22 = *puVar21;
                puVar21 = puVar21 + 1;
                puVar22 = puVar22 + 1;
              }
            }
          }
        }
        if ((**(byte **)(*(int *)scope + 8) & 0x1f) == 0x19) {
          diag_error(0x24c,pfVar19);
          return (byte *)0x0;
        }
        if (pfVar19 != *(fe_name **)(*(byte **)(*(int *)scope + 8) + 8)) {
          first_lookup_hit = '\x01';
          pcVar13 = expr_build_member_access_implicit(g_current_scope,pfVar19);
          pcVar5 = g_current_scope;
          if (pcVar13 == (c1_u8 *)0x0) {
            pbVar14 = (byte *)0x0;
          }
          else {
            pbVar14 = *(byte **)pcVar13;
          }
          scope = scope_saved;
          if (pbVar14 == (byte *)0x0) {
            first_lookup_hit = '\0';
            saved_reported = g_current_scope->reported;
            pcVar20 = g_current_scope->qual_class;
            saved_access_op = g_current_scope->access_op;
            cVar2 = g_current_scope->qualified;
            g_current_scope->reported = '\0';
            pcVar5->qual_class = (c1_symbol *)0x0;
            pcVar5->access_op = '\x01';
            pcVar5->qualified = '\0';
            pcVar13 = expr_build_member_access_implicit(g_current_scope,pfVar19);
            if (pcVar13 == (c1_u8 *)0x0) {
              pbVar14 = (byte *)0x0;
            }
            else {
              pbVar14 = *(byte **)pcVar13;
            }
            if (cVar2 == '\0') {
              g_current_scope->qual_class = (c1_symbol *)0x0;
              g_current_scope->access_op = '\x01';
              g_current_scope->qualified = '\0';
              g_current_scope->reported = '\0';
            }
            else {
              g_current_scope->qual_class = pcVar20;
              g_current_scope->access_op = saved_access_op;
              g_current_scope->qualified = '\x01';
              g_current_scope->reported = saved_reported;
            }
            scope = scope_saved;
            if (pbVar14 != (byte *)0x0) goto LAB_1045abd0;
          }
          else {
LAB_1045abd0:
            if ((*pbVar14 & 0x1f) == 0x12) {
              pbVar14 = *(byte **)(**(int **)(pbVar14 + 0x14) + 8);
            }
            if (((pbVar14[0x20] & 7) == 7) && ((**(ushort **)(pbVar14 + 0x14) & 0x300) != 0)) {
              if (*(int *)(pcVar13 + 4) == 0) {
                bVar23 = false;
              }
              else {
                bVar23 = *(char *)(*(int *)(pcVar13 + 4) + 8) == -6;
              }
              if (*(int *)(*(ushort **)(pbVar14 + 0x14) + 4) == *(int *)(*(int *)scope + 8)) {
                if (!bVar23) {
                  diag_warning(4,0x61,0x49,pfVar19,0x53,*(int *)(*(int *)scope + 8));
                }
                pcVar5 = g_current_scope;
                saved_reported_2 = g_current_scope->reported;
                saved_access_op_2 = g_current_scope->access_op;
                pcVar20 = g_current_scope->qual_class;
                cVar2 = g_current_scope->qualified;
                if (first_lookup_hit == '\0') {
                  g_current_scope->reported = '\0';
                  pcVar5->qual_class = (c1_symbol *)0x0;
                  pcVar5->access_op = '\x01';
                  pcVar5->qualified = '\0';
                }
                lookup_name_in_context(g_current_scope,pfVar19,0x132);
                if (cVar2 == '\0') {
                  g_current_scope->qual_class = (c1_symbol *)0x0;
                  g_current_scope->access_op = '\x01';
                  g_current_scope->qualified = '\0';
                  g_current_scope->reported = '\0';
                }
                else {
                  g_current_scope->qual_class = pcVar20;
                  g_current_scope->access_op = saved_access_op_2;
                  g_current_scope->qualified = '\x01';
                  g_current_scope->reported = saved_reported_2;
                }
                goto LAB_10407fd1;
              }
            }
          }
          diag_error(0x20b,*(undefined4 *)(*(int *)scope + 8),pfVar19);
        }
LAB_10407fd1:
        if (has_dtor != 0) {
          diag_error(0x254,pfVar19);
        }
        if (has_ctor != 0) {
          diag_error(0x253,pfVar19);
        }
        has_dtor = 1;
        name = g_name_dtor;
        saved_name = pfVar19;
        goto LAB_1040810f;
      }
      if (iVar25 == 0) {
        diag_error(0x24c,pfVar19);
        iVar25 = 1;
      }
      goto LAB_10408131;
    case 0x8c:
    case 0x8d:
      if ((char)leading_global == '\0') {
        diag_error(0x342,(uint)*pbVar6);
      }
      if ((g_compile_flags_c8 & 8) != 0) {
        diag_error(0x2d2,(uint)*pbVar6,(uint)*pbVar6);
      }
      g_yylval = CONCAT31(g_yylval._1_3_,2);
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pbVar14 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pbVar14 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (pbVar14 == (byte *)0x0) {
        return (byte *)0x0;
      }
      *pbVar14 = *pbVar6;
      puVar21 = &g_yylval;
      puVar22 = (uint *)(pbVar14 + 8);
      for (iVar25 = 10; iVar25 != 0; iVar25 = iVar25 + -1) {
        *puVar22 = *puVar21;
        puVar21 = puVar21 + 1;
        puVar22 = puVar22 + 1;
      }
      return pbVar14;
    case 0x97:
      pbVar6 = lex_operator_function_id();
      cVar2 = g_token_class[*pbVar6];
      if (cVar2 == '\x01') goto LAB_10408131;
      if (cVar2 == 0x8e) {
        pfVar19 = *(fe_name **)(pbVar6 + 0xc);
        bVar24 = pbVar6[8];
        goto LAB_104080cf;
      }
      if (cVar2 == 0x8f) {
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        pbVar6 = decl_qualified_name_make_token
                           (pbVar6,scope,(void *)0x0,scope_saved,leading_global,has_ctor,has_dtor,
                            saved_name,pair_second,set_flags1_80,set_flags3_01,token,p2);
        return pbVar6;
      }
      goto switchD_10407eb1_caseD_6;
    case 0xab:
      template_tok = token_next((c1_token_reader *)&g_token_position);
      if (*template_tok == 6) {
        uVar17 = *(uint *)(template_tok + 8);
        if (((*(uint *)(uVar17 + 8) & 0x4000000) == 0) ||
           (pcVar15 = lex_peek_token((uint *)&g_token_position), *pcVar15 != 'D')) {
          if (((*(uint *)(uVar17 + 8) & 0x8000000) == 0) ||
             (pcVar15 = lex_peek_token((uint *)&g_token_position), *pcVar15 != 'D')) {
            n = 0x387;
            goto LAB_1045aa0a;
          }
          if ((c1_type *)scope == (c1_type *)0x0) {
            pcVar20 = (c1_symbol *)0x0;
          }
          else {
            pcVar20 = *(c1_symbol **)(*(int *)scope + 8);
          }
          tmpl_resolve_function_template_name_token(&template_tok,pcVar20);
        }
        else {
          if ((c1_type *)scope == (c1_type *)0x0) {
            pcVar20 = (c1_symbol *)0x0;
          }
          else {
            pcVar20 = *(c1_symbol **)(*(int *)scope + 8);
          }
          tmpl_resolve_template_name_token(&template_tok,pcVar20,(char)leading_global);
        }
      }
      else {
        uVar17 = (uint)*template_tok;
        n = 0x386;
LAB_1045aa0a:
        diag_error(n,uVar17);
      }
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)template_tok);
    }
  } while( true );
switchD_10407eb1_caseD_6:
  if (*pbVar6 == 6) {
    pfVar19 = *(fe_name **)(pbVar6 + 8);
    if (((pfVar19->flags & 0x4000000) == 0) ||
       (pcVar15 = lex_peek_token((uint *)&g_token_position), *pcVar15 != 'D')) {
      if (((pfVar19->flags & 0x8000000) != 0) &&
         (pcVar15 = lex_peek_token((uint *)&g_token_position), *pcVar15 == 'D')) {
        if ((c1_type *)scope == (c1_type *)0x0) {
          pcVar20 = (c1_symbol *)0x0;
        }
        else {
          pcVar20 = *(c1_symbol **)(*(int *)scope + 8);
        }
        tmpl_resolve_function_template_name_token((c1_u8 **)&stack0xffffffc4,pcVar20);
      }
    }
    else {
      if ((c1_type *)scope == (c1_type *)0x0) {
        pcVar20 = (c1_symbol *)0x0;
      }
      else {
        pcVar20 = *(c1_symbol **)(*(int *)scope + 8);
      }
      tmpl_resolve_template_name_token((c1_u8 **)&stack0xffffffc4,pcVar20,(char)leading_global);
    }
  }
  if (*pbVar6 == 0xe4) {
    tmpl_rec = *(int **)(pbVar6 + 8);
    pfVar19 = (fe_name *)*tmpl_rec;
    if (tmpl_rec[1] == 1) {
      pbVar6 = decl_qualified_name_scan_part_1
                         (tmpl_rec,pfVar19,scope,bVar24,first_lookup_hit,pbVar6,scope_saved,
                          leading_global,iVar25,has_ctor,has_dtor,saved_name,template_tok,
                          set_flags1_80,set_flags3_01,saved_access_op,saved_reported,
                          saved_access_op_2,saved_reported_2,token,p2);
      return pbVar6;
    }
  }
LAB_104080cf:
  if ((c1_type *)scope == (c1_type *)0x0) {
    if (iVar25 == 0) {
      result = (*g_current_scope->global_scope->vtbl->lookup)
                         (g_current_scope->global_scope,pfVar19,1);
      if ((result == (c1_lookup_result *)0x0) ||
         (pcVar7 = lookup_check_ambiguous_symbol(result,'\x01'), pcVar7 == (c1_lookup_entry *)0x0))
      {
        pcVar20 = (c1_symbol *)0x0;
      }
      else {
        pcVar20 = pcVar7->sym;
      }
      if (pcVar20 == (c1_symbol *)0x0) {
        if (*pbVar6 == 0x8e) {
          g_yylval = CONCAT31(g_yylval._1_3_,pbVar6[8]);
          if (g_token_arena_index == 0) {
            pbVar6 = pool_alloc_raw(&g_pool_default,0x30);
          }
          else {
            pcVar9 = g_arenas + g_token_arena_index;
            pbVar6 = pcVar9->cur;
            pbVar14 = g_arenas[g_token_arena_index].end;
            pcVar9->cur = pbVar6 + 0x30;
            if (pbVar14 < pbVar6 + 0x30) {
              arena_grow(pcVar9);
            }
          }
          if (pbVar6 == (byte *)0x0) {
            return (byte *)0x0;
          }
          *pbVar6 = 0x97;
          puVar21 = &g_yylval;
          puVar22 = (uint *)(pbVar6 + 8);
          for (iVar25 = 10; iVar25 != 0; iVar25 = iVar25 + -1) {
            *puVar22 = *puVar21;
            puVar21 = puVar21 + 1;
            puVar22 = puVar22 + 1;
          }
          return pbVar6;
        }
        diag_error(0x205,pfVar19);
        iVar25 = 1;
        scope_saved = (c1_keyed_list *)0x0;
        pcVar8 = (c1_type *)0x0;
      }
      else {
        if (((((pcVar20->kind & 0x1f) == 10) && ((pcVar20->flags2 & 0x10) != 0)) &&
            ((pcVar20->type->code & 0x200) != 0)) &&
           ((pcVar20 = (pcVar20->type->extra).cls, (g_compile_flags_c4 & 0x80000) != 0 &&
            (pcVar15 = lex_peek_token((uint *)&g_token_position), *pcVar15 != -0x6b)))) {
          diag_error(0xf2);
        }
        tree_list_arena_set(4);
        pcVar8 = (c1_type *)tree_new_list_cell((c1_keyed_list *)0x0,0,pcVar20);
        scope_saved = (c1_keyed_list *)pcVar8;
        tree_list_arena_restore();
      }
    }
  }
  else {
    if ((((*(int *)scope != 0) &&
         (pcVar20 = *(c1_symbol **)(*(int *)scope + 8), (pcVar20->kind & 0x1f) == 4)) &&
        ((((pcVar20->detail).cls)->flags3e & 1) != 0)) &&
       (pvVar11 = tmpl_template_of_instance(pcVar20), *(fe_name **)((int)pvVar11 + 8) == pfVar19)) {
      pbVar6 = decl_lookup_qualified_template_name_fragment
                         (pcVar20,scope,bVar24,first_lookup_hit,pbVar6,scope_saved,leading_global,
                          iVar25,has_ctor,has_dtor,saved_name,template_tok,pair_second,set_flags1_80
                          ,set_flags3_01,saved_access_op,saved_reported,saved_access_op_2,
                          saved_reported_2,token,p2);
      return pbVar6;
    }
    name = pfVar19;
    if (((**(byte **)(*(int *)scope + 8) & 0x1f) != 0x19) &&
       (pfVar19 == *(fe_name **)(*(byte **)(*(int *)scope + 8) + 8))) {
      if (has_ctor != 0) {
        diag_error(0x253,pfVar19);
      }
      if (has_dtor != 0) {
        diag_error(0x254,pfVar19);
      }
      has_ctor = 1;
      name = g_name_ctor;
      saved_name = pfVar19;
    }
LAB_1040810f:
    pcVar8 = (c1_type *)lookup_qualified_name(scope,name,(c1_type *)0x0,(char)p2);
    pcVar13 = g_arenas[5].cur;
    pfVar19 = name;
    scope_saved = (c1_keyed_list *)pcVar8;
    if (pcVar8 == (c1_type *)0x0) {
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
          if (pcVar13 == (c1_u8 *)0x0) {
            pcVar13 = (c1_u8 *)0x0;
          }
          else {
            *(fe_name **)pcVar13 = saved_name;
            pcVar13[0x28] = '\0';
            pcVar13[0x29] = '\0';
            pcVar13[0x2a] = '\0';
            pcVar13[0x2b] = '\0';
            pcVar13[0x30] = '\x01';
            pcVar13[0x4c] = '\0';
            pcVar13[0x4d] = '\0';
            pcVar13[0x4e] = '\0';
            pcVar13[0x4f] = '\0';
            pcVar16 = arena_alloc(g_arenas + 5,0x4c);
            if (pcVar16 == (c1_decl_record *)0x0) {
              pcVar13[4] = '\0';
              pcVar13[5] = '\0';
              pcVar13[6] = '\0';
              pcVar13[7] = '\0';
              *(int *)(pcVar13 + 0x24) = g_token_position;
            }
            else {
              pcVar16 = decl_record_init_default
                                  (pcVar16,*(void **)pcVar13,*(c1_overload_set **)(pcVar13 + 0x28));
              *(c1_decl_record **)(pcVar13 + 4) = pcVar16;
              *(int *)(pcVar13 + 0x24) = g_token_position;
            }
          }
          pcVar13[0x55] = pcVar13[0x55] | 0x80;
          if (g_token_arena_index == 0) {
            if (g_pool_default_left < 0x30) {
              pool_reserve((c1xx_pool *)&g_pool_default,0x30);
            }
            g_pool_default_left = g_pool_default_left - 0x30;
            pbVar6 = g_pool_default;
            g_pool_default = g_pool_default + 0x30;
          }
          else {
            pbVar6 = arena_alloc(g_arenas + g_token_arena_index,0x30);
          }
          if (pbVar6 == (byte *)0x0) {
            return (byte *)0x0;
          }
          *(c1_u8 **)(pbVar6 + 8) = pcVar13;
          *pbVar6 = 0xa7;
          return pbVar6;
        }
        if (has_ctor != 0) {
          g_arenas[5].cur = g_arenas[5].cur + 0x58;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar13 == (c1_u8 *)0x0) {
            pcVar13 = (c1_u8 *)0x0;
          }
          else {
            *(fe_name **)pcVar13 = saved_name;
            pcVar13[0x28] = '\0';
            pcVar13[0x29] = '\0';
            pcVar13[0x2a] = '\0';
            pcVar13[0x2b] = '\0';
            pcVar13[0x30] = '\x01';
            pcVar13[0x4c] = '\0';
            pcVar13[0x4d] = '\0';
            pcVar13[0x4e] = '\0';
            pcVar13[0x4f] = '\0';
            pcVar16 = arena_alloc(g_arenas + 5,0x4c);
            if (pcVar16 == (c1_decl_record *)0x0) {
              pcVar13[4] = '\0';
              pcVar13[5] = '\0';
              pcVar13[6] = '\0';
              pcVar13[7] = '\0';
              *(int *)(pcVar13 + 0x24) = g_token_position;
            }
            else {
              pcVar16 = decl_record_init_default
                                  (pcVar16,*(void **)pcVar13,*(c1_overload_set **)(pcVar13 + 0x28));
              *(c1_decl_record **)(pcVar13 + 4) = pcVar16;
              *(int *)(pcVar13 + 0x24) = g_token_position;
            }
          }
          pcVar13[0x55] = pcVar13[0x55] | 0x40;
          if (g_token_arena_index == 0) {
            if (g_pool_default_left < 0x30) {
              pool_reserve((c1xx_pool *)&g_pool_default,0x30);
            }
            g_pool_default_left = g_pool_default_left - 0x30;
            pbVar6 = g_pool_default;
            g_pool_default = g_pool_default + 0x30;
          }
          else {
            pcVar9 = g_arenas + g_token_arena_index;
            pbVar6 = pcVar9->cur;
            pbVar14 = g_arenas[g_token_arena_index].end;
            pcVar9->cur = pbVar6 + 0x30;
            if (pbVar14 < pbVar6 + 0x30) {
              arena_grow(pcVar9);
            }
          }
          if (pbVar6 == (byte *)0x0) {
            return (byte *)0x0;
          }
          *(c1_u8 **)(pbVar6 + 8) = pcVar13;
          *pbVar6 = 0xa7;
          return pbVar6;
        }
      }
      if (((*(byte *)(*(int *)(*(int *)scope + 8) + 2) & 4) == 0) &&
         (pvVar11 = *(void **)(*(int *)(*(int *)scope + 8) + 8),
         pvVar12 = class_current_definition_name(), pvVar11 == pvVar12)) {
        if (bVar24 != 1) {
          if (g_token_arena_index == 0) {
            if (g_pool_default_left < 0x30) {
              pool_reserve((c1xx_pool *)&g_pool_default,0x30);
            }
            g_pool_default_left = g_pool_default_left - 0x30;
            pbVar6 = g_pool_default;
            g_pool_default = g_pool_default + 0x30;
          }
          else {
            pcVar9 = g_arenas + g_token_arena_index;
            pbVar6 = pcVar9->cur;
            pbVar14 = g_arenas[g_token_arena_index].end;
            pcVar9->cur = pbVar6 + 0x30;
            if (pbVar14 < pbVar6 + 0x30) {
              arena_grow(pcVar9);
            }
          }
          if (pbVar6 == (byte *)0x0) {
            return (byte *)0x0;
          }
          *(fe_name **)(pbVar6 + 0xc) = name;
          *pbVar6 = 0x8e;
          pbVar6[8] = bVar24;
          return pbVar6;
        }
        if (*pbVar6 == 6) {
          if (g_token_arena_index == 0) {
            if (g_pool_default_left < 0x30) {
              pool_reserve((c1xx_pool *)&g_pool_default,0x30);
            }
            g_pool_default_left = g_pool_default_left - 0x30;
            pbVar6 = g_pool_default;
            g_pool_default = g_pool_default + 0x30;
          }
          else {
            pcVar9 = g_arenas + g_token_arena_index;
            pbVar6 = pcVar9->cur;
            pbVar14 = g_arenas[g_token_arena_index].end;
            pcVar9->cur = pbVar6 + 0x30;
            if (pbVar14 < pbVar6 + 0x30) {
              arena_grow(pcVar9);
            }
          }
          if (pbVar6 == (byte *)0x0) {
            return (byte *)0x0;
          }
          *pbVar6 = 6;
          *(fe_name **)(pbVar6 + 8) = name;
          *(int *)(pbVar6 + 0xc) = g_token_position;
          return pbVar6;
        }
      }
      iVar25 = iVar25 + 1;
    }
  }
LAB_10408131:
  pbVar6 = token_next((c1_token_reader *)&g_token_position);
  scope = (c1_keyed_list *)pcVar8;
  if (*pbVar6 != 0x95) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar6);
    if (token == (char *)0x0) {
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pbVar6 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar9 = g_arenas + g_token_arena_index;
        pbVar6 = pcVar9->cur;
        pbVar14 = g_arenas[g_token_arena_index].end;
        pcVar9->cur = pbVar6 + 0x30;
        if (pbVar14 < pbVar6 + 0x30) {
          arena_grow(pcVar9);
        }
      }
      if (pbVar6 == (byte *)0x0) {
LAB_1045b4ab:
        pbVar6 = (byte *)0x0;
      }
      else {
        *pbVar6 = 0x96;
LAB_10408417:
        puVar21 = &g_yylval;
        puVar22 = (uint *)(pbVar6 + 8);
        for (iVar25 = 10; iVar25 != 0; iVar25 = iVar25 + -1) {
          *puVar22 = *puVar21;
          puVar21 = puVar21 + 1;
          puVar22 = puVar22 + 1;
        }
      }
    }
    else {
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pbVar6 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar9 = g_arenas + g_token_arena_index;
        pbVar6 = pcVar9->cur;
        pbVar14 = g_arenas[g_token_arena_index].end;
        pcVar9->cur = pbVar6 + 0x30;
        if (pbVar14 < pbVar6 + 0x30) {
          arena_grow(pcVar9);
        }
      }
      if (pbVar6 == (byte *)0x0) {
        pbVar6 = (byte *)0x0;
        uRam00000000 = 0x96;
      }
      else {
        pcVar15 = token;
        pbVar14 = pbVar6;
        for (iVar25 = 0xc; iVar25 != 0; iVar25 = iVar25 + -1) {
          *(undefined4 *)pbVar14 = *(undefined4 *)pcVar15;
          pcVar15 = pcVar15 + 4;
          pbVar14 = pbVar14 + 4;
        }
        *pbVar6 = 0x96;
      }
    }
    if ((c1_type *)scope == (c1_type *)0x0) {
      if (saved_name != (fe_name *)0x0) {
        *pbVar6 = 6;
        *(fe_name **)(pbVar6 + 8) = saved_name;
        return pbVar6;
      }
      if (pfVar19 != (fe_name *)0x0) {
        *pbVar6 = 6;
        *(fe_name **)(pbVar6 + 8) = pfVar19;
        return pbVar6;
      }
LAB_1045b010:
      if (*pbVar6 != 0x4a) {
        return g_token_colon_colon;
      }
    }
    else {
      if ((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
          (((g_compile_flags_c8 & 0x10000000) != 0 ||
           ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
            ((g_compile_flags_c4 & 0x200) == 0)))))) || ((g_compile_flags_cc & 0x50) != 0)) {
        iVar25 = 0;
      }
      else {
        iVar25 = 4;
      }
      pcVar10 = sym_new_overload_set_record(scope_saved,pfVar19,iVar25);
      if (*pbVar6 == 0x9f) {
        *pbVar6 = 0x9f;
        *(c1_overload_set **)(pbVar6 + 8) = pcVar10;
      }
      else {
        *pbVar6 = 0x96;
        pcVar13 = g_arenas[4].cur;
        g_arenas[4].cur = g_arenas[4].cur + 8;
        if (g_arenas[4].end < g_arenas[4].cur) {
          arena_grow(g_arenas + 4);
        }
        if (pcVar13 == (c1_u8 *)0x0) {
          pbVar6[8] = 0;
          pbVar6[9] = 0;
          pbVar6[10] = 0;
          pbVar6[0xb] = 0;
        }
        else {
          *(c1_overload_set **)pcVar13 = pcVar10;
          *(int *)(pcVar13 + 4) = pair_second;
          *(c1_u8 **)(pbVar6 + 8) = pcVar13;
        }
      }
      if ((char)leading_global != '\0') {
        if (g_current_scope->qualified != '\0') {
          diag_error(299,pcVar10,(uint)g_current_scope->access_op);
          pcVar10->flags3 = pcVar10->flags3 | 4;
        }
        pcVar10->flags3 = pcVar10->flags3 | 0x40;
      }
      if ((((g_compile_flags_c4 & 0x80000) != 0) && ((char)p2 == '\0')) &&
         (pcVar20 = pcVar10->list->head->sym, (pcVar20->kind & 0x1f) == 10)) {
        pbVar6 = decl_declarator_name_mark_fragment
                           (pcVar20,pbVar6,has_ctor,has_dtor,set_flags1_80,set_flags3_01);
        return pbVar6;
      }
      if (*pbVar6 == 0x96) {
        pcVar20 = (c1_symbol *)**(undefined4 **)(pbVar6 + 8);
      }
      else {
        pcVar20 = *(c1_symbol **)(pbVar6 + 8);
      }
      expr_resolve_overload_set_member(pcVar20,(c1_symbol *)0x0);
      if (has_ctor != 0) {
        pcVar20->flags1 = pcVar20->flags1 | 0x10;
      }
      if (has_dtor != 0) {
        pcVar20->flags1 = pcVar20->flags1 | 0x20;
      }
      if (set_flags1_80 != 0) {
        pcVar20->flags1 = pcVar20->flags1 | 0x80;
      }
      if (set_flags3_01 != 0) {
        pcVar20->flags3 = pcVar20->flags3 | 1;
        return pbVar6;
      }
    }
    return pbVar6;
  }
  goto LAB_10407e80;
}

