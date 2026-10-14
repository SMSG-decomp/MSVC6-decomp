int __cdecl asm_operand_type_allows_size(c1_asm_operand *operand,short type_bit)

{
  c1_symbol *pcVar1;
  c1_type *pcVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  
  iVar3 = 1;
  if (((operand->flags & 1) == 0) && (pcVar1 = operand->expr->sym, pcVar1 != (c1_symbol *)0x0)) {
    pcVar2 = pcVar1->type;
    bVar5 = (byte)pcVar2->code;
    if (type_bit == 0x20) {
      bVar4 = bVar5 >> 5;
    }
    else {
      bVar4 = bVar5 >> 4;
    }
    if ((bVar4 & 1) != 0) {
      while ((char)bVar5 < '\0') {
        pcVar2 = pcVar2->base;
        bVar5 = (byte)pcVar2->code;
      }
      if ('\x01' < (char)(&g_type_rank_table)[(byte)pcVar2->code & 0xf]) {
        return 1;
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}

