void __fastcall
alias_collect_symbols_in_range
          (c2_tuple *first,c2_tuple *end,int collect_writes,int collect_reads,
          c2_alias_memeffect *rec)

{
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_symbol_cell *pcVar3;
  
  do {
    if (first == end) {
      return;
    }
    if ((first->flags & 1) != 0) {
      if (collect_reads != 0) {
        for (pcVar1 = first->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
          switch(pcVar1->kind) {
          case '\x02':
          case '\x03':
            pcVar2 = pcVar1->sym;
            break;
          default:
            goto switchD_10753f75_caseD_4;
          case '\x05':
          case '\x06':
            pcVar2 = pcVar1->base_sym;
          }
          if ((pcVar2 != (c2_symbol *)0x0) && (pcVar2->cls != '\x03')) {
            pcVar3 = symbol_list_add_unique(rec->read,pcVar2->storage,1);
            rec->read = pcVar3;
          }
switchD_10753f75_caseD_4:
        }
      }
      if (collect_writes != 0) {
        for (pcVar1 = first->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
          if (pcVar1->kind == '\x02') {
            pcVar2 = pcVar1->sym;
LAB_10753fcb:
            if ((pcVar2 != (c2_symbol *)0x0) && (pcVar2->cls != '\x03')) {
              pcVar3 = symbol_list_add_unique(rec->written,pcVar2->storage,1);
              rec->written = pcVar3;
            }
          }
          else if (pcVar1->kind == '\x06') {
            pcVar2 = pcVar1->base_sym;
            goto LAB_10753fcb;
          }
        }
      }
    }
    first = first->next;
  } while( true );
}

