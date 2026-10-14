int __fastcall warn_uninit_scan_block(c2_function *fn,c2_block *b,int idx)

{
  byte bVar1;
  ushort uVar2;
  c2_tuple *t;
  uint uVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  c2_symbol *pcVar6;
  uint32_t uVar7;
  int iVar8;
  char *pcVar9;
  c2_edge *pcVar10;
  
  t = b->head->next;
  b->flags = b->flags | 2;
  do {
    if (t == b->end) {
      pcVar10 = b->succs;
      if (pcVar10 == (c2_edge *)0x0) {
        return 0;
      }
      while( true ) {
        uVar3 = pcVar10->to->flags;
        if ((((uVar3 & 2) == 0) && ((uVar3 & 1) != 0)) &&
           (iVar8 = warn_uninit_scan_block(fn,pcVar10->to,idx), iVar8 == 1)) break;
        pcVar10 = pcVar10->next_succ;
        if (pcVar10 == (c2_edge *)0x0) {
          return 0;
        }
      }
      return 1;
    }
    if (((t->flags & 1) != 0) && ((t->flags12 != '\0' || (t->flags13 != '\0')))) {
      uVar2 = t->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      if ((t->flags12 != '\0') || ((t->flags13 != 0 && ((t->flags13 & 2) != 0)))) {
        for (pcVar4 = t->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if ((pcVar4->kind == '\x02') &&
             (pcVar5 = (pcVar4->sym->u30).order_prev, pcVar5 != (c2_symbol *)0x0)) {
            if (pcVar5 == (c2_symbol *)idx) {
              uVar7 = (g_uninit_local_symbols[idx]->storage->u30).local_number;
              iVar8 = tuple_reads_shifted_self(t,pcVar4);
              if (iVar8 != 0) {
                return 1;
              }
              pcVar9 = fe_symbol_name(g_uninit_local_symbols[uVar7]->fe,1);
              warning(4,0x2bd,pcVar9);
              return 1;
            }
          }
          else if ((pcVar4->kind == '\x03') &&
                  ((pcVar5 = pcVar4->sym, (pcVar5->u30).order_prev != (c2_symbol *)0x0 &&
                   (pcVar6 = g_uninit_local_symbols[idx], pcVar5->storage == pcVar6->storage)))) {
            if (pcVar5 == pcVar6) {
              return 0;
            }
            if ((pcVar5->offset < pcVar6->size + pcVar6->offset) &&
               (pcVar6->offset < pcVar5->size + pcVar5->offset)) {
              return 0;
            }
          }
        }
      }
      bVar1 = t->flags13;
      if ((bVar1 != 0) && ((bVar1 & 2) == 0)) {
        pcVar5 = g_uninit_local_symbols[idx];
        if ((bVar1 & 8) != 0) {
          return 0;
        }
        if ((bVar1 & 4) == 0) {
          for (pcVar4 = t->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
            if (((pcVar4->kind == '\x02') &&
                (pcVar6 = pcVar4->sym, (pcVar6->u30).order_prev != (c2_symbol *)0x0)) &&
               (pcVar6->storage == pcVar5->storage)) {
              if (pcVar6 == pcVar5) {
                return 0;
              }
              if ((pcVar6->offset < pcVar5->size + pcVar5->offset) &&
                 (pcVar5->offset < pcVar6->size + pcVar6->offset)) {
                return 0;
              }
            }
          }
        }
        else {
          pcVar6 = ((t->u20).eh_try)->catch_rec->object->storage_sym;
          if (pcVar6->storage == pcVar5->storage) {
            if (pcVar6 == pcVar5) {
              return 0;
            }
            if ((pcVar6->offset < pcVar5->size + pcVar5->offset) &&
               (pcVar5->offset < pcVar6->size + pcVar6->offset)) {
              return 0;
            }
          }
        }
      }
    }
    t = t->next;
  } while( true );
}

