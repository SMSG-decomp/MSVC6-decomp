void __cdecl opt_parse_switch_string(byte *s)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char **ppcVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  bool bVar10;
  
  if (s != (byte *)0x0) {
    ppcVar5 = opt_check_switch_count();
    bVar1 = *s;
    while (bVar1 == 0x20) {
      pbVar8 = s + 1;
      s = s + 1;
      bVar1 = *pbVar8;
    }
    bVar1 = *s;
    while (bVar1 != 0) {
      *ppcVar5 = (char *)s;
      ppcVar5 = ppcVar5 + 1;
      bVar2 = false;
      bVar3 = false;
      if (799 < (int)((int)ppcVar5 - (int)g_switch_words & 0xfffffffcU)) {
        diag_fatal(0x4d,200);
      }
      g_option_args_left = g_option_args_left + 1;
      pbVar8 = s;
      while( true ) {
        uVar6 = 0;
        bVar4 = true;
        bVar1 = *pbVar8;
        while (bVar1 == 0x5c) {
          pbVar9 = pbVar8 + 1;
          pbVar8 = pbVar8 + 1;
          uVar6 = uVar6 + 1;
          bVar1 = *pbVar9;
        }
        if (*pbVar8 == 0x22) {
          uVar7 = uVar6 & 0x80000001;
          bVar10 = uVar7 == 0;
          if ((int)uVar7 < 0) {
            bVar10 = (uVar7 - 1 | 0xfffffffe) == 0xffffffff;
          }
          bVar4 = true;
          if (bVar10) {
            if ((bVar2) && (pbVar8[1] == 0x22)) {
              pbVar8 = pbVar8 + 1;
              bVar4 = true;
            }
            else {
              bVar4 = false;
            }
            bVar2 = !bVar2;
            bVar3 = bVar2;
          }
          uVar6 = (int)uVar6 / 2;
        }
        if (uVar6 != 0) {
          pbVar9 = s;
          for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            pbVar9[0] = 0x5c;
            pbVar9[1] = 0x5c;
            pbVar9[2] = 0x5c;
            pbVar9[3] = 0x5c;
            pbVar9 = pbVar9 + 4;
          }
          s = s + uVar6;
          for (uVar6 = uVar6 & 3; bVar2 = bVar3, uVar6 != 0; uVar6 = uVar6 - 1) {
            *pbVar9 = 0x5c;
            pbVar9 = pbVar9 + 1;
          }
        }
        bVar1 = *pbVar8;
        if ((bVar1 == 0) || ((!bVar2 && (bVar1 == 0x20)))) break;
        if (bVar4) {
          if (g_char_class[bVar1] == '#') {
            *s = bVar1;
            s = s + 1;
            pbVar8 = pbVar8 + 1;
          }
          *s = *pbVar8;
          s = s + 1;
        }
        pbVar8 = pbVar8 + 1;
      }
      bVar1 = *pbVar8;
      while (bVar1 == 0x20) {
        pbVar9 = pbVar8 + 1;
        pbVar8 = pbVar8 + 1;
        bVar1 = *pbVar9;
      }
      *s = 0;
      s = pbVar8;
      bVar1 = *pbVar8;
    }
    *ppcVar5 = (char *)0x0;
  }
  return;
}

