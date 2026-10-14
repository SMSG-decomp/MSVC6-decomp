int __fastcall iv_operand_is_variable(c2_operand *op)

{
  uint8_t uVar1;
  uint8_t uVar2;
  ushort uVar3;
  
  uVar1 = op->kind;
  if (uVar1 == '\a') {
    return 0;
  }
  if ((uVar1 == '\x03') && ((uVar2 = op->sym->cls, uVar2 == '\a' || (uVar2 == '\b')))) {
    return 0;
  }
  if ((uVar1 == '\x02') &&
     ((uVar3 = (op->sym->u30).globopt.marks, (uVar3 & 2) != 0 && ((uVar3 & 4) == 0)))) {
    return 0;
  }
  return 1;
}

