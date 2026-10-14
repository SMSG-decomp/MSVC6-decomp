c2_register_descriptor * __fastcall
spill_register_last_resort(c2_tuple *t,c2_operand *op,c2_symbol *temp)

{
  ushort uVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_fe_symbol *pcVar4;
  uint32_t n;
  c2_tuple *pcVar5;
  uint uVar6;
  c2_operand *pcVar7;
  c2_operand *pcVar8;
  c2_operand_u18 cVar9;
  c2_symbol *old_reg;
  bool bVar10;
  c2_bitset *bs;
  uint32_t uVar11;
  c2_symbol *pcVar12;
  c2_operand *pcVar13;
  c2_tuple *pcVar14;
  int only_live;
  c2_register_descriptor *pcVar15;
  ushort type;
  c2_fe_symbol *pcVar16;
  c2_tuple *anchor;
  c2_symbol *local_14;
  
  pcVar16 = (c2_fe_symbol *)temp;
  for (pcVar2 = t->next; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->next) {
    if ((pcVar2->flags & 1) != 0) {
      for (pcVar16 = (c2_fe_symbol *)pcVar2->src; pcVar16 != (c2_fe_symbol *)0x0;
          pcVar16 = pcVar16->next) {
        if ((((1 << (*(byte *)&pcVar16->storage_sym & 0x1f) & 6U) != 0) &&
            (pcVar3 = ((c2_symbol *)pcVar16->attrs)->def, pcVar3 != (c2_tuple *)0x0)) &&
           (pcVar3 == t)) {
          if (pcVar16 != (c2_fe_symbol *)0x0) goto LAB_1078b7d5;
          break;
        }
      }
    }
  }
LAB_1078b7d5:
  bs = bitset_new(6);
  if ((temp->flags5 & 0x80) != 0) {
    bitset_set(bs,7);
    bitset_set(bs,8);
    bitset_set(bs,6);
  }
  for (pcVar4 = (c2_fe_symbol *)pcVar2->src; pcVar4 != (c2_fe_symbol *)0x0; pcVar4 = pcVar4->next) {
    if (((pcVar4 != pcVar16) && (*(uint8_t *)&pcVar4->storage_sym == '\x01')) &&
       (((c2_operand_u18 *)&pcVar4->name)->reg->cls == '\x01')) {
      bitset_set(bs,((c2_operand_u18 *)&pcVar4->name)->reg->storage->id);
    }
  }
  for (pcVar13 = t->dst; pcVar13 != (c2_operand *)0x0; pcVar13 = pcVar13->next) {
    if ((pcVar13->kind == '\x01') && (((pcVar13->u18).reg)->cls == '\x01')) {
      bitset_set(bs,((pcVar13->u18).reg)->storage->id);
    }
  }
  for (pcVar13 = t->src; pcVar13 != (c2_operand *)0x0; pcVar13 = pcVar13->next) {
    if ((pcVar13->kind == '\x01') && (((pcVar13->u18).reg)->cls == '\x01')) {
      bitset_set(bs,((pcVar13->u18).reg)->storage->id);
    }
  }
  for (pcVar2 = t->prev; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->prev) {
    if (((((pcVar2->flags & 1) != 0) && (pcVar13 = pcVar2->dst, pcVar13 != (c2_operand *)0x0)) &&
        (pcVar13->kind == '\x01')) && (((pcVar13->u18).reg)->cls == '\x01')) {
      n = ((pcVar13->u18).reg)->storage->id;
      uVar11 = bitset_test(bs,n);
      if ((uVar11 == 0) && (g_register_holders[n] != (c2_symbol *)0x0)) break;
    }
  }
  bitset_free(bs);
  pcVar16 = (c2_fe_symbol *)temp;
  for (pcVar3 = pcVar2->next; pcVar3 != (c2_tuple *)0x0; pcVar3 = pcVar3->next) {
    if ((pcVar3->flags & 1) != 0) {
      for (pcVar16 = (c2_fe_symbol *)pcVar3->src; pcVar16 != (c2_fe_symbol *)0x0;
          pcVar16 = pcVar16->next) {
        if ((((1 << (*(byte *)&pcVar16->storage_sym & 0x1f) & 6U) != 0) &&
            (pcVar5 = ((c2_symbol *)pcVar16->attrs)->def, pcVar5 != (c2_tuple *)0x0)) &&
           (pcVar5 == pcVar2)) {
          if (pcVar16 != (c2_fe_symbol *)0x0) goto LAB_1078b935;
          break;
        }
      }
    }
  }
LAB_1078b935:
  pcVar13 = pcVar2->dst;
  spill_register_holder(((pcVar13->u18).reg)->id,pcVar2->next,pcVar3,(c2_operand *)pcVar16);
  type = op->type;
  uVar6 = op->sym->offset;
  pcVar12 = reg_find_subreg((pcVar13->u18).reg,(type & 0xfff) << 3,
                            (uVar6 & (3 < (int)uVar6) - 1) << 3);
  uVar1 = *(uint16_t *)((int)&((c2_symbol *)pcVar16)->storage + 2);
  if ((type & 0xfff) < (uVar1 & 0xfff)) {
    type = uVar1;
  }
  pcVar13 = operand_new_temp_sym(type);
  bVar10 = false;
  pcVar5 = t->next;
  anchor = t;
  old_reg = temp;
joined_r0x1078b9ba:
  if (pcVar5 != (c2_tuple *)0x0) {
    if (pcVar5 == pcVar3) {
      bVar10 = true;
    }
    local_14 = old_reg;
    if ((pcVar5->flags & 1) != 0) {
      for (pcVar7 = pcVar5->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
        if ((((1 << (pcVar7->kind & 0x1f) & 6U) != 0) &&
            (pcVar14 = pcVar7->sym->def, pcVar14 != (c2_tuple *)0x0)) && (pcVar14 == anchor)) {
          if (pcVar7 != (c2_operand *)0x0) {
            pcVar14 = tuple_new(1,type,pcVar13,anchor->dst,tuple_insert_after,anchor);
            pcVar14->src->sym->def = anchor;
            pcVar14 = tuple_new_unary_temp(1,type,pcVar13,tuple_insert_before,pcVar5);
            pcVar8 = pcVar14->dst;
            pcVar14->line = pcVar5->line;
            cVar9 = (c2_operand_u18)pcVar8->sym;
            pcVar7->sym = (c2_symbol *)cVar9;
            pcVar8->u18 = cVar9;
            if ((g_opt_global == 0) || (g_no_global_candidates != 0)) {
              only_live = 0;
            }
            else {
              only_live = 1;
            }
            local_14 = pcVar8->sym;
            local_ra_rename_register_in_span(anchor,old_reg,pcVar5,local_14,only_live);
            if (anchor != t) {
              bitset_clear(g_local_conflicts[((pcVar2->dst->u18).reg)->storage->id],old_reg->id);
            }
            pcVar7 = pcVar5->dst;
            goto joined_r0x1078bad2;
          }
          break;
        }
      }
    }
    goto LAB_1078b9fa;
  }
LAB_1078ba01:
  ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\regasg.c",0x260);
joined_r0x1078bad2:
  if (pcVar7 == (c2_operand *)0x0) goto LAB_1078bb07;
  if ((((1 << (pcVar7->kind & 0x1f) & 6U) != 0) && (pcVar7->sym->def != (c2_tuple *)0x0)) &&
     (((pcVar7->u18).reg)->storage->id == ((pcVar8->u18).reg)->storage->id)) goto LAB_1078bb33;
  pcVar7 = pcVar7->next;
  goto joined_r0x1078bad2;
LAB_1078bb33:
  if ((pcVar7 == (c2_operand *)0x0) || (anchor = pcVar5, bVar10)) {
LAB_1078bb07:
    if (pcVar5 != (c2_tuple *)0x0) {
      pcVar15 = bind_local_register(pcVar12->storage->id,temp);
      return pcVar15;
    }
    goto LAB_1078ba01;
  }
LAB_1078b9fa:
  pcVar5 = pcVar5->next;
  old_reg = local_14;
  goto joined_r0x1078b9ba;
}

