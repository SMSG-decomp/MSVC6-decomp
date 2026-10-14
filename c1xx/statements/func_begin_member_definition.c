c1_symbol * __thiscall func_begin_member_definition(c1_declarator *d,byte *specs)

{
  c1_u8 *pcVar1;
  byte *pbVar2;
  c1_keyed_cell *pcVar3;
  c1_type *pcVar4;
  c1_scope_stack *stack;
  byte bVar5;
  c1_decl_state *pcVar6;
  c1xx_hash_scope *pcVar7;
  c1_symbol *pcVar8;
  int iVar9;
  c1_symbol *pcVar10;
  c1xx_token *pcVar11;
  c1_symbol *pcVar12;
  short sVar13;
  uint uVar14;
  
  if ((((byte)g_compile_flags_cc & 4) == 0) && ((g_compile_flags_c4 & 0x20) != 0)) {
    func_definition_end('\x01');
  }
  pcVar1 = g_arenas[8].cur;
  stack = g_current_scope;
  if (-1 < g_class_depth) {
    return d->sym;
  }
  g_arenas[8].cur = g_arenas[8].cur + 0x1c;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  if (pcVar1 == (c1_u8 *)0x0) {
    pcVar6 = (c1_decl_state *)0x0;
  }
  else {
    pcVar6 = decl_state_snapshot((c1_decl_state *)pcVar1,stack,stack->saved,'\0');
  }
  stack->saved = pcVar6;
  pcVar12 = (c1_symbol *)0x0;
  if ((d->qualifier != (c1_overload_set *)0x0) &&
     (pcVar3 = d->qualifier->list->head->key, pcVar3 != (c1_keyed_cell *)0x0)) {
    g_member_function_class = pcVar3->sym;
    pcVar7 = scope_enclosing_namespace(g_current_scope,'\x01');
    if (pcVar7 != (c1xx_hash_scope *)0x0) {
      pcVar12 = pcVar7->ns;
    }
    scope_enter_symbol_scope(g_member_function_class);
    scope_stack_promote_class_scopes(g_current_scope);
  }
  if ((g_member_function_class == (c1_symbol *)0x0) ||
     ((g_member_function_class->kind & 0x1f) == 0x19)) {
    d->flags54 = d->flags54 | 8;
    pcVar10 = decl_declare_in_current_scope(d,(c1xx_decl_specifiers *)specs);
    if (pcVar10 == (c1_symbol *)0x0) {
      pcVar12 = d->sym;
      if (pcVar12 == (c1_symbol *)0x0) {
        pcVar12 = sym_new_from_declarator(d,5);
      }
      diag_error(0xf4,pcVar12);
      d->sym->flags3 = d->sym->flags3 | 4;
      return d->sym;
    }
    if (((pcVar10->flags23 & 0x40) != 0) && ((*(byte *)((int)&pcVar10->tail + 9) & 0x80) == 0)) {
      diag_error(0x390,pcVar10);
    }
    d->sym = pcVar10;
    pcVar10->flags2 = pcVar10->flags2 & 0xf7;
  }
  else {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x100;
    pcVar10 = d->qualifier->list->head->sym;
    d->kind = 2;
    if ((g_member_function_class->kind & 0x1f) != 4) {
      pcVar3 = d->qualifier->list->head->key;
      bVar5 = pcVar3->sym->kind;
      while ((bVar5 & 0x1f) != 4) {
        pcVar3 = pcVar3->key;
        bVar5 = pcVar3->sym->kind;
      }
      d->qualifier = (c1_overload_set *)0x0;
      g_member_function_class = pcVar3->sym;
      pcVar12 = d->sym;
      if (pcVar12 == (c1_symbol *)0x0) {
        pcVar12 = sym_new_from_declarator(d,5);
      }
      diag_error(0x1fd,pcVar12,g_member_function_class);
      func_reset_state();
      return d->sym;
    }
    if ((g_compile_flags_c4 & 0x200) == 0) {
      if ((d->spec[1] & 2) != 0) {
        pcVar8 = d->sym;
        if (pcVar8 == (c1_symbol *)0x0) {
          pcVar8 = sym_new_from_declarator(d,5);
        }
        diag_error(0x2d3,pcVar8,0xf);
      }
      if ((d->spec[0] & 7) == 3) {
        pcVar8 = d->sym;
        if (pcVar8 == (c1_symbol *)0x0) {
          pcVar8 = sym_new_from_declarator(d,5);
        }
        diag_error(0x2d4,pcVar8);
      }
    }
    pcVar8 = decl_declare_in_current_scope(d,(c1xx_decl_specifiers *)specs);
    bVar5 = pcVar10->kind & 0x1f;
    if ((bVar5 == 0x11) || (bVar5 == 8)) {
      if (pcVar8 == (c1_symbol *)0x0) {
        pcVar10 = sym_new_from_declarator(d,0xffffffff);
        d->sym = pcVar10;
        diag_error(0x1ff,pcVar10,pcVar10->type,g_member_function_class);
        (d->sym->tail).fn.op_token = '\x01';
        d->sym->flags1 = d->sym->flags1 & 0xef;
        d->sym->flags1 = d->sym->flags1 & 0xdf;
        d->sym->flags3 = d->sym->flags3 | 4;
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffeff;
        if (((byte)g_compile_flags_cc & 4) == 0) {
          lex_skip_to_closing_brace('\0');
        }
      }
      else {
        bVar5 = pcVar8->kind & 0x1f;
        if ((bVar5 == 7) || (bVar5 == 8)) {
          decl_merge_attributes(d,pcVar8);
          d->sym = pcVar8;
          if (((byte)g_compile_flags_cc & 4) == 0) {
            if ((pcVar8->flags2 & 4) != 0) {
              if ((*(byte *)((int)&pcVar8->tail + 9) & 0x10) == 0) {
                sVar13 = 0x54;
              }
              else {
                sVar13 = 600;
              }
              diag_error(sVar13,pcVar8);
              pcVar1 = &d->sym->flags3;
              *pcVar1 = *pcVar1 | 4;
            }
            d->sym->flags2 = d->sym->flags2 | 4;
            d->sym->flags2 = d->sym->flags2 & 0xf7;
            scope_stack_promote_class_scopes(g_current_scope);
          }
        }
      }
    }
    else {
      if (bVar5 == 0x1a) {
        d->sym = *(c1_symbol **)pcVar10->type;
      }
      pcVar10 = d->sym;
      bVar5 = (pcVar10->tail).fn.op_token;
      if (bVar5 == 1) {
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_error(0x1fd,pcVar10,g_member_function_class);
      }
      else {
        diag_error(0x221,(uint)bVar5);
      }
      d->sym->flags3 = d->sym->flags3 | 4;
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffeff;
      lex_skip_to_closing_brace('\0');
    }
  }
  if (pcVar12 != (c1_symbol *)0x0) {
    ns_check_definition_scope(&d->sym->kind,(int)pcVar12);
  }
  decl_check_operator_function(d->sym,1);
  if (((byte)g_compile_flags_cc & 4) == 0) {
    pcVar12 = d->sym;
    bVar5 = pcVar12->kind & 0x1f;
    if (((bVar5 == 7) || (bVar5 == 8)) && ((*(byte *)((int)&pcVar12->tail + 9) & 1) != 0)) {
      pcVar4 = pcVar12->type->base;
      if ((pcVar4->code & 0x200) == 0) {
        pcVar12 = (c1_symbol *)0x0;
      }
      else {
        pcVar12 = (pcVar4->extra).cls;
      }
      if ((((pcVar12->flags2 & 4) == 0) &&
          (tmpl_instantiate_if_needed(pcVar12), (pcVar12->flags2 & 4) == 0)) && (g_opt_Zg == '\0'))
      {
        diag_error(0x1b,pcVar12);
      }
      g_return_object_pointer_type = type_this_pointer(pcVar12,0,0);
      param_list_add_compiler_formal_front_or_back
                (0,&g_pending_parameter_scope,PTR_104d1648,g_return_object_pointer_type);
    }
    if ((g_compile_flags_c4 & 0x100) != 0) {
      if (((d->sym->flags1 & 0x10) == 0x10) &&
         ((((g_member_function_class->detail).cls)->layout_flags3b & 0x10) != 0)) {
        pcVar12 = decl_check_function_definition_head(d);
        return pcVar12;
      }
      if (g_pending_function_word == 0) {
        pbVar2 = (byte *)((int)&d->sym->tail + 8);
        *pbVar2 = *pbVar2 & 0xfe;
      }
      if ((*(byte *)((int)&d->sym->tail + 8) & 1) != 0) {
        pcVar4 = d->sym->type;
        param_list_add_compiler_formal_front_or_back
                  (0,&g_pending_parameter_scope,g_name_this,
                   (c1_type *)
                   **(undefined4 **)(((uint)pcVar4 & -(uint)((pcVar4->code & 0x80) != 0)) + 8));
      }
    }
    pcVar12 = d->sym;
    bVar5 = pcVar12->kind & 0x1f;
    if ((bVar5 != 7) && (bVar5 != 8)) {
      if (bVar5 == 6) {
        if (pcVar12 == (c1_symbol *)0x0) {
          pcVar12 = sym_new_from_declarator(d,5);
          diag_error(0xa9,pcVar12);
        }
        else {
          diag_error(0xa9,pcVar12);
        }
      }
      else {
        pcVar11 = parse_lookahead_token();
        if (pcVar11 == (c1xx_token *)0x0) {
          pcVar12 = d->sym;
          if (pcVar12 == (c1_symbol *)0x0) {
            pcVar12 = sym_new_from_declarator(d,5);
          }
          uVar14 = 0x53;
          sVar13 = 0x36;
        }
        else {
          pcVar12 = d->sym;
          if (pcVar12 == (c1_symbol *)0x0) {
            pcVar12 = sym_new_from_declarator(d,5);
          }
          pcVar11 = parse_lookahead_token();
          uVar14 = (uint)pcVar11->code;
          sVar13 = 0xef;
        }
        diag_error(sVar13,uVar14,pcVar12);
      }
      pcVar1 = &d->sym->flags3;
      *pcVar1 = *pcVar1 | 4;
      func_reset_state();
      return d->sym;
    }
    if ((d->flags55 & 8) == 0) {
      if (pcVar12 == (c1_symbol *)0x0) {
        pcVar12 = sym_new_from_declarator(d,5);
      }
      diag_error(0xce,pcVar12);
      g_pending_parameter_scope = (c1_sym_list *)0x0;
    }
    pcVar12 = d->sym;
    if (((pcVar12->flags22 & 8) != 0) && ((pcVar12->flags21 & 1) == 0)) {
      pcVar12 = decl_check_definition_dllimport(pcVar12,d);
      return pcVar12;
    }
    if (g_code_seg_name != (void *)0x0) {
      sym_set_segment_checked(d->sym,g_code_seg_name);
    }
    g_current_function = func_body_begin(d->sym);
    g_function_context_word = g_pending_function_word;
    g_function_parameter_scope = g_pending_parameter_scope;
    if ((((byte)g_function_return_type->code >> 6 & 1) == 0) &&
       (iVar9 = type_size(g_function_return_type), iVar9 == 0)) {
      if ((g_function_return_type->code & 0x200) == 0) {
        pcVar12 = (c1_symbol *)0x0;
      }
      else {
        pcVar12 = (g_function_return_type->extra).cls;
      }
      diag_error(0x4f,g_current_function,g_function_return_type,pcVar12);
    }
    return g_current_function;
  }
  return d->sym;
}

