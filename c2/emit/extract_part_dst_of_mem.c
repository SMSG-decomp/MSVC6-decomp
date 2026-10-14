c2_operand * __fastcall extract_part_dst_of_mem(c2_tuple *t,c2_operand *mem,int *reg)

{
  c2_operand *pcVar1;
  
  if ((mem->base != (c2_operand *)0x0) &&
     (pcVar1 = extract_part_dst_of(t,mem->base,reg), pcVar1 != (c2_operand *)0x0)) {
    return pcVar1;
  }
  pcVar1 = (c2_operand *)0x0;
  if (mem->index != (c2_operand *)0x0) {
    pcVar1 = extract_part_dst_of(t,mem->index,reg);
  }
  return pcVar1;
}

