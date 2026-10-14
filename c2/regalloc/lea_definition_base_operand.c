c2_operand * __fastcall lea_definition_base_operand(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  
  pcVar1 = t->src;
  if (pcVar1->op == 0x14c) {
    pcVar1 = pcVar1->base;
    pcVar1->rank = 0;
    return pcVar1;
  }
  if (pcVar1->op == 0x14f) {
    pcVar1 = pcVar1->index;
    pcVar1->rank = 0;
    return pcVar1;
  }
  pcVar2 = pcVar1->base;
  pcVar2->rank = (uint32_t)pcVar1->index;
  return pcVar2;
}

