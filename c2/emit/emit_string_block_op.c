c2_node * __fastcall
emit_string_block_op
          (uint32_t byte_count,c2_operand *count,c2_operand *count_src,c2_operand *dst,
          c2_operand *src_or_fill,int split_count,c2_operand *offset,int32_t size_code,int is_fill,
          uint32_t unused_20,uint32_t unused_24,c2_tuple *t,int32_t count_bias)

{
  c2_tuple *pcVar1;
  uint32_t dst_alias;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_symbol *reg;
  uint32_t uVar4;
  sbyte sVar5;
  c2_register_descriptor *pcVar6;
  uint16_t type;
  int iVar7;
  int iVar8;
  int local_28;
  c2_operand *local_24;
  uint32_t local_20;
  uint32_t local_1c;
  int local_18;
  int32_t local_14;
  uint32_t local_10;
  uint32_t local_c;
  int local_8;
  int local_4;
  
  pcVar3 = t;
  local_4 = 0;
  iVar8 = 1;
  if ((g_opt_favor_speed == 0) || (local_18 = 1, g_opt_cpu_target < 4)) {
    local_18 = 0;
  }
  if (split_count == 0) {
    local_14 = size_code;
    local_20 = byte_count;
  }
  else {
    local_14 = 4;
    local_20 = (int)byte_count >> (((byte)size_code ^ 3) & 0x1f);
  }
  if ((byte_count == 0) || (iVar7 = iVar8, (int)((is_fill != 0) + 4) < (int)local_20)) {
    iVar7 = 0;
  }
  local_24 = count;
  local_1c = byte_count;
  local_8 = iVar7;
  if (is_fill == 0) {
    iVar8 = 7;
    local_10 = 0x38;
    local_c = 0x10e;
    local_28 = 7;
    if (g_opt_global == 0) {
      dst_alias = 0;
      t = (c2_tuple *)0x0;
    }
    else {
      dst_alias = tuple_first_memeffect_dst_value(t);
      t = (c2_tuple *)tuple_get_memeffect_alias(pcVar3);
    }
  }
  else {
    local_10 = 0x3b;
    local_c = 0x111;
    local_28 = 1;
    if (g_opt_global == 0) {
      dst_alias = 0;
      t = (c2_tuple *)0x0;
    }
    else {
      dst_alias = tuple_first_memeffect_dst_value(t);
      t = (c2_tuple *)0x0;
    }
  }
  if ((iVar7 != 0) && (local_18 != 0)) {
    iVar8 = 0;
    local_28 = 0;
  }
  if ((is_fill != 0) && ((split_count != 0 || (offset != (c2_operand *)0x0)))) {
    if (iVar8 == 0) {
      pcVar6 = (c2_symbol *)0x0;
    }
    else {
      pcVar6 = g_reg_symbols + iVar8;
    }
    src_or_fill = lower_block_fill_value
                            (pcVar3,src_or_fill,src_or_fill->type & 0xfff,local_1c,pcVar6);
  }
  if (((1 << (src_or_fill->kind & 0x1f) & 6U) == 0) ||
     (pcVar1 = src_or_fill->sym->def, pcVar1 == (c2_tuple *)0x0)) {
    if (local_28 != 0) goto LAB_10764dcf;
LAB_1076508d:
    pcVar6 = (c2_symbol *)0x0;
LAB_10764de2:
    src_or_fill = lower_value_into_register(pcVar3,src_or_fill,pcVar6);
  }
  else {
    if (local_28 != 0) {
LAB_10764dcf:
      pcVar6 = g_reg_symbols + local_28;
      goto LAB_10764de2;
    }
    if ((pcVar1->op != 0x15a) || ((1 << (pcVar1->src->kind & 0x1f) & 0x18U) == 0))
    goto LAB_1076508d;
    src_or_fill = (c2_operand *)node_clone((c2_node *)pcVar1->src);
    tuple_unlink_free(pcVar1);
  }
  if (((1 << (dst->kind & 0x1f) & 6U) == 0) || (pcVar1 = dst->sym->def, pcVar1 == (c2_tuple *)0x0))
  {
    if (local_28 != 0) goto LAB_10764e20;
LAB_107650c3:
    reg = (c2_symbol *)0x0;
LAB_10764e25:
    dst = lower_value_into_register(pcVar3,dst,reg);
  }
  else {
    if (local_28 != 0) {
LAB_10764e20:
      reg = g_reg_symbols + 8;
      goto LAB_10764e25;
    }
    if ((pcVar1->op != 0x15a) || ((1 << (pcVar1->src->kind & 0x1f) & 0x18U) == 0))
    goto LAB_107650c3;
    dst = (c2_operand *)node_clone((c2_node *)pcVar1->src);
    tuple_unlink_free(pcVar1);
  }
  dst = block_op_fill_destination(pcVar3,dst,1);
  uVar4 = local_1c;
  sVar5 = (sbyte)local_28;
  if ((local_1c != 0) && ((int)local_20 <= (int)((is_fill != 0) + 4))) {
    tuple_unlink_free(local_24->sym->def);
    iVar8 = 0;
    pcVar2 = src_or_fill;
    if (0 < (int)local_20) {
      offset = (c2_operand *)0x0;
      do {
        if (((split_count == 0) || (local_20 << (((byte)size_code ^ 3) & 0x1f) == local_1c)) &&
           (iVar8 == local_20 - 1)) {
          iVar7 = 0;
          uVar4 = 0;
        }
        else {
          iVar7 = 1;
          uVar4 = 1 << sVar5 | 0x100;
        }
        if (local_18 == 0) {
          pcVar2 = (c2_operand *)
                   emit_string_insn(local_10,(uint16_t)local_14,&dst,&src_or_fill,(c2_operand **)0x0
                                    ,pcVar3->prev,uVar4,dst_alias,(uint32_t)t);
        }
        else {
          emit_unrolled_move_step
                    (pcVar3,is_fill,&src_or_fill,&dst,(uint16_t)local_14,(int32_t)offset,iVar7,
                     dst_alias,(uint32_t)t);
        }
        iVar8 = iVar8 + 1;
        offset = (c2_operand *)((int)&offset->next + local_14);
      } while (iVar8 < (int)local_20);
    }
    if (local_18 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = iVar8 * local_14;
      local_4 = iVar8;
    }
    goto LAB_10764efd;
  }
  local_24 = lower_value_into_register(pcVar3,local_24,g_reg_symbols + 2);
  iVar8 = split_count;
  if ((split_count == 0) || (uVar4 != 0)) {
    if (count_bias != 0) {
      offset = operand_new_intconst(0x1004,count_bias,count_bias >> 0x1f);
      emit_string_op_step(0x2b,0x1004,&local_24,&offset,pcVar3->prev,1);
    }
    if (uVar4 == 0) goto LAB_10764ead;
    if ((((int)uVar4 < 1) && (count_src->kind != '\a')) ||
       ((iVar8 != 0 && (local_20 << (((byte)size_code ^ 3) & 0x1f) != uVar4)))) goto LAB_10764ecb;
LAB_107651f3:
    uVar4 = 0;
  }
  else {
    offset = operand_new_intconst(0x1004,size_code ^ 3U,(int)(size_code ^ 3U) >> 0x1f);
    emit_string_op_step(0x2b,0x1004,&local_24,&offset,pcVar3->prev,1);
LAB_10764ead:
    if (iVar8 == 0) goto LAB_107651f3;
    if (size_code == 2) {
      uVar4 = 1 << sVar5 | 0x104;
    }
    else {
LAB_10764ecb:
      uVar4 = 1 << sVar5 | 0x100;
    }
  }
  pcVar2 = (c2_operand *)
           emit_string_insn(local_c,(uint16_t)local_14,&dst,&src_or_fill,&local_24,pcVar3->prev,
                            uVar4,dst_alias,(uint32_t)t);
  iVar8 = local_4;
LAB_10764efd:
  if (split_count != 0) {
    if (size_code == 1) {
      if (local_1c == 0) {
        local_24 = operand_new_temp_in_reg(2,0x1004);
        pcVar3 = emit_copy_after(0x1004,local_24,count_src,pcVar3->prev);
        size_code = (int32_t)operand_new_intconst(0x1004,3,0);
        pcVar3 = emit_string_op_step(0x2e,0x1004,&local_24,(c2_operand **)&size_code,pcVar3,1);
        pcVar3 = emit_string_insn(local_c,1,&dst,&src_or_fill,&local_24,pcVar3,0,dst_alias,
                                  (uint32_t)t);
        return (c2_node *)pcVar3;
      }
      if ((local_1c & 2) != 0) {
        if ((local_18 == 0) || (local_8 == 0)) {
          if ((local_1c & 1) == 0) {
            uVar4 = 0;
          }
          else {
            uVar4 = 1 << sVar5 | 0x100;
          }
          pcVar2 = (c2_operand *)
                   emit_string_insn(local_10,2,&dst,&src_or_fill,(c2_operand **)0x0,pcVar3->prev,
                                    uVar4,dst_alias,(uint32_t)t);
        }
        else {
          emit_unrolled_move_step
                    (pcVar3,is_fill,&src_or_fill,&dst,0x1002,iVar8,local_1c & 1,dst_alias,
                     (uint32_t)t);
          iVar8 = iVar8 + 2;
        }
      }
      if ((local_1c & 1) == 0) {
        return (c2_node *)pcVar2;
      }
      if ((local_18 != 0) && (local_8 != 0)) {
        emit_unrolled_move_step(pcVar3,is_fill,&src_or_fill,&dst,1,iVar8,0,dst_alias,(uint32_t)t);
        return (c2_node *)pcVar2;
      }
      pcVar3 = pcVar3->prev;
      type = 1;
    }
    else {
      if (local_1c == 0) {
        is_fill = (int)tuple_add_flags_result((c2_tuple *)pcVar2->rank);
        size_code = (int32_t)emit_string_op_step(0x118,0x1004,&local_24,(c2_operand **)&is_fill,
                                                 pcVar3->prev,1);
        pcVar3 = emit_string_insn(local_c,2,&dst,&src_or_fill,&local_24,pcVar3->prev,0,dst_alias,
                                  (uint32_t)t);
        return (c2_node *)pcVar3;
      }
      if ((local_1c & 1) == 0) {
        return (c2_node *)pcVar2;
      }
      if ((local_18 != 0) && (local_8 != 0)) {
        emit_unrolled_move_step(pcVar3,is_fill,&src_or_fill,&dst,2,iVar8,0,dst_alias,(uint32_t)t);
        return (c2_node *)pcVar2;
      }
      pcVar3 = pcVar3->prev;
      type = 2;
    }
    pcVar2 = (c2_operand *)
             emit_string_insn(local_10,type,&dst,&src_or_fill,(c2_operand **)0x0,pcVar3,0,dst_alias,
                              (uint32_t)t);
  }
  return (c2_node *)pcVar2;
}

