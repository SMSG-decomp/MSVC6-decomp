void __fastcall rewrite_index_times_two_as_base(c2_tuple *t,c2_operand *old)

{
  byte bVar1;
  c2_operand *pcVar2;
  
  if (((old->op == 0x14f) && (bVar1 = old->flags, (bVar1 & 0xf) == 1)) &&
     (old->base_sym == (c2_symbol *)0x0)) {
    pcVar2 = old->index;
    if (old->kind == '\x05') {
      pcVar2 = operand_new_addr(0x14d,old->type,(c2_symbol *)0x0,old->disp,pcVar2,pcVar2);
    }
    else {
      pcVar2 = operand_new_mem(0x14d,old->type,(c2_symbol *)0x0,old->disp,pcVar2,pcVar2,old->tag);
    }
    pcVar2->flags = (pcVar2->flags ^ bVar1) & 0x40 ^ pcVar2->flags;
    tuple_replace_src(t,old,pcVar2);
  }
  return;
}

