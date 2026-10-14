int encode_instruction_case_8
              (uint8_t *opcode,c2_operand *imm16,c2_tuple *t,uint8_t *form_code,uint8_t *buf,
              int size)

{
  if ((imm16->u18).lo == 0) {
    *opcode = *opcode | 1;
  }
  else {
    emit_value_bytes((imm16->u18).lo,2);
  }
  if ((((g_x86_op_flags[t->op] & 1) == 0) && ((*form_code & 0x80) != 0)) && (size != 1)) {
    *opcode = *opcode | 1;
  }
  return (int)g_encode_cursor - (int)buf;
}

