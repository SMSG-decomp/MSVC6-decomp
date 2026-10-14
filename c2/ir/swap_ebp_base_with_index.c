void __fastcall swap_ebp_base_with_index(c2_tuple *t,c2_operand *old,int is_source)

{
  byte bVar1;
  c2_operand *pcVar2;
  
  if (((old->op == 0x14d) && (pcVar2 = old->base, (pcVar2->u18).reg == g_reg_symbols + 6)) &&
     (bVar1 = old->flags, (bVar1 & 0xf) == 0)) {
    if (old->kind == '\x05') {
      pcVar2 = operand_new_addr(0x14d,old->type,old->base_sym,old->disp,old->index,pcVar2);
    }
    else {
      pcVar2 = operand_new_mem(0x14d,old->type,old->base_sym,old->disp,old->index,pcVar2,old->tag);
    }
    pcVar2->flags = (pcVar2->flags ^ bVar1) & 0x40 ^ pcVar2->flags;
    if (is_source != 0) {
      tuple_replace_src(t,old,pcVar2);
      return;
    }
    tuple_replace_dst(t,old,pcVar2);
  }
  return;
}

