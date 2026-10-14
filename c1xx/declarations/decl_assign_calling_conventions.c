void __fastcall decl_assign_calling_conventions(int rec)

{
  c1_type *pcVar1;
  c1_type *type;
  ushort flags;
  short n;
  int iVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  
  pcVar1 = *(c1_type **)(*(int *)(rec + 8) + 4);
  if ((*(byte *)(rec + 0x3c) & 8) != 0) {
    *(byte *)(rec + 0x3c) = *(byte *)(rec + 0x3c) | 2;
  }
  pcVar4 = (c1_type *)0x0;
  type = *(c1_type **)(rec + 4);
  do {
    if (type == pcVar1) {
      return;
    }
    flags = type->flags & 7;
    if (flags == 0) {
      if ((type->code & 0x83) == 0x81) {
        if (type == *(c1_type **)(rec + 4)) {
          flags = *(ushort *)(rec + 0xc) & 7;
          if (flags == 0) {
            *(byte *)(rec + 0x3c) = *(byte *)(rec + 0x3c) & 0xfd;
            iVar2 = decl_default_calling_convention((void *)rec,(byte *)type);
            flags = (ushort)iVar2;
          }
          else {
            *(ushort *)(rec + 0xc) = *(ushort *)(rec + 0xc) & 0xfff8;
          }
        }
        else {
          pcVar3 = pcVar4;
          if ((pcVar4->code & 0x8f) == 0x83) {
            pcVar3 = type_skip_arrays(pcVar4->base);
          }
          if ((pcVar3->flags & 7) == 0) {
            iVar2 = decl_default_calling_convention((void *)rec,(byte *)type);
            flags = (ushort)iVar2;
            goto LAB_10401ac6;
          }
          if ((pcVar4->code & 0x8f) == 0x83) {
            pcVar4 = type_skip_arrays(pcVar4->base);
            flags = (byte)pcVar4->flags & 7;
          }
          else {
            flags = (byte)pcVar4->flags & 7;
          }
        }
        goto LAB_10401a6b;
      }
      goto switchD_10401a9f_caseD_83;
    }
    type->flags = type->flags & 0xfff8;
    switch((byte)type->code & 0x8f) {
    case 0x80:
      n = 0x214;
      break;
    case 0x81:
    case 0x85:
      flags = decl_check_varargs_calling_convention((void *)rec,type,flags);
      if (type != *(c1_type **)(rec + 4)) {
LAB_10401ac6:
        pcVar4->flags = pcVar4->flags | flags;
      }
      goto LAB_10401a6b;
    case 0x82:
      n = 0xa5;
      break;
    default:
      goto switchD_10401a9f_caseD_83;
    case 0x84:
    case 0x86:
    case 0x8e:
      if (type->base != pcVar1) {
        flags = decl_check_varargs_calling_convention((void *)rec,type->base,flags);
      }
LAB_10401a6b:
      type->flags = type->flags | flags;
      goto switchD_10401a9f_caseD_83;
    case 0x8a:
      n = 0x27d;
    }
    diag_error(n,0x78);
    *(byte *)(rec + 0x3c) = *(byte *)(rec + 0x3c) | 1;
switchD_10401a9f_caseD_83:
    pcVar4 = type;
    type = type->base;
  } while( true );
}

