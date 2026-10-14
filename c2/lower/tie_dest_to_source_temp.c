void __fastcall tie_dest_to_source_temp(c2_tuple *t)

{
  c2_tuple *t_00;
  c2_operand_u18 cVar1;
  c2_operand *pcVar2;
  c2_operand *local_4;
  
  pcVar2 = t->dst;
  local_4 = (c2_operand *)t;
  local_4 = get_tied_source_operand(t);
  if (local_4 != (c2_operand *)0x0) {
    if (((local_4->u18).reg)->cls == '\x01') {
      cVar1 = t->src->u18;
      find_next_use_of_dst(t,&local_4);
      pcVar2 = (c2_operand *)0x0;
    }
    else {
      cVar1 = t->dst->u18;
    }
    while( true ) {
      if ((((pcVar2 != (c2_operand *)0x0) && (pcVar2->kind == '\x01')) &&
          (pcVar2->sym->cls == '\x03')) && (pcVar2->sym->def != (c2_tuple *)0x0)) {
        pcVar2->u18 = cVar1;
      }
      if (((local_4 == (c2_operand *)0x0) || (local_4->kind != '\x01')) ||
         ((local_4->sym->cls != '\x03' || (local_4->sym->def == (c2_tuple *)0x0)))) break;
      local_4->u18 = cVar1;
      t_00 = local_4->sym->def;
      pcVar2 = t_00->dst;
      local_4 = get_tied_source_operand(t_00);
    }
  }
  return;
}

