uint16_t __fastcall extension_source_type(c2_operand *a,c2_operand *b)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = a->type;
  if ((uVar1 & 0xfff) != 1) {
    iVar2 = operand_readable_as_dword(a);
    if (iVar2 != 0) {
      return b->type;
    }
    uVar1 = a->type;
  }
  return uVar1;
}

