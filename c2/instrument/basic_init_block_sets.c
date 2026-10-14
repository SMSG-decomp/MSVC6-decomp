void __fastcall basic_init_block_sets(c2_function *fn,uint32_t nbits,c2_bitvec **rows)

{
  c2_block *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  c2_symbol *pcVar5;
  int iVar6;
  c2_tuple *pcVar7;
  c2_bitvec *ue;
  c2_bitvec *kill;
  c2_bitvec *live_in;
  c2_bitvec *avail_in;
  
  pcVar1 = fn->cfg->first;
  do {
    if (pcVar1 == (c2_block *)0x0) {
      return;
    }
    ue = (c2_bitvec *)pcVar1->ue;
    bitvec_clear_words(ue);
    kill = (c2_bitvec *)pcVar1->kill;
    bitvec_clear_words(kill);
    live_in = (c2_bitvec *)pcVar1->live_in;
    bitvec_clear_words(live_in);
    bitvec_clear_words((c2_bitvec *)pcVar1->live_out);
    pcVar7 = pcVar1->head;
    avail_in = (c2_bitvec *)(pcVar1->avail_in).set;
    iVar6 = bitvec_is_empty(avail_in);
    if (iVar6 == 0) {
      bitvec_or_selected_rows(ue,avail_in,rows);
      bitvec_copy(live_in,ue);
      for (; (pcVar7 != pcVar1->end && (pcVar7->op != 0x19b)); pcVar7 = pcVar7->next) {
      }
    }
    pcVar2 = pcVar1->end;
    for (; pcVar7 != pcVar2; pcVar7 = pcVar7->next) {
      if ((pcVar7->flags & 1) != 0) {
        for (pcVar3 = pcVar7->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          if (pcVar3->kind == '\x02') {
            pcVar4 = pcVar3->sym;
            pcVar5 = pcVar4->storage;
            if ((pcVar5->u34).refs != 0) {
              if (pcVar4 != pcVar5) {
                if ((pcVar5->offset < pcVar4->offset) ||
                   (pcVar4->size + pcVar4->offset < pcVar5->size + pcVar5->offset))
                goto LAB_1079525f;
              }
              bitvec_set(kill,(pcVar5->u34).refs);
            }
          }
LAB_1079525f:
        }
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

