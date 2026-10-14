int __fastcall tuple_encoded_length(c2_tuple *t)

{
  int iVar1;
  uint8_t local_40 [64];
  
  iVar1 = encode_instruction(t,local_40,0,0,(c2_fe_symbol *)0x0);
  return iVar1;
}

