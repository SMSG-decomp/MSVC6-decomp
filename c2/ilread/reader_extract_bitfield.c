c2_operand * __fastcall reader_extract_bitfield(c2_reader_cell *cell,uint16_t type)

{
  c2_operand *pcVar1;
  c2_operand *pcVar2;
  c2_operand *src1;
  c2_tuple *pcVar3;
  c2_const_operand *pcVar4;
  uint32_t uVar5;
  c2_tuple *pcVar6;
  int iVar7;
  uint64_t uVar8;
  code *insert_fn_00;
  c2_insert_fn *insert_fn;
  
  pcVar1 = ((cell->u10).label)->src;
  pcVar2 = ((cell->u10).label)->next->src;
  iVar7 = (type & 0xfff) * 8;
  cell->flags = cell->flags & 0xfb;
  src1 = reader_pop_operand(cell);
  if ((type & 0xf000) == 0x1000) {
    pcVar3 = cell->tail;
    uVar5 = (iVar7 - (int)pcVar2) - (int)pcVar1;
    insert_fn = tuple_splice_after;
    pcVar4 = operand_new_intconst(0x1001,uVar5,(int)uVar5 >> 0x1f);
    pcVar6 = tuple_new_binary_temp(0x171,type,src1,pcVar4,insert_fn,pcVar3);
    uVar5 = iVar7 - (int)pcVar1;
    insert_fn_00 = tuple_splice_after;
    pcVar3 = pcVar6;
    pcVar4 = operand_new_intconst(0x1001,uVar5,(int)uVar5 >> 0x1f);
    pcVar3 = tuple_new_binary_temp(0x177,type,pcVar6->dst,pcVar4,insert_fn_00,pcVar3);
    src1 = pcVar6->dst;
    cell->tail = pcVar3;
  }
  else {
    if (pcVar2 != (c2_operand *)0x0) {
      pcVar3 = cell->tail;
      pcVar2 = ((cell->u10).bitfield)->next;
      pcVar2->rank = 0;
      pcVar3 = tuple_new_binary_temp(0x177,type,src1,pcVar2,tuple_splice_after,pcVar3);
      src1 = pcVar3->dst;
      cell->tail = pcVar3;
    }
    pcVar3 = cell->tail;
    insert_fn = tuple_splice_after;
    uVar8 = aullshr('@' - (char)pcVar1,0xffffffff,0xffffffff);
    pcVar4 = operand_new_intconst(type,(uint32_t)uVar8,(int32_t)(uVar8 >> 0x20));
    pcVar3 = tuple_new_binary_temp(0x172,type,src1,pcVar4,insert_fn,pcVar3);
    cell->tail = pcVar3;
  }
  pcVar1 = (cell->u10).bitfield;
  if ((pcVar1->next->flags & 0x10) == 0) {
    node_free((c2_node *)pcVar1->next);
  }
  if ((pcVar1->flags & 0x10) == 0) {
    node_free((c2_node *)pcVar1);
  }
  (cell->u10).bitfield = (c2_operand *)0x0;
  return src1;
}

