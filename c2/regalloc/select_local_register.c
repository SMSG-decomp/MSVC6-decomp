c2_register_descriptor * __fastcall select_local_register(c2_operand *op,c2_tuple *t)

{
  byte bVar1;
  c2_symbol *temp;
  uint uVar2;
  c2_symbol *pcVar3;
  c2_tuple *t_00;
  uint32_t *puVar4;
  uint32_t uVar5;
  c2_register_descriptor *pcVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint32_t uVar9;
  c2_operand *pcVar10;
  c2_tuple *t2;
  uint32_t *puVar11;
  c2_operand *local_8;
  c2_operand *local_4;
  
  temp = (op->u18).reg;
  uVar9 = temp->id;
  if (temp->order_next == (c2_symbol *)0x0) {
    if ((t->op == 1) && (t->src->kind == '\x01')) {
      pcVar3 = ((t->src->u18).reg)->storage;
      uVar2 = pcVar3->id;
      if ((uVar2 != 0) && ((uVar2 < 9 && (uVar2 != 5)))) {
        temp->order_next = pcVar3;
      }
    }
    if ((((temp->order_next == (c2_symbol *)0x0) && (t->op == 0x12)) &&
        (pcVar10 = t->src, pcVar10->kind == '\x05')) &&
       (((pcVar10->base != (c2_operand *)0x0 && (pcVar10->base_sym == (c2_symbol *)0x0)) &&
        ((pcVar10->index == (c2_operand *)0x0 ||
         (((pcVar10->flags & 0xf) == 0 && (pcVar10->disp == 0)))))))) {
      temp->order_next = (c2_symbol *)pcVar10->base->u18;
    }
  }
  local_4 = op;
  if (((temp->order_next != (c2_symbol *)0x0) &&
      (uVar5 = temp->order_next->id, g_register_holders[uVar5] == (c2_symbol *)0x0)) &&
     (uVar7 = bitset_test(g_local_conflicts[uVar5],uVar9), uVar7 == 0)) {
    pcVar6 = bind_local_register(uVar5,temp);
    return pcVar6;
  }
  puVar4 = g_local_rotation_cursor;
  puVar11 = g_local_rotation_cursor;
  if (g_opt_favor_speed != 0) {
    do {
      if (((*puVar11 == 0) || (3 < *puVar11)) &&
         (puVar11 = g_local_register_order, puVar4 == g_local_register_order)) break;
      uVar2 = *puVar11;
      puVar11 = puVar11 + 1;
      if ((g_register_holders[uVar2] == (c2_symbol *)0x0) &&
         (uVar5 = bitset_test(g_local_conflicts[uVar2],uVar9), uVar5 == 0)) {
        if ((*puVar11 == 0) || (g_local_rotation_cursor = puVar11, 3 < *puVar11)) {
          g_local_rotation_cursor = g_local_register_order;
        }
        pcVar6 = bind_local_register(uVar2,temp);
        return pcVar6;
      }
    } while (puVar11 != puVar4);
  }
  puVar4 = g_local_register_order;
  uVar5 = g_local_register_order[0];
  while (puVar4 = puVar4 + 1, uVar5 != 0) {
    if ((g_register_holders[uVar5] == (c2_symbol *)0x0) &&
       (uVar7 = bitset_test(g_local_conflicts[uVar5],uVar9), uVar7 == 0)) goto LAB_10735130;
    uVar5 = *puVar4;
  }
  uVar5 = move_holder_to_free_register(t,uVar9);
  if (uVar5 != 0) {
    pcVar6 = bind_local_register(uVar5,temp);
    return pcVar6;
  }
  if (((g_opt_global != 0) && (t->dst->next == (c2_operand *)0x0)) &&
     (uVar5 = hoist_holder_consumer(t,uVar9), uVar5 != 0)) {
    pcVar6 = bind_local_register(uVar5,temp);
    return pcVar6;
  }
  t_00 = t->next;
  bVar1 = t_00->flags;
  while ((bVar1 & 1) == 0) {
    t_00 = t_00->next;
    bVar1 = t_00->flags;
  }
  uVar7 = 0;
  puVar4 = g_local_register_order;
  uVar5 = g_local_register_order[0];
  while( true ) {
    puVar4 = puVar4 + 1;
    if (uVar5 == 0) {
      uVar9 = spill_register_furthest_use(temp,t);
      if (uVar9 != 0) {
        pcVar6 = bind_local_register(uVar9,temp);
        return pcVar6;
      }
      if (uVar7 == 0) {
        pcVar6 = spill_register_last_resort(t,local_4,temp);
        return pcVar6;
      }
      find_next_use_of_temp(g_register_holders[uVar7],t_00,&local_8);
      spill_register_holder(uVar7,t,t_00,local_8);
      pcVar6 = bind_local_register(uVar7,temp);
      return pcVar6;
    }
    uVar8 = bitset_test(g_local_conflicts[uVar5],uVar9);
    if (((uVar8 == 0) &&
        (pcVar10 = find_dst_reg_operand(g_register_holders[uVar5],t), pcVar10 == (c2_operand *)0x0))
       && (t2 = find_next_use_of_temp(g_register_holders[uVar5],t_00,&local_8), uVar7 = uVar5,
          t2 != t_00)) break;
    uVar5 = *puVar4;
  }
  spill_register_holder(uVar5,t,t2,local_8);
LAB_10735130:
  pcVar6 = bind_local_register(uVar5,temp);
  return pcVar6;
}

