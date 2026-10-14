c2_operand * __fastcall
build_byte_lane_copy
          (c2_operand *lane_operand,uint16_t type,c2_tuple *t,int dst_lane,int src_lane,
          int emit_copy)

{
  c2_operand *pcVar1;
  c2_const_operand *src;
  c2_operand *pcVar2;
  c2_tuple *pcVar3;
  c2_symbol *pcVar4;
  c2_insert_fn *insert_fn_00;
  c2_symbol *storage;
  c2_insert_fn *insert_fn;
  
  if ((type & 0xfff) == 1) {
    dst_lane = 0;
  }
  pcVar1 = strip_widening_converts(t->src,3);
  if (emit_copy != 0) {
    if (lane_operand == (c2_operand *)0x0) {
      lane_operand = operand_new_temp(type);
      if (1 < (type & 0xfff)) {
        insert_fn = tuple_insert_before;
        pcVar3 = t;
        src = operand_new_intconst(0x1004,0,0);
        pcVar2 = operand_narrow_to(lane_operand,0x1004,0);
        pcVar3 = tuple_new(0x15b,0x1004,pcVar2,src,insert_fn,pcVar3);
        pcVar4 = pcVar3->dst->sym;
        if (pcVar4->storage->part_next == (c2_symbol *)0x0) {
          pcVar4->def = pcVar3;
        }
        else {
          symbol_mark_overlapping_parts(pcVar4,pcVar3);
        }
      }
    }
    pcVar2 = operand_low_byte(lane_operand,dst_lane,1);
    pcVar3 = (c2_tuple *)0x0;
    insert_fn_00 = (c2_insert_fn *)0x0;
    pcVar1 = operand_low_byte(pcVar1,src_lane,0);
    pcVar3 = tuple_new(0x15b,0x1001,pcVar2,pcVar1,insert_fn_00,pcVar3);
    if (lane_operand->sym->def != (c2_tuple *)0x0) {
      tuple_append_src(pcVar3,lane_operand);
    }
    pcVar4 = pcVar2->sym;
    pcVar4->def = pcVar3;
    pcVar4 = pcVar4->storage;
    pcVar4->def = pcVar3;
    tuple_replace(t,(c2_node *)pcVar3);
    storage = (lane_operand->u18).reg;
    pcVar4 = symbol_get_part(pcVar4,type,type & 0xfff,0);
    pcVar1 = operand_new_reg(0x149,type,pcVar4,storage);
    return pcVar1;
  }
  pcVar1 = operand_low_byte(pcVar1,src_lane,0);
  tuple_unlink_free(t);
  return pcVar1;
}

