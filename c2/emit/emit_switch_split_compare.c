c2_tuple * __fastcall
emit_switch_split_compare
          (c2_switch_case_range *split,c2_tuple **right_label,c2_operand *value,c2_tuple *anchor)

{
  uint16_t type;
  uint32_t lo;
  int32_t hi;
  uint32_t lo_00;
  c2_fe_symbol *label_sym;
  c2_tuple *pcVar1;
  c2_const_operand *pcVar2;
  c2_tuple *cond_def;
  uint8_t cc;
  c2_insert_fn *splice_fn;
  
  label_sym = label_symbol_new_in_scope(g_reading_function);
  pcVar1 = tuple_new_label(label_sym);
  lo = split->last;
  hi = split->last_high;
  *right_label = pcVar1;
  splice_fn = tuple_splice_after;
  pcVar2 = operand_new_intconst(value->type,lo,hi);
  cond_def = tuple_new_compare(0x17d,value->type,value,pcVar2,splice_fn,anchor);
  pcVar1 = tuple_new_branch(0x185,'\x04',(c2_node *)pcVar1,cond_def->dst,cond_def,tuple_splice_after
                            ,cond_def);
  lo_00 = split->first;
  type = value->type;
  splice_fn = tuple_splice_after;
  pcVar2 = operand_new_intconst(type,lo_00,split->first_high);
  pcVar1 = tuple_new_compare(0x17d,type,value,pcVar2,splice_fn,pcVar1);
  if ((lo != lo_00) || (cc = '\x01', split->last_high != split->first_high)) {
    cc = '\x06';
  }
  pcVar1 = tuple_new_branch(0x185,cc,(c2_node *)split->label,pcVar1->dst,pcVar1,tuple_splice_after,
                            pcVar1);
  return pcVar1;
}

