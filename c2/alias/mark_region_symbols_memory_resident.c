void __fastcall
mark_region_symbols_memory_resident
          (c2_tuple *first,c2_tuple *end,int mark_destinations,int mark_address_sources)

{
  c2_operand *pcVar1;
  int iVar2;
  c2_symbol *pcVar3;
  
  iVar2 = g_opt_eh_enabled;
  do {
    if (first == end) {
      return;
    }
    if ((first->flags & 1) != 0) {
      if (mark_address_sources != 0) {
        for (pcVar1 = first->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
          if (pcVar1->kind == '\x03') {
            pcVar3 = pcVar1->sym;
LAB_10753ee8:
            if ((pcVar3 != (c2_symbol *)0x0) && (pcVar3->cls != '\x03')) {
              for (pcVar3 = pcVar3->storage; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next)
              {
                pcVar3->flags5 = pcVar3->flags5 | 2;
                if (iVar2 == 0) {
                  pcVar3->flags6 = pcVar3->flags6 | 1;
                }
              }
            }
          }
          else if (pcVar1->kind == '\x05') {
            pcVar3 = pcVar1->base_sym;
            goto LAB_10753ee8;
          }
        }
      }
      if (mark_destinations != 0) {
        for (pcVar1 = first->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
          if (pcVar1->kind == '\x02') {
            pcVar3 = pcVar1->sym;
LAB_10753f0f:
            if ((pcVar3 != (c2_symbol *)0x0) && (pcVar3->cls != '\x03')) {
              for (pcVar3 = pcVar3->storage; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next)
              {
                pcVar3->flags5 = pcVar3->flags5 | 2;
              }
            }
          }
          else if (pcVar1->kind == '\x06') {
            pcVar3 = pcVar1->base_sym;
            goto LAB_10753f0f;
          }
        }
      }
    }
    first = first->next;
  } while( true );
}

