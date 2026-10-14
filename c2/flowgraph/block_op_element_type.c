uint16_t __fastcall block_op_element_type(c2_tuple *t,uint32_t *is_flag8)

{
  uint16_t uVar1;
  c2_operand *pcVar2;
  
  pcVar2 = t->src;
  uVar1 = 0x6000;
  if (pcVar2 != (c2_operand *)0x0) {
    while (pcVar2->kind != '\a') {
      pcVar2 = pcVar2->next;
      if (pcVar2 == (c2_operand *)0x0) {
        return 0x6000;
      }
    }
    uVar1 = *(uint16_t *)&pcVar2->u18;
    *is_flag8 = (pcVar2->flags11 & 8) >> 3;
  }
  return uVar1;
}

