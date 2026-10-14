int is_known_nonnegative_case_146(c2_operand *k)

{
  int iVar1;
  int64_t iVar2;
  
  iVar2 = sign_extend_to_size(k,0x80000000);
  if (((uint)iVar2 & (k->u18).lo) != 0 || ((uint)((ulonglong)iVar2 >> 0x20) & k->tag) != 0) {
    iVar1 = is_known_nonnegative_case_147();
    return iVar1;
  }
  return 1;
}

