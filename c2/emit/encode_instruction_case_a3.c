int encode_instruction_case_a3
              (c2_operand *reg_op,c2_operand *rm_op,uint8_t *opcode,c2_tuple *t,uint8_t *form_code,
              uint8_t *buf,int size)

{
  byte bVar1;
  
  encode_modrm(t,rm_op,(((reg_op->u18).reg)->u28).frame_home);
  bVar1 = encode_imm_or_disp(rm_op->next,size,1);
  *opcode = *opcode | bVar1;
  if ((((g_x86_op_flags[t->op] & 1) == 0) && ((*form_code & 0x80) != 0)) && (size != 1)) {
    *opcode = *opcode | 1;
  }
  return (int)g_encode_cursor - (int)buf;
}

