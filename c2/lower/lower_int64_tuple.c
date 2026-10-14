c2_tuple * __fastcall lower_int64_tuple(c2_tuple *t)

{
  byte bVar1;
  c2_symbol *pcVar2;
  ushort uVar3;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  c2_operand *pcVar6;
  int iVar7;
  c2_operand *pcVar8;
  c2_const_operand *pcVar9;
  c2_tuple *pcVar10;
  c2_tuple *pcVar11;
  c2_tuple *pcVar12;
  c2_fe_symbol *pcVar13;
  uint8_t uVar14;
  uint uVar15;
  uint32_t uVar16;
  code *pcVar17;
  uint8_t local_1d;
  c2_tuple *last;
  c2_tuple *local_18;
  c2_operand *local_14;
  c2_operand *local_10;
  c2_operand *half_op;
  c2_operand *local_8;
  c2_operand *local_4;
  c2_insert_fn *insert_fn;
  
  if (((t->type & 0xfff) != 8) && ((t->src == (c2_operand *)0x0 || ((t->src->type & 0xfff) < 5)))) {
    return t;
  }
  local_18 = t;
  tuple_legalize_mem_operands(t);
  uVar15 = t->op;
  if (uVar15 < 0x170) {
    if (uVar15 == 0x16f) goto switchD_107676ad_caseD_171;
    if (uVar15 < 0x162) {
      if (uVar15 < 0x160) {
        if (uVar15 < 0x15c) {
          if (uVar15 == 0x15b) {
            t->op = 1;
          }
          else if (uVar15 != 1) {
            if (uVar15 != 0x15a) {
              return local_18;
            }
            uVar14 = t->dst->kind;
            t->type = t->type & 0xf004 | 4;
            if ((uVar14 == '\x01') && (((t->dst->u18).reg)->cls == '\x01')) {
              insert_fn = tuple_insert_after;
              pcVar5 = t;
              pcVar4 = split_int64_operand_half(t,t->src,(c2_operand *)0x0,(c2_operand *)0x0);
              pcVar6 = split_int64_operand_half(t,t->dst,(c2_operand *)0x0,(c2_operand *)0x0);
              pcVar5 = tuple_new(1,t->type,pcVar6,pcVar4,insert_fn,pcVar5);
            }
            else {
              local_14 = (c2_operand *)0x0;
              pcVar4 = operand_new_hardreg(5,0x1004);
              last = (c2_tuple *)
                     split_int64_operand_half(t,t->src,(c2_operand *)&local_14,(c2_operand *)0x0);
              pcVar5 = tuple_new(0xd,t->type,pcVar4,(c2_operand *)last,tuple_insert_before,t);
              if (local_14 != (c2_operand *)0x0) {
                tuple_append_dst(pcVar5,local_14);
                local_14->sym->def = pcVar5;
              }
              t->dst->type = t->dst->type & 0xf004 | 4;
              lower_tuple(t);
              local_18 = pcVar5;
            }
            goto LAB_10767411;
          }
          uVar14 = t->src->kind;
          t->type = t->type & 0xf004 | 4;
          if ((((uVar14 == '\x06') && (pcVar4 = t->src->base, pcVar4 != (c2_operand *)0x0)) &&
              (pcVar4->kind == '\x01')) &&
             ((((pcVar4->u18).reg)->cls == '\x02' &&
              (iVar7 = operands_may_alias(t->dst,pcVar4), iVar7 != 0)))) {
            last = tuple_new_unary_temp(1,pcVar4->type,pcVar4,tuple_insert_before,t);
            tuple_replace_src(t,pcVar4,last->dst);
          }
          insert_fn = tuple_insert_after;
          pcVar5 = t;
          pcVar4 = split_int64_operand_half(t,t->src,(c2_operand *)0x0,(c2_operand *)0x0);
          pcVar6 = split_int64_operand_half(t,t->dst,(c2_operand *)0x0,(c2_operand *)0x0);
          pcVar5 = tuple_new(1,t->type,pcVar6,pcVar4,insert_fn,pcVar5);
          if ((1 << (t->src->kind & 0x1f) & 0x7eU) != 0) {
            bVar1 = pcVar5->src->flags;
            pcVar5->src->flags = (t->src->flags ^ bVar1) & 0x40 ^ bVar1;
          }
          if (((1 << (pcVar5->dst->kind & 0x1f) & 6U) != 0) &&
             (pcVar2 = pcVar5->dst->sym, pcVar2->def != (c2_tuple *)0x0)) {
            pcVar2->def = pcVar5;
          }
        }
        else {
          if (uVar15 != 0x15f) {
            return local_18;
          }
          if ((t->type & 0xfff) != 8) {
            lower_int64_truncate(t);
            return local_18;
          }
          if ((t->src->type & 0xfff) != 4) {
            pcVar5 = tuple_new_unary_temp(0x15f,0x1004,t->src,tuple_insert_before,t);
            tuple_replace_src(t,t->src,pcVar5->dst);
            lower_tuple(pcVar5);
          }
          if ((t->src->type & 0xf000) == 0x1000) {
            t->op = 0xdf;
            return local_18;
          }
          iVar7 = 0;
          uVar16 = 0;
          t->type = t->type & 0xf004 | 4;
          t->op = 1;
          pcVar4 = split_int64_operand_half(t,t->dst,(c2_operand *)0x0,(c2_operand *)0x0);
          pcVar5 = build_zero_extend_int64(pcVar4,t,uVar16,iVar7);
          if (((1 << (t->dst->kind & 0x1f) & 6U) != 0) && (t->dst->sym->def != (c2_tuple *)0x0)) {
            pcVar5->dst->sym->def = pcVar5;
          }
        }
      }
      else {
        t->type = t->type & 0xf004 | 4;
        pcVar6 = split_int64_operand_half(t,t->src,(c2_operand *)0x0,(c2_operand *)0x0);
        insert_fn = tuple_insert_after;
        pcVar4 = pcVar6;
        pcVar5 = t;
        pcVar8 = split_int64_operand_half(t,t->dst,(c2_operand *)0x0,(c2_operand *)0x0);
        uVar16 = lookup_int64_high_op(g_int64_high_half_op_table,t->op);
        pcVar5 = tuple_new(uVar16,t->type,pcVar8,pcVar4,insert_fn,pcVar5);
        if (t->op == 0x161) {
          insert_fn = tuple_insert_after;
          pcVar10 = t;
          pcVar9 = operand_new_intconst(0x1004,0,0);
          last = tuple_new_binary_temp(0x2c,t->type,pcVar6,pcVar9,insert_fn,pcVar10);
          tuple_replace_src(pcVar5,pcVar6,last->dst);
          pcVar4 = tuple_add_flags_result(t);
          tuple_append_src(last,pcVar4);
        }
      }
    }
    else {
      switch(uVar15) {
      case 0x16a:
      case 0x16b:
        pcVar5 = lower_small_block_copy_as_scalar(t);
        break;
      case 0x16c:
        pcVar17 = tuple_insert_after;
        uVar3 = (ushort)CONCAT31((byte)(t->type >> 8) & 0xf0,4);
        t->type = uVar3;
        pcVar5 = t;
        pcVar4 = split_int64_operand_half(t,t->src,(c2_operand *)0x0,(c2_operand *)0x0);
        pcVar6 = operand_new_temp_in_reg(3,uVar3 | 4);
        pcVar5 = tuple_new(1,uVar3,pcVar6,pcVar4,pcVar17,pcVar5);
        pcVar5->dst->sym->def = pcVar5;
        last = tuple_new_pseudo(0x19e,t->type);
        pcVar4 = (c2_operand *)node_clone((c2_node *)pcVar5->dst);
        tuple_append_src(last,pcVar4);
        tuple_insert_after(pcVar5,last);
        return local_18;
      case 0x16d:
      case 0x16e:
        goto switchD_107675ff_caseD_16d;
      default:
        goto switchD_107675ff_default;
      }
    }
    goto LAB_10767411;
  }
  switch(uVar15) {
  case 0x171:
  case 0x177:
    goto switchD_107676ad_caseD_171;
  case 0x172:
  case 0x173:
  case 0x174:
switchD_107675ff_caseD_16d:
    last = (c2_tuple *)t->src->next;
    t->type = t->type & 0xf004 | 4;
    pcVar4 = split_int64_operand_half(t,t->src,(c2_operand *)0x0,(c2_operand *)0x0);
    pcVar17 = tuple_insert_after;
    pcVar5 = t;
    pcVar6 = split_int64_operand_half(t,(c2_operand *)last,(c2_operand *)0x0,(c2_operand *)0x0);
    pcVar8 = split_int64_operand_half(t,t->dst,(c2_operand *)0x0,(c2_operand *)0x0);
    uVar16 = lookup_int64_high_op(g_int64_high_half_op_table,t->op);
    pcVar5 = tuple_new_binary(uVar16,t->type,pcVar8,pcVar4,pcVar6,pcVar17,pcVar5);
    if (((t->dst->kind == '\x01') && (pcVar2 = t->dst->sym, pcVar2->cls == '\x03')) &&
       (pcVar2->def != (c2_tuple *)0x0)) {
      pcVar5->dst->sym->def = pcVar5;
    }
    if ((g_x86_op_flags[pcVar5->op] & 4) != 0) {
      pcVar4 = tuple_add_flags_result(t);
      tuple_append_src(pcVar5,pcVar4);
    }
    if ((g_opt_global != 0) && ((uVar16 = t->op, uVar16 == 0x172 || (uVar16 == 0x173)))) {
      local_18 = simplify_int64_and_or_const_half(t,uVar16);
      pcVar5 = simplify_int64_and_or_const_half(pcVar5,pcVar5->op);
    }
    goto LAB_10767411;
  case 0x175:
  case 0x176:
    break;
  default:
    goto switchD_107675ff_default;
  case 0x17d:
    pcVar5 = tuple_next_real(t);
    if ((pcVar5->kind != '\x11') ||
       (((pcVar5->u20).cond_cells == (c2_cond_cell *)0x0 && (pcVar5->op != 0x18b)))) {
      lower_int64_compare_operands(t);
    }
    t->type = t->type & 0xf004 | 4;
    pcVar4 = split_int64_operand_half(t,t->src,(c2_operand *)0x0,(c2_operand *)0x0);
    pcVar6 = split_int64_operand_half(t,t->src->next,(c2_operand *)0x0,(c2_operand *)0x0);
    pcVar5 = emit_op_before_with_parts(0x2f,0x1004,pcVar4,pcVar6,t);
    pcVar4 = pcVar5->dst;
    (pcVar4->u18).reg = g_reg_symbols + 0x42;
    pcVar10 = find_next_use_of_dst(t,(c2_operand **)&last);
    if ((t->type & 0xf000) == 0x2000) {
      *(byte *)&pcVar10->type = g_unsigned_cc[(byte)pcVar10->type];
    }
    uVar15 = (uint)(byte)pcVar10->type;
    local_18 = pcVar5;
    switch(uVar15) {
    case 1:
    case 2:
      pcVar4 = t->src;
      if (pcVar4->next->kind == '\a') {
        uVar15 = (pcVar4->next->u18).lo;
        half_op = (pcVar5->src->next->u18).children;
        if ((half_op == (c2_operand *)0x0 && uVar15 == 0) ||
           (((uint)half_op & uVar15) == 0xffffffff)) {
          pcVar10 = pcVar5;
          pcVar6 = (c2_operand *)node_clone((c2_node *)pcVar5->src);
          pcVar8 = (c2_operand *)node_clone((c2_node *)pcVar4);
          pcVar10 = emit_op_before_with_parts
                              ((-(uint)((pcVar4->next->u18).reg != (c2_symbol *)0x0) & 0xfffffffe) +
                               0x30,0x1004,pcVar8,pcVar6,pcVar10);
          tuple_unlink_free(pcVar5);
          tuple_replace_src(t,pcVar4,pcVar10->dst);
          pcVar5 = pcVar10;
          local_18 = pcVar10;
          goto LAB_10767411;
        }
      }
      if ((char)pcVar10->type == '\x02') {
        pcVar11 = tuple_new_branch(0x185,'\x02',*(c2_node **)((int)&pcVar10->src->sym->u30 + 2),
                                   pcVar5->dst,pcVar5,tuple_insert_after,pcVar5);
      }
      else {
        pcVar13 = label_symbol_new();
        pcVar12 = tuple_new_label(pcVar13);
        pcVar11 = tuple_new_branch(0x185,'\x02',(c2_node *)pcVar12,pcVar5->dst,pcVar5,
                                   tuple_insert_after,pcVar5);
        tuple_insert_after(pcVar10,pcVar12);
      }
      pcVar4 = pcVar5->src;
      half_op = (c2_operand *)node_clone((c2_node *)pcVar4);
      local_10 = (c2_operand *)node_clone((c2_node *)pcVar4->next);
      pcVar10 = pcVar11->next;
      tuple_replace_src(pcVar5,pcVar4,pcVar10->src);
      tuple_replace_src(pcVar5,pcVar5->src->next,pcVar10->src->next);
      tuple_replace_src(pcVar10,pcVar10->src,half_op);
      tuple_replace_src(pcVar10,pcVar10->src->next,local_10);
      goto LAB_10767411;
    case 3:
    case 5:
      uVar14 = '\x03';
      local_1d = '\x04';
      *(byte *)&pcVar10->type = g_unsigned_cc[uVar15];
      break;
    case 4:
    case 6:
      uVar14 = '\x04';
      local_1d = '\x03';
      *(byte *)&pcVar10->type = g_unsigned_cc[uVar15];
      break;
    case 7:
    case 9:
      local_1d = '\b';
      pcVar6 = pcVar5->src->next;
      uVar14 = '\a';
      if ((pcVar6->kind != '\a') ||
         (pcVar11 = pcVar5, local_14 = pcVar4, (pcVar6->u18).reg != (c2_symbol *)0x0)) break;
      goto LAB_10767a4c;
    case 8:
    case 10:
      uVar14 = '\b';
      local_1d = '\a';
      break;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lower.c",0x8eb);
    }
    pcVar11 = tuple_new_branch(0x185,uVar14,*(c2_node **)((int)&pcVar10->src->sym->u30 + 2),pcVar4,
                               pcVar5,tuple_insert_after,pcVar5);
    local_14 = operand_new_hardreg(0x42,0x8000);
LAB_10767a4c:
    pcVar13 = label_symbol_new();
    pcVar12 = tuple_new_label(pcVar13);
    tuple_new_branch(0x185,local_1d,(c2_node *)pcVar12,local_14,pcVar5,tuple_insert_after,pcVar11);
    tuple_insert_after(pcVar10,pcVar12);
    goto LAB_10767411;
  case 0x184:
    t->type = t->type & 0xf004 | 4;
    return local_18;
  case 400:
    switch((t->u20).intrinsic.id) {
    case 0xe9:
      uVar16 = 0x2a;
      break;
    case 0xea:
      uVar16 = 0x2b;
      break;
    case 0xeb:
      uVar16 = 0x29;
      break;
    case 0xec:
    case 0xed:
      pcVar5 = tuple_new_binary((-(uint)((t->type & 0xf000) != 0x1000) & 0x1c) + 6,t->type,t->dst,
                                t->src->sym->def->src,t->src->next->sym->def->src,
                                tuple_insert_before,t);
      pcVar4 = t->src;
      local_18 = pcVar5;
      tuple_unlink_free(pcVar4->sym->def);
      tuple_unlink_free(pcVar4->next->sym->def);
      t->op = 0x145;
      if (t->dst->kind != '\x01') {
        return local_18;
      }
      pcVar2 = t->dst->sym;
      if (pcVar2->cls != '\x03') {
        return local_18;
      }
      if (pcVar2->def == (c2_tuple *)0x0) {
        return local_18;
      }
      pcVar2->def = pcVar5;
      return pcVar5;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lower.c",0x918);
    }
    lower_int64_shift_intrinsic(uVar16,t);
    t->op = 0x145;
    return t;
  case 0x19e:
    pcVar4 = t->src;
    if (((1 << (pcVar4->kind & 0x1f) & 6U) != 0) &&
       (pcVar5 = pcVar4->sym->def, pcVar5 != (c2_tuple *)0x0)) {
      if (pcVar5->op != 0x16b) {
        uVar3 = t->type & 0xf004 | 4;
        t->type = uVar3;
        pcVar5 = tuple_new_pseudo(0x19e,uVar3);
        pcVar4 = split_int64_operand_half(t,pcVar4,(c2_operand *)0x0,(c2_operand *)0x0);
        tuple_append_src(pcVar5,pcVar4);
        tuple_insert_after(t,pcVar5);
        return local_18;
      }
      if ((pcVar5->src->flags & 0x40) == 0) {
        operand_set_type(pcVar5->dst,0x1004);
        pcVar6 = pcVar5->src;
        operand_set_type(pcVar6,0x1004);
        pcVar8 = pcVar5->dst;
        pcVar8->u18 = (c2_operand_u18)pcVar8->sym;
        last = tuple_new(1,0x1004,pcVar8,pcVar6,tuple_insert_before,pcVar5);
        tuple_unlink_free(pcVar5);
        t->type = 0x1004;
        operand_set_type(pcVar4,0x1004);
        pcVar4->u18 = (c2_operand_u18)pcVar4->sym;
        symbol_mark_overlapping_parts(pcVar4->sym,last);
        return local_18;
      }
      uVar3 = pcVar5->src->type;
      local_10 = operand_new_temp_in_reg(7,0x1004);
      local_4 = operand_new_hardreg(1,0x1004);
      local_14 = operand_new_temp_in_reg(2,0x1004);
      local_8 = operand_new_hardreg(2,0x1004);
      half_op = operand_new_hardreg(7,0x1004);
      operand_set_type(pcVar5->dst,0x1004);
      pcVar17 = tuple_insert_before;
      pcVar10 = pcVar5;
      pcVar9 = operand_new_intconst(0x1004,(uVar3 & 0xfff) >> 2,0);
      last = tuple_new(1,0x1004,local_14,pcVar9,pcVar17,pcVar10);
      pcVar6 = pcVar5->src;
      local_14->sym->def = last;
      if (pcVar6->kind == '\x06') {
        pcVar6 = pcVar6->base;
      }
      else {
        pcVar13 = operand_base_fe_symbol((c2_node *)pcVar6);
        pcVar6 = operand_for_symbol_ref(pcVar13);
      }
      pcVar17 = tuple_insert_before;
      pcVar8 = local_10;
      pcVar10 = pcVar5;
      uVar16 = load_op_for_operand(pcVar6);
      last = tuple_new(uVar16,0x1004,pcVar8,pcVar6,pcVar17,pcVar10);
      local_10->sym->def = last;
      pcVar6 = pcVar5->dst;
      (pcVar6->u18).reg = g_reg_symbols + 7;
      last = tuple_new_binary(0x112,0x1004,pcVar6,local_10,local_14,tuple_insert_before,pcVar5);
      tuple_unlink_free(pcVar5);
      pcVar2 = pcVar4->sym;
      t->type = 0x1004;
      symbol_mark_overlapping_parts(pcVar2,last);
      operand_set_type(pcVar4,0x1004);
      (pcVar4->u18).reg = g_reg_symbols + 7;
      tuple_append_dst(last,local_8);
      tuple_append_dst(last,local_4);
      uVar15 = uVar3 & 3;
      if ((uVar3 & 3) != 0 && uVar15 != 1) {
        pcVar4 = operand_new_hardreg(9,0x1002);
        last = tuple_new(0x37,0x1002,pcVar4,half_op,tuple_insert_after,last);
        uVar15 = uVar15 - 2;
      }
      if (uVar15 != 0) {
        pcVar4 = operand_new_hardreg(0x11,0x1001);
        tuple_new(0x37,0x1001,pcVar4,half_op,tuple_insert_after,last);
        return local_18;
      }
    }
    goto switchD_107675ff_default;
  }
  pcVar4 = t->src->next;
  if ((pcVar4->kind == '\a') && ((pcVar4->u18).reg == (c2_symbol *)0x0 && pcVar4->tag == 0)) {
    warning(3,(uVar15 != 0x175) + 0x2d3);
  }
switchD_107676ad_caseD_171:
  if ((g_opt_global != 0) && ((uVar15 == 0x177 || (uVar15 == 0x171)))) {
    pcVar4 = t->src->next;
    if ((pcVar4->kind == '\a') && ((0x1f < (int)(pcVar4->u18).reg && (t->src->kind != '\x06')))) {
      pcVar5 = lower_int64_const_shift_ge32(t,uVar15,(c2_operand *)0x0);
      local_18 = pcVar5;
LAB_10767411:
      if ((((pcVar5 != (c2_tuple *)0x0) && (pcVar5->dst->kind == '\x01')) &&
          (pcVar2 = pcVar5->dst->sym, pcVar2->cls == '\x03')) && (pcVar2->def != (c2_tuple *)0x0)) {
        pcVar2->def = pcVar5;
      }
switchD_107675ff_default:
      return local_18;
    }
  }
  pcVar5 = lower_int64_mul_div_shift_call(t);
  return pcVar5;
}

