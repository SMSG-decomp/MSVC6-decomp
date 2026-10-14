int __fastcall memory_operand_field_range(c2_operand *mem,int32_t *out_offset,uint32_t *out_size)

{
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  
  pcVar1 = mem->base->sym;
  pcVar2 = pcVar1->def;
  if (pcVar2 == (c2_tuple *)0x0) {
    if ((pcVar1->flags5 & 8) == 0) {
      return 0;
    }
    *out_offset = mem->disp;
  }
  else {
    uVar3 = pcVar2->op;
    if ((uVar3 != 0x16d) && (uVar3 != 0x16e)) {
      return 0;
    }
    pcVar4 = pcVar2->src;
    if (((pcVar4->kind != '\x02') || (pcVar4->sym->def != (c2_tuple *)0x0)) ||
       (pcVar4->next->kind != '\a')) {
      return 0;
    }
    if ((pcVar4->sym->flags5 & 8) == 0) {
      return 0;
    }
    uVar5 = (pcVar4->next->u18).lo;
    *out_offset = uVar5;
    if (uVar3 == 0x16e) {
      *out_offset = -uVar5;
    }
    *out_offset = *out_offset + mem->disp;
  }
  *out_size = mem->type & 0xfff;
  return 1;
}

