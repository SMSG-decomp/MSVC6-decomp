void __fastcall lower_int64_truncate(c2_tuple *anchor)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  
  pcVar1 = anchor->src;
  anchor->op = 1;
  if (((pcVar1->kind == '\x01') && (pcVar1->sym->cls == '\x03')) &&
     (pcVar1->sym->def != (c2_tuple *)0x0)) {
    pcVar1 = split_int64_operand_half(anchor,pcVar1,(c2_operand *)0x0,(c2_operand *)0x0);
    if ((((1 << (pcVar1->kind & 0x1f) & 6U) != 0) &&
        (pcVar2 = pcVar1->sym->def, pcVar2 != (c2_tuple *)0x0)) &&
       ((pcVar2->op == 1 && (pcVar2->src->kind == '\a')))) {
      tuple_unlink_free(pcVar2);
      operand_retype(anchor->src,anchor->type,0);
      return;
    }
    pcVar2 = tuple_new_pseudo(0x19e,pcVar1->type);
    tuple_append_src(pcVar2,pcVar1);
    tuple_insert_after(anchor,pcVar2);
  }
  operand_retype(anchor->src,anchor->type,0);
  return;
}

