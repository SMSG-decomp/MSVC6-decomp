ushort __cdecl decl_apply_default_calling_convention(uint kind,ushort flags)

{
  bool bVar1;
  ushort uVar2;
  
  if (g_opt_Zg != '\0') {
    return flags;
  }
  bVar1 = false;
  switch(kind & 0x8f) {
  case 0x80:
  case 0x82:
  case 0x83:
    return flags;
  case 0x81:
  case 0x85:
    break;
  case 0x84:
  case 0x86:
    goto switchD_1042e7a0_caseD_84;
  default:
    goto switchD_1042e7a0_default;
  }
  bVar1 = true;
switchD_1042e7a0_caseD_84:
  if ((flags & 7) == 0) {
    if ((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) {
      if ((flags & 0x8000) != 0) {
        diag_warning(2,0x60,0x25,0x6a);
        goto LAB_10472b1d;
      }
      if (g_opt_Gr != '\0') {
        flags = flags | 3;
        goto LAB_10472b29;
      }
    }
    if (g_default_stdcall == 0) {
      if (g_opt_Gc == '\0') goto LAB_10472b1d;
      flags = flags | 2;
    }
    else {
      flags = flags | (~flags & 0xbfff | 0x2000) >> 0xd;
    }
  }
  else if ((((flags & 7) == 5) || ((flags & 7) == 3)) && ((flags & 0x8000) != 0)) {
    flags = flags & 0xfff9;
LAB_10472b1d:
    flags = flags | 1;
  }
LAB_10472b29:
  if (((bVar1) && ((flags & 0x8000) != 0)) &&
     ((uVar2 = flags & 7, uVar2 != 5 && ((uVar2 != 4 && (uVar2 != 1)))))) {
    diag_error(0xd9,0x25,0x6a);
    return flags;
  }
switchD_1042e7a0_default:
  return flags;
}

