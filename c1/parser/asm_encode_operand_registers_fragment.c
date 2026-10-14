void asm_encode_operand_registers_fragment(c1_u8 base,int operand_number,c1_asm_operand *operand)

{
  byte bVar1;
  c1_asm_expr *pcVar2;
  c1_asm_operand *pcVar3;
  c1_asm_operand *operand_00;
  
  asm_report_operand_error(0x1a5,operand_number);
  while( true ) {
    pcVar2 = operand->expr;
    if (pcVar2->index == base) {
      if ((pcVar2->seg_scale & 0xc0) == 0) {
        if (pcVar2->base == base) {
          asm_report_operand_error(0x1af,operand_number);
        }
        else {
          pcVar2->index = pcVar2->base;
          operand->expr->base = base;
        }
      }
      else {
        asm_report_operand_error(0x1af,operand_number);
      }
    }
    bVar1 = operand->expr->seg_scale;
    operand->expr->seg_scale =
         ((&g_asm_register_classes)[(bVar1 & 0x3f) * 2] ^ bVar1) & 0x3f ^ bVar1;
    operand->expr->index = (&g_asm_register_classes)[(uint)operand->expr->index * 2];
    pcVar2 = operand->expr;
    bVar1 = pcVar2->base;
    if ((pcVar2->kind & 0x20) == 0x20) {
      pcVar2->base = bVar1 + 0x28;
    }
    else if (bVar1 == 0) {
      if ((pcVar2->seg_scale & 0xc0) == 0) {
        pcVar2->base = pcVar2->index;
        operand->expr->index = '?';
      }
      else {
        pcVar2->base = '?';
      }
    }
    else if ((*(ushort *)(&g_asm_register_classes + (uint)bVar1 * 2) & 0x80c0) == 0x8080) {
      pcVar2->base = (&g_asm_register_classes)[(uint)bVar1 * 2] + '(';
    }
    else {
      pcVar2->base = (&g_asm_register_classes)[(uint)bVar1 * 2];
    }
    operand_number = operand_number + 1;
    operand_00 = operand + 1;
    if (g_asm_operand_index <= operand_number) break;
    pcVar3 = operand + 1;
    operand = operand_00;
    if (((pcVar3->flags & 1) != 0) &&
       (g_asm_kind_class[g_asm_kind_index[operand_00->expr->kind & 0x1f]] == 1)) {
      asm_encode_operand_registers_fragment(base,operand_number,operand_00);
      return;
    }
  }
  return;
}

