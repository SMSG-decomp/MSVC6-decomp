void __fastcall x87_add_implicit_stack_operands(c2_tuple *t)

{
  uint uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  
  pcVar3 = t->dst;
  switch(t->op) {
  case 0x62:
  case 99:
    if (((pcVar3->kind == '\x01') && ((pcVar3->type & 0xf000) == 0x4000)) &&
       (uVar1 = ((pcVar3->u18).reg)->id, 0x1f < uVar1)) {
      pcVar2 = t->src;
      while( true ) {
        if (pcVar2 == (c2_operand *)0x0) {
          pcVar3 = (c2_operand *)node_clone((c2_node *)pcVar3);
          tuple_append_src(t,pcVar3);
          return;
        }
        if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->id == uVar1)) break;
        pcVar2 = pcVar2->next;
      }
    }
    break;
  case 0x86:
  case 0x91:
  case 0x92:
    if (pcVar3->kind != '\x01') {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0xfbb);
    }
    if (t->src->kind != '\x01') {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0xfbc);
    }
    pcVar2 = t->src->next;
    if ((pcVar2 == (c2_operand *)0x0) || (pcVar2->kind != '\x01')) {
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\MDmisc.c",0xfbd);
    }
    if (pcVar3->next == (c2_operand *)0x0) {
      pcVar2 = operand_new_hardreg(0x1f,pcVar3->type);
      tuple_append_dst(t,pcVar2);
    }
    (pcVar3->u18).reg = g_reg_symbols + 0x20;
    (pcVar3->next->u18).reg = (c2_symbol *)0x107ad15c;
    pcVar3 = t->src;
    if (((pcVar3->u18).reg)->id == 0x1f) {
      pcVar2 = pcVar3->next;
      t->src = pcVar2;
      pcVar2->next = pcVar3;
      pcVar2->next->next = (c2_operand *)0x0;
      return;
    }
    break;
  case 0x87:
  case 0x8a:
  case 0xd4:
    if (t->src->next == (c2_operand *)0x0) {
      pcVar3 = operand_new_hardreg(0x20,pcVar3->type);
      tuple_append_src(t,pcVar3);
    }
  }
  return;
}

