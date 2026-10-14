uint32_t * __fastcall get_byte_masked_source(c2_operand *opnd)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  
  bVar1 = opnd->kind;
  if ((((bVar1 == 1) && (opnd->sym->cls == '\x03')) &&
      (pcVar2 = opnd->sym->def, pcVar2 != (c2_tuple *)0x0)) && (pcVar2->op == 0x172)) {
    pcVar3 = pcVar2->src;
    iVar4 = operand_is_const_value(pcVar3->next,0xff);
    if (iVar4 != 0) {
      return (uint32_t *)pcVar3;
    }
  }
  if (((opnd->type & 0xfff) < 2) && (bVar1 != 0)) {
    if (bVar1 < 3) {
      return (uint32_t *)(~-(uint)(opnd->sym->offset != 0) & (uint)opnd);
    }
    if (bVar1 == 6) {
      return (uint32_t *)opnd;
    }
  }
  return (uint32_t *)0x0;
}

