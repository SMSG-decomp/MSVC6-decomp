int __fastcall warn_uninit_path_initialises(c2_function *fn,c2_block *b,int idx)

{
  byte bVar1;
  c2_symbol *pcVar2;
  c2_bitvec *v;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  int iVar6;
  c2_block *pcVar7;
  
  pcVar2 = g_uninit_local_symbols[idx];
  pcVar7 = fn->cfg->first;
  if (pcVar7 != (c2_block *)0x0) {
    v = (c2_bitvec *)b->x64;
    do {
      iVar6 = bitvec_test(v,(int)pcVar7->rpo);
      if ((iVar6 != 0) && (iVar6 = bitvec_test(pcVar7->dominators,(int)b->rpo), iVar6 == 0)) {
        for (pcVar3 = pcVar7->head->next; pcVar3 != pcVar7->end; pcVar3 = pcVar3->next) {
          if (((pcVar3->flags & 1) != 0) && (bVar1 = pcVar3->flags13, bVar1 != 0)) {
            if ((bVar1 & 8) != 0) {
              return 1;
            }
            if ((bVar1 & 2) == 0) {
              if ((bVar1 & 4) == 0) {
                for (pcVar4 = pcVar3->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
                  if (((pcVar4->kind == '\x02') &&
                      (pcVar5 = pcVar4->sym, (pcVar5->u30).order_prev != (c2_symbol *)0x0)) &&
                     (pcVar5->storage == pcVar2->storage)) {
                    if (pcVar5 == pcVar2) {
                      return 1;
                    }
                    if ((pcVar5->offset < pcVar2->size + pcVar2->offset) &&
                       (pcVar2->offset < pcVar5->size + pcVar5->offset)) {
                      return 1;
                    }
                  }
                }
              }
              else {
                pcVar5 = ((pcVar3->u20).eh_try)->catch_rec->object->storage_sym;
                if (pcVar5->storage == pcVar2->storage) {
                  if (pcVar5 == pcVar2) {
                    return 1;
                  }
                  if ((pcVar5->offset < pcVar2->size + pcVar2->offset) &&
                     (pcVar2->offset < pcVar5->size + pcVar5->offset)) {
                    return 1;
                  }
                }
              }
            }
            else {
              for (pcVar4 = pcVar3->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
                if (((pcVar4->kind == '\x03') &&
                    (pcVar5 = pcVar4->sym, (pcVar5->u30).order_prev != (c2_symbol *)0x0)) &&
                   (pcVar5->storage == pcVar2->storage)) {
                  if (pcVar5 == pcVar2) {
                    return 1;
                  }
                  if ((pcVar5->offset < pcVar2->size + pcVar2->offset) &&
                     (pcVar2->offset < pcVar5->size + pcVar5->offset)) {
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
      pcVar7 = pcVar7->next;
    } while (pcVar7 != (c2_block *)0x0);
  }
  return 0;
}

