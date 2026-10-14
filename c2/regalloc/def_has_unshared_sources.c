int __fastcall def_has_unshared_sources(c2_tuple *t)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  int iVar6;
  
  pcVar2 = t->src;
  pcVar5 = pcVar2;
  do {
    if (pcVar5 == (c2_operand *)0x0) {
      for (; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((pcVar2->kind == '\x01') && (((pcVar2->u18).reg)->cls == '\x03')) {
          tuple_unlink_free(pcVar2->sym->def);
        }
      }
      return 1;
    }
    if (((1 << (pcVar5->kind & 0x1f) & 0x7eU) != 0) && ((pcVar5->flags & 0x40) != 0)) {
      return 0;
    }
    if (pcVar5->kind == 1) {
      uVar1 = ((pcVar5->u18).reg)->cls;
      if (uVar1 == '\x01') {
        return 0;
      }
      if (uVar1 == '\x02') {
        iVar6 = tuple_chain_reads_reg(t->prev,pcVar5->sym);
        if (iVar6 == 0) {
          return 0;
        }
      }
      else {
        pcVar3 = pcVar5->sym->def;
        if (pcVar3->dst->next != (c2_operand *)0x0) {
          return 0;
        }
        for (pcVar4 = pcVar3->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (((1 << (pcVar4->kind & 0x1f) & 0x7eU) != 0) && ((pcVar4->flags & 0x40) != 0)) {
            return 0;
          }
          if (pcVar4->kind == 1) {
            if (((pcVar4->u18).reg)->cls != '\x02') {
              return 0;
            }
            iVar6 = tuple_chain_reads_reg(pcVar3->prev,pcVar4->sym);
            if (iVar6 == 0) {
              return 0;
            }
          }
        }
      }
    }
    pcVar5 = pcVar5->next;
  } while( true );
}

