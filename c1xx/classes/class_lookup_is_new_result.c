char __cdecl class_lookup_is_new_result(byte *sym,c1_vector *found)

{
  int iVar1;
  short sVar2;
  
  if (((*sym & 0x1f) == 0xf) && ((sym[0x1a] & 1) != 0)) {
    sVar2 = 0;
    while ((found != (c1_vector *)0x0 && (iVar1 = (int)sVar2, iVar1 < (int)(uint)found->count))) {
      sVar2 = sVar2 + 1;
      if (((*(byte *)found->data[iVar1] & 0x1f) == 0xf) &&
         ((*(byte *)((int)found->data[iVar1] + 0x1a) & 1) != 0)) {
        return '\0';
      }
    }
  }
  else {
    iVar1 = sym_is_static_data_member((c1_symbol *)sym);
    if (iVar1 == 0) {
      if ((sym[2] & 0x10) != 0) {
        sVar2 = 0;
        while ((found != (c1_vector *)0x0 && (iVar1 = (int)sVar2, iVar1 < (int)(uint)found->count)))
        {
          sVar2 = sVar2 + 1;
          if (sym == found->data[iVar1]) {
            return '\0';
          }
        }
      }
    }
    else {
      sVar2 = 0;
      while ((found != (c1_vector *)0x0 && (iVar1 = (int)sVar2, iVar1 < (int)(uint)found->count))) {
        sVar2 = sVar2 + 1;
        if (sym == found->data[iVar1]) {
          return '\0';
        }
      }
    }
  }
  return '\x01';
}

