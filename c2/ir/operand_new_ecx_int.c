c2_operand * operand_new_ecx_int(void)

{
  c2_operand *pcVar1;
  
  pcVar1 = operand_new_hardreg(1,0x1004);
  return pcVar1;
}

