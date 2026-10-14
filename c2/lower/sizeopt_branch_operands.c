uint32_t __fastcall sizeopt_branch_operands(void *t,c2_operand *opnd)

{
  c2_tuple *t_00;
  c2_operand *pcVar1;
  ushort uVar2;
  uint32_t uVar3;
  int iVar4;
  
  t_00 = opnd->sym->def;
  if ((((t_00->op == 0x17d) && ((t_00->type & 0xf000) != 0x4000)) &&
      (uVar2 = t_00->type & 0xfff, uVar2 < 5)) &&
     (((pcVar1 = t_00->src, pcVar1 == (c2_operand *)0x0 || ((pcVar1->type & 0xfff) < 5)) &&
      (((pcVar1->type & 0xf000) != 0x4000 && (uVar2 != 1)))))) {
    uVar3 = operand_known_leading_zero_bits(pcVar1);
    if (((0x17 < (int)(uVar3 + (4 - (pcVar1->type & 0xfff)) * 8)) &&
        (pcVar1 = pcVar1->next, uVar3 = operand_known_leading_zero_bits(pcVar1),
        0x17 < (int)(uVar3 + (4 - (pcVar1->type & 0xfff)) * 8))) &&
       ((iVar4 = branch_cc_is_unsigned(t), iVar4 != 0 &&
        (iVar4 = op_supports_width(t_00,1), iVar4 != 0)))) {
      set_op_width(t_00,1);
      return 1;
    }
    pcVar1 = t_00->src;
    iVar4 = operand_fits_signed_byte(pcVar1);
    if ((iVar4 != 0) ||
       (uVar3 = operand_known_leading_zero_bits(pcVar1),
       0x18 < (int)(uVar3 + (4 - (pcVar1->type & 0xfff)) * 8))) {
      pcVar1 = pcVar1->next;
      iVar4 = operand_fits_signed_byte(pcVar1);
      if (((iVar4 != 0) ||
          (uVar3 = operand_known_leading_zero_bits(pcVar1),
          0x18 < (int)(uVar3 + (4 - (pcVar1->type & 0xfff)) * 8))) &&
         (iVar4 = op_supports_width(t_00,1), iVar4 != 0)) {
        set_op_width(t_00,1);
        return 1;
      }
    }
    if ((t_00->type & 0xfff) == 2) {
      if ((t_00->type & 0xf000) == 0x2000) {
        pcVar1 = t_00->src;
        uVar3 = operand_self_def_bits(pcVar1);
        if (0xf < (int)uVar3) {
          pcVar1 = pcVar1->next;
          uVar3 = operand_self_def_bits(pcVar1);
          if ((0xf < (int)uVar3) || ((g_opt_favor_speed != 0 && (pcVar1->kind == '\a')))) {
            set_op_width(t_00,4);
            return 1;
          }
        }
      }
    }
    else {
      pcVar1 = t_00->src;
      uVar3 = operand_known_leading_zero_bits(pcVar1);
      if ((((0xf < (int)(uVar3 + (4 - (pcVar1->type & 0xfff)) * 8)) &&
           (pcVar1 = pcVar1->next, uVar3 = operand_known_leading_zero_bits(pcVar1),
           0xf < (int)(uVar3 + (4 - (pcVar1->type & 0xfff)) * 8))) &&
          (iVar4 = branch_cc_is_unsigned(t), iVar4 != 0)) &&
         (iVar4 = op_supports_width(t_00,2), iVar4 != 0)) {
sizeopt_branch_narrow_compare_to_word:
        set_op_width(t_00,2);
        return 1;
      }
      pcVar1 = t_00->src;
      iVar4 = operand_fits_signed_word(pcVar1);
      if ((iVar4 != 0) ||
         (uVar3 = operand_known_leading_zero_bits(pcVar1),
         0x10 < (int)(uVar3 + (4 - (pcVar1->type & 0xfff)) * 8))) {
        pcVar1 = pcVar1->next;
        iVar4 = operand_fits_signed_word(pcVar1);
        if (((iVar4 != 0) ||
            (uVar3 = operand_known_leading_zero_bits(pcVar1),
            0x10 < (int)(uVar3 + (4 - (pcVar1->type & 0xfff)) * 8))) &&
           (iVar4 = op_supports_width(t_00,2), iVar4 != 0))
        goto sizeopt_branch_narrow_compare_to_word;
      }
    }
  }
  return 0;
}

