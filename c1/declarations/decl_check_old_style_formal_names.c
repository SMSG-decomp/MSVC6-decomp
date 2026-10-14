int __cdecl decl_check_old_style_formal_names(void *params)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 1;
  if (params == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)((int)params + 4);
  }
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return uVar3;
    }
    pbVar1 = (byte *)(piVar2 + -2);
    switch(uVar3) {
    case 1:
      if ((*pbVar1 & 0x1f) == 0xc) {
        uVar3 = 4;
      }
      else if ((*pbVar1 & 0x1f) == 0xb) {
        uVar3 = (uint)(byte)((~*(byte *)((int)piVar2 + -5) & 0x10 | 0x20) >> 4);
      }
      break;
    case 2:
      if ((*pbVar1 & 0x1f) == 0xc) {
        diag_error(0x7a,0x54,piVar2[3]);
      }
      else if (((*pbVar1 & 0x1f) == 0xb) && ((*(byte *)((int)piVar2 + -5) & 0x10) == 0)) {
        if (((void *)*piVar2 == g_name_ellipsis) && (g_ms_extensions != '\0')) {
          diag_warning(4,0xca);
        }
        else {
          diag_error(0x7a,0x53,pbVar1);
        }
      }
      break;
    case 3:
    case 4:
      if ((*pbVar1 & 0x1f) == 0xc) {
        uVar3 = 4;
      }
      else if (((*pbVar1 & 0x1f) == 0xb) && ((*(byte *)((int)piVar2 + -5) & 0x10) != 0)) {
        diag_error(0x51,pbVar1);
      }
    }
    if (piVar2 == (int *)0x0) break;
    piVar2 = (int *)piVar2[1];
  }
  return uVar3;
}

