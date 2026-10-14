void __fastcall seh_rebase_record_parts(c2_function *fn,c2_symbol *rec,c2_symbol *old)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  int iVar3;
  c2_symbol *pcVar4;
  c2_symbol *pcVar5;
  uint32_t size;
  ushort type;
  
  pcVar4 = old;
  pcVar1 = fn->cfg->first->head;
  do {
    if (pcVar1 == (c2_tuple *)0x0) {
      return;
    }
    if ((pcVar1->flags & 1) != 0) {
      old = (c2_symbol *)0x0;
      do {
        if (old == (c2_symbol *)0x0) {
          pcVar2 = pcVar1->dst;
        }
        else {
          pcVar2 = pcVar1->src;
        }
        for (; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
          if (pcVar2->kind == '\x02') {
            if (pcVar2->sym->storage == pcVar4) {
              type = pcVar2->type;
              iVar3 = pcVar2->sym->offset;
              size = type & 0xfff;
LAB_107958a2:
              pcVar5 = symbol_get_part(rec,type,size,iVar3 + 0xc);
              pcVar2->sym = pcVar5;
            }
          }
          else if ((pcVar2->kind == '\x03') && (pcVar5 = pcVar2->sym, pcVar5->storage == pcVar4)) {
            iVar3 = pcVar5->offset;
            size = pcVar5->size;
            type = pcVar5->type;
            goto LAB_107958a2;
          }
        }
        old = (c2_symbol *)((int)&old->fe + 1);
      } while ((int)old < 2);
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

