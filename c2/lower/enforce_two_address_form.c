void __fastcall enforce_two_address_form(c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  c2_operand_u18 cVar3;
  c2_operand *pcVar4;
  
  pcVar4 = t->dst;
  if (((pcVar4->kind == '\x01') && (pcVar4->sym->cls == '\x03')) &&
     (pcVar4->sym->def != (c2_tuple *)0x0)) {
    pcVar4 = t->dst;
    pcVar2 = get_tied_source_operand(t);
    if (pcVar2 != (c2_operand *)0x0) {
      if (((pcVar2->u18).reg)->cls == '\x01') {
        cVar3 = t->src->u18;
        find_next_use_of_dst(t,(c2_operand **)&stack0xfffffffc);
        pcVar4 = (c2_operand *)0x0;
      }
      else {
        cVar3 = t->dst->u18;
      }
      while( true ) {
        if (((pcVar4 != (c2_operand *)0x0) && (pcVar4->kind == '\x01')) &&
           ((pcVar4->sym->cls == '\x03' && (pcVar4->sym->def != (c2_tuple *)0x0)))) {
          pcVar4->u18 = cVar3;
        }
        if (((pcVar2 == (c2_operand *)0x0) || (pcVar2->kind != '\x01')) ||
           ((pcVar2->sym->cls != '\x03' || (pcVar2->sym->def == (c2_tuple *)0x0)))) break;
        pcVar2->u18 = cVar3;
        pcVar1 = pcVar2->sym->def;
        pcVar4 = pcVar1->dst;
        pcVar2 = get_tied_source_operand(pcVar1);
      }
    }
    return;
  }
  pcVar2 = get_tied_source_operand(t);
  pcVar1 = pcVar2->sym->def;
  tuple_replace_src(t,pcVar2,pcVar4);
  pcVar2 = pcVar1->dst;
  pcVar4 = (c2_operand *)node_clone((c2_node *)pcVar4);
  pcVar4 = operand_set_type(pcVar4,pcVar2->type);
  tuple_replace_dst(pcVar1,pcVar2,pcVar4);
  return;
}

