byte __cdecl type_member_pointer_is_aggregate(c1_type *type)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = type->code & 0x8f;
  if ((uVar1 == 0x8a) || (uVar1 == 0x8e)) {
    iVar2 = class_complete_type_of(type);
    switch(iVar2) {
    case 2:
      return (type->code & 0x8f) == 0x8e;
    case 3:
    case 4:
      return 1;
    }
  }
  return 0;
}

