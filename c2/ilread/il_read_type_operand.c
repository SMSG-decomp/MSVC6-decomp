void __fastcall il_read_type_operand(c2_reader_op *op)

{
  byte *pbVar1;
  ushort uVar2;
  undefined2 extraout_var;
  uint size;
  uint uVar3;
  byte bVar4;
  
  uVar2 = il_read_type();
  bVar4 = (byte)uVar2 & 0xf;
  if (((uVar2 & 0x1000) != 0) && (((&g_il_op_attr_high)[op->op * 2] & 4) != 0)) {
    pbVar1 = (byte *)((int)&op->qualifiers + 1);
    *pbVar1 = *pbVar1 | 8;
  }
  size = CONCAT22(extraout_var,uVar2) >> 4 & 0x1f;
  if ((bVar4 == 6) && (size == 0)) {
    size = il_read_long();
  }
  if (op->op != 0x27) {
    uVar3 = il_type_to_c2_type((short)(char)bVar4,size);
    op->type = (uint16_t)uVar3;
    if ((uVar3 & 0xf000) == 0x5000) {
      op->size = size;
    }
  }
  return;
}

