longlong __cdecl lex_scan_integer_constant(byte *digits,int count,int base)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  bool bVar6;
  longlong lVar7;
  
  iVar3 = g_integral_max_bytes * 8;
  iVar2 = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
  if (iVar2 < count) {
    bVar1 = *digits;
    while (bVar1 == 0x30) {
      pbVar4 = digits + 1;
      count = count + -1;
      digits = digits + 1;
      bVar1 = *pbVar4;
    }
    if (count == 0) {
      return 0;
    }
    if (iVar2 < count) {
      if (base == 8) {
        iVar2 = iVar3 / 3 + 1;
        if ((iVar2 <= count) &&
           ((count != iVar2 ||
            ((int)(char)((-(iVar3 % 3 != 2) & 0xfeU) + 0x33) < (int)(uint)*digits))))
        goto LAB_10463620;
      }
      else if (base == 10) {
        if (g_integral_max_bytes == 8) {
          iVar3 = 0x14;
        }
        else {
          iVar3 = (-(uint)(g_integral_max_bytes != 0x10) & 0xffffffe3) + 0x27;
        }
        if (iVar3 <= count) {
          if (g_integral_max_bytes == 8) {
            iVar3 = 0x14;
          }
          else {
            iVar3 = (-(uint)(g_integral_max_bytes != 0x10) & 0xffffffe3) + 0x27;
          }
          if (count == iVar3) {
            pbVar4 = digits;
            if (g_integral_max_bytes == 8) {
              pcVar5 = "18446744073709551615";
            }
            else {
              pcVar5 = "340282366920938463463374607431768211455";
              if (g_integral_max_bytes != 0x10) {
                pcVar5 = "4294967295";
              }
            }
            do {
              bVar1 = *pbVar4;
              bVar6 = bVar1 < (byte)*pcVar5;
              if (bVar1 != *pcVar5) {
LAB_104636c2:
                iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
                goto LAB_10463688;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar6 = bVar1 < (byte)pcVar5[1];
              if (bVar1 != pcVar5[1]) goto LAB_104636c2;
              pcVar5 = pcVar5 + 2;
              pbVar4 = pbVar4 + 2;
            } while (bVar1 != 0);
            iVar3 = 0;
LAB_10463688:
            if (iVar3 < 1) goto LAB_1040aa0f;
          }
LAB_10463620:
          diag_error(0xb1);
          return 0;
        }
      }
      else if (base == 0x10) goto LAB_10463620;
    }
  }
LAB_1040aa0f:
  lVar7 = 0;
  while( true ) {
    iVar3 = lex_hex_digit_value((uint)*digits);
    if (base <= iVar3) {
      diag_error(0x29,(uint)*digits,base);
    }
    lVar7 = lVar7 + iVar3;
    pbVar4 = digits + 1;
    digits = digits + 1;
    if (*pbVar4 == 0) break;
    lVar7 = _allmul(base,base >> 0x1f,(uint)lVar7,(int)((ulonglong)lVar7 >> 0x20));
  }
  return lVar7;
}

