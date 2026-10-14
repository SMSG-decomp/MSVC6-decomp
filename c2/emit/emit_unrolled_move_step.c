void __fastcall
emit_unrolled_move_step
          (c2_tuple *anchor,int is_fill,c2_operand **src,c2_operand **dst,uint16_t type,
          int32_t offset,int rebind,uint32_t dst_alias,uint32_t src_alias)

{
  c2_operand *pcVar1;
  c2_tuple *anchor_00;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  ushort type_00;
  
  type_00 = type | 0x1000;
  if (is_fill == 0) {
    pcVar3 = *src;
    pcVar1 = operand_at_offset(pcVar3,type_00,offset,src_alias);
    anchor_00 = tuple_new_unary_temp(1,type_00,pcVar1,tuple_insert_before,anchor);
    pcVar1 = *dst;
    pcVar2 = operand_at_offset(pcVar1,type_00,offset,dst_alias);
    offset = (int32_t)tuple_new(1,type_00,pcVar2,anchor_00->dst,tuple_insert_after,anchor_00);
    if (((1 << (pcVar2->kind & 0x1f) & 6U) != 0) && (pcVar4 = pcVar2->sym, pcVar4->cls == '\x03')) {
      if (pcVar4->storage->part_next == (c2_symbol *)0x0) {
        pcVar4->def = (c2_tuple *)offset;
      }
      else {
        symbol_mark_overlapping_parts(pcVar4,(c2_tuple *)offset);
      }
    }
  }
  else {
    pcVar1 = *dst;
    pcVar2 = operand_at_offset(pcVar1,type_00,offset,dst_alias);
    pcVar3 = *src;
    offset = (int32_t)tuple_new(1,type_00,pcVar2,pcVar3,tuple_insert_before,anchor);
    pcVar2 = ((c2_tuple *)offset)->src;
    pcVar2->type = type_00;
    anchor_00 = (c2_tuple *)offset;
    if (pcVar2->sym->type != type_00) {
      pcVar4 = symbol_get_part(pcVar2->sym,type_00,type & 0xfff,0);
      pcVar2->sym = pcVar4;
    }
  }
  _type = anchor_00;
  if (rebind != 0) {
    if (pcVar3->kind == '\x01') {
      pcVar3 = bind_value_to_new_temp(_type,pcVar3->sym,1);
      *src = pcVar3;
    }
    if (pcVar1->kind == '\x01') {
      pcVar3 = bind_value_to_new_temp((c2_tuple *)offset,pcVar1->sym,1);
      *dst = pcVar3;
    }
  }
  return;
}

