c2_operand * __fastcall operand_new_labelref(c2_tuple *label,int delta)

{
  c2_symbol *pcVar1;
  c2_operand *pcVar2;
  
  pcVar2 = (c2_operand *)node_alloc('\x04');
  pcVar1 = (c2_symbol *)label->src;
  pcVar2->op = 0x154;
  pcVar2->sym = pcVar1;
  *(int *)((int)&pcVar1->u38 + 2) = *(int *)((int)&pcVar1->u38 + 2) + delta;
  return pcVar2;
}

