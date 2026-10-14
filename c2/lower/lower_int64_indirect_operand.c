void __fastcall lower_int64_indirect_operand(c2_tuple *t,c2_operand *opnd)

{
  uint16_t type;
  c2_operand *dst;
  c2_tuple *t_00;
  
  if (((opnd->kind == '\x06') && ((1 << (opnd->base->kind & 0x1f) & 6U) != 0)) &&
     (opnd->base->sym->def != (c2_tuple *)0x0)) {
    type = opnd->type;
    dst = operand_new_temp_sym(type);
    t_00 = tuple_new(1,type,dst,opnd,tuple_insert_before,t);
    tuple_replace_src(t,opnd,dst);
    lower_int64_tuple(t_00);
  }
  return;
}

