int __fastcall inline_tuple_may_write(c2_tuple *t,c2_operand *op)

{
  uint8_t uVar1;
  c2_symbol *pcVar2;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  
  if (op->kind == '\x02') {
    pcVar2 = op->sym;
    if (((t->kind == '\x0e') || (t->kind == '\x12')) &&
       (((pcVar2->flags5 & 2) != 0 ||
        (((uVar1 = pcVar2->cls, uVar1 != '\x03' && (uVar1 != '\x04')) &&
         ((uVar1 != '\x05' && (uVar1 != '\x06')))))))) {
      return 1;
    }
    pcVar4 = t->dst;
    if (pcVar4 != (c2_operand *)0x0) {
      do {
        if (pcVar4->kind == '\x02') {
          pcVar3 = pcVar4->sym;
          if (pcVar3->storage == pcVar2->storage) {
            if (pcVar3 == pcVar2) {
              return 1;
            }
            if ((pcVar3->offset < pcVar2->size + pcVar2->offset) &&
               (pcVar2->offset < pcVar3->size + pcVar3->offset)) {
              return 1;
            }
          }
        }
        else if (pcVar4->kind == '\x06') {
          if ((pcVar2->flags5 & 2) != 0) {
            return 1;
          }
          uVar1 = pcVar2->cls;
          if ((((uVar1 != '\x03') && (uVar1 != '\x04')) && (uVar1 != '\x05')) && (uVar1 != '\x06'))
          {
            return 1;
          }
        }
        pcVar4 = pcVar4->next;
        if (pcVar4 == (c2_operand *)0x0) {
          return 0;
        }
      } while( true );
    }
  }
  else {
    if (t->kind == '\x0e') {
      return 1;
    }
    if (t->kind == '\x12') {
      return 1;
    }
    for (pcVar4 = t->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
      if (pcVar4->kind == '\x02') {
        if ((pcVar4->sym->flags5 & 2) != 0) {
          return 1;
        }
        uVar1 = pcVar4->sym->cls;
        if ((((uVar1 != '\x03') && (uVar1 != '\x04')) && (uVar1 != '\x05')) && (uVar1 != '\x06')) {
          return 1;
        }
      }
      else if (pcVar4->kind == '\x06') {
        return 1;
      }
    }
  }
  return 0;
}

