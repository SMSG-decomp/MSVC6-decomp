uint __cdecl type_classify_class_form(c1_type *type,int *cls_out)

{
  ushort uVar1;
  
  *cls_out = 0;
  uVar1 = type->code;
  if ((uVar1 & 0x200) != 0) {
    *cls_out = (int)type->extra;
    return 1;
  }
  if ((char)uVar1 < '\0') {
    uVar1 = uVar1 & 0x8f;
    if (uVar1 == 0x82) {
      if ((type->base->code >> 9 & 1) != 0) {
        *cls_out = (int)type->base->extra;
        return 4;
      }
    }
    else if (uVar1 == 0x80) {
      if ((type->base->code >> 9 & 1) != 0) {
        *cls_out = (int)type->base->extra;
        return 8;
      }
    }
    else {
      if (uVar1 == 0x83) {
        do {
          type = type->base;
        } while ((type->code & 0x8f) == 0x83);
      }
      if ((type->code & 0x200) != 0) {
        *cls_out = (int)type->extra;
        return 2;
      }
    }
  }
  return 0;
}

