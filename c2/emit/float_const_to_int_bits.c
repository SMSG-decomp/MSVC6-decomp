c2_const_operand * __fastcall float_const_to_int_bits(c2_float_const *value,uint16_t type)

{
  ushort uVar1;
  c2_const_operand *pcVar2;
  uint32_t int_bits [2];
  
  uVar1 = type & 0xfff;
  if (uVar1 == 4) {
    fpu_store_float(value,(float *)int_bits);
  }
  else if (uVar1 == 8) {
    fpu_store_double(value,(double *)int_bits);
  }
  else if (uVar1 == 10) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\lowerflt.c",0x508);
  }
  pcVar2 = operand_new_intconst(type,int_bits[0],int_bits[1]);
  return pcVar2;
}

