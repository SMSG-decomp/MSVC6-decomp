int __fastcall inline_range_has_call_or_memory(c2_tuple *first,c2_tuple *end)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  
  pcVar2 = first->next;
  do {
    if (pcVar2 == end) {
      return 0;
    }
    if ((pcVar2->flags & 1) != 0) {
      if (pcVar2->kind == '\x0e') {
        return 1;
      }
      if (pcVar2->kind == '\x12') {
        return 1;
      }
      iVar4 = 0;
      do {
        if (iVar4 == 0) {
          pcVar3 = pcVar2->dst;
        }
        else {
          pcVar3 = pcVar2->src;
        }
        for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          if (pcVar3->kind == '\x02') {
            if ((pcVar3->sym->flags5 & 2) != 0) {
              return 1;
            }
            uVar1 = pcVar3->sym->cls;
            if ((((uVar1 != '\x03') && (uVar1 != '\x04')) && (uVar1 != '\x05')) && (uVar1 != '\x06')
               ) {
              return 1;
            }
          }
          else if (pcVar3->kind == '\x06') {
            return 1;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 2);
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

