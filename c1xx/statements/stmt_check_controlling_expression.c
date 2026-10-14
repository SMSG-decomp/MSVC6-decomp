c1_node * __cdecl stmt_check_controlling_expression(c1_node *cond,int is_switch)

{
  byte bVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  int iVar4;
  c1_u8 cVar5;
  c1_type *pcVar6;
  c1_conversion *conv;
  c1_node *pcVar7;
  short n;
  c1_type local_20;
  c1_u8 local_10 [16];
  c1_u32 *real_words;
  
  if ((g_flow_state_abandoned != '\0') || (g_sizeof_depth != 0)) {
    return cond;
  }
  if (cond == (c1_node *)0x0) {
    if (is_switch == 0) {
      local_10[4] = '\0';
      local_10[5] = '\0';
      local_10[6] = '\0';
      local_10[7] = '\0';
      local_10[8] = '\0';
      local_10[9] = '\0';
      local_10[10] = '\0';
      local_10[0xb] = '\0';
      local_10[0] = '?';
      local_10[1] = '\0';
      local_10[2] = '\0';
      local_10[3] = '\0';
      local_10[0xc] = '\0';
      local_10[0xd] = '\0';
      local_10[0xe] = '\0';
      local_10[0xf] = '\0';
      func_check_flow_state_complexity(local_10,0x10);
    }
  }
  else {
    pcVar2 = cond;
    if ((cond->kind & 7) != 5) {
      pcVar2 = fold_static_const_member(cond);
    }
    conv = (c1_conversion *)g_arenas[5].cur;
    bVar1 = pcVar2->kind & 7;
    if ((bVar1 != 3) && (bVar1 != 5)) {
      if (is_switch == 0) {
        cVar5 = 'r';
        cond = (c1_node *)0x72;
        pcVar6 = g_type_bool;
      }
      else {
        cVar5 = 0x84;
        cond = (c1_node *)0x84;
        pcVar6 = g_type_any_integral;
      }
      g_arenas[5].cur = g_arenas[5].cur + 0x50;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (conv == (c1_conversion *)0x0) {
        conv = (c1_conversion *)0x0;
      }
      else {
        conv->op = cVar5;
        switch(cond) {
        case (c1_node *)0x64:
          cVar5 = '\x04';
          break;
        default:
          cVar5 = '\x02';
          break;
        case (c1_node *)0x74:
          cVar5 = '\x01';
          break;
        case (c1_node *)0xc8:
          cVar5 = '\x06';
          break;
        case (c1_node *)0xd6:
          cVar5 = '\a';
          break;
        case (c1_node *)0xdd:
          cVar5 = '\b';
          break;
        case (c1_node *)0xde:
          cVar5 = '\t';
        }
        *(c1_u8 *)((int)conv + 1) = cVar5;
        *(c1_u8 *)((int)conv + 2) = '\0';
        *(c1_node **)((int)conv + 4) = pcVar2;
        if (pcVar2 == (c1_node *)0x0) {
          local_20.base = (c1_type *)0x0;
          local_20.debug_index = 0;
          local_20.code = 0x80f;
          local_20.flags = 0;
          local_20.extra.cls = (c1_symbol *)0x0;
          pcVar3 = type_intern(&local_20);
          *(c1_type **)((int)conv + 8) = pcVar3;
          *(c1_type **)((int)conv + 0xc) = pcVar6;
          conv_compute_conversion(conv);
        }
        else {
          *(c1_type **)((int)conv + 8) = pcVar2->type;
          *(c1_type **)((int)conv + 0xc) = pcVar6;
          conv_compute_conversion(conv);
        }
      }
      if ((conv->flags4e & 1) == 0) {
        diag_begin_global(g_token_position);
        if (is_switch == 0) {
          pcVar6 = pcVar2->type;
          n = 0x1c3;
        }
        else {
          pcVar6 = pcVar2->type;
          n = 0x1c2;
        }
        diag_error(n,pcVar6);
        conv_report_cannot_convert(conv,'\0');
        diag_end_global();
        pcVar2 = tree_new_int_constant(0);
        pcVar2 = expr_full_expression_guarded(pcVar2,3);
        return pcVar2;
      }
      pcVar2 = conv_apply_conversion(conv,(c1_node *)0x0);
      pcVar2 = expr_full_expression_guarded(pcVar2,3);
      return pcVar2;
    }
    pcVar7 = (c1_node *)0x0;
    cond = pcVar2;
    if (((bVar1 == 5) || (pcVar7 = pcVar2, pcVar2 == (c1_node *)0x0)) ||
       ((pcVar6 = pcVar2->type, (char)pcVar6->code < '\0' && (pcVar6 != (c1_type *)0x0)))) {
      if (is_switch == 0) {
        if (bVar1 != 5) {
          if (pcVar7->left == (void *)0x0 && pcVar7->right == (void *)0x0) {
            local_10[4] = '\0';
            local_10[5] = '\0';
            local_10[6] = '\0';
            local_10[7] = '\0';
            local_10[8] = '\0';
            local_10[9] = '\0';
            local_10[10] = '\0';
            local_10[0xb] = '\0';
            local_10[0] = '@';
            local_10[1] = '\0';
            local_10[2] = '\0';
            local_10[3] = '\0';
            local_10[0xc] = '\0';
            local_10[0xd] = '\0';
            local_10[0xe] = '\0';
            local_10[0xf] = '\0';
            func_check_flow_state_complexity(local_10,0x10);
            return pcVar2;
          }
          local_10[4] = '\0';
          local_10[5] = '\0';
          local_10[6] = '\0';
          local_10[7] = '\0';
          local_10[8] = '\0';
          local_10[9] = '\0';
          local_10[10] = '\0';
          local_10[0xb] = '\0';
          local_10[0] = '?';
          local_10[1] = '\0';
          local_10[2] = '\0';
          local_10[3] = '\0';
          local_10[0xc] = '\0';
          local_10[0xd] = '\0';
          local_10[0xe] = '\0';
          local_10[0xf] = '\0';
          func_check_flow_state_complexity(local_10,0x10);
          return pcVar2;
        }
        if (pcVar2->left == (void *)0x0) {
          local_10[4] = '\0';
          local_10[5] = '\0';
          local_10[6] = '\0';
          local_10[7] = '\0';
          local_10[8] = '\0';
          local_10[9] = '\0';
          local_10[10] = '\0';
          local_10[0xb] = '\0';
          local_10[0] = '@';
          local_10[1] = '\0';
          local_10[2] = '\0';
          local_10[3] = '\0';
          local_10[0xc] = '\0';
          local_10[0xd] = '\0';
          local_10[0xe] = '\0';
          local_10[0xf] = '\0';
          func_check_flow_state_complexity(local_10,0x10);
          return pcVar2;
        }
        local_10[4] = '\0';
        local_10[5] = '\0';
        local_10[6] = '\0';
        local_10[7] = '\0';
        local_10[8] = '\0';
        local_10[9] = '\0';
        local_10[10] = '\0';
        local_10[0xb] = '\0';
        local_10[0] = '?';
        local_10[1] = '\0';
        local_10[2] = '\0';
        local_10[3] = '\0';
        local_10[0xc] = '\0';
        local_10[0xd] = '\0';
        local_10[0xe] = '\0';
        local_10[0xf] = '\0';
        func_check_flow_state_complexity(local_10,0x10);
        return pcVar2;
      }
    }
    else {
      bVar1 = (byte)pcVar6->code;
      if ((bVar1 >> 4 & 1) != 0) {
        if (is_switch != 0) {
          stmt_switch_constant_selector_flow_state((int)pcVar2->left);
          return pcVar2;
        }
        if (pcVar2->left == (void *)0x0 && pcVar2->right == (void *)0x0) {
          local_20.base = (c1_type *)0x0;
          local_20.extra.cls = (c1_symbol *)0x0;
          local_20.code = 0x40;
          local_20.flags = 0;
          local_20.debug_index = 0;
          func_check_flow_state_complexity((c1_u8 *)&local_20,0x10);
          return pcVar2;
        }
        local_20.base = (c1_type *)0x0;
        local_20.extra.cls = (c1_symbol *)0x0;
        local_20.code = 0x3f;
        local_20.flags = 0;
        local_20.debug_index = 0;
        func_check_flow_state_complexity((c1_u8 *)&local_20,0x10);
        return pcVar2;
      }
      if ((is_switch == 0) && ((bVar1 >> 5 & 1) != 0)) {
        real_words = pcVar2->left;
        local_20._0_4_ = *real_words;
        local_20.base = (c1_type *)real_words[1];
        local_20.extra = *(c1_type_extra *)(real_words + 2);
        iVar4 = float_const_compare_mask(6,&local_20,&g_float_zero);
        if (iVar4 == 0) {
          local_10[4] = '\0';
          local_10[5] = '\0';
          local_10[6] = '\0';
          local_10[7] = '\0';
          local_10[8] = '\0';
          local_10[9] = '\0';
          local_10[10] = '\0';
          local_10[0xb] = '\0';
          local_10[0] = '@';
          local_10[1] = '\0';
          local_10[2] = '\0';
          local_10[3] = '\0';
          local_10[0xc] = '\0';
          local_10[0xd] = '\0';
          local_10[0xe] = '\0';
          local_10[0xf] = '\0';
          func_check_flow_state_complexity(local_10,0x10);
          return pcVar2;
        }
        local_10[4] = '\0';
        local_10[5] = '\0';
        local_10[6] = '\0';
        local_10[7] = '\0';
        local_10[8] = '\0';
        local_10[9] = '\0';
        local_10[10] = '\0';
        local_10[0xb] = '\0';
        local_10[0] = '?';
        local_10[1] = '\0';
        local_10[2] = '\0';
        local_10[3] = '\0';
        local_10[0xc] = '\0';
        local_10[0xd] = '\0';
        local_10[0xe] = '\0';
        local_10[0xf] = '\0';
        func_check_flow_state_complexity(local_10,0x10);
        return pcVar2;
      }
    }
  }
  return cond;
}

