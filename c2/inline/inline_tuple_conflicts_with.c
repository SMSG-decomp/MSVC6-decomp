int __fastcall inline_tuple_conflicts_with(c2_tuple *t,c2_operand *op)

{
  uint8_t uVar1;
  c2_symbol *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  
  if (op->kind == '\x02') {
    pcVar2 = op->sym;
    if (((t->kind != '\x0e') && (t->kind != '\x12')) ||
       (((pcVar2->flags5 & 2) == 0 &&
        (((uVar1 = pcVar2->cls, uVar1 == '\x03' || (uVar1 == '\x04')) ||
         ((uVar1 == '\x05' || (uVar1 == '\x06')))))))) {
      iVar5 = 0;
      do {
        if (iVar5 == 0) {
          pcVar3 = t->dst;
        }
        else {
          pcVar3 = t->src;
        }
        for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          if (pcVar3->kind == '\x02') {
            pcVar4 = pcVar3->sym;
            if (pcVar4->storage == pcVar2->storage) {
              if (pcVar4 == pcVar2) {
                return 1;
              }
              if ((pcVar4->offset < pcVar2->size + pcVar2->offset) &&
                 (pcVar2->offset < pcVar4->size + pcVar4->offset)) {
                return 1;
              }
            }
          }
          else if (pcVar3->kind == '\x06') {
            if ((pcVar2->flags5 & 2) != 0) {
              return 1;
            }
            uVar1 = pcVar2->cls;
            if ((((uVar1 != '\x03') && (uVar1 != '\x04')) && (uVar1 != '\x05')) && (uVar1 != '\x06')
               ) {
              return 1;
            }
          }
        }
        iVar5 = iVar5 + 1;
        if (1 < iVar5) {
          return 0;
        }
      } while( true );
    }
  }
  else if ((t->kind != '\x0e') && (t->kind != '\x12')) {
    iVar5 = 0;
    do {
      if (iVar5 == 0) {
        pcVar3 = t->dst;
      }
      else {
        pcVar3 = t->src;
      }
      for (; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
        if (pcVar3->kind == '\x02') {
          if ((pcVar3->sym->flags5 & 2) != 0) {
            return 1;
          }
          uVar1 = pcVar3->sym->cls;
          if ((((uVar1 != '\x03') && (uVar1 != '\x04')) && (uVar1 != '\x05')) && (uVar1 != '\x06'))
          {
            return 1;
          }
        }
        else if (pcVar3->kind == '\x06') {
          return 1;
        }
      }
      iVar5 = iVar5 + 1;
      if (1 < iVar5) {
        return 0;
      }
    } while( true );
  }
  return 1;
}

