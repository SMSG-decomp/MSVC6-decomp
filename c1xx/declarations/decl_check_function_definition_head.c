c1_symbol * decl_check_function_definition_head(c1_declarator *d)

{
  byte *pbVar1;
  c1_u8 *pcVar2;
  c1_type *pcVar3;
  byte bVar4;
  int iVar5;
  c1xx_token *pcVar6;
  c1_symbol *pcVar7;
  short n;
  uint uVar8;
  
  param_list_add_compiler_formal_front_or_back
            (1,&g_pending_parameter_scope,PTR_104d162c,g_type_unsigned_int);
  if (g_pending_function_word == 0) {
    pbVar1 = (byte *)((int)&d->sym->tail + 8);
    *pbVar1 = *pbVar1 & 0xfe;
  }
  if ((*(byte *)((int)&d->sym->tail + 8) & 1) != 0) {
    pcVar3 = d->sym->type;
    param_list_add_compiler_formal_front_or_back
              (0,&g_pending_parameter_scope,g_name_this,
               (c1_type *)
               **(undefined4 **)(((uint)pcVar3 & -(uint)((pcVar3->code & 0x80) != 0)) + 8));
  }
  pcVar7 = d->sym;
  bVar4 = pcVar7->kind & 0x1f;
  if ((bVar4 != 7) && (bVar4 != 8)) {
    if (bVar4 == 6) {
      if (pcVar7 == (c1_symbol *)0x0) {
        pcVar7 = sym_new_from_declarator(d,5);
        diag_error(0xa9,pcVar7);
      }
      else {
        diag_error(0xa9,pcVar7);
      }
    }
    else {
      pcVar6 = parse_lookahead_token();
      if (pcVar6 == (c1xx_token *)0x0) {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        uVar8 = 0x53;
        n = 0x36;
      }
      else {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        pcVar6 = parse_lookahead_token();
        uVar8 = (uint)pcVar6->code;
        n = 0xef;
      }
      diag_error(n,uVar8,pcVar7);
    }
    pcVar2 = &d->sym->flags3;
    *pcVar2 = *pcVar2 | 4;
    func_reset_state();
    return d->sym;
  }
  if ((d->flags55 & 8) == 0) {
    if (pcVar7 == (c1_symbol *)0x0) {
      pcVar7 = sym_new_from_declarator(d,5);
    }
    diag_error(0xce,pcVar7);
    g_pending_parameter_scope = (c1_sym_list *)0x0;
  }
  pcVar7 = d->sym;
  if (((pcVar7->flags22 & 8) != 0) && ((pcVar7->flags21 & 1) == 0)) {
    pcVar7 = decl_check_definition_dllimport(pcVar7,d);
    return pcVar7;
  }
  if (g_code_seg_name != (void *)0x0) {
    sym_set_segment_checked(d->sym,g_code_seg_name);
  }
  g_current_function = func_body_begin(d->sym);
  g_function_context_word = g_pending_function_word;
  g_function_parameter_scope = g_pending_parameter_scope;
  if ((((byte)g_function_return_type->code >> 6 & 1) == 0) &&
     (iVar5 = type_size(g_function_return_type), iVar5 == 0)) {
    if ((g_function_return_type->code & 0x200) == 0) {
      pcVar7 = (c1_symbol *)0x0;
    }
    else {
      pcVar7 = (g_function_return_type->extra).cls;
    }
    diag_error(0x4f,g_current_function,g_function_return_type,pcVar7);
  }
  return g_current_function;
}

