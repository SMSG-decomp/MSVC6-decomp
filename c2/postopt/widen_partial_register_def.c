void __fastcall widen_partial_register_def(c2_tuple *t,c2_symbol *reg)

{
  ushort uVar1;
  c2_operand *pcVar2;
  int iVar3;
  c2_operand *pcVar4;
  c2_operand *dst;
  c2_tuple *pcVar5;
  uint32_t uVar6;
  c2_symbol *reg_00;
  c2_insert_fn *insert_fn;
  
  if (((t->dst != (c2_operand *)0x0) && (pcVar2 = t->dst->next, pcVar2 != (c2_operand *)0x0)) &&
     (pcVar2->type != 0x8000)) {
    return;
  }
  if (reg == (c2_symbol *)0x0) goto LAB_10775e78;
  pcVar2 = find_src_overlapping_reg(t,reg);
  if (((pcVar2 != (c2_operand *)0x0) || (t->op == 1)) &&
     ((iVar3 = flags_last_set_by_temp_def(t), iVar3 == 0 &&
      ((iVar3 = is_redundant_zero_move(t), iVar3 == 0 &&
       (iVar3 = is_redundant_zero_move(t->prev), iVar3 == 0)))))) {
    if (pcVar2 == (c2_operand *)0x0) {
      if ((t->op != 1) || (pcVar2 = find_dst_clobbering_reg(t,reg), pcVar2 == (c2_operand *)0x0))
      goto LAB_10775e78;
      uVar6 = reg->id;
      insert_fn = tuple_insert_before;
      pcVar5 = t;
      pcVar2 = operand_new_hardreg(uVar6,g_reg_symbols[uVar6].type);
      pcVar4 = operand_new_hardreg(uVar6,g_reg_symbols[uVar6].type);
      dst = operand_new_hardreg(uVar6,g_reg_symbols[uVar6].type);
      pcVar5 = tuple_new_binary(0x34,g_reg_symbols[uVar6].type,dst,pcVar4,pcVar2,insert_fn,pcVar5);
      set_flags_effects(pcVar5);
    }
    else {
      if (pcVar2->kind != '\x01') goto LAB_10775e78;
      if (((((pcVar2->sym->cls == '\x03') && (pcVar2->sym->def != (c2_tuple *)0x0)) && (t->op == 1))
          && ((pcVar4 = t->src, pcVar4->next == (c2_operand *)0x0 && ((t->type & 0xfff) != 4)))) &&
         ((pcVar4->kind != '\x01' || ((pcVar4->u18).reg != (t->dst->u18).reg)))) {
        uVar1 = pcVar4->type;
        if ((uVar1 & 0xf000) == 0x2000) {
          uVar6 = ((uVar1 & 0xfff) != 1) + 0xc2;
        }
        else {
          uVar6 = ((uVar1 & 0xfff) != 1) + 0xc4;
        }
        uVar1 = t->type & 0xf004;
        t->type = uVar1 | 4;
        t->op = uVar6;
        operand_retype(t->dst,uVar1 | 4,0);
      }
      else if ((pcVar2->sym->cls != '\x03') || (pcVar2->sym->def != (c2_tuple *)0x0))
      goto LAB_10775e78;
    }
  }
  reg = (c2_symbol *)0x0;
LAB_10775e78:
  pcVar2 = t->src;
joined_r0x10775e7d:
  pcVar4 = pcVar2;
  if (pcVar4 == (c2_operand *)0x0) {
    return;
  }
  pcVar2 = pcVar4->next;
  if (((1 << (pcVar4->kind & 0x1f) & 6U) == 0) ||
     (pcVar5 = pcVar4->sym->def, pcVar5 == (c2_tuple *)0x0)) goto LAB_10775ed7;
  uVar1 = pcVar4->type & 0xfff;
  reg_00 = reg;
  if (((pcVar5->dst->type & 0xfff) < uVar1) && (uVar1 == 4)) {
    reg_00 = ((pcVar4->u18).reg)->storage;
  }
  goto LAB_10775ec2;
LAB_10775ed7:
  if (((pcVar4->kind == 1) &&
      (((pcVar4->sym->cls == '\x03' && (pcVar4->sym->def == (c2_tuple *)0x0)) &&
       (pcVar5 = find_recent_single_def_of(t,pcVar4), pcVar5 != (c2_tuple *)0x0)))) &&
     ((uVar1 = pcVar4->type & 0xfff, (pcVar5->type & 0xfff) < uVar1 && (uVar1 == 4)))) {
    reg_00 = ((pcVar4->u18).reg)->storage;
LAB_10775ec2:
    widen_partial_register_def(pcVar5,reg_00);
  }
  goto joined_r0x10775e7d;
}

