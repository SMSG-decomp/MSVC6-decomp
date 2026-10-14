uint32_t __fastcall load_op_for_operand(c2_operand *op)

{
  uint8_t uVar1;
  
  if (((op->kind != '\x03') ||
      ((((uVar1 = op->sym->cls, uVar1 != '\x03' && (uVar1 != '\x04')) && (uVar1 != '\x05')) &&
       (uVar1 != '\x06')))) && (op->kind != '\x05')) {
    return 1;
  }
  return 0x12;
}

