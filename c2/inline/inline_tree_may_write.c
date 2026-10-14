int __fastcall inline_tree_may_write(c2_tuple *t,c2_operand *op)

{
  uint8_t uVar1;
  byte bVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  int iVar5;
  
  pcVar3 = op->sym->def;
  uVar1 = pcVar3->kind;
  if ((uVar1 == '\x0e') || (uVar1 == '\x12')) {
    if ((t->kind == '\x0e') || (t->kind == '\x12')) {
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
  pcVar4 = pcVar3->src;
  do {
    if (pcVar4 == (c2_operand *)0x0) {
      return 0;
    }
    bVar2 = pcVar4->kind;
    if (((1 << (bVar2 & 0x1f) & 6U) == 0) || (pcVar4->sym->def == (c2_tuple *)0x0)) {
      if ((bVar2 == 2) || (bVar2 == 6)) {
        iVar5 = inline_tuple_may_write(t,pcVar4);
        goto joined_r0x10752444;
      }
    }
    else {
      iVar5 = inline_tree_may_write(t,pcVar4);
joined_r0x10752444:
      if (iVar5 != 0) {
        return 1;
      }
    }
    pcVar4 = pcVar4->next;
  } while( true );
}

