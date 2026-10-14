ushort decl_check_calling_convention_fragment(void)

{
  ushort uVar1;
  ushort in_stack_00000010;
  
  if ((in_stack_00000010 & 7) == 0) {
    if ((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) {
      if ((in_stack_00000010 & 0x8000) != 0) {
        diag_warning(2,0x60,0x25,0x6a);
        goto LAB_10634987;
      }
      if (g_opt_Gr != '\0') {
        in_stack_00000010 = in_stack_00000010 | 3;
        goto LAB_10634993;
      }
    }
    if (g_opt_Gz != 0) {
      in_stack_00000010 = in_stack_00000010 | (~in_stack_00000010 & 0xbfff | 0x2000) >> 0xd;
      goto LAB_10634993;
    }
    if (g_opt_Gc != '\0') {
      in_stack_00000010 = in_stack_00000010 | 2;
      goto LAB_10634993;
    }
  }
  else {
    if ((((in_stack_00000010 & 7) != 5) && ((in_stack_00000010 & 7) != 3)) ||
       ((in_stack_00000010 & 0x8000) == 0)) goto LAB_10634993;
    in_stack_00000010 = in_stack_00000010 & 0xfff9;
  }
LAB_10634987:
  in_stack_00000010 = in_stack_00000010 | 1;
LAB_10634993:
  if ((((in_stack_00000010 & 0x8000) != 0) && (uVar1 = in_stack_00000010 & 7, uVar1 != 5)) &&
     ((uVar1 != 4 && (uVar1 != 1)))) {
    diag_error(0xd9,0x25,0x6a);
    return in_stack_00000010;
  }
  return in_stack_00000010;
}

