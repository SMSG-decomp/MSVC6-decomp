void __fastcall tmpl_deferred_report_c2780(c1xx_obj_104cee94 *action)

{
  ushort uVar1;
  c1xx_vtbl_104cee94 *pcVar2;
  uint uVar3;
  int iVar4;
  char cStack_1;
  
  pcVar2 = action[1].vtbl;
  uVar3 = (uint)pcVar2[5].tmpl_deferred_report_c2780 &
          -(uint)(((byte)*pcVar2[5].tmpl_deferred_report_c2780 & 0x80) != 0);
  uVar1 = *(ushort *)(uVar3 + 2);
  if ((uVar1 & 0x4000) == 0) {
    iVar4 = **(int **)(*(int *)(uVar3 + 8) + 0xc);
    if ((uVar1 & 0x8000) == 0) {
      cStack_1 = '\0';
    }
    else {
      iVar4 = iVar4 + -1;
      cStack_1 = '\x01';
    }
  }
  else {
    cStack_1 = (char)((uint)action >> 0x18);
    iVar4 = 0;
  }
  if (cStack_1 != '\0') {
    diag_error(0x30d,pcVar2,iVar4,action[3].vtbl);
    return;
  }
  diag_error(0x30c,pcVar2,iVar4,action[3].vtbl);
  return;
}

