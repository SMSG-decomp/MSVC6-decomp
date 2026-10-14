c2_tuple * __fastcall eliminate_compare_with_zero(c2_tuple *t)

{
  byte bVar1;
  c2_tuple *t_00;
  uint uVar2;
  c2_symbol *pcVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  uint8_t uVar7;
  c2_operand *pcVar8;
  int iVar9;
  c2_operand *pcVar10;
  c2_tuple *pcVar11;
  c2_tuple *local_18;
  c2_operand *local_14;
  c2_operand *local_c;
  c2_operand *local_8;
  c2_register_descriptor *src_reg;
  
  pcVar10 = t->src;
  local_18 = t->next;
  bVar5 = false;
  local_c = (c2_operand *)0x0;
  bVar6 = false;
  if ((1 << (pcVar10->kind & 0x1f) & 6U) == 0) {
    return local_18;
  }
  if (pcVar10->next->kind != '\a') {
    return local_18;
  }
  if ((pcVar10->next->u18).reg != (c2_symbol *)0x0) {
    return local_18;
  }
  t_00 = t->prev;
  uVar7 = t_00->kind;
  while (((uVar7 != '\x1a' && (uVar7 != '\x19')) && (uVar7 != '\x15'))) {
    if ((t_00->flags & 1) != 0) {
      local_14 = find_dst_clobbering_reg(t_00,g_reg_symbols + 0x42);
      if (local_14 != (c2_operand *)0x0) goto LAB_1071f569;
      local_8 = find_dst_symbol_ref(t_00,pcVar10->sym);
      if (local_8 != (c2_operand *)0x0) {
        if (bVar5) {
          return local_18;
        }
        if (t_00->op != 1) {
          return local_18;
        }
        if (((local_8->type ^ pcVar10->type) & 0xfff) != 0) {
          return local_18;
        }
        bVar6 = true;
        local_c = t_00->src;
        bVar5 = true;
      }
      pcVar8 = find_src_overlapping_reg(t_00,g_reg_symbols + 0x42);
      if (pcVar8 != (c2_operand *)0x0) {
        return local_18;
      }
    }
    t_00 = t_00->prev;
    uVar7 = t_00->kind;
  }
  if (local_14 == (c2_operand *)0x0) {
    return local_18;
  }
LAB_1071f569:
  bVar1 = t_00->kind;
  if (bVar1 == 0xe) {
    return local_18;
  }
  if ((0x18 < bVar1) && (bVar1 < 0x1b)) {
    return local_18;
  }
  if (bVar5) {
    iVar9 = operand_compare(local_c,t_00->dst);
    if (iVar9 != 0) {
      return local_18;
    }
  }
  else {
    local_8 = find_dst_symbol_ref(t_00,pcVar10->sym);
    iVar9 = operand_compare(local_8,pcVar10);
    if (iVar9 != 0) {
      return local_18;
    }
  }
  uVar7 = t->kind;
  pcVar11 = local_18;
  if (uVar7 == '\x1a') {
    return local_18;
  }
  do {
    if (((pcVar11->flags & 1) != 0) &&
       (pcVar10 = find_src_symbol_ref(pcVar11,t->dst->sym), pcVar10 != (c2_operand *)0x0)) break;
    pcVar11 = pcVar11->next;
  } while (uVar7 != '\x1a');
  if (uVar7 == '\x1a') {
    return local_18;
  }
  if (pcVar11->op == 0x119) {
    return local_18;
  }
  if (pcVar11->op == 0x118) {
    return local_18;
  }
  pcVar10 = find_src_overlapping_reg(pcVar11,g_reg_symbols + 0x42);
  uVar7 = x86_fixed_reg_class(pcVar11);
  uVar2 = t_00->op;
  if (uVar2 < 0x2f) {
    if (uVar2 == 0x2e) {
switchD_1071f7ba_caseD_30:
    }
    else {
      switch(uVar2) {
      case 6:
      case 0xe:
      case 0x1f:
      case 0x20:
      case 0x22:
        return local_18;
      case 0x29:
      case 0x2a:
      case 0x2b:
        pcVar8 = t_00->src->next;
        if (pcVar8->kind != '\a') {
          return local_18;
        }
        pcVar3 = (pcVar8->u18).reg;
        if ((int)pcVar3 < 1) {
          return local_18;
        }
        if (0x1f < (int)pcVar3) {
          return local_18;
        }
      }
switchD_1071f715_caseD_7:
      src_reg = (pcVar10->u18).reg;
      if (src_reg->id == 0x43) {
        return local_18;
      }
      if (src_reg->id == 0x44) {
        uVar7 = (uVar7 != '\x03') + '\r';
      }
      else {
        if ((src_reg == g_reg_symbols + 0x49) ||
           ((iVar9 = src_reg->offset, iVar9 < g_reg_symbols[0x49].size + g_reg_symbols[0x49].offset
            && (g_reg_symbols[0x49].offset < src_reg->size + iVar9)))) {
          halt_baddata();
        }
        iVar4 = ((local_14->u18).range)->refcount;
        if (iVar9 < iVar4) {
          return local_18;
        }
        if ((int)(((local_14->u18).range)->allowed->pad_05 + iVar4 + -5) < src_reg->size + iVar9) {
          return local_18;
        }
      }
    }
    if (uVar7 != '\0') {
      tuple_unlink_free(t);
      pcVar3 = pcVar10->sym;
      local_14->sym = pcVar3;
      pcVar3->def = t_00;
      set_condition_code(pcVar11,uVar7);
      if (((!bVar6) && ((1 << (local_8->kind & 0x1f) & 6U) != 0)) &&
         (local_8->sym->def != (c2_tuple *)0x0)) {
        if ((local_8->kind == 1) && (((local_8->u18).reg)->cls == '\x01')) {
          local_8->sym = (local_8->u18).reg;
        }
        else if ((t_00->op == 0x2e) &&
                ((local_8->next == local_14 && (local_14->next == (c2_operand *)0x0)))) {
          tuple_remove_dst(t_00,local_8);
        }
        else {
          pcVar11 = tuple_new_pseudo(0x19e,local_8->type);
          tuple_append_src(pcVar11,local_8);
          tuple_insert_after(t_00,pcVar11);
          pcVar11->flags = pcVar11->flags & 0xf | 0x10;
        }
      }
      if (((t_00->op == 0x2e) && (t_00->dst == local_14)) && (local_14->next == (c2_operand *)0x0))
      {
        t_00->op = 0x33;
        fold_single_use_loads(t_00);
        local_18 = merge_test_branch_chain(t_00,local_18);
      }
    }
switchD_1071f715_caseD_6:
    return local_18;
  }
  switch(uVar2) {
  case 0x30:
  case 0x33:
  case 0x34:
    goto switchD_1071f7ba_caseD_30;
  default:
    goto switchD_1071f715_caseD_7;
  case 0xa3:
  case 0xc1:
  case 0x118:
  case 0x119:
    goto switchD_1071f715_caseD_6;
  }
}

