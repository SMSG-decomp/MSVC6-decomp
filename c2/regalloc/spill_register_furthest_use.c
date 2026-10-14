uint32_t __fastcall spill_register_furthest_use(c2_symbol *temp,c2_tuple *t)

{
  uint32_t *puVar1;
  c2_bitset *dst;
  c2_bitset *dst_00;
  c2_bitset *dst_01;
  c2_bitset *bs;
  c2_bitset *bs_00;
  uint32_t uVar2;
  c2_tuple *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *sym;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_symbol *pcVar7;
  int iVar8;
  uint32_t uVar9;
  uint16_t type;
  uint uVar10;
  c2_tuple *local_1c;
  uint32_t local_10;
  c2_operand *local_8;
  c2_bitset *local_4;
  
  dst = bitset_new(6);
  dst_00 = bitset_new(6);
  local_4 = dst_00;
  dst_01 = bitset_new(6);
  bs = bitset_new(6);
  bs_00 = bitset_new(6);
  for (pcVar4 = t->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
    if (pcVar4->kind == '\x01') {
      if (((pcVar4->u18).reg)->cls == '\x01') {
        bitset_set(dst_00,((pcVar4->u18).reg)->storage->id);
      }
    }
    else if (pcVar4->kind == '\n') {
      bitset_or(dst_00,(c2_bitset *)pcVar4->sym);
    }
  }
  puVar1 = g_local_register_order;
  uVar9 = g_local_register_order[0];
  while (puVar1 = puVar1 + 1, uVar9 != 0) {
    bitset_set(bs_00,uVar9);
    uVar9 = *puVar1;
  }
  if ((temp->flags5 & 0x80) != 0) {
    bitset_set(bs,7);
    bitset_set(bs,8);
    bitset_set(bs,6);
  }
  while( true ) {
    local_1c = (c2_tuple *)0x0;
    local_10 = 0;
    bitset_copy(dst,dst_00);
    bitset_copy(dst_01,bs);
    pcVar3 = t->next;
    if (pcVar3->kind == '\x19') break;
    do {
      if ((pcVar3->flags & 1) != 0) {
        for (pcVar4 = pcVar3->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (pcVar4->kind == '\x01') {
            pcVar7 = (pcVar4->u18).reg;
            if (pcVar7->cls == '\x01') {
              bitset_set(dst_01,pcVar7->storage->id);
            }
            else if ((pcVar7 == temp) &&
                    (pcVar5 = find_dst_reg_operand(temp,pcVar3), pcVar5 == (c2_operand *)0x0))
            goto LAB_1075ad7d;
          }
        }
        for (pcVar4 = pcVar3->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (pcVar4->kind == '\x01') {
            if (((pcVar4->u18).reg)->cls == '\x01') {
              uVar9 = ((pcVar4->u18).reg)->storage->id;
              uVar2 = bitset_test(bs_00,uVar9);
              if (((uVar2 != 0) && (uVar2 = bitset_test(dst_01,uVar9), uVar2 == 0)) &&
                 (uVar2 = bitset_test(dst,uVar9), uVar2 == 0)) {
                bitset_set(dst,uVar9);
                local_1c = pcVar3;
                local_10 = uVar9;
              }
            }
          }
          else if (pcVar4->kind == '\n') {
            uVar9 = bitset_iter_next((c2_bitset *)pcVar4->sym);
            while (uVar9 != 0xffffffff) {
              uVar2 = bitset_test(bs_00,uVar9);
              if (((uVar2 != 0) && (uVar2 = bitset_test(dst_01,uVar9), uVar2 == 0)) &&
                 (uVar2 = bitset_test(dst,uVar9), uVar2 == 0)) {
                bitset_set(dst,uVar9);
                local_1c = pcVar3;
                local_10 = uVar9;
              }
              uVar9 = bitset_iter_next((c2_bitset *)0x0);
            }
          }
        }
      }
      pcVar3 = pcVar3->next;
    } while (pcVar3->kind != '\x19');
LAB_1075ad7d:
    if (((local_1c == (c2_tuple *)0x0) || (g_register_holders[local_10] == (c2_symbol *)0x0)) ||
       (iVar8 = local_move_value_to_free_register(local_10,t), iVar8 != 0)) break;
    bitset_set(bs,local_10);
    dst_00 = local_4;
  }
  bitset_free(dst);
  bitset_free(local_4);
  bitset_free(dst_01);
  bitset_free(bs);
  bitset_free(bs_00);
  if (local_1c == (c2_tuple *)0x0) {
    return 0;
  }
  pcVar3 = find_next_use_of_temp(temp,local_1c,&local_8);
  if (pcVar3 == (c2_tuple *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\regasg.c",0x508);
  }
  pcVar4 = find_dst_reg_operand(temp,t);
  uVar10 = (uint)pcVar4->type;
  for (pcVar6 = t->next; pcVar6 != local_1c; pcVar6 = pcVar6->next) {
    if ((((pcVar6->flags & 1) != 0) &&
        (pcVar4 = find_dst_reg_operand(temp,pcVar6), pcVar4 != (c2_operand *)0x0)) &&
       ((uVar10 & 0xfff) < (pcVar4->type & 0xfff))) {
      uVar10 = (uint)pcVar4->type;
    }
  }
  type = (uint16_t)uVar10;
  pcVar4 = operand_new_temp_sym(type);
  pcVar7 = temp;
  sym = symbol_get_part(local_8->sym->storage,type,uVar10 & 0xfff,local_8->sym->offset & 0xfffffffe)
  ;
  pcVar5 = operand_new_reg(0x149,type,sym,pcVar7);
  pcVar6 = tuple_new(1,type,pcVar4,pcVar5,tuple_insert_before,local_1c);
  pcVar6->src->flags11 = pcVar6->src->flags11 | 0x10;
  pcVar6->line = local_1c->line;
  pcVar6 = tuple_new_unary_temp(1,type,pcVar4,tuple_insert_before,pcVar3);
  pcVar4 = pcVar6->dst;
  pcVar6->line = pcVar3->line;
  pcVar7 = symbol_get_part(pcVar4->sym,local_8->type,local_8->type & 0xfff,local_8->sym->offset & 1)
  ;
  local_8->sym = pcVar7;
  if ((g_opt_global == 0) || (g_no_global_candidates != 0)) {
    iVar8 = 0;
  }
  else {
    iVar8 = 1;
  }
  local_ra_rename_register_in_span(t,temp,pcVar3,(pcVar4->u18).reg,iVar8);
  return local_10;
}

