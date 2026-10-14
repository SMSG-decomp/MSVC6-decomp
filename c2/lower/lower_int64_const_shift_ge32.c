c2_tuple * __fastcall lower_int64_const_shift_ge32(c2_tuple *anchor,uint32_t op,c2_operand *cond)

{
  uint16_t uVar1;
  uint uVar2;
  c2_operand *dst;
  bool bVar3;
  c2_operand *dst_00;
  c2_operand *src;
  c2_operand *dst_01;
  c2_operand *dst_02;
  c2_tuple *pcVar4;
  c2_const_operand *pcVar5;
  c2_operand *src_00;
  c2_symbol *pcVar6;
  code *insert_fn_00;
  c2_tuple *pcVar7;
  c2_tuple *local_1c;
  c2_insert_fn *insert_fn;
  
  uVar2 = (anchor->src->next->u18).lo;
  anchor->type = (uint16_t)CONCAT31((byte)(anchor->type >> 8) & 0xf0,4);
  dst_00 = split_int64_operand_half(anchor,anchor->dst,(c2_operand *)0x0,(c2_operand *)0x0);
  if (((1 << (dst_00->kind & 0x1f) & 6U) == 0) ||
     (bVar3 = true, dst_00->sym->def == (c2_tuple *)0x0)) {
    bVar3 = false;
  }
  src = split_int64_operand_half(anchor,anchor->src,(c2_operand *)0x0,(c2_operand *)0x0);
  src_00 = anchor->src;
  uVar1 = anchor->type;
  dst = anchor->dst;
  dst_01 = operand_new_temp(uVar1);
  if (op == 0x177) {
    if ((uVar1 & 0xf000) == 0x2000) {
      pcVar4 = tuple_new(1,uVar1,dst_01,src,tuple_insert_after,anchor);
      pcVar6 = dst_01->sym;
      if (pcVar6->storage->part_next == (c2_symbol *)0x0) {
        pcVar6->def = pcVar4;
      }
      else {
        symbol_mark_overlapping_parts(pcVar6,pcVar4);
      }
      uVar1 = anchor->type;
      insert_fn = tuple_insert_after;
      pcVar7 = pcVar4;
      pcVar5 = operand_new_intconst(0x1004,0,0);
      local_1c = tuple_new(1,uVar1,dst_00,pcVar5,insert_fn,pcVar7);
    }
    else {
      dst_02 = operand_new_temp_sym(uVar1);
      pcVar4 = tuple_new(1,uVar1,dst_02,src,tuple_insert_after,anchor);
      uVar1 = anchor->type;
      pcVar4 = tuple_new(1,uVar1,dst_01,dst_02,tuple_insert_after,pcVar4);
      pcVar6 = dst_01->sym;
      if (pcVar6->storage->part_next == (c2_symbol *)0x0) {
        pcVar6->def = pcVar4;
      }
      else {
        symbol_mark_overlapping_parts(pcVar6,pcVar4);
      }
      insert_fn = tuple_insert_after;
      pcVar7 = pcVar4;
      pcVar5 = operand_new_intconst(0x1004,0x1f,0);
      local_1c = tuple_new_binary(0x29,uVar1,dst_00,dst_02,pcVar5,insert_fn,pcVar7);
      legalize_machine_tuple(local_1c);
    }
    if (bVar3) {
      pcVar6 = dst_00->sym;
      if (pcVar6->storage->part_next == (c2_symbol *)0x0) {
        pcVar6->def = local_1c;
      }
      else {
        symbol_mark_overlapping_parts(pcVar6,local_1c);
      }
    }
    insert_fn = tuple_insert_after;
    if (uVar2 < 0x21) {
      pcVar4 = tuple_new(1,uVar1,dst,dst_01,tuple_insert_after,pcVar4);
    }
    else {
      pcVar5 = operand_new_intconst(0x1004,uVar2 - 0x20,0);
      pcVar4 = tuple_new_binary((-(uint)((uVar1 & 0xf000) != 0x2000) & 0xfffffffe) + 0x2b,uVar1,dst,
                                dst_01,pcVar5,insert_fn,pcVar4);
      legalize_machine_tuple(pcVar4);
    }
    if (((1 << (dst->kind & 0x1f) & 6U) == 0) || (pcVar6 = dst->sym, pcVar6->def == (c2_tuple *)0x0)
       ) goto LAB_1076108c;
    if (pcVar6->storage->part_next == (c2_symbol *)0x0) {
      pcVar6->def = pcVar4;
      goto LAB_1076108c;
    }
  }
  else {
    local_1c = tuple_new(1,uVar1,dst_01,src_00,tuple_insert_after,anchor);
    pcVar6 = dst_01->sym;
    if (pcVar6->storage->part_next == (c2_symbol *)0x0) {
      pcVar6->def = local_1c;
    }
    else {
      symbol_mark_overlapping_parts(pcVar6,local_1c);
    }
    insert_fn = tuple_insert_after;
    pcVar4 = local_1c;
    pcVar5 = operand_new_intconst(0x1004,0,0);
    pcVar4 = tuple_new(1,anchor->type,dst,pcVar5,insert_fn,pcVar4);
    if (((1 << (dst->kind & 0x1f) & 6U) != 0) && (pcVar6 = dst->sym, pcVar6->def != (c2_tuple *)0x0)
       ) {
      if (pcVar6->storage->part_next == (c2_symbol *)0x0) {
        pcVar6->def = pcVar4;
      }
      else {
        symbol_mark_overlapping_parts(pcVar6,pcVar4);
      }
    }
    insert_fn_00 = tuple_insert_after;
    if (uVar2 < 0x21) {
      pcVar4 = tuple_new(1,anchor->type,dst_00,dst_01,tuple_insert_after,pcVar4);
    }
    else {
      pcVar5 = operand_new_intconst(0x1004,uVar2 - 0x20,0);
      pcVar4 = tuple_new_binary(0x2a,local_1c->type,dst_00,dst_01,pcVar5,insert_fn_00,pcVar4);
      legalize_machine_tuple(pcVar4);
    }
    if (!bVar3) goto LAB_1076108c;
    pcVar6 = dst_00->sym;
    if (pcVar6->storage->part_next == (c2_symbol *)0x0) {
      pcVar6->def = pcVar4;
      goto LAB_1076108c;
    }
  }
  symbol_mark_overlapping_parts(pcVar6,pcVar4);
LAB_1076108c:
  anchor->dst = (c2_operand *)0x0;
  if (op != 0x177) {
    src_00 = src;
  }
  anchor->src = src_00;
  tuple_delete_if_dead((c2_node *)anchor,0);
  return local_1c;
}

