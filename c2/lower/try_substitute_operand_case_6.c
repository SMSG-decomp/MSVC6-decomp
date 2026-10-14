int __fastcall
try_substitute_operand_case_6
          (uint16_t new_type,uint16_t op_type,c2_operand *op,c2_operand *new_op,int part_offset,
          c2_tuple *t,c2_replace_fn *replace_fn)

{
  int iVar1;
  
  if ((new_type & 0xfff) < (op_type & 0xfff)) {
    iVar1 = test_narrowing_ok(t,new_type & 0xfff);
    if (iVar1 == 0) {
      return 0;
    }
    set_op_width(t,new_type & 0xfff);
  }
  else {
    new_op = operand_narrow_to(new_op,op_type,part_offset);
  }
  (*replace_fn)(t,op,new_op);
  return 1;
}

