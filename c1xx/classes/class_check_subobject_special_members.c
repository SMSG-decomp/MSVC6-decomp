int __cdecl class_check_subobject_special_members(c1_symbol *cls,c1_symbol *sub,c1_u8 *rows)

{
  int iVar1;
  int iVar2;
  int kind;
  
  iVar2 = 0;
  kind = 1;
  do {
    if ((((sub->detail).cls)->implicit_state41 & (byte)(1 << ((byte)kind & 0x1f))) == 0) {
      iVar1 = class_subobject_special_member_usable(cls,sub,rows,kind);
      iVar2 = iVar2 + iVar1;
    }
    kind = kind + 1;
  } while (kind < 5);
  return iVar2;
}

