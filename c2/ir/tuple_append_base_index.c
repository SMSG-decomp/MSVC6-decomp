void __fastcall tuple_append_base_index(c2_tuple *t,c2_operand *mem)

{
  c2_operand *pcVar1;
  
  pcVar1 = mem->base;
  if (pcVar1 != (c2_operand *)0x0) {
    pcVar1->flags = pcVar1->flags & 0xef;
    tuple_append_src(t,pcVar1);
  }
  pcVar1 = mem->index;
  if (pcVar1 != (c2_operand *)0x0) {
    pcVar1->flags = pcVar1->flags & 0xef;
    tuple_append_src(t,pcVar1);
  }
  return;
}

