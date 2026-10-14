void __fastcall mark_inline_asm_operand_symbols(c2_tuple *tuples)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  
  do {
    if (tuples == (c2_tuple *)0x0) {
      return;
    }
    if ((tuples->flags & 1) != 0) {
      for (pcVar2 = tuples->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        uVar1 = pcVar2->kind;
        if (uVar1 == '\x02') {
          for (pcVar3 = pcVar2->sym->storage; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next
              ) {
            pcVar3->flags6 = pcVar3->flags6 | 0x10;
          }
        }
        else {
          if (uVar1 == '\x03') {
            pcVar3 = pcVar2->sym;
          }
          else {
            if (uVar1 != '\x05') goto LAB_1078b48b;
            pcVar3 = pcVar2->base_sym;
          }
          if (pcVar3 != (c2_symbol *)0x0) {
            for (pcVar3 = pcVar3->storage; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next) {
              pcVar3->flags5 = pcVar3->flags5 | 6;
            }
          }
        }
LAB_1078b48b:
      }
      for (pcVar2 = tuples->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (pcVar2->kind == '\x02') {
          pcVar3 = pcVar2->sym;
LAB_1078b4a9:
          if (pcVar3 != (c2_symbol *)0x0) {
            for (pcVar3 = pcVar3->storage; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next) {
              pcVar3->flags5 = pcVar3->flags5 | 2;
            }
          }
        }
        else if (pcVar2->kind == '\x06') {
          pcVar3 = pcVar2->base_sym;
          goto LAB_1078b4a9;
        }
      }
    }
    tuples = tuples->next;
  } while( true );
}

