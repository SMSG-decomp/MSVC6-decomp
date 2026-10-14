c1_type * __cdecl conv_check_conditional_operands(c1_u8 op,c1_node **a,c1_node **b)

{
  uint uVar1;
  c1_u8 *conv;
  c1_u8 cVar2;
  char cVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  c1_type *pcVar6;
  c1_node *pcVar7;
  int iVar8;
  c1_conversion *conv_00;
  c1_type local_10;
  
  cVar2 = op;
  pcVar7 = *a;
  uVar1 = (uint)op;
  pcVar4 = pcVar7->type;
  pcVar5 = (*b)->type;
  switch(uVar1) {
  case 0x34:
  case 0x74:
    if ((((pcVar4->code & 0x10) != 0) && (pcVar7->op == '=')) && (*(char *)pcVar7->left == '5')) {
      pcVar4->extra = *(c1_type_extra *)(*(int *)(*(int *)((int)pcVar7->left + 0x14) + 0x14) + 0x10)
      ;
    }
    pcVar7 = conv_convert_expression(op,pcVar4,*b,'\x02','\b');
    *b = pcVar7;
    if ((pcVar4->code & 0x10) != 0) {
      (pcVar4->extra).cls = (c1_symbol *)0x0;
      return pcVar4;
    }
    break;
  default:
    pcVar4 = conv_operand_type_for_common_type(pcVar4);
    pcVar5 = conv_operand_type_for_common_type(pcVar5);
    conv = g_arenas[5].cur;
    if (((pcVar4->code & 0x130) != 0) && ((pcVar5->code & 0x130) != 0)) {
      pcVar6 = conv_usual_arithmetic(op,pcVar4,pcVar5);
      if (((pcVar6->code & 0x100) != 0) && (cVar3 = type_compare(pcVar4,pcVar5,2), cVar3 == '\0')) {
        pcVar6 = g_type_int;
      }
      pcVar7 = conv_convert_expression(op,pcVar6,*b,'\x02','\0');
      *b = pcVar7;
      pcVar7 = conv_convert_expression(op,pcVar6,*a,'\x02','\0');
      *a = pcVar7;
      return pcVar6;
    }
    g_arenas[5].cur = g_arenas[5].cur + 0x50;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (conv == (c1_u8 *)0x0) {
      _op = (c1_conversion *)0x0;
      conv_00 = (c1_conversion *)g_arenas[5].cur;
    }
    else {
      pcVar7 = *a;
      *conv = op;
      conv[1] = '\x03';
      conv[2] = '\b';
      *(c1_node **)(conv + 4) = pcVar7;
      if (pcVar7 == (c1_node *)0x0) {
        local_10.base = (c1_type *)0x0;
        local_10.debug_index = 0;
        local_10.code = 0x80f;
        local_10.flags = 0;
        local_10.extra.cls = (c1_symbol *)0x0;
        pcVar6 = type_intern(&local_10);
      }
      else {
        pcVar6 = pcVar7->type;
      }
      *(c1_type **)(conv + 8) = pcVar6;
      *(c1_type **)(conv + 0xc) = pcVar5;
      conv_compute_conversion((c1_conversion *)conv);
      _op = (c1_conversion *)conv;
      conv_00 = (c1_conversion *)g_arenas[5].cur;
    }
    g_arenas[5].cur = &conv_00[1].op;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (conv_00 == (c1_conversion *)0x0) {
      conv_00 = (c1_conversion *)0x0;
    }
    else {
      pcVar7 = *b;
      conv_00->op = cVar2;
      conv_00->mode = '\x03';
      conv_00->flags = '\b';
      conv_00->expr = pcVar7;
      if (pcVar7 == (c1_node *)0x0) {
        local_10.base = (c1_type *)0x0;
        local_10.debug_index = 0;
        local_10.code = 0x80f;
        local_10.flags = 0;
        local_10.extra.cls = (c1_symbol *)0x0;
        pcVar6 = type_intern(&local_10);
      }
      else {
        pcVar6 = pcVar7->type;
      }
      conv_00->source = pcVar6;
      conv_00->target = pcVar4;
      conv_compute_conversion(conv_00);
    }
    iVar8 = ovl_compare_conversion_sequences(_op,conv_00,0);
    if (iVar8 != -1) {
      if (iVar8 != 0) {
        if (iVar8 != 1) {
          pcVar4 = conv_check_conditional_operands_tail((c1_type *)0x0);
          return pcVar4;
        }
LAB_104176b5:
        pcVar7 = conv_apply_conversion(_op,(c1_node *)0x0);
        *a = pcVar7;
        return pcVar5;
      }
      if ((conv_00->flags4e & 1) == 0) {
        diag_begin_global(g_token_position);
        diag_error(0x1be,uVar1,pcVar5,pcVar4);
        conv_report_cannot_convert(conv_00,'\0');
        diag_end_global();
        local_10.base = (c1_type *)0x0;
        local_10.debug_index = 0;
        local_10.code = 0x80f;
        local_10.flags = 0;
        local_10.extra.cls = (c1_symbol *)0x0;
        pcVar4 = type_intern(&local_10);
        return pcVar4;
      }
      if (((*a)->kind & 0x80) != 0) goto LAB_104176b5;
    }
    pcVar7 = conv_apply_conversion(conv_00,(c1_node *)0x0);
    *b = pcVar7;
    break;
  case 0x70:
  case 0x7d:
    return (c1_type *)0x0;
  }
  return pcVar4;
}

