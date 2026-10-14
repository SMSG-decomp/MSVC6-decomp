c2_tuple * __fastcall
emit_string_insn(uint32_t op,uint16_t type,c2_operand **dst,c2_operand **src,c2_operand **count,
                c2_tuple *anchor,uint32_t temp_mask,uint32_t dst_alias,uint32_t src_alias)

{
  uint32_t uVar1;
  c2_operand *src2;
  c2_symbol *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *t;
  
  uVar1 = (((*dst)->u18).reg)->id;
  if ((temp_mask & 1 << ((byte)uVar1 & 0x1f)) == 0) {
    pcVar3 = operand_new_hardreg(8,0x1004);
  }
  else {
    pcVar3 = operand_new_temp_in_reg(uVar1,0x1004);
  }
  src2 = *dst;
  t = tuple_new_binary(op,type | 0x1000,pcVar3,*src,src2,tuple_insert_after,anchor);
  if ((1 << ((byte)((src2->u18).reg)->id & 0x1f) & temp_mask) != 0) {
    *dst = pcVar3;
    pcVar2 = pcVar3->sym;
    if (pcVar2->storage->part_next == (c2_symbol *)0x0) {
      pcVar2->def = t;
    }
    else {
      symbol_mark_overlapping_parts(pcVar2,t);
    }
  }
  if (count != (c2_operand **)0x0) {
    pcVar3 = *count;
    tuple_append_src(t,pcVar3);
    uVar1 = ((pcVar3->u18).reg)->id;
    if ((temp_mask & 1 << ((byte)uVar1 & 0x1f)) == 0) {
      pcVar3 = operand_new_hardreg(2,0x1004);
      tuple_append_dst(t,pcVar3);
    }
    else {
      pcVar3 = operand_new_temp_in_reg(uVar1,0x1004);
      *count = pcVar3;
      tuple_append_dst(t,pcVar3);
      pcVar2 = pcVar3->sym;
      if (pcVar2->storage->part_next == (c2_symbol *)0x0) {
        pcVar2->def = t;
      }
      else {
        symbol_mark_overlapping_parts(pcVar2,t);
      }
    }
  }
  uVar1 = (((*src)->u18).reg)->id;
  if ((temp_mask & 1 << ((byte)uVar1 & 0x1f)) == 0) {
    if ((((op != 0x111) && (op != 0x110)) && (op != 0x3b)) && (op != 0x3a)) {
      pcVar3 = operand_new_hardreg(7,0x1004);
      tuple_append_dst(t,pcVar3);
    }
  }
  else {
    pcVar3 = operand_new_temp_in_reg(uVar1,0x1004);
    *src = pcVar3;
    tuple_append_dst(t,pcVar3);
    pcVar2 = pcVar3->sym;
    if (pcVar2->storage->part_next == (c2_symbol *)0x0) {
      pcVar2->def = t;
    }
    else {
      symbol_mark_overlapping_parts(pcVar2,t);
    }
  }
  if (dst_alias != 0) {
    pcVar3 = operand_new_memeffect(dst_alias);
    tuple_append_dst(t,pcVar3);
  }
  if (src_alias != 0) {
    pcVar3 = operand_new_memeffect(src_alias);
    tuple_append_src(t,pcVar3);
  }
  return t;
}

