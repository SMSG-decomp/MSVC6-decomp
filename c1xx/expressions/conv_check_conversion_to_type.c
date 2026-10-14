int __cdecl conv_check_conversion_to_type(uint op,c1_type *target,c1_node *e)

{
  char cVar1;
  c1_type *pcVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  
  if ((e->kind & 0x80) != 0) {
    uVar3 = target->code & 0x8f;
    if ((uVar3 == 0x83) || (uVar3 == 0x82)) {
      return 1;
    }
    if (uVar3 == 0x86) {
      iVar4 = expr_check_void_in_conditional_return_true();
      return iVar4;
    }
  }
  iVar4 = conv_check_assignment_compatibility(op,target,e->type);
  if (((char)target->code < '\0') || (pcVar2 = e->type, (char)pcVar2->code < '\0')) {
    return iVar4;
  }
  cVar1 = (char)pcVar2->code;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  iVar5 = ((target->code & 0x40) >> 6) + (((byte)pcVar2->code & 0x40) >> 6);
  if ((char)op == '6') {
    if (iVar5 == 1) {
      diag_warning(4,0x35);
      conv_warn_possible_loss_of_data(op,e,target);
      return iVar4;
    }
  }
  else {
    if (iVar5 == 1) {
      if ((char)op == '}') {
        if ((g_current_function->flags22 & 1) == 0) {
          diag_error(0x231,g_current_function);
          conv_warn_possible_loss_of_data(op,e,target);
          return iVar4;
        }
        goto LAB_104811f0;
      }
    }
    else if (iVar5 != 2) {
      conv_warn_possible_loss_of_data(op,e,target);
      return iVar4;
    }
    diag_error(0x78);
  }
LAB_104811f0:
  conv_warn_possible_loss_of_data(op,e,target);
  iVar4 = expr_check_void_in_conditional_return(iVar4);
  return iVar4;
}

