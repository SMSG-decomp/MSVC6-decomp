ushort __cdecl import_typedesc_to_vartype(c1_itypeinfo *typeinfo,void *typedesc)

{
  byte bVar1;
  bool bVar2;
  ushort uVar3;
  long err;
  c1_itypeinfo *pcStack_8;
  c1_typeattr *pcStack_4;
  
  switch(*(ushort *)((int)typedesc + 4)) {
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x11:
    return *(ushort *)((int)typedesc + 4);
  case 0x10:
    return 0x11;
  case 0x12:
    return 2;
  case 0x13:
  case 0x16:
  case 0x17:
    return 3;
  case 0x18:
    return 0;
  case 0x19:
    return 10;
  case 0x1a:
    uVar3 = import_typedesc_to_vartype(typeinfo,*(void **)typedesc);
    if (((uVar3 != 0xffff) && (uVar3 != 0)) && ((uVar3 & 0x4000) == 0)) {
      if ((uVar3 & 0x8000) == 0) {
        return uVar3 | 0x4000;
      }
      return uVar3 ^ 0x8000;
    }
    break;
  case 0x1b:
    uVar3 = import_typedesc_to_vartype(typeinfo,*(void **)typedesc);
    if (((uVar3 != 0xffff) && (uVar3 != 0)) && ((uVar3 & 0x6000) == 0)) {
      return uVar3 | 0x2000;
    }
    break;
  case 0x1d:
    bVar1 = import_get_ref_type_info(typeinfo,*(uint *)typedesc,&typeinfo);
    if (bVar1 != 0) {
      err = (*typeinfo->vtbl->GetTypeAttr)(typeinfo,&typedesc);
      if (err < 0) {
        diag_fatal_file(err,0x54,0x166,g_import_file_as_written);
      }
      switch(*(undefined4 *)((int)typedesc + 0x28)) {
      case 0:
        uVar3 = 3;
        break;
      default:
        uVar3 = 0xffff;
        break;
      case 3:
        uVar3 = (byte)~*(byte *)((int)typedesc + 0x36) >> 4 & 4 | 0x8009;
        break;
      case 4:
        uVar3 = 0x8009;
        break;
      case 5:
        bVar2 = import_coclass_default_interface(typeinfo,typedesc,&pcStack_8,&pcStack_4);
        if (bVar2) {
          if (pcStack_4->typekind == 3) {
            uVar3 = (byte)~(byte)pcStack_4->wTypeFlags >> 4 & 4 | 0x8009;
          }
          else if (pcStack_4->typekind == 4) {
            uVar3 = 0x8009;
          }
          else {
            uVar3 = 0xffff;
          }
          (*pcStack_8->vtbl->ReleaseTypeAttr)(pcStack_8,pcStack_4);
          (*pcStack_8->vtbl->Release)(pcStack_8);
        }
        else {
          uVar3 = 0xffff;
        }
        break;
      case 6:
        uVar3 = import_typedesc_to_vartype(typeinfo,(void *)((int)typedesc + 0x3c));
      }
      (*typeinfo->vtbl->ReleaseTypeAttr)(typeinfo,typedesc);
      (*typeinfo->vtbl->Release)(typeinfo);
      return uVar3;
    }
    return 0xffff;
  }
  return 0xffff;
}

