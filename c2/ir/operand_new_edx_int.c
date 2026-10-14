c2_operand * operand_new_edx_int(void)

{
  c2_operand *pcVar1;
  
  pcVar1 = operand_new_hardreg(2,0x1004);
  return pcVar1;
}

