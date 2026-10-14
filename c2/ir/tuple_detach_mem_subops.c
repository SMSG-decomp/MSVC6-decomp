void __fastcall tuple_detach_mem_subops(c2_node *node,c2_operand *op)

{
  c2_operand *pcVar1;
  
  pcVar1 = op->base;
  if ((pcVar1 != (c2_operand *)0x0) && ((op->flags11 & 0x20) == 0)) {
    pcVar1->flags = pcVar1->flags & 0xdf;
    tuple_detach_src(node,pcVar1);
    pcVar1->flags = pcVar1->flags | 0x30;
  }
  pcVar1 = op->index;
  if ((pcVar1 != (c2_operand *)0x0) && ((op->flags11 & 0x20) == 0)) {
    pcVar1->flags = pcVar1->flags & 0xdf;
    tuple_detach_src(node,pcVar1);
    pcVar1->flags = pcVar1->flags | 0x30;
  }
  return;
}

