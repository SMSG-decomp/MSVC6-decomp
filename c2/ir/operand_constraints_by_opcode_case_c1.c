void operand_constraints_by_opcode_case_c1
               (c2_operand *opnd,c2_operand *opnd2,uint32_t *constraints,c2_operand *dst,c2_tuple *t
               )

{
  if (opnd->kind != '\x01') {
    *constraints = *constraints | 2;
  }
  operand_pair_constraints(t,dst,opnd,opnd2,constraints);
  return;
}

