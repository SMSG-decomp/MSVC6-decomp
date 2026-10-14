int __fastcall fold_shift_into_mask(c2_tuple *shift,c2_tuple *user,c2_tuple *op)

{
  uint16_t type;
  uint32_t lo;
  int iVar1;
  c2_operand *pcVar2;
  int32_t hi;
  uint64_t uVar3;
  uint64_t uVar4;
  int64_t iVar5;
  longlong lVar6;
  uint32_t local_8;
  uint32_t count_hi;
  uint count_lo;
  c2_operand *count_opnd;
  uint k_lo;
  uint k_hi;
  
  if (op->op == 0x177) {
    if ((op->type & 0xf000) == 0x1000) {
      return 0;
    }
  }
  else if (shift->op == 0x16f) {
    pcVar2 = shift->src;
    if (pcVar2 == (c2_operand *)0x0) {
      return 0;
    }
    do {
      iVar1 = fold_shift_into_mask((c2_tuple *)pcVar2,shift,op);
      if (iVar1 != 0) {
        return 1;
      }
      pcVar2 = pcVar2->next;
    } while (pcVar2 != (c2_operand *)0x0);
    return 0;
  }
  if (shift->op == (-(uint)(op->op != 0x177) & 6) + 0x171) {
    count_opnd = shift->src->next;
    if (count_opnd->kind != '\a') {
      return 0;
    }
    count_lo = (count_opnd->u18).lo;
    count_hi = count_opnd->tag;
    lVar6._0_4_ = count_opnd->u18;
    lVar6._4_4_ = count_opnd->tag;
    for (pcVar2 = op->src; (pcVar2 != (c2_operand *)0x0 && (pcVar2->kind != '\a'));
        pcVar2 = pcVar2->next) {
    }
    k_lo = (pcVar2->u18).lo;
    k_hi = pcVar2->tag;
    uVar3 = shift_mask_constant(shift);
    if (op->op == 0x16f) {
      iVar5 = shift_loop_noop(-k_lo & k_lo,-(k_hi + (k_lo != 0)) & k_hi);
      if (iVar5 < lVar6) {
        return 0;
      }
      lVar6 = allshr(k_lo,k_hi,(uint8_t)count_lo);
      uVar4 = const_normalize(pcVar2->type,(uint32_t)lVar6,(int32_t)((ulonglong)lVar6 >> 0x20));
      pcVar2->u18 = (c2_operand_u18)(int)uVar4;
      pcVar2->tag = (int)(uVar4 >> 0x20);
    }
    else {
      lo = count_lo - k_lo;
      hi = (count_hi - k_hi) - (uint)(count_lo < k_lo);
      if (hi < 0) {
        lo = k_lo - count_lo;
        hi = (k_hi - count_hi) - (uint)(k_lo < count_lo);
      }
      if (((int)k_hi <= (int)count_hi) && (((int)k_hi < (int)count_hi || (k_lo < count_lo)))) {
        op->op = shift->op;
      }
      uVar4 = const_normalize(pcVar2->type,lo,hi);
      pcVar2->u18 = (c2_operand_u18)(int)uVar4;
      pcVar2->tag = (int)(uVar4 >> 0x20);
    }
    type = shift->type;
    local_8 = (uint32_t)uVar3;
    uVar3 = const_normalize(type,local_8,(int32_t)(uVar3 >> 0x20));
    shift->op = 0x172;
    count_opnd->u18 = (c2_operand_u18)(int)uVar3;
    count_opnd->tag = (int)(uVar3 >> 0x20);
    count_opnd->type = type;
    if (user != (c2_tuple *)0x0) {
      tuple_detach_src((c2_node *)user,(c2_operand *)shift);
      pcVar2 = (c2_operand *)
               tuple_new_unary_temp
                         (op->op,op->type,(c2_operand *)shift,(c2_insert_fn *)0x0,(c2_tuple *)0x0);
      tuple_unlink_mem_subops((c2_tuple *)pcVar2);
      *(undefined1 *)&pcVar2->x12 = 2;
      tuple_detach_src((c2_node *)op,(c2_operand *)user);
      ((pcVar2->u18).reg)->fe = (c2_fe_symbol *)op->src;
      tuple_append_src(user,pcVar2);
      op->src = (c2_operand *)user;
      pcVar2 = identity_constant_for_op(op->op,op->type);
      tuple_append_src(op,pcVar2);
    }
    g_simplify_changed = 1;
    return 1;
  }
  return 0;
}

