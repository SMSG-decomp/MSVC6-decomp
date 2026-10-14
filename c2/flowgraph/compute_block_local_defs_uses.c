void __fastcall compute_block_local_defs_uses(c2_function *fn,int nlocals)

{
  ushort uVar1;
  c2_block *pcVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  c2_symbol *pcVar5;
  c2_operand *pcVar6;
  c2_symbol *pcVar7;
  uint32_t uVar8;
  c2_fe_symbol *pcVar9;
  c2_symbol **ppcVar10;
  c2_bitset *dst;
  c2_bitset *bs;
  
  pcVar2 = fn->cfg->first;
  do {
    if (pcVar2 == (c2_block *)0x0) {
      return;
    }
    dst = bitset_new(6);
    bs = bitset_new(6);
    pcVar4 = pcVar2->head;
    for (pcVar3 = pcVar2->end; pcVar3 != pcVar4; pcVar3 = pcVar3->prev) {
      if ((pcVar3->flags & 1) != 0) {
        pcVar3->flags12 = '\0';
        pcVar3->flags13 = '\0';
        if ((pcVar3->op == 0x191) ||
           ((pcVar3->kind == '\x12' && ((pcVar3->u20).intrinsic.id == 0xdb)))) {
          bitset_set_range(dst,nlocals + 1);
          bitset_clear_all(bs);
          pcVar3->flags13 = '\b';
        }
        else if ((pcVar3->op == 0x1a5) &&
                (pcVar9 = ((pcVar3->u20).eh_try)->catch_rec->object, pcVar9 != (c2_fe_symbol *)0x0))
        {
          pcVar7 = pcVar9->storage_sym;
          if ((pcVar7->u30).order_prev != (c2_symbol *)0x0) {
            for (pcVar5 = pcVar7->storage; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next) {
              uVar8 = (pcVar5->u30).local_number;
              if (pcVar7 == pcVar5) {
LAB_10795abb:
                bitset_set(dst,uVar8);
                bitset_clear(bs,uVar8);
              }
              else if ((pcVar7->offset < pcVar5->size + pcVar5->offset) &&
                      (pcVar5->offset < pcVar7->size + pcVar7->offset)) goto LAB_10795abb;
            }
            pcVar3->flags13 = '\x04';
          }
        }
        else {
          for (pcVar6 = pcVar3->dst; pcVar6 != (c2_operand *)0x0; pcVar6 = pcVar6->next) {
            if ((pcVar6->kind == '\x02') &&
               (pcVar7 = pcVar6->sym, (pcVar7->u30).order_prev != (c2_symbol *)0x0)) {
              for (pcVar5 = pcVar7->storage; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next)
              {
                uVar8 = (pcVar5->u30).local_number;
                if (pcVar7 == pcVar5) {
LAB_1072a6dc:
                  bitset_set(dst,uVar8);
                  bitset_clear(bs,uVar8);
                }
                else if ((pcVar7->offset < pcVar5->size + pcVar5->offset) &&
                        (pcVar5->offset < pcVar7->size + pcVar7->offset)) goto LAB_1072a6dc;
              }
              pcVar3->flags13 = pcVar3->flags13 | 1;
            }
          }
          ppcVar10 = g_uninit_local_symbols;
          for (pcVar6 = pcVar3->src; g_uninit_local_symbols = ppcVar10, pcVar6 != (c2_operand *)0x0;
              pcVar6 = pcVar6->next) {
            if (pcVar6->kind == '\x02') {
              pcVar7 = pcVar6->sym;
              if (((pcVar7->storage != pcVar7) ||
                  ((uVar1 = pcVar6->type, uVar1 != 0x5001 &&
                   (((uVar1 & 0xf000) != 0x5000 || ((uVar1 & 0xfff) != 1)))))) &&
                 (uVar8 = (pcVar7->u30).local_number, uVar8 != 0)) {
                ppcVar10[uVar8] = pcVar7;
                ppcVar10[(pcVar7->storage->u30).local_number] = pcVar7->storage;
                bitset_set(bs,uVar8);
                pcVar3->flags12 = pcVar3->flags12 | 1;
              }
            }
            else if ((pcVar6->kind == '\x03') && ((pcVar6->sym->u30).order_prev != (c2_symbol *)0x0)
                    ) {
              for (pcVar7 = pcVar6->sym->storage; pcVar7 != (c2_symbol *)0x0;
                  pcVar7 = pcVar7->part_next) {
                uVar8 = (pcVar7->u30).local_number;
                bitset_set(dst,uVar8);
                bitset_clear(bs,uVar8);
              }
              pcVar3->flags13 = pcVar3->flags13 | 2;
            }
            ppcVar10 = g_uninit_local_symbols;
          }
        }
      }
    }
    pcVar2->de = dst;
    pcVar2->ue = bs;
    pcVar2 = pcVar2->next;
  } while( true );
}

