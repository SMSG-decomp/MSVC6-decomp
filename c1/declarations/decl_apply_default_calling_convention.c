ushort __cdecl decl_apply_default_calling_convention(uint code,ushort flags)

{
  bool bVar1;
  ushort uVar2;
  
  if (g_opt_Zg == '\0') {
    bVar1 = false;
    switch(code & 0x8f) {
    case 0x81:
    case 0x85:
      goto decl_check_calling_convention_fragment;
    case 0x82:
    case 0x83:
      return flags;
    default:
      return flags;
    case 0x86:
      goto switchD_106155f0_caseD_86;
    }
  }
  return flags;
decl_check_calling_convention_fragment:
  bVar1 = true;
switchD_106155f0_caseD_86:
  if ((flags & 7) == 0) {
    if ((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) {
      if ((flags & 0x8000) != 0) {
        diag_warning(2,0x60,0x25,0x6a);
        goto LAB_10634987;
      }
      if (g_opt_Gr != '\0') {
        flags = flags | 3;
        goto LAB_10634993;
      }
    }
    if (g_opt_Gz != 0) {
      flags = flags | (~flags & 0xbfff | 0x2000) >> 0xd;
      goto LAB_10634993;
    }
    if (g_opt_Gc != '\0') {
      flags = flags | 2;
      goto LAB_10634993;
    }
  }
  else {
    if ((((flags & 7) != 5) && ((flags & 7) != 3)) || ((flags & 0x8000) == 0)) goto LAB_10634993;
    flags = flags & 0xfff9;
  }
LAB_10634987:
  flags = flags | 1;
LAB_10634993:
  if (((bVar1) && ((flags & 0x8000) != 0)) &&
     ((uVar2 = flags & 7, uVar2 != 5 && ((uVar2 != 4 && (uVar2 != 1)))))) {
    diag_error(0xd9,0x25,0x6a);
    return flags;
  }
  return flags;
}

