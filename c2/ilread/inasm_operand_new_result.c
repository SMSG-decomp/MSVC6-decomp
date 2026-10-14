c2_operand * __fastcall inasm_operand_new_result(int op,uint16_t type)

{
  c2_operand *pcVar1;
  
  if (((g_x86_op_flags[op] & 1) != 0) && (3 < (type & 0xfff))) {
    pcVar1 = operand_new_hardreg(0x1f,type);
    return pcVar1;
  }
  pcVar1 = operand_new_hardreg(0x42,0x8000);
  return pcVar1;
}

