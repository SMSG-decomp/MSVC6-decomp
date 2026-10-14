void __cdecl asm_encode_operand_registers(void)

{
  byte bVar1;
  c1_asm_expr *pcVar2;
  c1_asm_operand *operand;
  int operand_number;
  
  operand_number = 0;
  if (0 < g_asm_operand_index) {
    operand = g_asm_operands;
    do {
      if (((operand->flags & 1) != 0) &&
         (g_asm_kind_class[g_asm_kind_index[operand->expr->kind & 0x1f]] == 1)) {
        asm_encode_operand_registers_fragment('\x05',operand_number,operand);
        return;
      }
      pcVar2 = operand->expr;
      if (pcVar2->index == '\x05') {
        if ((pcVar2->seg_scale & 0xc0) == 0) {
          if (pcVar2->base == '\x05') {
            asm_report_operand_error(0x1af,operand_number);
          }
          else {
            pcVar2->index = pcVar2->base;
            operand->expr->base = '\x05';
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
      operand = operand + 1;
    } while (operand_number < g_asm_operand_index);
  }
  return;
}

