int __fastcall sum_call_arg_bytes(c2_node *t)

{
  char cVar1;
  c2_node *t_00;
  uint32_t uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar3 = 0;
  piVar4 = (int *)**(int **)&t[1].kind;
  iVar5 = g_default_stack_align;
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  do {
    cVar1 = (char)piVar4[2];
    if ((((cVar1 != '\v') && (cVar1 != '\n')) && ((*(byte *)(piVar4 + 4) & 0x20) == 0)) &&
       ((cVar1 != '\x01' || (*(char *)(piVar4[5] + 4) != '\x01')))) {
      t_00 = *(c2_node **)(piVar4[5] + 0x14);
      uVar2 = t_00->op;
      if ((uVar2 == 0x15a) || (uVar2 == 0x16a)) {
        if ((cVar1 != '\x01') || (*(char *)(piVar4[6] + 4) != '\x01')) {
          if (uVar2 == 0x15a) {
            iVar3 = iVar3 + (((*(ushort *)((int)piVar4 + 10) & 0xfff) - 1) + iVar5 & ~(iVar5 - 1U));
          }
          else {
            uVar2 = arg_stack_size(t_00);
            iVar3 = iVar3 + uVar2;
            iVar5 = g_default_stack_align;
          }
        }
      }
      else if (uVar2 == 400) {
        if (*(short *)&t_00[2].next == 0xdf) {
          iVar3 = iVar3 + (*(int *)(*(int *)&t_00[1].kind + 0x18) + -1 + iVar5 & ~(iVar5 - 1U));
        }
        else {
          iVar3 = iVar3 + (*(int *)(**(int **)&t_00[1].kind + 0x18) + -1 + iVar5 & ~(iVar5 - 1U));
        }
      }
    }
    piVar4 = (int *)*piVar4;
  } while (piVar4 != (int *)0x0);
  return iVar3;
}

