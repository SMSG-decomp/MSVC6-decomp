void __fastcall
restore_temp_destinations_visit
          (c2_tuple *t,c2_bitset *bs,c2_bitset *bs2,c2_bitset *bs3,c2_tuple **next)

{
  byte bVar1;
  ushort type;
  c2_tuple *pcVar2;
  c2_operand *old;
  c2_tuple *pcVar3;
  c2_symbol *pcVar4;
  int iVar5;
  uint32_t uVar6;
  c2_operand *new_op;
  c2_operand *pcVar7;
  c2_symbol *pcVar8;
  uint uVar9;
  c2_symbol *pcVar10;
  
  pcVar7 = t->dst;
  if ((pcVar7 != (c2_operand *)0x0) && ((1 << (pcVar7->kind & 0x1f) & 6U) != 0)) {
    pcVar4 = pcVar7->sym;
    if ((pcVar4->cls == '\x03') &&
       ((((pcVar4->def == (c2_tuple *)0x0 && ((pcVar4->flags7 & 2) == 0)) &&
         (pcVar4 = find_restorable_temp(bs,bs3,pcVar4->storage), pcVar4 != (c2_symbol *)0x0)) &&
        (iVar5 = tuple_def_conflicts_with_pending(t,pcVar4), iVar5 == 0)))) {
      pcVar8 = pcVar7->sym;
      pcVar2 = (c2_tuple *)pcVar4->defs;
      old = (c2_operand *)pcVar4->uses;
      pcVar3 = pcVar8->def;
      if (pcVar3 == (c2_tuple *)0x0) {
        uVar6 = bitset_test(bs,pcVar8->id);
      }
      else {
        uVar6 = (uint32_t)(pcVar8->u30).globopt.live;
      }
      if ((uVar6 == 0) && (g_dead_dst_overlap_live == 0)) {
        pcVar7->flags11 = pcVar7->flags11 | 0x10;
      }
      if (pcVar3 == (c2_tuple *)0x0) {
        for (pcVar10 = pcVar8->storage; pcVar10 != (c2_symbol *)0x0; pcVar10 = pcVar10->part_next) {
          if ((pcVar8->offset <= pcVar10->offset) &&
             (pcVar10->size + pcVar10->offset <= pcVar8->size + pcVar8->offset)) {
            uVar6 = pcVar10->id;
            bitset_clear(bs,uVar6);
            bitset_set(bs2,uVar6);
          }
        }
      }
      else {
        pcVar10 = pcVar8->storage;
        if (pcVar10 != (c2_symbol *)0x0) {
          iVar5 = pcVar8->offset;
          do {
            if ((iVar5 <= pcVar10->offset) &&
               (pcVar10->size + pcVar10->offset <= pcVar8->size + iVar5)) {
              (pcVar10->u30).globopt.live = '\0';
              (pcVar10->u30).globopt.killed = '\x01';
            }
            pcVar10 = pcVar10->part_next;
          } while (pcVar10 != (c2_symbol *)0x0);
        }
      }
      pcVar4->defs = (c2_list_cell *)0x0;
      pcVar4->uses = (c2_list_cell *)0x0;
      bitset_clear(bs3,pcVar4->id);
      new_op = operand_new_temp(pcVar7->type);
      pcVar7 = tuple_replace_dst(t,pcVar7,new_op);
      pcVar8 = pcVar7->sym;
      pcVar8->def = t;
      (pcVar8->u30).globopt.live = '\x01';
      type = old->type;
      pcVar7 = tuple_replace_src(pcVar2,old,pcVar7);
      pcVar7->type = type;
      if (type != pcVar7->sym->type) {
        pcVar4 = symbol_get_part(pcVar7->sym,type,type & 0xfff,
                                 pcVar4->offset - pcVar4->storage->offset);
        pcVar7->sym = pcVar4;
      }
      pcVar7->flags11 = pcVar7->flags11 | 0x10;
    }
    for (pcVar7 = t->dst; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
      if ((pcVar7->kind != 0) && (pcVar7->kind < 3)) {
        pcVar4 = pcVar7->sym;
        bVar1 = pcVar7->flags11;
        pcVar2 = pcVar4->def;
        pcVar7->flags11 = bVar1 & 0xef;
        if (pcVar2 == (c2_tuple *)0x0) {
          uVar9 = bitset_test(bs,pcVar4->id);
        }
        else {
          uVar9 = (uint)(pcVar4->u30).globopt.live;
        }
        if ((uVar9 == 0) && (g_dead_dst_overlap_live == 0)) {
          pcVar7->flags11 = bVar1 & 0xef | 0x10;
        }
        if (pcVar2 == (c2_tuple *)0x0) {
          pcVar8 = pcVar4->storage;
          if (pcVar8 != (c2_symbol *)0x0) {
            iVar5 = pcVar4->offset;
            do {
              if ((iVar5 <= pcVar8->offset) &&
                 (pcVar8->size + pcVar8->offset <= pcVar4->size + iVar5)) {
                uVar6 = pcVar8->id;
                bitset_clear(bs,uVar6);
                bitset_set(bs2,uVar6);
              }
              pcVar8 = pcVar8->part_next;
            } while (pcVar8 != (c2_symbol *)0x0);
          }
        }
        else {
          pcVar8 = pcVar4->storage;
          if (pcVar8 != (c2_symbol *)0x0) {
            iVar5 = pcVar4->offset;
            do {
              if ((iVar5 <= pcVar8->offset) &&
                 (pcVar8->size + pcVar8->offset <= pcVar4->size + iVar5)) {
                (pcVar8->u30).globopt.live = '\0';
                (pcVar8->u30).globopt.killed = '\x01';
              }
              pcVar8 = pcVar8->part_next;
            } while (pcVar8 != (c2_symbol *)0x0);
          }
        }
        pcVar4->defs = (c2_list_cell *)0x0;
        pcVar4->uses = (c2_list_cell *)0x0;
      }
    }
  }
  pcVar7 = t->src;
  do {
    if (pcVar7 == (c2_operand *)0x0) {
      return;
    }
    switch(restore_temp_destinations_visit_case_index[pcVar7->kind]) {
    case 0:
      pcVar4 = pcVar7->sym;
      uVar6 = pcVar4->id;
      pcVar7->flags11 = pcVar7->flags11 & 0xef;
      bitset_set(bs3,uVar6);
      if (pcVar4->def == (c2_tuple *)0x0) {
        uVar6 = bitset_test(bs,uVar6);
      }
      else {
        uVar6 = (uint32_t)(pcVar4->u30).globopt.live;
      }
      if (uVar6 == 0) {
        pcVar4->uses = (c2_list_cell *)pcVar7;
        pcVar4->defs = (c2_list_cell *)t;
      }
      else {
        pcVar4->defs = (c2_list_cell *)0x0;
        pcVar4->uses = (c2_list_cell *)0x0;
      }
      if (pcVar4->def == (c2_tuple *)0x0) {
        uVar6 = symbol_in_set_or_flag(pcVar4,bs);
        if (uVar6 == 0) {
          uVar6 = pcVar4->id;
          pcVar7->flags11 = pcVar7->flags11 | 0x10;
          bitset_set(bs,uVar6);
        }
        for (pcVar8 = pcVar4->storage; pcVar8 != (c2_symbol *)0x0; pcVar8 = pcVar8->part_next) {
          if (pcVar8 == pcVar4) {
LAB_10710c1f:
            bitset_clear(bs2,pcVar8->id);
          }
          else if ((pcVar8->offset < pcVar4->size + pcVar4->offset) &&
                  (pcVar4->offset < pcVar8->size + pcVar8->offset)) goto LAB_10710c1f;
        }
      }
      else {
        uVar6 = symbol_in_set_or_flag(pcVar4,bs);
        if (uVar6 == 0) {
          bVar1 = pcVar7->flags11;
          (pcVar4->u30).globopt.live = '\x01';
          pcVar7->flags11 = bVar1 | 0x10;
        }
        for (pcVar8 = pcVar4->storage; pcVar8 != (c2_symbol *)0x0; pcVar8 = pcVar8->part_next) {
          if (pcVar8 == pcVar4) {
LAB_10710c94:
            (pcVar8->u30).globopt.killed = '\0';
          }
          else if ((pcVar8->offset < pcVar4->size + pcVar4->offset) &&
                  (pcVar4->offset < pcVar8->size + pcVar8->offset)) goto LAB_10710c94;
        }
      }
      break;
    case 2:
      pcVar4 = (c2_symbol *)pcVar7->tag;
      goto LAB_10710cc5;
    case 3:
      pcVar4 = pcVar7->sym;
LAB_10710cc5:
      restore_temp_alias_members((uint32_t)pcVar4,bs,bs2);
    }
    pcVar7 = pcVar7->next;
  } while( true );
}

