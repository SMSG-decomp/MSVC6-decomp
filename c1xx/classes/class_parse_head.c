c1_u8 * __thiscall class_parse_head(void *head,c1_u8 *token,undefined4 edx)

{
  void **ppvVar1;
  c1_u8 cVar2;
  fe_name *name;
  c1xx_scope *scope;
  c1_u8 *pcVar3;
  c1_lookup_entry *pcVar4;
  c1_symbol *pcVar5;
  c1_arena *a;
  c1_u8 *pcVar6;
  c1_lookup_result *result;
  void *pvVar7;
  char *pcVar8;
  char *pcVar9;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar10;
  void *extraout_ECX;
  undefined2 extraout_var_01;
  undefined2 uVar11;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  c1_symbol *pcVar12;
  uint *puVar13;
  uint *puVar14;
  
  uVar11 = (undefined2)((uint)edx >> 0x10);
  pcVar12 = (c1_symbol *)0x0;
  pvVar7 = head;
  if (((g_compile_flags_c8 & 0x2000000) != 0) && (g_paren_depth == 0)) {
    tmpl_close_parameter_scope();
    pvVar7 = extraout_ECX;
    uVar11 = extraout_var_06;
  }
  if ((*(ushort *)((int)head + 0xc) & 0xfff) == 0x802) goto LAB_10437c2c;
  pcVar5 = *(c1_symbol **)((int)head + 4);
  if (pcVar5 == (c1_symbol *)0x0) {
    if (*(int *)head == 0) {
      pvVar7 = name_new_S();
      *(void **)head = pvVar7;
      uVar11 = extraout_var_07;
    }
    name = *(fe_name **)head;
    if (name == (fe_name *)0x0) {
      diag_error(0x3b,0x4c,(uint)*token);
      *(undefined4 *)((int)head + 4) = 0;
      return g_token_newline;
    }
    pcVar5 = pcVar12;
    if ((*(byte *)(*(int *)((int)head + 0x28) + 1) & 4) == 0) {
      scope = g_current_scope->current;
      if ((scope->kind == '\0') && (g_paren_depth == 0)) {
        if (*(char *)((int)head + 0x30) == '\0') {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x10;
          pcVar4 = lookup_name_in_context(g_current_scope,*(void **)head,0x132);
          g_compile_flags_c4 = g_compile_flags_c4 & 0xffffffef;
          uVar11 = extraout_var;
LAB_10437bed:
          if (pcVar4 == (c1_lookup_entry *)0x0) goto LAB_10437bf5;
          pcVar5 = pcVar4->sym;
          if ((pcVar5->flags2 & 0x20) != 0) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x10;
            pcVar5 = expr_resolve_overload_set_member(pcVar5,(c1_symbol *)0x0);
            g_compile_flags_c4 = g_compile_flags_c4 & 0xffffffef;
            uVar11 = extraout_var_02;
          }
          if ((pcVar5->kind & 0x1f) == 4) {
            if (((g_compile_flags_c8 & 0x2000000) != 0) &&
               ((((pcVar5->detail).cls)->flags3e & 2) == 0)) {
              pcVar5->flags3 = pcVar5->flags3 | 4;
              diag_error(0x3dd,pcVar5);
              uVar11 = extraout_var_03;
            }
            pcVar5 = decl_tag_check_kind_and_browse
                               (pcVar5,CONCAT22(uVar11,*(undefined2 *)((int)head + 0xc)));
            *(c1_symbol **)((int)head + 4) = pcVar5;
            g_qualified_lookup_found_overloads = 1;
            goto LAB_10437c2c;
          }
          if ((g_compile_flags_c8 & 0x2000000) != 0) {
            diag_error(0x388,pcVar5->name,pcVar5);
          }
          *(void **)((int)head + 0x2c) = scope_insert_through_object;
          pcVar5 = decl_tag_declare(*(fe_name **)head,*(c1_u16 *)((int)head + 0xc),
                                    (void **)((int)head + 0x2c),'\0');
          iVar10 = CONCAT22(extraout_var_08,*(undefined2 *)((int)head + 0xc));
          *(c1_symbol **)((int)head + 4) = pcVar5;
        }
        else {
          result = (*scope->vtbl->lookup)(scope,name,1);
          if (result != (c1_lookup_result *)0x0) {
            pcVar4 = lookup_check_ambiguous_symbol(result,'\x01');
            uVar11 = extraout_var_01;
            goto LAB_10437bed;
          }
LAB_10437bf5:
          *(void **)((int)head + 0x2c) = scope_insert_through_object;
          pcVar5 = decl_tag_declare(*(fe_name **)head,*(c1_u16 *)((int)head + 0xc),
                                    (void **)((int)head + 0x2c),'\0');
          iVar10 = CONCAT22(extraout_var_00,*(undefined2 *)((int)head + 0xc));
          *(c1_symbol **)((int)head + 4) = pcVar5;
        }
        pcVar5 = decl_tag_check_kind_and_browse(pcVar5,iVar10);
        *(c1_symbol **)((int)head + 4) = pcVar5;
        g_qualified_lookup_found_overloads = 1;
        goto LAB_10437c2c;
      }
      if (g_class_depth < 0) {
        if (((g_compile_flags_c8 & 0x10000000) == 0) ||
           ((((cVar2 = *token, cVar2 != '7' && (cVar2 != '>')) && (cVar2 != '4')) && (cVar2 != 0xbf)
            ))) {
          if (((scope->kind == 0) || (0xf8 < scope->kind)) || (scope->kind == '\x01')) {
            *(code **)((int)head + 0x2c) = scope_insert_into_enclosing_namespace;
          }
          else {
            *(code **)((int)head + 0x2c) = scope_insert_through_object;
          }
        }
        else {
          *(void **)((int)head + 0x2c) = (void *)0x0;
          pcVar12 = decl_tag_declare(name,*(c1_u16 *)((int)head + 0xc),(void **)((int)head + 0x2c),
                                     '\0');
          pcVar12 = decl_tag_check_kind_and_browse
                              (pcVar12,CONCAT22(extraout_var_04,*(undefined2 *)((int)head + 0xc)));
          *(c1_symbol **)((int)head + 4) = pcVar12;
          uVar11 = extraout_var_09;
        }
        pcVar12 = decl_tag_lookup_qualified_or_declare
                            (*(fe_name **)head,CONCAT22(uVar11,*(undefined2 *)((int)head + 0xc)),
                             (void **)((int)head + 0x2c));
      }
      else {
        ppvVar1 = (void **)((int)head + 0x2c);
        if (*token == '\x7f') {
          *ppvVar1 = scope_insert_through_object;
          pcVar5 = decl_tag_declare(name,*(c1_u16 *)((int)head + 0xc),ppvVar1,'\0');
          *(c1_symbol **)((int)head + 4) = pcVar5;
          pcVar5 = decl_tag_check_kind_and_browse
                             (pcVar5,CONCAT22(extraout_var_05,*(undefined2 *)((int)head + 0xc)));
          *(c1_symbol **)((int)head + 4) = pcVar5;
          if (pcVar5 != (c1_symbol *)0x0) {
            if (g_class_depth < 0) {
              if ((g_current_scope->current->kind == '\0') && (pcVar5->scope_index == 0)) {
                pcVar5 = scope_current_namespace(g_current_scope);
                *(undefined2 *)(*(int *)((int)head + 4) + 6) = *(undefined2 *)&pcVar5->type->base;
              }
            }
            else if (pcVar5->scope_index == 0) {
              pcVar5->flags2 =
                   (g_class_def_stack[g_class_depth].flags ^ pcVar5->flags2) & 3 ^ pcVar5->flags2;
              *(c1_u16 *)(*(int *)((int)head + 4) + 6) =
                   (((g_class_def_stack[g_class_depth].cls)->detail).cls)->scope_index;
            }
          }
          goto LAB_10437c2c;
        }
        *ppvVar1 = scope_insert_into_enclosing_namespace;
        pcVar12 = decl_tag_lookup_qualified_or_declare
                            (name,CONCAT22((short)((uint)ppvVar1 >> 0x10),
                                           *(undefined2 *)((int)head + 0xc)),ppvVar1);
      }
    }
    else {
      ppvVar1 = (void **)((int)head + 0x2c);
      if (g_block_depth == '\0') {
        *ppvVar1 = scope_insert_into_enclosing_namespace;
        pcVar12 = decl_tag_lookup_qualified_or_declare
                            (name,CONCAT22(uVar11,*(undefined2 *)((int)head + 0xc)),ppvVar1);
      }
      else {
        *ppvVar1 = class_head_insert_in_enclosing_scope;
        pcVar12 = decl_tag_lookup_qualified_or_declare
                            (name,CONCAT22(uVar11,*(undefined2 *)((int)head + 0xc)),ppvVar1);
      }
    }
  }
  else {
    pcVar12 = decl_tag_check_kind_and_browse
                        (pcVar5,CONCAT22((short)((uint)pvVar7 >> 0x10),*(ushort *)((int)head + 0xc))
                        );
  }
  *(c1_symbol **)((int)head + 4) = pcVar12;
  pcVar12 = pcVar5;
LAB_10437c2c:
  g_yylval_spec_type_sym = *(c1_symbol **)((int)head + 4);
  if (*(int *)((int)head + 4) == 0) {
    if (*(int *)head != 0) {
      if (pcVar12 == (c1_symbol *)0x0) {
        pcVar8 = "typename";
      }
      else {
        pcVar8 = diag_symbol_display_name(pcVar12);
      }
      pcVar9 = type_keyword_text(*(ushort *)((int)head + 0xc));
      diag_error(0x289,pcVar8,pcVar9);
    }
    return g_token_newline;
  }
  if (((g_ms_extensions == '\0') && (g_current_scope->current->kind == '\x01')) &&
     (*(int *)((int)head + 0x2c) != 0)) {
    diag_error(0x14f,*(int *)((int)head + 4));
  }
  class_check_uuid_redefinition(*(c1_symbol **)((int)head + 4),(c1_u8 *)((int)head + 0x10));
  class_apply_tag_declspecs(*(c1_symbol **)((int)head + 4),(c1_u8 *)((int)head + 0x10));
  g_yylval_spec_insert_fn = *(void **)((int)head + 0x2c);
  if (g_token_arena_index == 0) {
    if (g_pool_default_left < 0x30) {
      pool_reserve((c1xx_pool *)&g_pool_default,0x30);
    }
    g_pool_default_left = g_pool_default_left - 0x30;
    pcVar6 = g_pool_default;
    g_pool_default = g_pool_default + 0x30;
  }
  else {
    a = g_arenas + g_token_arena_index;
    pcVar6 = a->cur;
    pcVar3 = g_arenas[g_token_arena_index].end;
    a->cur = pcVar6 + 0x30;
    if (pcVar3 < pcVar6 + 0x30) {
      arena_grow(a);
    }
  }
  if (pcVar6 == (c1_u8 *)0x0) {
    return (c1_u8 *)0x0;
  }
  *pcVar6 = '$';
  puVar13 = &g_yylval;
  puVar14 = (uint *)(pcVar6 + 8);
  for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar14 = *puVar13;
    puVar13 = puVar13 + 1;
    puVar14 = puVar14 + 1;
  }
  return pcVar6;
}

