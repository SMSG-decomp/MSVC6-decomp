c1xx_block_scope * __cdecl
tmpl_bind_arguments(c1_sym_list *params,c1_arg_list *args,c1_symbol *tmpl,char in_block,char prefix,
                   int prefix_count)

{
  c1_u32 *pcVar1;
  char cVar2;
  c1_arg_value cVar3;
  c1xx_block_scope_vtbl *pcVar4;
  c1_symbol *sym;
  byte bVar5;
  ushort uVar6;
  c1xx_block_scope *type2;
  c1_decl_record *pcVar7;
  c1_symbol *pcVar8;
  c1_node *pcVar9;
  c1_node *pcVar10;
  c1_type *pcVar11;
  byte bVar12;
  short n;
  int iVar13;
  c1_declarator *d;
  c1_u32 *spec_word_2;
  c1_type *pcVar14;
  c1_u32 *spec_word;
  c1_u32 *spec_word_3;
  c1_u32 *spec_word_4;
  c1_u8 *pcVar15;
  c1_arg_item *local_38;
  int local_30;
  c1_sym_link *param_link;
  c1xx_decl_specifiers local_24;
  
  local_30 = 0;
  type2 = tmpl_binding_scope_new(g_current_scope,(c1_sym_list *)0x0);
  g_tmpl_binding_in_progress = 1;
  local_38 = args->first;
  if (params == (c1_sym_list *)0x0) {
    param_link = (c1_sym_link *)0x0;
  }
  else {
    param_link = params->head;
  }
  if (param_link != (c1_sym_link *)0x0) {
    while (d = (c1_declarator *)g_arenas[5].cur, pcVar1 = &param_link[-1].position,
          local_38 != (c1_arg_item *)0x0) {
      pcVar15 = g_arenas[5].cur;
      if ((*pcVar1 & 0x1f) == 0x16) {
        pcVar14 = (param_link->type).type;
        cVar2 = (char)pcVar14->code;
        while (cVar2 < '\0') {
          pcVar14 = pcVar14->base;
          cVar2 = (char)pcVar14->code;
        }
        if ((pcVar14->code & 0xfff) == 0x801) {
          bVar5 = local_38->kind & 3;
          if ((bVar5 != 0) && (bVar5 != 2)) {
            diag_fatal(1,".\\template.cpp",0x185a);
          }
          if ((local_38->kind & 3) == 0) {
            g_arenas[5].cur = g_arenas[5].cur + 0x58;
            if (g_arenas[5].end < g_arenas[5].cur) {
              arena_grow(g_arenas + 5);
            }
            if (d == (c1_declarator *)0x0) {
              d = (c1_declarator *)0x0;
            }
            else {
              d->name = param_link->name;
              pcVar15[0x28] = '\0';
              pcVar15[0x29] = '\0';
              pcVar15[0x2a] = '\0';
              pcVar15[0x2b] = '\0';
              *(c1_u8 *)((int)d + 0x30) = '\x01';
              pcVar15[0x4c] = '\x03';
              pcVar15[0x4d] = '\0';
              pcVar15[0x4e] = '\0';
              pcVar15[0x4f] = '\0';
              pcVar7 = arena_alloc(g_arenas + 5,0x4c);
              if (pcVar7 == (c1_decl_record *)0x0) {
                pcVar15[4] = '\0';
                pcVar15[5] = '\0';
                pcVar15[6] = '\0';
                pcVar15[7] = '\0';
                *(int *)((int)d + 0x24) = g_token_position;
              }
              else {
                pcVar7 = decl_record_init_default
                                   (pcVar7,d->name,*(c1_overload_set **)((int)d + 0x28));
                *(c1_decl_record **)((int)d + 4) = pcVar7;
                *(int *)((int)d + 0x24) = g_token_position;
              }
            }
            spec_word_3 = (c1_u32 *)&local_24;
            for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
              *spec_word_3 = 0;
              spec_word_3 = spec_word_3 + 1;
            }
            local_24.spec[0] = local_24.spec[0] | 7;
            spec_word_2 = (c1_u32 *)&local_24;
            pcVar15 = d->spec;
            for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
              *(c1_u32 *)pcVar15 = *spec_word_2;
              spec_word_2 = spec_word_2 + 1;
              pcVar15 = pcVar15 + 4;
            }
            cVar3 = local_38->value;
            d->flags55 = d->flags55 | 4;
            d->type = (c1_type *)cVar3;
            d->name->flags = d->name->flags | 0x20000;
            pcVar4 = type2->vtbl;
            pcVar8 = sym_new_from_declarator(d,0xffffffff);
            (*pcVar4->insert)(type2,pcVar8);
          }
        }
      }
      else {
        bVar5 = local_38->kind & 3;
        if ((bVar5 != 1) && (bVar5 != 2)) {
          diag_fatal(1,".\\template.cpp",0x189d);
        }
        if ((local_38->kind & 3) == 1) {
          g_arenas[5].cur = g_arenas[5].cur + 0x58;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (d == (c1_declarator *)0x0) {
            d = (c1_declarator *)0x0;
          }
          else {
            d->name = param_link->name;
            pcVar15[0x28] = '\0';
            pcVar15[0x29] = '\0';
            pcVar15[0x2a] = '\0';
            pcVar15[0x2b] = '\0';
            *(c1_u8 *)((int)d + 0x30) = '\x01';
            pcVar15[0x4c] = '\v';
            pcVar15[0x4d] = '\0';
            pcVar15[0x4e] = '\0';
            pcVar15[0x4f] = '\0';
            pcVar7 = arena_alloc(g_arenas + 5,0x4c);
            if (pcVar7 == (c1_decl_record *)0x0) {
              pcVar15[4] = '\0';
              pcVar15[5] = '\0';
              pcVar15[6] = '\0';
              pcVar15[7] = '\0';
              *(int *)((int)d + 0x24) = g_token_position;
            }
            else {
              pcVar7 = decl_record_init_default(pcVar7,d->name,*(c1_overload_set **)((int)d + 0x28))
              ;
              *(c1_decl_record **)((int)d + 4) = pcVar7;
              *(int *)((int)d + 0x24) = g_token_position;
            }
          }
          pcVar14 = (param_link->type).type;
          uVar6 = tmpl_type_find_parameter(pcVar14,1,0);
          if ((uVar6 != 0) &&
             (pcVar11 = tmpl_substitute_type(pcVar14,args), pcVar11 != (c1_type *)0x0)) {
            pcVar14 = pcVar11;
          }
          local_24.type = type_with_added_qualifiers(pcVar14,0x20);
          bVar5 = local_24.spec[0] & 7;
          spec_word_4 = (c1_u32 *)&local_24;
          for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
            *spec_word_4 = 0;
            spec_word_4 = spec_word_4 + 1;
          }
          local_24.spec[0] = local_24.spec[0] ^ (bVar5 ^ local_24.spec[0]) & 7;
          if (in_block == '\0') {
            local_24.spec[0] = local_24.spec[0] & 0xf8;
          }
          else {
            local_24.spec[0] = local_24.spec[0] & 0xfb | 3;
          }
          decl_check_conversion_return_type(d->decl,&local_24);
          decl_finish_declarator(d->decl);
          spec_word = (c1_u32 *)&local_24;
          pcVar15 = d->spec;
          for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
            *(c1_u32 *)pcVar15 = *spec_word;
            spec_word = spec_word + 1;
            pcVar15 = pcVar15 + 4;
          }
          pcVar8 = decl_declare_and_check(d,local_24.spec);
          iVar13 = g_expr_arena_index;
          g_expr_arena_index = 0;
          pcVar9 = fold_static_const_member((local_38->value).expr);
          g_expr_arena_index = iVar13;
          if ((pcVar9->kind & 7) != 3) {
            pcVar8->flags5 = pcVar8->flags5 & 0xbf;
            pcVar10 = pcVar9;
            if (((pcVar9->kind & 7) == 1) && (pcVar9->op == 'd')) {
              pcVar10 = pcVar9->left;
            }
            if (((((pcVar10->kind & 7) == 1) && (uVar6 = pcVar10->type->code, (char)uVar6 < '\0'))
                && (-1 < (char)pcVar10->type->base->code)) &&
               (((uVar6 = uVar6 & 0x8f, uVar6 == 0x83 || (uVar6 == 0x82)) || (uVar6 == 0x86)))) {
              pcVar10 = pcVar10->left;
            }
            if ((pcVar10->kind & 7) != 4) {
              diag_error(0x3cd,tmpl,pcVar1);
              bVar5 = pcVar8->flags3;
              (pcVar8->tail).data.value_lo = 0;
              pcVar8->flags3 = bVar5 | 4;
              goto LAB_10450d2e;
            }
            sym = pcVar10->left;
            bVar5 = sym->storage & 7;
            if (bVar5 == 2) {
LAB_104b75c3:
              if (bVar5 != 1) goto LAB_10450f2b;
            }
            else if (bVar5 != 1) {
              if ((bVar5 != 3) || ((bVar12 = sym->kind & 0x1f, bVar12 != 8 && (bVar12 != 3)))) {
                n = 0x3cc;
                if (bVar5 == 3) {
                  n = 0x3ca;
                }
                else if (bVar5 == 4) {
                  n = 0x3cb;
                }
                diag_error(n,tmpl,pcVar1,sym);
                bVar5 = pcVar8->flags3;
                (pcVar8->tail).data.value_lo = 0;
                pcVar8->flags3 = bVar5 | 4;
                goto LAB_10450d2e;
              }
              goto LAB_104b75c3;
            }
            sym_mark_referenced(sym);
            iVar13 = tmpl_argument_is_local_extern(sym);
            if ((char)iVar13 != '\0') {
              diag_error(0x3b3,sym);
            }
          }
LAB_10450f2b:
          (pcVar8->tail).tparam_value = pcVar9;
        }
      }
LAB_10450d2e:
      if ((prefix != '\0') && (local_30 = local_30 + 1, local_30 == prefix_count))
      goto LAB_10450d71;
      local_38 = local_38->next;
      if ((param_link == (c1_sym_link *)0x0) ||
         (param_link = param_link->next, param_link == (c1_sym_link *)0x0)) break;
    }
  }
  g_tmpl_binding_in_progress = 0;
  if (local_38 != (c1_arg_item *)0x0) {
    diag_fatal(1,".\\template.cpp",0x1972);
  }
LAB_10450d71:
  g_tmpl_binding_in_progress = 0;
  scope_pop_child(g_current_scope);
  return type2;
}

